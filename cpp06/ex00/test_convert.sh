#!/bin/bash

LOG_FILE="log.txt"

# Clear previous log (optional)
# > "$LOG_FILE"

# Define a simple delimiter
DELIM="------------------------------------------------------------"

# Define your test cases
TESTS=(
    "0"
    "42"
    "a"
    "nan"
    "nanf"
    "+inf"
    "-inf"
    "+inff"
    "-inff"
    "1.00000001f"
    "1.000001f"
    "-3.40282e+38f"
    "-3.40282e+39f"
    "+3.40282e+38f"
    "+3.40282e+39f"
    "-1.7976931348623158e+308"
    "+1.7976931348623158e+308"
    "-1.7976931348623158e+308f"
    "+1.7976931348623158e+308f"
    "1e-324"
    "1e-46f"
    "1.17549e-38f"
    "-0.0"
    "31"
	"126"
	"128"
	"2147483647"
	"2147483648"
	"-2147483648"
	"1.234567f"
	"1.2345678901234567"
	"42.0f"
	"1.23"
	"-0.5"
	"3e10"
	"1e-324"
	".5"
	"2."
	"+4.2E+3"
	"abc"
	"1e"
	"--1.2"
	"1.23f"	
	"-3.4E+10F"
	"1e-324f"
	".5f"
	"2."
	"--1.2f"
	"d"
	"1.2e"	
	"d"
	"abc"
)

# Run all tests
for t in "${TESTS[@]}"; do
    echo "$DELIM" >> "$LOG_FILE"
    echo "./convert $t" >> "$LOG_FILE"
    echo "" >> "$LOG_FILE"

    ./convert "$t" >> "$LOG_FILE" 2>&1
    echo "" >> "$LOG_FILE"
done

echo "$DELIM" >> "$LOG_FILE"
echo "All tests finished at $(date)" >> "$LOG_FILE"
echo "$DELIM" >> "$LOG_FILE"

echo "✅ All tests logged to $LOG_FILE"
