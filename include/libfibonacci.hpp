/** @file libfibonacci.hpp
 * @brief Header file for Assignment Analysis of Algorithms
 *
 * @author Jane Programmer
 * @note   class: COSC 2336, Fall 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Recursion
 * @date   October 1, 2021
 *
 * Implement algorithms with varying time complexities and compare
 * their performance.
 *
 * This file contains function prototypes and class declarations
 * for the assignment.  These are the things that need to be
 * declared in order for another project or file to use the
 * functions defined here and in the implementation file.  Only
 * class declarations, function prototypes and signatures
 * go in the header file.  All actual implementation of functions
 * and member functions should be put into the [.cpp] implementation
 * file.
 */
#ifndef _LIBFIBONACCI_HPP_
#define _LIBFIBONACCI_HPP_
#include <iostream>
using namespace std;

// function prototypes for Assignment Analysis of Algorithms
// You will need to add in the correct function protypes for the functions
// you are to write for this assignment here.  The actual implementation
// of your functions should be put into the corresponding [x.cpp]
// source implementation file.
void initializeFibonacciTable();
int fibonacciLinear(int n);
int fibonacciRecursive(int n);
int fibonacciConstant(int n);
int fibonacciMemoization(int n);

#endif // _LIBFIBONACCI_HPP_
