#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include <conio.h>
#include "Object.h"
#include "Login.h"
#include "Status.h"
#include"File.h"
#include<vector>

namespace nw {
	class Menu //: public Start
	{
		std::string login;
		int number_of_objects;
	public:
		Menu(const std::string& login, const int number) : login(login), number_of_objects(number) {}

		void Menu_start() {
			std::cout << "press number of activity u want to do:\n" <<
				"1.borrowed items\n" <<
				"2.show books\n" <<
				"3.show video games\n" <<
				"4.borrow \n"
				"5.return an item \n" <<
				"6.exit\n";
			char choice = 0;
			while (choice == 0) {
				choice = _getch();
				switch (choice) {
				case 49://1
					system("cls");
					borrowed_items();
					break;
				case 50://2
					system("cls");
					show_books();
					break;
				case 51://3
					system("cls");
					show_video_games();
					break;
				case 52: //4
					system("cls");
					borrow_number();
					break;
				case 53: //5
					system("cls");
					return_number();
					break;
				case 54: //6
					system("cls");
					exit(0);
				default:
					std::cout << "type 1/2/3/4/5!" << std::endl;
					choice = 0;
				}
			}
		}
		void borrowed_items(){
			std::fstream plik_users, plik_books, plik_games;
			std::stringstream ss;
			std::string get_line, tmp_login, tmp_password, gl_author_name, gl_author_lname, gl_title, gl_producer;
			int number, first_borrowed, second_borrowed, th_borrowed, gl_number = 0, gl_ibsn;
			plik_users.open("users.txt", std::ios::in);
			plik_books.open("books.txt", std::ios::in);
			plik_games.open("videogames.txt", std::ios::in);
			if (plik_users.is_open() and plik_books.is_open() and plik_games.is_open()) {
				while (std::getline(plik_users, get_line)) {
					ss << get_line;
					ss >> tmp_login >> tmp_password >> number >> first_borrowed >> second_borrowed >> th_borrowed;
					ss = std::stringstream("");
					if (tmp_login == login) {
							std::cout << "You got "<< number <<" object:\n";
							if (first_borrowed <= 1999 and first_borrowed > 999) {
								while (first_borrowed != gl_number) {
									std::getline(plik_books, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_author_name >> gl_author_lname >> gl_ibsn;
									ss = std::stringstream("");
									if (first_borrowed == gl_number) {
										Book b(gl_number, gl_title, gl_author_name, gl_author_lname, gl_ibsn);
										b.write();
										std::cout << std::endl;
									}
								}
								plik_books.seekg(0);
							}
							if(first_borrowed > 1999){
								while (first_borrowed != gl_number) {
									std::getline(plik_games, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_producer;
									ss = std::stringstream("");
									if (first_borrowed == gl_number) {
										Videogame v(gl_number, gl_title, gl_producer);
										v.write();
										std::cout << std::endl;
									}
								}
								plik_games.seekg(0);
							}
							if (second_borrowed <= 1999 and second_borrowed > 999) {
								while (second_borrowed != gl_number) {
									std::getline(plik_books, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_author_name >> gl_author_lname >> gl_ibsn;
									ss = std::stringstream("");
									if (second_borrowed == gl_number) {
										Book b(gl_number, gl_title, gl_author_name, gl_author_lname, gl_ibsn);
										b.write();
										std::cout << std::endl;
									}
								}
								plik_books.seekg(0);
							}
							if (second_borrowed > 1999) {
								while (second_borrowed != gl_number) {
									std::getline(plik_games, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_producer;
									ss = std::stringstream("");
									if (second_borrowed == gl_number) {
										Videogame v(gl_number, gl_title, gl_producer);
										v.write();
										std::cout << std::endl;
									}
								}
								plik_games.seekg(0);
							}
							if (th_borrowed <= 1999 and th_borrowed > 999) {
								while (th_borrowed != gl_number) {
									std::getline(plik_books, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_author_name >> gl_author_lname >> gl_ibsn;
									ss = std::stringstream("");
									if (th_borrowed == gl_number) {
										Book b(gl_number, gl_title, gl_author_name, gl_author_lname, gl_ibsn);
										b.write();
										std::cout << std::endl;
									}
								}
								plik_books.seekg(0);
							}
							if (th_borrowed > 1999) {
								while (th_borrowed != gl_number) {
									std::getline(plik_games, get_line);
									ss << get_line;
									ss >> gl_number >> gl_title >> gl_producer;
									ss = std::stringstream("");
									if (th_borrowed == gl_number) {
										Videogame v(gl_number, gl_title, gl_producer);
										v.write();
										std::cout << std::endl;
									}
								}
								plik_games.seekg(0);
							}

							plik_books.close();
							plik_games.close();
							plik_users.close();
							_getch();
							system("cls");
							Menu_start();
							break;
					}

				}
			}
			else {
				std::cout << "file problems\n:";
					_getch();
				Menu_start();
			}
			_getch();
			Menu_start();
		}

		void show_books() {
			std::fstream plik_objects, plik_status;
			std::stringstream ss;
			std::string get_line_objects, get_line_status;
			int number, number_status, isbn, lenght;
			std::string  title, author_name, author_lastname, status;

			plik_objects.open("books.txt", std::ios::in);
			plik_status.open("status.txt", std::ios::in);
			if (plik_objects.is_open() and plik_status.is_open()) {
				while (std::getline(plik_objects, get_line_objects)) {
					ss << get_line_objects;
					ss >> number >> title >> author_name >> author_lastname >> isbn;
					Book b(number, title, author_name, author_lastname, isbn);
					ss = std::stringstream("");
					b.write();
					if (!plik_status.is_open())
						plik_status.open("status.txt", std::ios::in);
					while (std::getline(plik_status, get_line_status)) {
						ss << get_line_status;
						ss >> number_status >> status;
						if (number_status == number) {
							Status s(status);
							s.write();
							std::cout << std::endl;
						}
						ss = std::stringstream("");
					}
					plik_status.close();
				}
			}
			plik_objects.close();
			plik_status.close();
			_getch();
			system("cls");
			Menu_start();
		}

		void show_video_games(){
			std::fstream plik_objects, plik_status;
			std::string title, producer, status, get_line_status;
			int number, number_status;
			std::stringstream ss;
			std::string get_line;

			plik_objects.open("videogames.txt", std::ios::in);
			if (plik_objects.is_open()) {
				while (std::getline(plik_objects, get_line)) {
					ss << get_line;
					ss >> number >> title >> producer;
					Videogame v(number, title, producer);
					ss = std::stringstream("");
					v.write();
					if (!plik_status.is_open())
						plik_status.open("status.txt", std::ios::in);
					while (std::getline(plik_status, get_line_status)) {
						ss << get_line_status;
						ss >> number_status >> status;
						if (number_status == number) {
							Status s(status);
							s.write();
							std::cout << std::endl;
						}
						ss = std::stringstream("");
					}
					plik_status.close();
				}
			}
			plik_objects.close();
			plik_status.close();
			_getch();
			system("cls");
			Menu_start();
		}

		void borrow_number() {
			if (number_of_objects < 3) {
				std::string input = "";
				bool correct = true;
				int id = 0;
				std::cout << "type number of object, wchich you want to borrow\n";
					std::cin >> id;
					std::cin.clear();
					if (id < 1000 or id> 3000)
					{
						std::cout << "it is not a corect number! try again\n";
						_getch();
						system("cls");
						Menu_start();
					}
				system("cls");
				borrow_plik(id);
				Menu_start();
			}
			else {
				std::cout << "you can not borrow more than 3 objects in the same time\n";
				_getch();
				system("cls");
				Menu_start();
			}
		}

		void borrow_plik(int id) {
			std::fstream plik_status,plik_users;
			std::string get_line_string, private_status, user;
			std::stringstream ss;
			int private_number;

			plik_status.open("status.txt", std::ios::in);
			if(plik_status.is_open()){
				Status_file* status_file = new Status_file();

				while (std::getline(plik_status, get_line_string)) {
					ss << get_line_string;
					ss >> private_number >> private_status >> user;
					ss = std::stringstream("");
					if (private_number != id) {
						status_file->Add_line(get_line_string);
					}
					else {
						if (private_status == "a") {
							plik_users.open("users.txt");
							if (plik_users.is_open()) {
								Users_file* users_file = new Users_file();
								std::string tmp_login, tmp_password;
								int borrowed_number, first_item, sec_item, third_item;

								private_status = "n";
								user = login;
								std::vector<std::string> v;
								std::string tmp_string = std::to_string(private_number);
								v.push_back(tmp_string);
								v.push_back(private_status);
								v.push_back(user);
								status_file->Create_line(v);
								//user class
							    while (std::getline(plik_users, get_line_string)) {
									ss << get_line_string;
									ss >> tmp_login >> tmp_password >> borrowed_number >> first_item >> sec_item >> third_item;
									ss = std::stringstream("");
									if (tmp_login != login) {
										users_file->Add_line(get_line_string);
									}
							        else if (tmp_login == login) {
										std::vector<std::string> v2;
										borrowed_number++;
										if (first_item == 0)
											first_item = id;
										else if (sec_item == 0)
											sec_item = id;
										else
											third_item = id;
										v2.push_back(tmp_login);
										v2.push_back(tmp_password);
										tmp_string = std::to_string(borrowed_number);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(first_item);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(sec_item);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(third_item);
										v2.push_back(tmp_string);
										users_file->Create_line(v2);
									}
								}
								plik_users.close();
								users_file->out_write("users.txt");
								delete users_file;
								number_of_objects++;
								std::cout << "you succesfuly borrowed an object\n";
								_getch();
							}
							else {
								std::cout << "files dont works\n";
								_getch();
								Menu_start();
							}
						}
						else {
							std::cout << "u cant borrow this object, it is already taken\n";
							_getch();
							system("cls");
							//usunac vecotr w statusie i usunac wskaznik stuatus
							Menu_start();
						}
					}
				}
				status_file->out_write("status.txt");
				delete status_file;
			}
			else {
				std::cout << "files dontg works\n";
				_getch();
				Menu_start();
			}
		}

		void return_number() {
			if (number_of_objects != 0) {
				std::fstream plik;
				std::string gl_login, gl_password, gl;
				std::stringstream ss;
				int number, first, second, three;
				plik.open("users.txt", std::ios::in);
				std::string input = "";
				bool correct = true;
				int id = 0;
				std::cout << "type number of object, wchich you want to return\n";

				std::cin >> id;
					std::cin.clear();
					if (id > 1000 and id < 3000){}
					else {
						std::cout << "it is not a corect number! try again\n";
						_getch();
						system("cls");
						Menu_start();
					}
					if (plik.is_open()) {
						while (gl_login != login) {
							std::getline(plik, gl);
							ss << gl;
							ss >> gl_login >> gl_password >> number >> first >> second >> three;
							ss = std::stringstream("");
						}
						if (id == first or id == second or id == three) {
							system("cls");
							return_plik(id);
						}
						else {
							std::cout << "This object is no borrowed by you!\n";
							_getch();
							system("cls");
							Menu_start();
						}
					}
			}
			else {
				std::cout << "you dont have objects so u cant return!\n";
				_getch();
				system("cls");
				Menu_start();
			}
		}

		void return_plik(int id) {
				std::fstream plik_status,plik_users;
			std::string get_line_string, private_status, user;
			std::stringstream ss;
			int private_number;

			plik_status.open("status.txt", std::ios::in);
			if(plik_status.is_open()){
				Status_file* status_file = new Status_file();

				while (std::getline(plik_status, get_line_string)) {
					ss << get_line_string;
					ss >> private_number >> private_status >> user;
					ss = std::stringstream("");
					if (private_number != id) {
						status_file->Add_line(get_line_string);
					}
					else {
						if (private_status == "n") {
							plik_users.open("users.txt");
							if (plik_users.is_open()) {
								Users_file* users_file = new Users_file();
								std::string tmp_login, tmp_password;
								int borrowed_number, first_item, sec_item, third_item;

								private_status = "a";
								user = login;
								std::vector<std::string> v;
								std::string tmp_string = std::to_string(private_number);
								v.push_back(tmp_string);
								v.push_back(private_status);
								v.push_back("");
								status_file->Create_line(v);
								//user class
							    while (std::getline(plik_users, get_line_string)) {
									ss << get_line_string;
									ss >> tmp_login >> tmp_password >> borrowed_number >> first_item >> sec_item >> third_item;
									ss = std::stringstream("");
									if (tmp_login != login) {
										users_file->Add_line(get_line_string);
									}
							        else if (tmp_login == login) {
										std::vector<std::string> v2;
										borrowed_number--;
										if (first_item == id)
											first_item = 0;
										else if (sec_item == id)
											sec_item = 0;
										else if(third_item == id)
											third_item = 0;
										v2.push_back(tmp_login);
										v2.push_back(tmp_password);
										tmp_string = std::to_string(borrowed_number);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(first_item);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(sec_item);
										v2.push_back(tmp_string);
										tmp_string = std::to_string(third_item);
										v2.push_back(tmp_string);
										users_file->Create_line(v2);
									}
								}
								plik_users.close();
								users_file->out_write("users.txt");
								delete users_file;
								number_of_objects--;
								std::cout << "you succesfuly returned an object\n";
								_getch();
							}
							else {
								std::cout << "files dont works\n";
								_getch();
								Menu_start();
							}
						}
						else {
							std::cout << "this object \n";
							_getch();
							system("cls");
							//usunac vecotr w statusie i usunac wskaznik stuatus
							Menu_start();
						}
					}
				}
				status_file->out_write("status.txt");
				delete status_file;
			}
			else {
				std::cout << "files dontg works\n";
				_getch();
				Menu_start();
			}
		}
	};
}

////////////////////////////////////////////////////
			/*std::cout << "\ntype back if u want back to menu or type number of book if u want it\n";
			std::cin >> choice;
			if (choice == "back") {
				Menu_start();
			}
			else {
				if (number_of_objects == 3) {
					std::cout << "you have max number of books idk\n";
					return;
				}
				else{
					number = 0;
					plik.seekp(0);
					while (std::getline(plik, get_line) or choice == std::to_string(number)) {
						ss << get_line;
						ss >> number >> title >> author_name >> author_lastname >> isbn >> status;
						Book b(number, title, author_name, author_lastname, isbn, status);
						ss = std::stringstream("");
						position = plik.tellg();
					}

					plik.seekg(0, std::ios_base::end);
					lenght = plik.tellg();
					char* bufor = new char[lenght];
					plik.seekg(0, std::ios_base::beg);
					plik.read(bufor, lenght);
					if (bufor[position - 2] == 'a') {
						std::cout << "avaible\n";
					}
					else
						std::cout << "nie udalo sie\n";
					}
			}*/