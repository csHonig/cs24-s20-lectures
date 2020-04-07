// Basics of Object Oriented Programming
// Classes: Bundle data and functions that operate on that data
// Object: Instance of a class 
// Think of classes as an extension of structs (from CS16)
// structs: Define custom data types
// C++ classes: structs + member functions + information hiding


#include <iostream>
using namespace std;

// Example: Datatype to represent complex numbers (we could define this as a struct)
// In general a complex number is of the form: a + i*b, where  a: real part  b: imaginary part

// Special member functions of every class (Big Four)
// 1. Constructor: Routine for initializing an object routine. It is called right AFTER we create a new object
// Complex c1; The contructor is called. Initialize the member variables
// Complex* p = new Complex;  
// Flavors of contructors
// - Default constructor: 
//   It doesn't take any parameters and C++ generates one automatically
// - Parametrized constructor:
// 2. Destructor: Called right BEFORE an object is going to be deleted
// 3. Copy Constructor:  Initialize a new object using an existing object
//                       passing parameters to functions
// 4. Copy Assignment:  
// Complex c1, c2;
// c1 = c2; // This is a function call, calling the copy assignment function

class Complex{
   public: 
      // Member functions and variables in the public region can be accessed by any code. 
      // getters (accessors): return value of member variables
      // Complex(); // Default constructor: there is no return type
      Complex(double re = 0 , double im = 0 ); // parametrized constructor with default values
      ~Complex(); //destructor
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
/*
Complex::Complex(){
 // the default constructor provided by C++ is an empty function
 real = 0;
 imag = 0;
} */

Complex::~Complex(){
   // destructor is an empty routine by default.
   imag = 0;
   real = 0;
}
Complex::Complex(double re, double im){
   // paramerized constructor
   real = re;
   imag = im;
}
void Complex::print() const{ 
   // :: scope operator, Complex::print Complex class's print function
   if(imag > 0){
      cout<<real<<" + "<<imag<<"*i"<<endl;
   }
   else{
      cout<<real<<" - "<<-1*imag<<"*i"<<endl;
   }
}
void Complex::setReal(double a){
   // Q1: How long does 'a' exist in memory
   // A: As long as main is running
   // B: As log as setReal is running // Correct
   // C: Forever
   // a is not a member variable, it is not part of the object
   // a is a local variable of setReal

   // object is a implicit c1.setReal 
   real = a;
   // Q2: How long foes 'real' exist in memory
   // A: As long as the the object containing real exists in memory // Correct
   // B: As log as setReal is running
   // C: Forever

   // int x, y; // local variables, are removed from the stack
             // after setReal returns.

}

void Complex::setImaginary(double a){
   imag = a;
}
// a + i*b -> a - i*b
void Complex::conjugate(){
   imag = - imag;
}
// c1 |real: ? | imag: ?|           c2 | real:? | imag: ?|
int main(){
   int x;
   Complex c1;    // (a) c1 is created on the stack, c1 exists as longs as main is running
                  // (b) c1's default contructor is called 
                  // or (c) parametrized constructor with default values
   Complex c2;    // 5 + 4i
   // Complex c3(2, 3); // parameterized constructor , older C++ notation
   Complex c3 {2, 3};  // C++ 11 notation for initializing a complex object
   int arr[4] { 1, 2, 3, 4}; // C++ 11 notation for initializng an int array
   // set c1: 2 + 3i, we will use a better way soon!

   c1.setReal(2); // calling a member function on c1
                  // real member variable is on the stack
   c1.setImaginary(3);
   c1.print();
   c1.conjugate();
   c1.print();

   Complex *p = new Complex; // object is on the heap
   p->setReal(5); // in this the real member variable is on the heap
   p->setImaginary(6);
   p->print();
   delete p; // object is removed from the heap
   return 0;
}
// g++ -c -> object file: machine code version of complex.cpp
// linking stage: combines all the object files into an excecutable
