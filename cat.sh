#!/bin/bash

echo "Test '1 file'"
diff <(./cat test1.txt) <(cat test1.txt)
echo "Test '2 files'"
diff <(./cat test1.txt test2.txt) <(cat test1.txt test2.txt)
echo "Test 'b flag'"
diff <(./cat -b test1.txt) <(cat -b test1.txt)
echo "Test 'n flag'"
diff <(./cat -n test1.txt) <(cat -n test1.txt)
echo "Test 'v flag'"
diff <(./cat -v test1.txt) <(cat -v test1.txt)
echo "Test 's flag'"
diff <(./cat -s test1.txt) <(cat -s test1.txt)
echo "Test 'e flag'"
diff <(./cat -e test1.txt) <(cat -e test1.txt)
echo "Test 't flag'"
diff <(./cat -t test1.txt) <(cat -t test1.txt)
echo "Test 'E flag'"
diff <(./cat -E test1.txt) <(cat -E test1.txt)
echo "Test 'T flag'"
diff <(./cat -T test1.txt) <(cat -T test1.txt)
echo "Test --number-nonblank"
diff <(./cat --number-nonblank test1.txt) <(cat --number-nonblank test1.txt)
echo "Test --number"
diff <(./cat --number test1.txt) <(cat --number test1.txt)
echo "Test --squeeze-blank"
diff <(./cat --squeeze-blank test1.txt) <(cat --squeeze-blank test1.txt)
