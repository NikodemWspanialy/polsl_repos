#pragma once
#include<string>
#include "Author.h"
#include "ISBN.h"
#include "Status.h"

namespace nw {
	class Object //'podstawa do dziedziczenia
	{
		int privateNumber;
		std::string title;
	public:
		Object(const int& pN ,const std::string& title) :privateNumber(pN), title(title) {}

		virtual void write(){}

		 std::string ToString() {
			return(std::to_string(privateNumber)+ " \"" + title + "\"");
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