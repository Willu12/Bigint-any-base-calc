# Bigint-any-base-calc
a calculator which covers basic operation for integers in any base from 2 to 16 written in C. School Project.

Running the programme:
For the programme to run correctly, a file, containing the operations we want, entitled "in.txt" must be placed in the same folder with the executable file. For the programme to run correctly the input file must be formatted according to the project assumptions. After starting the project.exe file, the programme will ask us to select the option to save the results, which will be saved in the Results folder. Entering the number 2 will save all calculations in separate files entitled: "(action no.).txt". Entering the number 1 will save all results to a file named: "(action no.).txt". Entering the wrong data will select the default method of saving, which is to save to a single file.
Changes made:
- Handling of erroneous operations (when the text file contains operation characters not included in the project assumptions such as "-", then the program in the results file will indicate that the given data is incorrect).
- Improved formatting of the main.c file (removal of unnecessary blank lines)
- Adding a display of the current state of the program in the console while it is running (the console will display the numbers of completed operations).
- The program does not shut down on its own after all operations have been completed, any button must be pressed to terminate it.
Programme structure:
The program consists of a globally declared 16 element array assigning to each index from 0 to 15 a number equal to it in hexadecimal. Below the array is a function that checks which number is greater and a function that swaps the 2 given numbers with each other. Underneath are functions for mathematical operations of type int that return the length of the resulting number. In the main function the variables used are declared and the operations for reading actions from a file and writing results are stored. The main function also implements the handling of erroneous data. A subtraction operation is also implemented in the program, but it is only used auxiliary to implement other operations.
Libraries used:
Only standard libraries (stdio.h and stdlib.h) were used in the program.
Description of the implementation of operations:
The operations of addition, subtraction, multiplication and division have identical operation to the written versions of these operations. Multiplication is based on the multiplication operation, which must be performed the given number of times. The modulo operation divides the first number by the second number, then multiplies the result by the second number, and compares the result with the first number, recording their difference. The conversion is divided into 2 steps: converting a number to a decimal-based number and converting a decimal-based number to any system. These operations are performed analogously to how they would be performed in writing using the mathematical operation functions described above.





