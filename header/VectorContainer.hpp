#ifndef VECTOR_CONTAINER_HPP
#define VECTOR_CONTAINER_HPP

#include "container.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Base;
class Container;
class Sort;

class VectorContainer: public Container {
	protected:
        Sort* sort_function;
		vector<Base*> trees;

	public:
        /* Constructors */
        VectorContainer() : Container() { };
        VectorContainer(Sort* function) : Container(function) { };

		/* Non Virtual Functions */
        void set_sort_function(Sort* sort_function){
			this->sort_function = sort_function;
		}
        /* Pure Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element){
			this->trees.push_back(element);
		}
		// iterate through trees and output the expressions (use stringify())
        virtual void print(){
			for (int i = 0; i < trees.size(); i++){
				cout << trees.at(i)->stringify() << " = " << trees.at(i)->evaluate();
				cout << endl;
			}
		}
		// calls on the previously set sorting-algorithm. Checks if sort_function is not
		// null, throw exception if otherwise
		virtual void sort(){
			sort_function->sort(this);
		}
		/* Functions Needed to Sort */
        //switch tree locations
		virtual void swap(int i, int j){
			Base* temp = trees.at(i);
			trees.at(i) = trees.at(j);
			trees.at(j) = temp;
		}
		// get top ptr of tree at index i
		virtual Base* at(int i){
			return trees.at(i);
		}
		// return container size
	    virtual int size(){
			return trees.size();
		}
};

#endif
