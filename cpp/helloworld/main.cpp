/**
 * tutorials-cpp helloworld
 * main.cpp
 * Purpose: Try out www.tutorialspoint.com tutorial on C++
 *
 * @author Jeffrey Zhou
 * @version 0.01 06/14/17
 *
 * It seems using clang++ as a compiler is recommended with Mac OSX because
 * Mac OSX uses clang by default (gcc is linked to clang).
 *
 * Compile example:
 *     clang++ -Wall main.cpp
 *     ./a.out
 */

#include <iostream>
#include "main.h"
using namespace std;

int main() {
  // Hello World
  cout << "Hello World" << endl;

  print_data_types();
  print_variable_types();
  print_variable_scope();

  return 0;
}

void print_data_types() {
  // Sizes of various C++ data types
  cout << "Size of char : " << sizeof(char) << endl;
  cout << "Size of int : " << sizeof(int) << endl;
  cout << "Size of short int : " << sizeof(short int) << endl;
  cout << "Size of long int : " << sizeof(long int) << endl;
  cout << "Size of float : " << sizeof(float) << endl;
  cout << "Size of double : " << sizeof(double) << endl;
  cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

  // typdef Declarations
  typedef int feet;
  feet var = 4;
  cout << "typdef feet as int works: " << var << endl;

  // enumerated types
  enum color { red, green, blue } c;
  c = blue;
  cout << "enum works by replacing \"blue\" with values: " << c << endl;
}

void print_variable_types() {
  // Multiple variables can be declared on the same linked
  int i, j, k;
  i = 10;
  j = 20;
  k = i + j;
  cout << "Multiple variables declared on on the same line: " << k << endl;

  // Extern allows us to use globals even though they are initialized elsewhere
  cout << "Extern variables allow us to access global_a: " << global_a << endl;
}

int global_a = 10;

void print_variable_scope() {
  // We can mask global variables with another local declaration
  int global_a = 42;
  cout << "Global_a is masked as a local variable: " << global_a << endl;
}
