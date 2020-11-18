#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container;
class Sort;

class BubbleSort: public Sort {
    public:
        /* Constructors */
        BubbleSort() : Sort(){};

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
			for (int i = 0; i < container->size() - 1; i++){
				for (int j = 0; j < container->size() - i - 1; j++){
					if (container->at(j)->evaluate() > container->at(j + 1)->evaluate()){
						container->swap(j, j + 1);
					}
				}
			}
		}
};

#endif
