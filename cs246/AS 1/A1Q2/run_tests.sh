#!/bin/bash

# Set the path to the gas executable
GAS_EXEC="./shiftChar"

# Check if the gas executable exists
if [ ! -f "$GAS_EXEC" ]; then
    echo "Error: gas executable not found!"
    exit 1
fi

# Navigate to the test suite folder
cd test_suite || { echo "Error: test_suite folder not found!"; exit 1; }
 echo "Error: taj executable not"
# Loop through all test cases
for i in test*.args; do
    testname=$(basename "$i" .args)
    echo "Running $testname..."
    
    # Run the gas program with test inputs
    ../shiftChar $(cat "$testname.args") < "$testname.in" > "$testname_result.out"
    
    # Compare output with expected result
    if diff -u "$testname.out" "$testname_result.out"; then
        echo "$testname PASSED ✅"
    else
        echo "$testname FAILED ❌"
    fi

    echo "----------------------"
done
