# Threading-or-Not-
Cmpe 322 Project on Threads

# Introduction
This project is designed to generate N integers from scratch and put them into an integer list. The integers must be between 1000-10000(both included). The number N will be passed as a parameter of the main program. The program then calculates various statistics on the generated integer list including:

- Min
- Max
- Range
- Mode (If there is multiple modes, return first one)
- Median
- Sum
- Arithmetic Mean
- Harmonic Mean
- Standard Deviation (Where you divide by N-1)
- Interquartile Range
- The program also times the entire operation and output the results to a file.

## First Part
In the first part of the project, the program runs as a single-process/single-thread program. The output is written to a file named "output1.txt".

## Second Part
In the second part of the project, every 10 operations must be done in a separate thread and they must start working at the same time. The program should be designed with:

10 threads (One task each)
5 threads (Two tasks each).
The output is written to a file named "output2.txt" and created by the main thread to avoid mixing the print orders.

## Execution
To run the program, use the following command:

`./"program_name" "number_of_integers"`
For example:


./myprogram.o 100000
## Conclusion
This project aims to demonstrate the ability to generate a list of integers and perform various statistical calculations on them. Additionally, it highlights the differences in performance between single-threaded and multi-threaded execution. A simple pdf report explaining the timing differences is included in the project.
