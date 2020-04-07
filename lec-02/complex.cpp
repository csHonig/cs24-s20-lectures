// Basics of Object Oriented Programming
// Classes: Bundle data and functions that operate on that data
// Object: Instance of a class 
// Think of classes as an extension of structs (from CS16)
// structs: Define custom data types
// Example: Datatype to represent complex numbers (we could define this as a struct)
// In general a complex number is of the form: a + i*b, where  a: real part  b: imaginary part
// C++ classes: structs + member functions + information hiding


#include <iostream>
using namespace std;
class Complex{
   public: 
      // Member functions and variables in the public region can be accessed
      // by any code. 
      // getters (accessors): return value of member variables
      double getReal() const; // the const keyword at the end means that
                              // getReal() cannot modify any of the member variables.
                              // Trying to modify the member variables, 
                              // will result in a compiler error
      double getImaginary() const;
      void print() const;
      Complex getConjugate() const ; // gets the conjugate value of the complex number

      // setters (mutators): used to modify the member variables
      void setReal(double a);
      void setImaginary(double b);
      void conjugate(); // apply the conjugate operation, conjugate of a+ib  is a - ib
      
   private:
      // member variables, these are typically private which means 
      // they can only be accessed by member functions of the class
      double real; 
      double imag;
};
// c1 |real: ? | imag: ?|           c2 | real:? | imag: ?|
int main(){
   int x;
   Complex c1;   
   Complex c2;    // 5 + 4i
   // set c1: 2 + 3i, we will use a better way soon!
   c1.setReal(2); 
   c1.setImaginary(3);
   c1.print();
   c1.conjugate();
   c1.print();
   return 0;
}
// g++ -c -> object file: machine code version of complex.cpp
// linking stage: combines all the object files into an excecutable
