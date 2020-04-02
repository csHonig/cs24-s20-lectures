// Basics of Object Oriented Programming
// Designing classes
// - simple barebones class, add more sophistication
// In CS16, structs: Define custom data types
// Example: New datatype to represent complex numbers
// a + i*b  a: real part  b: imaginary part
// C++ classes: structs + member functions + information hiding

#include <iostream>
using namespace std;
class Complex{
   public: // everything below this line is accessible outside the class
      //member functions
      // getters (accessors): return value of member variables
      double getReal() const; // getReal() cannot modify any of the member variables
                              // if it tries to modify the member variables, 
                              // results in a compiler error
      double getImaginary() const;
      void print() const;
      Complex getConjugate() const ; // gets the conjugate value of the complex number

      // setters (mutators)
      void setReal(double a);
      void setImaginary(double b);
      // conjugate of a+ib  is a - ib
      void conjugate(); // apply the conjugate operation
      
   private:
      //member variables
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
