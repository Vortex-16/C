#!/bin/bash

# Password Generator
# Generates strong random passwords using /dev/urandom
# Skills: /dev/urandom, tr, head, openssl

show_usage() {
    echo "Usage: $0 [OPTIONS]"
    echo ""
    echo "Options:"
    echo "  -l, --length <number>   Password length (default: 16)"
    echo "  -c, --count <number>    Generate multiple passwords (default: 1)"
    echo "  -t, --type <type>       Password type:"
    echo "                          - basic    (alphanumeric only)"
    echo "                          - strong   (alphanumeric + symbols)"
    echo "                          - complex  (all characters)"
    echo "  -s, --special           Include special characters"
    echo "  -n, --numbers           Include numbers"
    echo "  -u, --uppercase         Include uppercase letters"
    echo "  -C, --clipboard         Copy password to clipboard"
    echo ""
    echo "Examples:"
    echo "  $0                           # 16-char strong password"
    echo "  $0 -l 32 -c 5                # 5 passwords of 32 chars each"
    echo "  $0 -l 20 -t basic            # Alphanumeric only"
    echo "  $0 -l 24 -t complex          # Maximum complexity"
}

# Default values
PASSWORD_LENGTH=16
PASSWORD_COUNT=1
PASSWORD_TYPE="strong"
INCLUDE_SPECIAL=true
INCLUDE_NUMBERS=true
INCLUDE_UPPERCASE=true
COPY_TO_CLIPBOARD=false

# Parse command line arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        -l|--length)
            PASSWORD_LENGTH="$2"
            shift 2
            ;;
        -c|--count)
            PASSWORD_COUNT="$2"
            shift 2
            ;;
        -t|--type)
            PASSWORD_TYPE="$2"
            shift 2
            ;;
        -s|--special)
            INCLUDE_SPECIAL=true
            shift
            ;;
        -n|--numbers)
            INCLUDE_NUMBERS=true
            shift
            ;;
        -u|--uppercase)
            INCLUDE_UPPERCASE=true
            shift
            ;;
        -C|--clipboard)
            COPY_TO_CLIPBOARD=true
            shift
            ;;
        -h|--help)
            show_usage
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            show_usage
            exit 1
            ;;
    esac
done

# Validate password length
if ! [[ "$PASSWORD_LENGTH" =~ ^[0-9]+$ ]] || [ "$PASSWORD_LENGTH" -lt 4 ]; then
    echo "Error: Password length must be at least 4"
    exit 1
fi

# Set character sets based on type
case $PASSWORD_TYPE in
    basic)
        CHARSET="a-zA-Z0-9"
        ;;
    strong)
        CHARSET="a-zA-Z0-9!@#$%^&*"
        ;;
    complex)
        CHARSET="a-zA-Z0-9!@#$%^&*()_+-={}[]|:;<>,.?/~"
        ;;
    *)
        echo "Error: Unknown password type '$PASSWORD_TYPE'"
        show_usage
        exit 1
        ;;
esac

# Generate passwords
echo "Password Generator"
echo "════════════════════════════════════════"
echo ""

for ((i=1; i<=PASSWORD_COUNT; i++)); do
    # Generate password using /dev/urandom and tr
    PASSWORD=$(head -c 100 /dev/urandom | tr -cd "$CHARSET" | head -c "$PASSWORD_LENGTH")
    
    # Ensure password meets minimum requirements
    while [ ${#PASSWORD} -lt $PASSWORD_LENGTH ]; do
        PASSWORD=$(head -c 100 /dev/urandom | tr -cd "$CHARSET" | head -c $((PASSWORD_LENGTH - ${#PASSWORD})))
    done
    
    # Display the password
    if [ "$PASSWORD_COUNT" -eq 1 ]; then
        echo -e "Generated Password: \033[1;32m$PASSWORD\033[0m"
    else
        echo -e "Password $i: \033[1;32m$PASSWORD\033[0m"
    fi
    
    # Copy to clipboard if requested (single password only)
    if [ "$COPY_TO_CLIPBOARD" = true ] && [ "$PASSWORD_COUNT" -eq 1 ]; then
        if command -v xclip &> /dev/null; then
            echo "$PASSWORD" | xclip -selection clipboard
            echo "✓ Copied to clipboard!"
        elif command -v xsel &> /dev/null; then
            echo "$PASSWORD" | xsel --clipboard --input
            echo "✓ Copied to clipboard!"
        else
            echo "⚠ Clipboard tools not available"
        fi
    fi
done

echo ""
echo "════════════════════════════════════════"
echo "Length: $PASSWORD_LENGTH characters"
echo "Type: $PASSWORD_TYPE"
echo ""

# Password strength indicator
calculate_strength() {
    local pass="$1"
    local strength=0
    
    # Check for lowercase
    if [[ $pass =~ [a-z] ]]; then
        ((strength++))
    fi
    
    # Check for uppercase
    if [[ $pass =~ [A-Z] ]]; then
        ((strength++))
    fi
    
    # Check for numbers
    if [[ $pass =~ [0-9] ]]; then
        ((strength++))
    fi
    
    # Check for special characters
    if [[ $pass =~ [^a-zA-Z0-9] ]]; then
        ((strength++))
    fi
    
    # Check length
    if [ ${#pass} -ge 16 ]; then
        ((strength++))
    fi
    
    echo $strength
}

if [ "$PASSWORD_COUNT" -eq 1 ]; then
    STRENGTH=$(calculate_strength "$PASSWORD")
    echo -n "Strength: "
    case $STRENGTH in
        1|2)
            echo "Weak"
            ;;
        3)
            echo "Good"
            ;;
        4)
            echo "Strong"
            ;;
        5)
            echo "Very Strong"
            ;;
    esac
fi
