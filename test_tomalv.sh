#!/bin/bash

# Directory paths
input_dir="data/heuristic-public"
output_file="output.txt"

# Clean up previous output file if it exists
rm -f "$output_file"

# Iterate over the input files
for i in $(seq 1 100); do
    echo $i
    input_file="$input_dir/$i.gr"

    timeout -s SIGTERM 120 ./build/heiCross < $input_file > temp.txt

    # Read the output from heiCross
    solution=$(cat temp.txt)

    # Append the result along with the elapsed time to the output file
    echo $solution >> "$output_file"

    # Clean up temporary files
    rm -f temp.txt
done