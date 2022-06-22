#pragma once
#include<string>
//#include "Author.h"
//#include "ISBN.h"
#include "Status.h"

namespace nw {
	class ISBN
	{
		int isbn;
	public:
		ISBN(const int& isbn) :isbn(isbn) {}

		std::string ToString() {
			std::string str = std::to_string(isbn);
			return str;
		}
	};
	class Author {
		std::string firstName;
		std::string lastName;
	public:
		Author(const std::string& fn, const std::string& ln) : firstName(fn), lastName(ln) {}
		std::string ToString() const {
			return(firstName + " " + lastName);
		}
		std::string getFirstName() {
			return firstName;
		}
		std::string getLastName() {
			return lastName;
		}
	};


	class Object //'podstawa do dziedziczenia
	{
		int privateNumber;
		std::string title;
	public:
		Object(const int& pN ,const std::string& title) :privateNumber(pN), title(title) {}

		virtual void write(){}
		std::string addspace(std::string a) {
			for (size_t i = 0; i < a.length(); i++) {
				if (a[i] == '_')
					a[i] = ' ';
			}
			return a;
		}
		 std::string ToString() {
			return(std::to_string(privateNumber)+ " \"" + addspace(title) + "\"");
		}
		std::string getNumber() {
			return(std::to_string(privateNumber));
		}
	};




	class Book : public Object
	{
		Author author;
		ISBN isbn; //klasa isbn - miedzynarodowy znormalizowany numer ksiazki 
	public:
		Book(const int& pN, const std::string& title, const std::string& firstName, const std::string& lastName, const int& isbn) : Object(pN, title), author(firstName, lastName), isbn(isbn) {}
		Book(const Object& o, const std::string& firstName, const std::string& lastName, const ISBN& isbn) : Object(o), author(firstName, lastName), isbn(isbn) {}
		Book(const Object& o, const Author& a, const ISBN& isbn) : Object(o), author(a), isbn(isbn) {}
		Book(const int& pN, const std::string& title, const Author& a, const int& isbn) : Object(pN, title), author(a), isbn(isbn) {}

		 std::string ToString() {
			return(Object::ToString() + ", author: " + author.ToString() + ", ISBN: " + isbn.ToString());
		}
		std::string getNumber() {
			return(Object::getNumber());
		}

		virtual void write() {
			std::cout << ToString();
		}
	};


	class Videogame : public Object
	{
		std::string producer;
     public:
		 Videogame(const int& pN, const std::string& title, const std::string& prod): Object(pN, title), producer(prod){}

		  std::string ToString() {
			 return(Object::ToString() + ", producer: " + producer);
		 }

		  virtual void write() {
			  std::cout << ToString();
		  }
	};
}