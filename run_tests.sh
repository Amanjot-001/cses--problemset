#!/bin/bash

# Path to the compiled solution executable
solution_executable="./graphs/Building_Roads"

# Directory containing the test cases
test_dir="./test-cases/tests"

for input_file in ${test_dir}/*.in; do
    # Determine the corresponding output file
    output_file="${input_file%.in}.out"

    # Run the solution executable with the input file
    ./${solution_executable} < ${input_file} > temp_output.txt

    # Compare the result with the expected output
    if diff -q temp_output.txt ${output_file}; then
        echo "Test case ${input_file} passed."
    else
        echo "Test case ${input_file} failed."
		# cat ${input_file}
        # echo "Expected output:"
        # cat ${output_file}
        # echo "Your output:"
        # cat temp_output.txt
    fi
done

# Clean up
rm temp_output.txt
