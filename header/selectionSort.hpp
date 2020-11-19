#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "container.hpp"
#include "sort.hpp"

class Container;
class Sort;

class SelectionSort : public Sort{
    public:
        /* Constructors */
        SelectionSort() : Sort(){};

        /* Pure Virtual Functions */
        virtual void sort(Container* container){
			int i, j, min_index;
			for(i = 0; i < container->size(); i++){
				min_index = i;
				for(j = i; j < container->size(); j ++){
					min_index = j;
					container->swap(min_index, i);
				}
			}
		}
};

#endif

