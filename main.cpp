#include <iostream>

#include "header/base.hpp"
#include "header/mult.hpp"
#include "header/div.hpp"
#include "header/sub.hpp"
#include "header/add.hpp"
#include "header/op.hpp"
#include "header/rand.hpp"
#include "header/pow.hpp"
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
	return 0;
}


