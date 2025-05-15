#!/bin/bash

# Function to compile the C++ program (only if modified)
compile_cpp() {
    if [[ ! -f run.out || run.cpp -nt run.out ]]; then
        echo "Compiling run.cpp..."
        g++ -std=c++17 run.cpp -o run.out
        if [[ $? -ne 0 ]]; then
            echo "Compilation Failed! Exiting..."
            exit 1
        fi
    fi
}

# Compile initially
compile_cpp

# File paths
INPUT_FILE="input.txt"
OUTPUT_FILE="output.txt"

# Read input and expected output into arrays
mapfile -t input_cases < "$INPUT_FILE"
mapfile -t expected_cases < "$OUTPUT_FILE"

test_case=1
passed_cases=0
total_cases=0
input_index=0
output_index=0

while (( input_index < ${#input_cases[@]} && output_index < ${#expected_cases[@]} )); do
    # Recompile if an empty line is encountered
    if [[ -z "${input_cases[$input_index]}" ]]; then
        echo -e "\nEmpty line encountered: Recompiling and restarting..."
        compile_cpp
        test_case=1
        ((input_index++, output_index))
        continue
    fi

    ((total_cases++))

    # Read input block efficiently
    input_data=""
    while (( input_index < ${#input_cases[@]} && ${#input_cases[$input_index]} )); do
        input_data+="${input_cases[$input_index]}"$'\n'
        ((input_index++))
    done
    ((input_index++)) # Move past separator line

    # Run program with input
    actual_output=$(./run.out <<< "$input_data")

    # Read expected output block efficiently
    expected_output=""
    while (( output_index < ${#expected_cases[@]} && ${#expected_cases[$output_index]} )); do
        expected_output+="${expected_cases[$output_index]}"$'\n'
        ((output_index++))
    done
    ((output_index++)) # Move past separator line

    # Trim trailing newlines for direct string comparison
    actual_output=$(echo -n "$actual_output")
    expected_output=$(echo -n "$expected_output")

    # Print Test Case Details
    echo "---------------------------------------------------------"
    echo "Test #$test_case"
    echo "Input:"
    printf "%s\n" "$input_data"
    echo "Expected Output:"
   
    printf "%s\n" "$expected_output"
    echo "Actual Output:"
    printf "%s\n" "$actual_output"

    # Compare actual vs expected output
    if [[ "$actual_output" == "$expected_output" ]]; then
        ((passed_cases++))
        echo "Test #$test_case Passed!"
    else
        echo "Test #$test_case Failed!"
    fi

    ((test_case++))
done

# Summary
echo "---------------------------------------------------------"
echo "Test Summary:"
echo "$passed_cases / $total_cases tests passed!"

if (( passed_cases == total_cases )); then
    echo "All Tests Passed!"
else
    echo "Some Tests Failed! Debug your code."
    echo "---------------------------------------------------------"
fi 
