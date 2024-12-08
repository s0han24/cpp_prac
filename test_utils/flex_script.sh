# when the code requires a flexible checker, make a checker.cpp or checker.py
set -e
g++ ../q1.cpp -o code
g++ gen.cpp -o gen
# g++ brute.cpp -o brute
# g++ checker.cpp -o checker
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    # ./brute < input_file > correctAnswer
    # ./checker > checker_log
    python3 checker.py > checker_log
    # if the output is not correct according to the checker_log, print the input and output files and end the program
    # if checker log says AC then the output is correct
    if [[ $(cat checker_log) != "AC" ]]; then
        echo "Failed test: " $i
        cat input_file
        # cat correctAnswer
        cat myAnswer
        exit 1
    fi
    echo "Passed test: "  $i
done