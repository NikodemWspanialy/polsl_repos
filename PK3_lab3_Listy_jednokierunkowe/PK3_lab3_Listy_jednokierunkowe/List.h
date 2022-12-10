// insert i erase zostalo

#pragma once

#include<string>
#include<functional>

namespace nw {
	template <typename T> T DefValue() { throw std::exception(); }
	template <> int DefValue() { return 0; }
	template <> double DefValue() { return 0.0; }
	template <> char DefValue() { return 'a'; }
	template <> std::string DefValue() { return ""; }
	template<class T>
	struct Node
	{
		T data;
		Node<T>* ptr_next;
		Node() { ptr_next = 0; };
		/*~Node() {
			std::cout << "zwolniona pamiec z " << data << std::endl;
		}*/
	};

	template<class T>
	struct Lista {
		Node<T>* ptr_begin;
		class  const_iterator {
		protected:
			Node<T>* pointer;
		public:
			const_iterator( Node<T>* p) : pointer(p) {}
			
			bool operator !=(const_iterator& it) {
				return pointer != it.pointer;
			}
			const const_iterator operator ++() {
				pointer = pointer->ptr_next;
				return pointer;
			}
			const const_iterator operator ++(int) {
				Node<T>* temp = pointer;
				pointer = pointer->ptr_next;
				return temp;
			}
			const T operator *() {
				return pointer->data;
			}
		};
		class iterator {
		public:
			Node<T>* pointer;
			iterator(Node<T>* ptr): pointer(ptr){}
			bool operator !=(iterator it) {
				return pointer != it.pointer;
			}
			iterator operator ++() {
				pointer = pointer->ptr_next;
				return pointer;
			}
			iterator operator ++(int) {
				Node<T>* temp = pointer;
				pointer = pointer->ptr_next;
				return temp;
			}
			T& operator *() {
				return pointer->data;
			}
			T* operator ->() {
				return pointer->data;
			}
			void operator =(T x) {
				pointer->data = x;
			}
		};
		const const_iterator begin() const noexcept {
			return const_iterator( ptr_begin);
		}
		iterator begin() noexcept {
			return iterator(ptr_begin);
		}
		const const_iterator end() const noexcept {
			return const_iterator(0);
		}
		iterator end() noexcept {
			Node<T>* temp = ptr_end();
			return iterator(temp);
		}
		T operator ()(iterator it) {
			return *it;
		}
		T operator ()(const_iterator it) {
			return *it;
		}
		Lista(){ptr_begin = 0;};
		void push_back();
		Lista(std::initializer_list<T> args) {
			ptr_begin = 0;
			for (auto arg : args) {
				push_back(arg);
			}
		}
		Lista(const int size, const std::function<T(const size_t)>& func) {
			ptr_begin = 0;
			int i = 0;
			while(i < size){
				const T value = func(i);
				push_back(value);
				i++;;
			}
		}
		Lista(T value) {
			ptr_begin = 0;
			push_back(value);

		}
		Node<T>* ptr_end() {
			Node<T>* temp = ptr_begin;
			while (temp->ptr_next) {
				temp = temp->ptr_next;
			}
			temp = temp->ptr_next;
			return temp;
		}
		Node<T>* ptr_almostend() {
			Node<T>* temp = ptr_begin;
			Node<T>* end = ptr_end();
			while ((temp->ptr_next)->ptr_next != end) {
				temp = temp->ptr_next;
			}
			return temp;
		}
		int count() {
			int counter = 1;
			Node<T>* temp = ptr_begin;
			while (temp->ptr_next) {
				temp = temp->ptr_next;
				counter++;
			}
			return counter;
		}
		void insert(iterator it, T value) {
			iterator temp = end();
			if (it != temp) {
				Node<T>* newNode = new Node<T>;
				newNode->data = it.pointer->data;
				newNode->ptr_next = it.pointer->ptr_next;
				it.pointer->data = value;
				it.pointer->ptr_next = newNode;
				return;
			}
			push_back(value);
		}
		void erase(iterator it) {
			iterator temp = end();
			if (it != temp) {
				it.pointer->data = (it.pointer->ptr_next)->data;
				it.pointer->ptr_next = (it.pointer->ptr_next)->ptr_next;
				return;
			}
			temp = ptr_almostend();
			temp.pointer->ptr_next = 0;
			delete it.pointer;
		}
		void push_back(T value) {
			Node<T> * newNode = new Node<T>;
			newNode->data = value;
			if (ptr_begin == 0) {
				ptr_begin = newNode;
			}
			else {
				Node<T>* temp = ptr_begin;
				while (temp->ptr_next) {
					temp = temp->ptr_next;
				}
				temp->ptr_next = newNode;
				newNode->ptr_next = 0;
			}
		}
		void toString() {
			Node<T>* temp = ptr_begin;
			while (temp) {
				std::cout << temp->data << std::endl;
				temp = temp->ptr_next;
			}
		}

		~Lista() {
			Node<T>* temp = ptr_begin;
			Node<T>* saved;
			if (temp != 0) {
				while (temp->ptr_next) {
					saved = temp;
					temp = temp->ptr_next;
					delete saved;
				}
			}
			delete temp;
		}
	};
}
