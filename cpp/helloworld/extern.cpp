/**
 * tutorials-cpp helloworld
 * extern.cpp
 * Purpose: Hold some external stuff
 *
 * @author Jeffrey Zhou
 * @version 0.01
 */

 #include <iostream>

 extern int global_a;

 void write_extern() {
   std::cout << "Global_a externally is: " << global_a << std::endl;
 }
