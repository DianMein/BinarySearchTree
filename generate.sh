#!/bin/bash
set -e  # Exit on error

# Go into build directory (create if missing)
mkdir -p build
cd build

# Generate build files
cmake ..

# Compile
make

# Copy executable to project root
cp binSearchTree ..
echo "Build complete!"

echo "Executing..."
../binSearchTree
