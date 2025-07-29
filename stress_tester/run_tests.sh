#!/bin/bash  # Tells the system to run this script with the Bash shell

# ---------- Function: compile_cpp ----------
compile_cpp() {  # Define a function to compile run.cpp
    if [[ ! -f run.out || run.cpp -nt run.out ]]; then  # If run.out doesn't exist OR run.cpp is newer than run.out
        echo "Compiling run.cpp..."  # Display message
        g++ -std=c++17 run.cpp -o run.out  # Compile run.cpp with C++17 standard
        if [[ $? -ne 0 ]]; then  # If compilation failed (non-zero exit status)
            echo "Compilation Failed! Exiting..."  # Show error message
            exit 1  # Exit the script
        fi
    fi
}

compile_cpp  # Call the compile function once at the beginning

# ---------- Input/Output File Paths ----------
INPUT_FILE="input.txt"       # File containing input test cases
OUTPUT_FILE="output.txt"     # File containing expected output for test cases

# ---------- Reading Lines into Arrays ----------
mapfile -t input_cases < "$INPUT_FILE"       # Read input.txt line-by-line into input_cases array
mapfile -t expected_cases < "$OUTPUT_FILE"   # Read output.txt line-by-line into expected_cases array

# ---------- Initialize Counters ----------
test_case=1          # Current test case number
passed_cases=0       # Counter for passed test cases
total_cases=0        # Counter for total test cases
input_index=0        # Index to track position in input array
output_index=0       # Index to track position in output array

# ---------- Main Test Loop ----------
while (( input_index < ${#input_cases[@]} && output_index < ${#expected_cases[@]} )); do  # Loop until all inputs/outputs are processed

    # ---------- Handle Empty Line (used as separator) ----------
    if [[ -z "${input_cases[$input_index]}" ]]; then  # If a blank line is found
        echo -e "\nEmpty line encountered: Recompiling and restarting..."  # Display message
        compile_cpp  # Recompile the code (useful if changed)
        test_case=1  # Reset test number
        ((input_index++, output_index))  # Skip to the next test block
        continue  # Skip the rest of this loop iteration
    fi

    ((total_cases++))  # Increase total test case count

    # ---------- Read One Test Case Input Block ----------
    input_data=""  # Clear input buffer
    while (( input_index < ${#input_cases[@]} && ${#input_cases[$input_index]} )); do  # Read lines until a blank line
        input_data+="${input_cases[$input_index]}"$'\n'  # Add each line to input_data
        ((input_index++))  # Move to the next input line
    done
    ((input_index++))  # Skip the blank line after input block

    # ---------- Run the Program ----------
    actual_output=$(./run.out <<< "$input_data")  # Feed input_data to the C++ executable

    # ---------- Read One Test Case Expected Output Block ----------
    expected_output=""  # Clear expected output buffer
    while (( output_index < ${#expected_cases[@]} && ${#expected_cases[$output_index]} )); do  # Read until blank line
        expected_output+="${expected_cases[$output_index]}"$'\n'  # Append to expected_output
        ((output_index++))  # Move to the next output line
    done
    ((output_index++))  # Skip the blank line after output block

    # ---------- Trim Trailing Newlines ----------
    actual_output=$(echo -n "$actual_output")  # Remove trailing newline
    expected_output=$(echo -n "$expected_output")  # Remove trailing newline

    # ---------- Display Test Case Details ----------
    echo "---------------------------------------------------------"
    echo "Test #$test_case"
    echo "Input:"
    printf "%s\n" "$input_data"
    echo "Expected Output:"
    printf "%s\n" "$expected_output"
    echo "Actual Output:"
    printf "%s\n" "$actual_output"

    # ---------- Compare Outputs ----------
    if [[ "$actual_output" == "$expected_output" ]]; then  # If output matches
        ((passed_cases++))  # Count it as passed
        echo "Test #$test_case Passed!"
    else
        echo "Test #$test_case Failed!"
    fi

    ((test_case++))  # Move to next test number
done

# ---------- Final Test Summary ----------
echo "---------------------------------------------------------"
echo "Test Summary:"
echo "$passed_cases / $total_cases tests passed!"  # Show overall results

if (( passed_cases == total_cases )); then  # If all passed
    echo "All Tests Passed!"  # Success message
else
    echo "Some Tests Failed! Debug your code."  # Encourage debugging
    echo "---------------------------------------------------------"
fi
