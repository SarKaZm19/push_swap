#!/bin/sh

# Path to the push_swap program
push_swap="../push_swap"

# Path to the file containing the lists
input_file="new_tests.txt"

# Variable to compare (as null-terminated strings)
compare_variable="^ra\npb\nrra"

# Temporary file to store push_swap program output
temp_file="temp_output.txt"

# Output file for recording occurrences
occurrences_file="variable_occurrences.txt"

# Clear the occurrences file before starting
> "$occurrences_file"

# Read the lists from the input file
while IFS= read -r line || [ -n "$line" ]; do
  echo "List: $line"

  # Execute the push_swap program with the compare variable as input
  echo -e "$compare_variable" | $push_swap "$line" > "$temp_file"

  # Search for occurrences of the compare variable sequence in the temporary file
  occurrences=$(pcregrep -M "$compare_variable" "$temp_file" | wc -l)

  # Record occurrences in the occurrences file
  echo "Input: $line\nOccurrences: $occurrences" >> "$occurrences_file"

  echo
done < "$input_file"

# Clean up: remove the temporary file
rm "$temp_file"