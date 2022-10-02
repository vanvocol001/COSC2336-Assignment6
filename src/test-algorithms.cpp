/** @file test-algorithms.cpp
 *
 * @brief Unit tests for Assignment Analysis of Algorithms
 *   Developing and comparing performance of algorithms with
 *   varying time complexities.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Analysis of Algorithms
 * @date   October 1, 2021
 *
 * Implement algorithms of varying computational complexity and
 * compare their performance.
 *
 * This file contains test cases and individual unit tests for the
 * Assignment Analysis of Algorithms implementation.  This file uses
 * the catch2 unit test framework to define the test cases and test
 * assertions.
 */
#include "libfibonacci.hpp"
#include "catch.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>
using namespace std;

// global constants defined from libfibonacci.cpp
extern double PHI;

/// global variable used to count number of operations in algorithms so we
/// can estimate computational complexity.  Defined in global space of the
/// libfibonacci.cpp implementation file
extern int operationCount;


/** Task 1: implement linear Fibonacci calculation
 */

TEST_CASE("<fibonacciLinear> test linear fibonacci calculations", "[task1]")
{
  // test base cases are correct
  CHECK(fibonacciLinear(0) == 0);
  CHECK(fibonacciLinear(1) == 1);

  // test all nth numbers from 2 to 10
  CHECK(fibonacciLinear(2) == 1);
  CHECK(fibonacciLinear(3) == 2);
  CHECK(fibonacciLinear(4) == 3);
  CHECK(fibonacciLinear(5) == 5);
  CHECK(fibonacciLinear(6) == 8);
  CHECK(fibonacciLinear(7) == 13);
  CHECK(fibonacciLinear(8) == 21);
  CHECK(fibonacciLinear(9) == 34);
  CHECK(fibonacciLinear(10) == 55);

  // check some bigger ones, up to the limit that int can hold/represent
  CHECK(fibonacciLinear(15) == 610);
  CHECK(fibonacciLinear(20) == 6765);
  CHECK(fibonacciLinear(25) == 75025);
  CHECK(fibonacciLinear(30) == 832040);
  CHECK(fibonacciLinear(40) == 102334155);
  CHECK(fibonacciLinear(42) == 267914296);
  CHECK(fibonacciLinear(43) == 433494437);
  CHECK(fibonacciLinear(44) == 701408733);
  CHECK(fibonacciLinear(45) == 1134903170);
  CHECK(fibonacciLinear(46) == 1836311903);

  // this is the correct result for n=47 but will fail using signed
  // integers because result is too big to fit into 32 bit signed int
  CHECK_FALSE(fibonacciLinear(47) == 2971215073);
}


/** Task 2: implement recursive fibonacci calculation
 */

TEST_CASE("<fibonacciRecursive> test recursive fibonacci calculations", "[task2]")
{
  // test base cases are correct
  CHECK(fibonacciRecursive(0) == 0);
  CHECK(fibonacciRecursive(1) == 1);

  // test all nth numbers from 2 to 10
  CHECK(fibonacciRecursive(2) == 1);
  CHECK(fibonacciRecursive(3) == 2);
  CHECK(fibonacciRecursive(4) == 3);
  CHECK(fibonacciRecursive(5) == 5);
  CHECK(fibonacciRecursive(6) == 8);
  CHECK(fibonacciRecursive(7) == 13);
  CHECK(fibonacciRecursive(8) == 21);
  CHECK(fibonacciRecursive(9) == 34);
  CHECK(fibonacciRecursive(10) == 55);

  // check some bigger ones, up to the limit that int can hold/represent
  // NOTE: the larger n > 42 calculations will probably star taking your
  // program to compute if done as specified in the task.  Depending on your
  // machine speed, to run tests in reasonable amount of time, might have to
  // comment out some of the last bigger tests here.
  CHECK(fibonacciRecursive(15) == 610);
  CHECK(fibonacciRecursive(20) == 6765);
  CHECK(fibonacciRecursive(25) == 75025);
  CHECK(fibonacciRecursive(30) == 832040);
  CHECK(fibonacciRecursive(40) == 102334155);
  //CHECK(fibonacciRecursive(42) == 267914296);
  //CHECK(fibonacciRecursive(43) == 433494437);
  //CHECK(fibonacciRecursive(44) == 701408733);
  //CHECK(fibonacciRecursive(45) == 1134903170);
  //CHECK(fibonacciRecursive(46) == 1836311903);

  // this is the correct result for n=47 but will fail using signed
  // integers because result is too big to fit into 32 bit signed int
  //CHECK_FALSE(fibonacciRecursive(47) == 2971215073);
}


/** Task 3: empirical timing tests of wall clock compute time needed
 * for the linear and recursive versions.
 */
/*
TEST_CASE("<fibonacci algorithms> empirical test of linear and recursive performance", "[task3]")
{
  const int NUM_TEST_ITERATIONS = 5;
  
  // get wall clock time of running linear fibonacci some number of times
  int result;
  
  auto start = chrono::steady_clock::now();
  for (int testIteration = 1; testIteration <= NUM_TEST_ITERATIONS; testIteration++)
  {
    result = fibonacciLinear(40);
  }
  auto end = chrono::steady_clock::now();

  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  double averageElapsedTime = (double)elapsed / (double)NUM_TEST_ITERATIONS;
  
  cout << "Task 3: fibonacciLinear average elapsed time in nanoseconds: "
       << averageElapsedTime << " ns" << endl;
  CHECK(result == 102334155);

  // get wall clock time of running recursive fibonacci some number of times
  start = chrono::steady_clock::now();
  for (int testIteration = 1; testIteration <= NUM_TEST_ITERATIONS; testIteration++)
  {
    result = fibonacciRecursive(40);
  }
  end = chrono::steady_clock::now();

  elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  averageElapsedTime = (double)elapsed / (double)NUM_TEST_ITERATIONS;
  
  cout << "Task 3: fibonacciRecursive average elapsed time in nanoseconds: "
       << fixed << averageElapsedTime << " ns" << endl;
  CHECK(result == 102334155);
}
*/

/** Task 3: computational complexity, count number of operations in each
 *    separate implementation
 */

TEST_CASE("<fibonacci algorithms> operation counts of linear and recursive algorithms", "[task3]")
{
  // count operations in linear implementation
  int n = 40;
  int result;
  operationCount = 0;  
  result = fibonacciLinear(n);
  cout << "Task 3: fibonacciLinear operation count: " << operationCount << endl;

  // here when n = 40, for linear algorithm we expect total to be
  //    c1 + (n-1) * c2
  // where c1 is operation count outside of the loop, and c2 is
  // number of operations for each loop iteration.  The example
  // implementation needs to execute the loop (n-1) times to calculate the
  // nth fibonacci number.  Modify c1 and c2 here to match your implementation
  int c1 = 3;
  int c2 = 3;
  CHECK(operationCount == c1 + (n-1) * c2);
  CHECK(result == 102334155);

  // count recursive calls in recursive implementation
  operationCount = 0;
  result = fibonacciRecursive(n);
  cout << "Task 3: fibonacciRecursive operation count: " << operationCount << endl;

  // here n = 40, for the recursive algorithm we expect total recursive calls to be
  //   2 * phi**(n+1) / sqrt(5)
  // why? well it is related to O(2^n), but number of recursive calls is a bit more
  // complicated, the recursion tree is not fully filled out, so O(2^n) is an upper
  // bound.  We will discuss after this assignment is finished.
  int expectedOperationCount = int(2 * pow(PHI, n+1) / sqrt(5.0)) - 1;
  CHECK(operationCount == expectedOperationCount);
  CHECK(result == 102334155);
}


/** Task 4: implement constant fibonacci calculation
 */

TEST_CASE("<fibonacciConstant> test constant fibonacci calculations", "[task4]")
{
  // test base cases are correct
  CHECK(fibonacciConstant(0) == 0);
  CHECK(fibonacciConstant(1) == 1);

  // test all nth numbers from 2 to 10
  CHECK(fibonacciConstant(2) == 1);
  CHECK(fibonacciConstant(3) == 2);
  CHECK(fibonacciConstant(4) == 3);
  CHECK(fibonacciConstant(5) == 5);
  CHECK(fibonacciConstant(6) == 8);
  CHECK(fibonacciConstant(7) == 13);
  CHECK(fibonacciConstant(8) == 21);
  CHECK(fibonacciConstant(9) == 34);
  CHECK(fibonacciConstant(10) == 55);

  // check some bigger ones, up to the limit that int can hold/represent
  // NOTE: the larger n > 42 calculations will probably star taking your
  // program to compute if done as specified in the task.  Depending on your
  // machine speed, to run tests in reasonable amount of time, might have to
  // comment out some of the last bigger tests here.
  CHECK(fibonacciConstant(15) == 610);
  CHECK(fibonacciConstant(20) == 6765);
  CHECK(fibonacciConstant(25) == 75025);
  CHECK(fibonacciConstant(30) == 832040);
  CHECK(fibonacciConstant(40) == 102334155);
  CHECK(fibonacciConstant(42) == 267914296);
  CHECK(fibonacciConstant(43) == 433494437);
  CHECK(fibonacciConstant(44) == 701408733);
  CHECK(fibonacciConstant(45) == 1134903170);
  CHECK(fibonacciConstant(46) == 1836311903);

  // this is the correct result for n=47 but will fail using signed
  // integers because result is too big to fit into 32 bit signed int
  CHECK_FALSE(fibonacciConstant(47) == 2971215073);
}


/** Task 5: implement memoization fibonacci calculation
 */

TEST_CASE("<fibonacciMemoization> test memoization fibonacci calculations", "[task5]")
{
  // memoization technique needs to ensure memoization table is initialized before
  // beginning to use
  initializeFibonacciTable();
  
  // test base cases are correct
  CHECK(fibonacciMemoization(0) == 0);
  CHECK(fibonacciMemoization(1) == 1);

  // test all nth numbers from 2 to 10
  CHECK(fibonacciMemoization(2) == 1);
  CHECK(fibonacciMemoization(3) == 2);
  CHECK(fibonacciMemoization(4) == 3);
  CHECK(fibonacciMemoization(5) == 5);
  CHECK(fibonacciMemoization(6) == 8);
  CHECK(fibonacciMemoization(7) == 13);
  CHECK(fibonacciMemoization(8) == 21);
  CHECK(fibonacciMemoization(9) == 34);
  CHECK(fibonacciMemoization(10) == 55);

  // check some bigger ones, up to the limit that int can hold/represent
  // NOTE: the larger n > 42 calculations will probably star taking your
  // program to compute if done as specified in the task.  Depending on your
  // machine speed, to run tests in reasonable amount of time, might have to
  // comment out some of the last bigger tests here.
  CHECK(fibonacciMemoization(15) == 610);
  CHECK(fibonacciMemoization(20) == 6765);
  CHECK(fibonacciMemoization(25) == 75025);
  CHECK(fibonacciMemoization(30) == 832040);
  CHECK(fibonacciMemoization(40) == 102334155);
  CHECK(fibonacciMemoization(42) == 267914296);
  CHECK(fibonacciMemoization(43) == 433494437);
  CHECK(fibonacciMemoization(44) == 701408733);
  CHECK(fibonacciMemoization(45) == 1134903170);
  CHECK(fibonacciMemoization(46) == 1836311903);

  // this is the correct result for n=47 but will fail using signed
  // integers because result is too big to fit into 32 bit signed int
  CHECK_FALSE(fibonacciMemoization(47) == 2971215073);
}


/** Task 6: empirical timing tests of wall clock compute time needed
 * for the constant and memoization versions.
 */

TEST_CASE("<fibonacci algorithms> empirical test of performance second set", "[task6]")
{
  const int NUM_TEST_ITERATIONS = 5;
  
  // get wall clock time of running constant fibonacci some number of times
  int result;
  
  auto start = chrono::steady_clock::now();
  for (int testIteration = 1; testIteration <= NUM_TEST_ITERATIONS; testIteration++)
  {
    result = fibonacciConstant(40);
  }
  auto end = chrono::steady_clock::now();

  auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  double averageElapsedTime = (double)elapsed / (double)NUM_TEST_ITERATIONS;
  
  cout << "Task 6: fibonacciConstant average elapsed time in nanoseconds: "
       << averageElapsedTime << " ns" << endl;
  CHECK(result == 102334155);

  // memoization technique needs to ensure memoization table is initialized before
  // beginning to use
  initializeFibonacciTable();
  
  // get wall clock time of running memoization fibonacci some number of times
  start = chrono::steady_clock::now();
  for (int testIteration = 1; testIteration <= NUM_TEST_ITERATIONS; testIteration++)
  {
    result = fibonacciMemoization(40);
  }
  end = chrono::steady_clock::now();

  elapsed = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  averageElapsedTime = (double)elapsed / (double)NUM_TEST_ITERATIONS;
  
  cout << "Task 6: fibonacciMemoization average elapsed time in nanoseconds: "
       << fixed << averageElapsedTime << " ns" << endl;
  CHECK(result == 102334155);
}


/** Task 6: computational complexity, count number of operations in each
 *    separate implementation
 */

TEST_CASE("<fibonacci algorithms> operation counts of algorithms second set", "[task6]")
{
  // count operations in const implementation
  int n = 40;
  int result;
  operationCount = 0;  
  result = fibonacciConstant(n);
  cout << "Task 6: fibonacciConstant operation count: " << operationCount << endl;

  // here when n = 40, for constatn algorithm we expect total to be
  // always a fixed constant number of operations.
  CHECK(operationCount == 3);
  CHECK(result == 102334155);

  // memoization technique needs to ensure memoization table is initialized before
  // beginning to use
  initializeFibonacciTable();
  
  // count operations in memoization implementation
  operationCount = 0;
  result = fibonacciMemoization(n);
  cout << "Task 6: fibonacciMemoization operation count: " << operationCount << endl;

  // here n = 40, for the memoization algorithm we expect total calls to be
  // just about 40
  int c1 = 2; // number of operations needed when calculation occurs
  int c2 = 1; // number of operations needed when just looking up result in table
  int expectedOperationCount = c1 * (n-1) + c2 * n;
  CHECK(operationCount == expectedOperationCount);
  CHECK(result == 102334155);
}


