# Contributing to libDSA

First off, thank you for considering contributing to libDSA! 🎉

## How Can I Contribute?

### Reporting Bugs

Before creating bug reports, please check existing issues to avoid duplicates.

**When submitting a bug report, include:**
- Clear, descriptive title
- Steps to reproduce the issue
- Expected behavior
- Actual behavior
- Environment details (OS, compiler version)
- Code sample that demonstrates the bug

### Suggesting Enhancements

Enhancement suggestions are tracked as GitHub issues.

**When suggesting an enhancement, include:**
- Clear, descriptive title
- Detailed description of the proposed functionality
- Explain why this enhancement would be useful
- Examples of how it would be used

### Pull Requests

1. Fork the repository
2. Create a new branch: `git checkout -b feature/your-feature-name`
3. Make your changes
4. Run tests to ensure nothing is broken
5. Commit with a clear message: `git commit -m 'Add feature: description'`
6. Push to your fork: `git push origin feature/your-feature-name`
7. Submit a pull request

## Development Guidelines

### Code Style

- Use 4 spaces for indentation (no tabs)
- Keep lines under 100 characters when possible
- Use meaningful variable and function names
- Add comments for complex logic
- Follow existing code style in the project

### Naming Conventions

- **Functions**: `lowercase_with_underscores`
- **Structs/Types**: `PascalCase`
- **Constants**: `UPPER_CASE_WITH_UNDERSCORES`
- **Variables**: `lowercase_with_underscores`

### Documentation

- Add Doxygen-style comments for all public functions
- Update README.md if adding new features
- Add examples for new data structures

### Testing

- Add tests for new features
- Ensure all existing tests pass
- Test memory leaks with valgrind (if available)

### Commit Messages

Good commit message format:
```
Add feature: brief description

Detailed explanation of what changed and why.
Include any relevant issue numbers.

Fixes #123
```

## Code Review Process

1. Maintainers will review your PR within a few days
2. Address any requested changes
3. Once approved, your PR will be merged

## Community

- Be respectful and inclusive
- Follow the Code of Conduct
- Help others in discussions

## Questions?

Feel free to open an issue with the "question" label.

Thank you for contributing! 🚀
