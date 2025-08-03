#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encode the string
void encode(char *message, int key) {
    int len = strlen(message);
    printf("Encoded message: ");
    for (int i = 0; i < len; i++) {
        // XOR with key and shift for obfuscation
        char encoded_char = (message[i] ^ key) + (key % 5);
        printf("%02X", (unsigned char)encoded_char); // Print in hex
    }
    printf("\n");
}

// Function to decode the string
void decode(char *encoded, int key) {
    int len = strlen(encoded);
    if (len % 2 != 0) {
        printf("Invalid encoded string.\n");
        return;
    }

    printf("Decoded message: ");
    for (int i = 0; i < len; i += 2) {
        char hex_byte[3] = {encoded[i], encoded[i+1], '\0'};
        unsigned char byte = (unsigned char)strtol(hex_byte, NULL, 16);
        char original_char = (byte - (key % 5)) ^ key;
        printf("%c", original_char);
    }
    printf("\n");
}

int main() {
    int choice, key;
    char message[1024];
    char encoded[2048];

    printf("Secure String Encoder/Decoder\n");
    printf("=============================\n");
    printf("1. Encode a message\n");
    printf("2. Decode a message\n");
    printf("Choose option: ");
    scanf("%d", &choice);
    getchar(); // Consume newline

    if (choice == 1) {
        printf("Enter the message to encode: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = 0; // Remove newline

        printf("Enter your secret number (key): ");
        scanf("%d", &key);

        encode(message, key);

    } else if (choice == 2) {
        printf("Enter the encoded message (hex string): ");
        fgets(encoded, sizeof(encoded), stdin);
        encoded[strcspn(encoded, "\n")] = 0;

        printf("Enter the secret number (key) to decode: ");
        scanf("%d", &key);

        decode(encoded, key);

    } else {
        printf("Invalid option.\n");
    }

    return 0;
}