#!/bin/bash
# AUR Package Publication Script for libDSA
# This script helps automate the AUR package submission process

set -e

echo "╔════════════════════════════════════════════════════════╗"
echo "║      libDSA AUR Package Publication Helper             ║"
echo "╚════════════════════════════════════════════════════════╝"
echo ""

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Configuration
REPO_URL="https://github.com/Vortex-16/C"
VERSION="1.0.0"
PACKAGE_NAME="libdsa"
AUR_SSH="ssh://aur@aur.archlinux.org/${PACKAGE_NAME}.git"

echo -e "${YELLOW}Step 1: Checking prerequisites...${NC}"
echo ""

# Check if running on Arch Linux
if ! command -v makepkg &> /dev/null; then
    echo -e "${RED}✗ makepkg not found. Install base-devel:${NC}"
    echo "  sudo pacman -S base-devel"
    exit 1
fi
echo -e "${GREEN}✓ makepkg installed${NC}"

# Check if git is installed
if ! command -v git &> /dev/null; then
    echo -e "${RED}✗ git not found${NC}"
    exit 1
fi
echo -e "${GREEN}✓ git installed${NC}"

# Check if SSH key is configured
if ! ssh -T aur@aur.archlinux.org 2>&1 | grep -q "user"; then
    echo -e "${YELLOW}⚠ SSH key not configured for AUR${NC}"
    echo "  Setup SSH key at: https://aur.archlinux.org/"
    read -p "Continue anyway? (y/n) " -n 1 -r
    echo
    if [[ ! $REPLY =~ ^[Yy]$ ]]; then
        exit 1
    fi
fi
echo -e "${GREEN}✓ SSH configured${NC}"

echo ""
echo -e "${YELLOW}Step 2: Validating PKGBUILD...${NC}"
echo ""

# Validate PKGBUILD syntax
if ! bash -n PKGBUILD 2>/dev/null; then
    echo -e "${RED}✗ PKGBUILD syntax error${NC}"
    exit 1
fi
echo -e "${GREEN}✓ PKGBUILD syntax valid${NC}"

echo ""
echo -e "${YELLOW}Step 3: Test building package...${NC}"
echo ""

# Create temp directory
TEMP_DIR=$(mktemp -d)
trap "rm -rf $TEMP_DIR" EXIT

cp PKGBUILD "$TEMP_DIR/"
cd "$TEMP_DIR"

if ! makepkg --noconfirm --syncdeps 2>&1 | tail -10; then
    echo -e "${RED}✗ Build failed${NC}"
    exit 1
fi

echo -e "${GREEN}✓ Build successful${NC}"

echo ""
echo -e "${YELLOW}Step 4: Generate .SRCINFO...${NC}"
echo ""

# Generate .SRCINFO
makepkg --printsrcinfo > .SRCINFO
echo -e "${GREEN}✓ .SRCINFO generated${NC}"

echo ""
echo -e "${YELLOW}Step 5: Ready for AUR submission${NC}"
echo ""

echo "Next steps:"
echo "1. Clone AUR repository:"
echo "   git clone $AUR_SSH aur-${PACKAGE_NAME}"
echo ""
echo "2. Copy files:"
echo "   cp PKGBUILD .SRCINFO aur-${PACKAGE_NAME}/"
echo ""
echo "3. Commit and push:"
echo "   cd aur-${PACKAGE_NAME}"
echo "   git add PKGBUILD .SRCINFO"
echo "   git commit -m 'Add ${PACKAGE_NAME} v${VERSION}'"
echo "   git push origin master"
echo ""
echo "4. Verify at:"
echo "   https://aur.archlinux.org/packages/${PACKAGE_NAME}"
echo ""

echo -e "${GREEN}✓ All checks passed!${NC}"
echo ""
echo "For more information, visit:"
echo "https://wiki.archlinux.org/title/AUR_submission_guidelines"
