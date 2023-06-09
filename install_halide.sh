#!/bin/sh

# Get halide release
wget https://github.com/halide/Halide/releases/download/v15.0.1/Halide-15.0.1-x86-64-linux-4c63f1befa1063184c5982b11b6a2cc17d4e5815.tar.gz

# Unpack to ./halide
mkdir halide_lib
tar -xzf Halide-15.0.1-x86-64-linux-4c63f1befa1063184c5982b11b6a2cc17d4e5815.tar.gz -C halide_lib --strip-components=1

# Remove tar.gz file
rm Halide-15.0.1-x86-64-linux-4c63f1befa1063184c5982b11b6a2cc17d4e5815.tar.gz