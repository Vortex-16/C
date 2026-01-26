# libDSA AUR Package Configuration

This directory contains the AUR (Arch User Repository) package configuration for libDSA.

## Files

- **PKGBUILD** - Main package build script for Arch Linux
- **.SRCINFO** - Package metadata file (auto-generated)

## What is AUR?

AUR (Arch User Repository) is a community-driven repository for Arch Linux users. It allows developers to share their software with the Arch Linux community.

## How to Use This Package

### For End Users (Installing from AUR)

```bash
# Clone the AUR repository
git clone https://aur.archlinux.org/libdsa.git
cd libdsa

# Build and install
makepkg -si

# Or use an AUR helper
yay -S libdsa
paru -S libdsa
```

### For Maintainers (Publishing to AUR)

## Step-by-Step AUR Publication Guide

### Prerequisites

1. **Arch Linux SSH Key** - Register with AUR and set up SSH key
2. **AUR Account** - Create account at https://aur.archlinux.org/
3. **Git** - For cloning and pushing

### Step 1: Create AUR Account

1. Visit https://aur.archlinux.org/
2. Click "Register" or login with existing account
3. Upload your SSH public key in account settings

### Step 2: Prepare Package

Ensure PKGBUILD is correct:

```bash
# Test local build
cd libDSA/aur
makepkg -f  # Build locally
makepkg -f --printsrcinfo > .SRCINFO  # Generate .SRCINFO
```

### Step 3: Calculate SHA256 Sum

Download the source and calculate hash:

```bash
wget https://github.com/Vortex-16/C/archive/refs/tags/v1.0.0.tar.gz
sha256sum v1.0.0.tar.gz
```

Update the `sha256sums` in PKGBUILD with the calculated value.

### Step 4: Setup AUR Git Repository

```bash
# Clone the AUR repository for your package
git clone ssh://aur@aur.archlinux.org/libdsa.git aur-libdsa
cd aur-libdsa

# Copy PKGBUILD and .SRCINFO
cp ../PKGBUILD .
cp ../.SRCINFO .

# Add files
git add PKGBUILD .SRCINFO

# Commit
git commit -m "Add libDSA v1.0.0"

# Push to AUR
git push origin master
```

### Step 5: Verify Submission

Visit: https://aur.archlinux.org/packages/libdsa

You should see your package listed!

## After Publication

### Keep Package Updated

When releasing a new version:

```bash
# Update version in PKGBUILD
pkgver=1.1.0

# Rebuild .SRCINFO
makepkg --printsrcinfo > .SRCINFO

# Commit and push
git add PKGBUILD .SRCINFO
git commit -m "Update to v1.1.0"
git push
```

### Respond to Issues

Users can report issues on your package's page. Respond promptly to:
- Build failures
- Installation issues
- Feature requests
- Bug reports

## Installation Methods

Once published, users can install with:

```bash
# Using yay (most popular AUR helper)
yay -S libdsa

# Using paru
paru -S libdsa

# Using git directly
git clone https://aur.archlinux.org/libdsa.git
cd libdsa
makepkg -si

# Using pikaur
pikaur -S libdsa
```

## Package Statistics

After publication, you can view:
- Download statistics
- User ratings
- Comments and issues
- Package information

Visit: https://aur.archlinux.org/packages/libdsa

## Troubleshooting

### "makepkg: command not found"
Install build tools:
```bash
sudo pacman -S base-devel
```

### "PKGBUILD syntax error"
Validate with:
```bash
bash -n PKGBUILD
```

### SHA256 mismatch
Recalculate and update in PKGBUILD:
```bash
wget https://github.com/Vortex-16/C/archive/refs/tags/v1.0.0.tar.gz
sha256sum v1.0.0.tar.gz
```

## Related Resources

- **AUR Documentation**: https://wiki.archlinux.org/title/Arch_User_Repository
- **PKGBUILD Guidelines**: https://wiki.archlinux.org/title/PKGBUILD
- **AUR Submission Guidelines**: https://wiki.archlinux.org/title/AUR_submission_guidelines
- **Arch Packaging Standards**: https://wiki.archlinux.org/title/Arch_packaging_standards

## Support

For AUR-related questions:
- AUR Mailing List
- Arch Linux Forums
- AUR Package Comments

For libDSA questions:
- GitHub Issues: https://github.com/Vortex-16/C/issues
- GitHub Discussions
- Package Comments on AUR
