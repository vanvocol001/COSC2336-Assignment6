/** @file libfibonacci.cpp
 * @brief Implementation of algorithmes for Assignment
 *   Analysis of Algorithms
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
 * This file contains the actual implementation of the functions
 * and code you are required to complete for Assignment Recursion.
 * Make sure you modify the file header information to be correct
 * for the code you are creating.
 */
#include <cmath>
#include <iostream>

using namespace std;


/// phi is the golden ratio, not defined in <cmath> for c++ 11 so define it
/// here by hand for use in this assignment
double PHI = (sqrt(5.0) + 1.0) / 2.0;

/// global variable used to count number of operations in algorithms so we
/// can estimate computational complexity.
int operationCount;

/// global fibonacci table for memoization solution
/// We initialize F_0 and F_1 to 1.  All other values
/// initially 0 indicate not calculated yet NOT_CALCULATED
const int NOT_CALCULATED = -1;
const int MAX_FIBONACCI_NUMBER = 47;
int fibonacciTable[MAX_FIBONACCI_NUMBER + 1] = { NOT_CALCULATED };

/** @brief initialize fibonacci table
 *
 * Function that will (re)intiailzie the fibonacci table, which
 * is used in the task to implement the fibonacci calculation using
 * the memoization technique.  We need to be able to reinitialize
 * this table so that we can accuratly calculate performance and
 * complexity of the implementation.
 */
void initializeFibonacciTable()
{
  // set x_0 to 0 and x_1 to 1
  fibonacciTable[0] = 0;
  fibonacciTable[1] = 1;

  // initialze rest of table to not calculated yet
  for (int n = 2; n <= MAX_FIBONACCI_NUMBER; n++)
  {
    fibonacciTable[n] = NOT_CALCULATED; 
  }
}

/** @brief Linear Fibonacci Algorithm 
 * 
 * returns the value at a specific point in the Fibonacci Sequence
 * calculated through iteration
 * 
 * @param - int n - the requested point in the sequence
 * 
 * @returns - the integer value associated with the nth value of the sequence
 * 
 **/
int fibonacciLinear(int n)
{
  if (n <= 1)
  {
    return n;  //If n is 0 or 1, automatically return without looping
  }
  else
  {
    int nMin1 = 1;
    operationCount++;
    int nMin2 = 0; 
    operationCount++;
    int current = 0;
    operationCount++;

    for (int index = 2; index <= n; index++) //loop that will calculate the current sequence number of index
    {
      current = nMin1 + nMin2;
      operationCount++;
      nMin2 = nMin1;
      operationCount++;
      nMin1 = current;
      operationCount++;
    }
    return current;
  } 
}

/** @brief Recursive Fibonacci Algorithm
 * 
 * return the value at a specific point in the fibonacci sequence
 * calculated through recursion
 * 
 * @param - int n - the requested point in the sequence
 * 
 * @returns - the integer value associated with the nth term of the sequence
 * 
 **/
int fibonacciRecursive(int n)
{
  if (n <= 1)
  {
    operationCount++;
    return n;
  }
  else
  {
    int nMin1 = n-1;
    int nMin2 = n-2;
    int current = 0;
    current = fibonacciRecursive(nMin1) + fibonacciRecursive(nMin2);
    operationCount++;
    return current; 
  }
}

/** @brief Constant Time Fibonacci Calculation
 * 
 * Uses a standard equation to calculate any index of the Fibonacci sequence 
 * in a constant amount of time
 * 
 * @param - int n - the requested point in the sequence
 * 
 * @returns - the integer value associated with the nth term of the sequence
 * 
 **/
int fibonacciConstant(int n)
{
  operationCount += 3;
  return round(pow(PHI, n)/sqrt(5));
}

/** @brief Memoization Fibonacci Calculation
 * 
 * Utilizes an array of Fibonacci number values in order to return any
 * index of the Fibonacci sequence
 * 
 * @returns - the integer value associated with the nth term of the sequence
 * 
 **/
int fibonacciMemoization(int n)
{
  if (fibonacciTable[n] == NOT_CALCULATED)
  {
    int current = fibonacciMemoization(n -1) + fibonacciMemoization(n - 2);
    fibonacciTable[n] = current;
    operationCount++;
  }
  operationCount++;
  return fibonacciTable[n];
}

