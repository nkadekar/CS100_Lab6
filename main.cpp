#include <iostream>

#include "header/VectorContainer.hpp"
#include "header/ListContainer.hpp"
#include "header/selectionSort.hpp"
#include "header/bubbleSort.hpp"
#include "header/sort.hpp"
#include "header/container.hpp"
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
	cout << "VectorContainer" << endl;
	Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->set_sort_function(new SelectionSort());
	container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

	container->print();
	cout << endl;
	cout << "Selection Sort" << endl;
	container->sort();
	container->print();
	cout << endl;

	container->swap(0, 2);
	container->print();
	cout << endl;
	cout << "Bubble Sort" << endl;
	container->set_sort_function(new BubbleSort());
	container->sort();
	container->print();
	cout << endl;

	cout << "ListContainer" << endl;
    ListContainer* container2 = new ListContainer();
    container2->set_sort_function(new SelectionSort());
    container2->add_element(TreeA);
    container2->add_element(TreeB);
    container2->add_element(TreeC);

    container2->print();
    cout << endl;
	cout << "Selection Sort" << endl;
    container2->sort();
    container2->print();
    cout << endl;

	ListContainer* container3 = new ListContainer();
    container3->set_sort_function(new BubbleSort());
    container3->add_element(TreeA);
    container3->add_element(TreeB);
    container3->add_element(TreeC);

    container3->print();
    cout << endl;
	cout << "Bubble Sort" << endl;
    container3->sort();
    container3->print();
    cout << endl;

	return 0;
}
