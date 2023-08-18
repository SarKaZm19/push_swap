#!/bin/sh

# Path to the push_swap program
push_swap="../push_swap"

# Path to the file containing the lists
input_file="lists.txt"

# Path to the output file
output_file="output_sorted.txt"

# Maximum number of steps
max_steps=650

# personnal best
min_steps=480

# Read the lists from the input file
while IFS= read -r line || [ -n "$line" ]; do

  # Execute the push_swap program and count the number of lines in the output
  num_steps=$($push_swap $line)

  # Check if the number of steps exceeds the maximum
  if [ "$num_steps" -gt "$max_steps" ]; then
    echo "$line\nsteps = $num_steps" >> "$output_file"
  elif [ "$num_steps" -lt "$min_steps" ]; then
    echo "$line\nsteps: $num_steps" >> "$output_file"
  fi
done < "$input_file"