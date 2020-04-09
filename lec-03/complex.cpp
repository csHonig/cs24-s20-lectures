#include <iostream>
using namespace std;
// class Complex: Datatype to represent complex numbers (we could define this as a struct)
// In general a complex number is of the form: a + i*b, where  a: real part  b: imaginary part

// Big Four: Special member functions of a class. 
// C++ provides default implementations for all these functions if the class does not explicitly define one 
// 1. Constructor: Function for initializing an object of the class. 
//    It is called right AFTER we create a new object as in the following cases:
//    Complex c1; 
//    Complex* p = new Complex;  
//    Different types of contructors:
//    - Default constructor: Doesn't take any parameters and C++ generates one automatically
//    - Parametrized constructor
// 2. Destructor: Called right BEFORE an object is going to be deleted
// 3. Copy Constructor:  Initialize a new object using an existing object
//                       passing parameters to functions
// 4. Copy Assignment: Assign the member variables of one object to another existing object
//    Complex c1, c2;
//    c1 = c2; // This is a function call, calling the copy assignment function

class Complex{
   public: 
      // Member functions and variables in the public region can be accessed by any code. 
      // getters (accessors): return value of member variables
      // Complex(); // Default constructor: there is no return type
      Complex(double re = 0 , double im = 0 );
      
      // parametrized constructor with default values
      // Copy constructor
      Complex(const Complex& c);
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
      // Define the assignment operator as a member function
      Complex& operator=(const Complex& c);
      // c1 = c2; -> c1.operator=(c2)
   private:
      // member variables, these are typically private which means 
      // they can only be accessed by member functions of the class
      double real; 
      double imag;
};

Complex& Complex::operator=(const Complex& c){
  /* setReal(c.real);
   setImaginary(c.imag);*/
   real = c.real;
   imag = c.imag;
   return *this; // this is a pointer to the implicit object
                // "this" is the name of a pointer to c1
}
// c1 = c4;  c1.operator=(c4);
// c1 = c2 = c3;
// x = y;
// if(x){

//}

// How much are you feeling engaged with the lecture?
// A. Not all all
// B. Somewhat
// C. Mosty
// D. Very engaged.

// Complex c1 = c4; // calls the copy constructor
// Complex c1 {c4};  // copy constructor
// c1 = c4; // copy assignment, c1 is the implicit object
// Complex& c1 = c4; // This does not call the copy constructor
                     // Reference semantics 
                     // Value semantics: call to copy constructor
                     // or call to copy assignment


// c1 = c4
/*
Complex::Complex(){
 // the default constructor provided by C++ is an empty function but we could override it.
 real = 0;
 imag = 0;
} */

Complex::~Complex(){
   // destructor is an empty routine by default but you can overide it
   // by writing your own
   // cleaning up any heap that was allocated by the class
}
//Initializer list
// If the member varible were const, then we must initialize
// them using the  initializer list
Complex::Complex(double re, double im): real{re}, imag{im}{
   // paramerized constructor
}
// This is the same implementation as the the C++ default
// copy constructor
Complex::Complex(const Complex& c){
   real = c.real; // Can access private member variables
   imag = c.imag;
}

//Complex c4 {c1} // Complex c = c1
// Parameters of type Complex are passed by value
// by calling the copy constructor

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

   // Copy constructor: 
   Complex c4 {c1}; // Default version copies the member variables of c1 into c4
   // Shallow copy 
   cout<<"Print c1 and then c4"<<endl;
   c1.print();
   c4.print();
   // Copy constructor is called any time we do a pass by value

   Complex* pc = new Complex{c1}; //Calls the copy constructor

   // Copy assignment
   c2 = c1; // Function call to copy assignment
            // c1's member variables are copied into c2
            // = operator is overloaded by default
   c2.print();

   int w = 10, y = 20;
   y = w + y;
   // c3 = c1 + c2; // + operator can be redefined for Complex type
   //bool z = (c1 == c2);

   c1 = c2 = c3;


   return 0;
}
// g++ -c -> object file: machine code version of complex.cpp
// linking stage: combines all the object files into an excecutable
