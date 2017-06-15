/**
 * JYZ Tutorial 1
 * helloworld.cpp
 * Purpose: Try out www.tutorialspoint.com tutorial on C++
 *
 * @author Jeffrey Zhou
 * @version 0.01 06/14/17
 *
 * It seems using clang++ as a compiler is recommended with Mac OSX because
 * Mac OSX uses clang by default (gcc is linked to clang).
 *
 * Compile example:
 *     clang++ -Wall helloworld.cpp
 *     ./a.out
 */

#include <iostream>
using namespace std;

// Include any header files
extern int a, b; // these are global vars that might be found in other file
extern float f; // usually placed in the header

// #define preprocessor way of defining a constant
#define LENGTH 10
#define NEWLINE '\n'

// Declare constants that are needed
int g = 20; // this global variable is an example of what not to do

//

int main() {
  // Hello World
  cout << "Hello World" << endl;

  // Sizes of various C++ data types
  cout << "Size of char : " << sizeof(char) << endl;
  cout << "Size of int : " << sizeof(int) << endl;
  cout << "Size of short int : " << sizeof(short int) << endl;
  cout << "Size of long int : " << sizeof(long int) << endl;
  cout << "Size of float : " << sizeof(float) << endl;
  cout << "Size of double : " << sizeof(double) << endl;
  cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

  // Must make variable definition inside the main function (local variables)
  int a, b, c;
  float f;

  // Actual initialzation of local variables
  a = 10;
  b = 20;
  c = a + b;

  // Local variable declaration overrides global variable
  int g = 10;

  cout << c << endl;
  cout << g << endl;

  f = 70.0 / 3.0;
  cout << f << endl;

  // Character literals
  cout << "Hello\tWorld\n\n";

  // Keyword const for constants (normally should be declared at top of func)
  const int WIDTH = 5;
  int area;
  area = LENGTH * WIDTH;
  cout << area;
  cout << NEWLINE;

  return 0;
}
