#!/bin/sh
set -e

echo "Installing Lamon..."

# Detect OS
OS="$(uname -s)"

case "$OS" in
    Linux|Darwin)
        PREFIX="/usr/local/bin"
        ;;
    *)
        echo "Unsupported OS: $OS"
        echo "Use Windows installer for Windows."
        exit 1
        ;;
esac

# Check binary
if [ ! -f "./lamon" ]; then
    echo "lamon binary not found in this folder."
    echo "Build first with:"
    echo "  cmake -B build"
    echo "  cmake --build build"
    exit 1
fi

echo "Installing to $PREFIX"

if [ -w "$PREFIX" ]; then
    cp ./lamon "$PREFIX/lamon"
else
    echo "Need sudo..."
    sudo cp ./lamon "$PREFIX/lamon"
fi

chmod +x "$PREFIX/lamon"

echo ""
echo "Lamon installed!"
echo "Run: lamon --help"
