#Compile the code
# if the file calculate exits then remove it
program=decode
group=1
for i in `seq 1 1 3`; do
    if [ -f output${group}${i}.txt ]; then
        rm output${group}${i}.txt
    fi
done

if [ -f ${program} ]; then
    rm ${program}
fi
g++ -std=c++11 *.cpp -o ${program}
# if the file 'decode' does not exist then exit the test
if [ ! -f ${program} ]; then
    echo -e "\033[1;91mCompile FAILED.\033[0m"
    exit
fi
# clean
if [ -f *.out ]; then
	rm *.out
fi
if [ -f *.stdeer ]; then
	rm *.stderr
fi
if [ -f *.stdcout ]; then
	rm *.stdcout
fi
# For test case 1
# input11.txt and output11.out
./${program} "input=input${group}1.txt;output=output${group}1.txt" 1>1.stdcout 2>1.stderr
# compare 1.out with 1.ans, output the difference to 1.diff
diff -iEBwu ans${group}1.txt output${group}1.txt > 1.diff
# if diff returns nothing, it means you pass the test case (Your output file 1.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 1 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 1    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 1 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 1    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 1.diff
fi
# For test case 2
# input12.txt and output12.out
./${program} "input=input${group}2.txt;output=output${group}2.txt" 1>1.stdcout 2>1.stderr
# compare 2.out with 2.ans, output the difference to 2.diff
diff -iEBwu ans${group}2.txt output${group}2.txt > 2.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 2.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 2 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 2    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 2 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 2    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 2.diff
fi
# For test case 3
# input 13.txt and output 13.out
./${program} "input=input${group}3.txt;output=output${group}3.txt" 1>1.stdcout 2>1.stderr
# compare 3.out with 3.ans, output the difference to 3.diff
diff -iEBwu ans${group}3.txt output${group}3.txt > 3.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 3.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 3 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 3    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 3 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 3    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 3.diff
fi
# For test case 4
# input 14.txt and output 14.out
./${program} "input=input${group}4.txt;output=output${group}4.txt" 1>1.stdcout 2>1.stderr
# compare 4.out with 4.ans, output the difference to 4.diff
diff -iEBwu ans${group}4.txt output${group}4.txt > 4.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 4.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 4 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 4    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 4 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 4    \033[1;92mPASSED.\033[0m"
    # remove the file 4.diff
    rm -f 4.diff
fi
# For test case 5
# input 15.txt and output 15.out
./${program} "input=input${group}5.txt;output=output${group}5.txt" 1>1.stdcout 2>1.stderr
# compare 5.out with 5.ans, output the difference to 5.diff
diff -iEBwu ans${group}5.txt output${group}5.txt > 5.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 5.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 5 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 5    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 5 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 5    \033[1;92mPASSED.\033[0m"
    # remove the file 5.diff
    rm -f 5.diff
fi
# For test case 7
# input 17.txt and output 17.out
./${program} "input=input${group}7.txt;output=output${group}7.txt" 1>1.stdcout 2>1.stderr
# compare 7.out with 7.ans, output the difference to 7.diff
diff -iEBwu ans${group}7.txt output${group}7.txt > 7.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 7.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 7 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 7    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 7 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 7    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 7.diff
fi
# For test case 8
# input 18.txt and output 18.out
./${program} "input=input${group}8.txt;output=output${group}8.txt" 1>1.stdcout 2>1.stderr
# compare 8.out with 8.ans, output the difference to 8.diff
diff -iEBwu ans${group}8.txt output${group}8.txt > 8.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 8.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 8 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 8    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 8 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 8    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 8.diff
fi
# For test case 9
# input 19.txt and output 19.out
./${program} "input=input${group}9.txt;output=output${group}9.txt" 1>1.stdcout 2>1.stderr
# compare 9.out with 9.ans, output the difference to 9.diff
diff -iEBwu ans${group}9.txt output${group}9.txt > 9.diff
# if diff returns nothing, it means you pass the test case (Your ourput file 9.out is correct)
if [ $? -ne 0 ]; then
    # display "Test case 9 FAILED" to the screen. The word "FAILED" is highlighted in Red color
    echo -e "Test case 9    \033[1;91mFAILED.\033[0m"
else
    # display "Test case 9 PASSED" to the screen. The word "PASSED" is highlighted in Green color
    echo -e "Test case 9    \033[1;92mPASSED.\033[0m"
    # remove the file 1.diff
    rm -f 9.diff
fi