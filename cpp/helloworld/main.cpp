/**
 * tutorials-cpp helloworld
 * main.cpp
 * Purpose: Try out www.tutorialspoint.com tutorial on C++
 *
 * @author Jeffrey Zhou
 * @version 0.01
 *
 * It seems using clang++ as a compiler is recommended with Mac OSX because
 * Mac OSX uses clang by default (gcc is linked to clang).
 *
 * Compile example:
 *     clang++ -Wall main.cpp extern.cpp
 *     ./a.out
 */

#include <iostream>
#include "main.hpp"
using namespace std;

int main() {
  // Hello World
  cout << "Hello World" << endl;

  print_data_types();
  print_variable_types();
  print_variable_scope();
  print_constants_literals();
  print_modifier_types();
  print_storage_classes();

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

#define LENGTH 10
void print_constants_literals() {
  // Define constants with the #define keyword, utilizes the preprocessor
  cout << "This is a constant with #define: " << LENGTH * 5 << endl;

  // Define constants with const
  const char NEWLINE = '\n';
  cout << "A newline will happen here." << NEWLINE;
}

void print_modifier_types() {
  // Modifers: signed, unsigned, long, and short
  short int i;
  short unsigned int j;

  j = 50000;

  // Assigning i to j doesn't change the byte value, but the number changes
  i = j;
  cout << "The byte value stays the same: " << i << " " << j << endl;
}

void test_static_variable();
static int counter = 10;
extern void write_extern();
void print_storage_classes() {
  // auto storage class is the default for all local variable (deprecated)
  // auto int month; // equivalent to: int month

  // register storage class (is deprecated)
  // stores the variable in a register instead of RAM for quick access
  // register int j;

  // static storage class
  // keep local variable alive for duration of program, don't create + destory
  // each time it goes in and out of scope.
  while(counter--) {
    test_static_variable();
  }

  // extern storage class
  // use extern to declare variables that were initialized in another file
  // extern points the variable name at a storage location previously defined
  // extern int global_b;
  write_extern();

}
void test_static_variable() {
  // i is a local variable, but it isn't destroyed at the end of the function
  static int i = 5; // each time this func is called, i will increment
  i++;
  cout << "i is " << i;
  cout << " and count is " << counter << endl;
}
