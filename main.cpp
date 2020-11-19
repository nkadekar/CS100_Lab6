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
	Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Ope* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer(new SelectionSort());
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

	container->print();
	container->sort();
	container->print();

	container->swap(0, 2);
	container->print();
	container->set_sort_function(new BubbleSort());
	container->sort();
	container->print();

	return 0;
}


