#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "container.hpp"
#include <list>
#include <iostream>

class Base;
class Container;
class Sort;

class ListContainer: public Container {
	protected:
		Sort* _sort_function;
		std::list<Base*> _list;

	public:
		ListContainer() : Container() { };

		ListContainer(Sort* function) : Container(function) { };

		void set_sort_function(Sort* sort_function){
			_sort_function = sort_function;
		}
		
		virtual void add_element(Base* element){
			_list.push_back(element);
		}

		virtual void print(){
            Base* data = nullptr;
            for(auto it = _list.begin(); it != _list.end(); ++it){
				data = *it;
				cout << data->stringify() << " = " << data->evaluate();
				std::cout << std::endl;
			}
		}

		virtual void sort(){
			_sort_function->sort(this);
		}
		
		virtual void swap(int i, int j){
			int pos1, pos2 = 0;
			Base* data1 = nullptr;
            Base* data2 = nullptr;
			
			for(auto it = _list.begin(); it != _list.end(); ++it){
				if(data1 != nullptr && data2 != nullptr){
                    break;
                }           	

				if(pos1 == i){
                    data1 = *it;
				}

				if(pos2 == j){
                    data2 = *it;
                }
				
				pos1 += 1;
				pos2 += 1;
			}
			
			Base* temp = data1;
			data1 = data2;
			data2 = temp;

			pos1 = 0;
			pos2 = 0;
			for(auto it = _list.begin(); it != _list.end(); ++it){
                if(pos1 == i){
                   *it = data1;
                }

                if(pos2 == j){
                   *it = data2;
                }

                pos1 += 1;
                pos2 += 1;
            }

		}
		
		virtual Base* at(int i){
	        int pos = 0;
			Base* data = nullptr;
			for(auto it = _list.begin(); it != _list.end(); ++it){
				if(pos == i){
					data = *it;
		            return data;
				}
				pos += 1;
			}
		}
		
		virtual int size(){
			return _list.size();
		}
};
#endif
