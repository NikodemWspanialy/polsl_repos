#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
#include <conio.h>
#include "Object.h"
#include "Login.h"
#include "Status.h"

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
					borrow();
					break;
				case 53: //5
					system("cls");
					return_items();
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
			std::fstream plik_users;
			std::stringstream ss;
			std::string get_line, tmp_login, tmp_password;
			int number, first_borrowed, second_borrowed, th_borrowed;
			plik_users.open("users.txt", std::ios::in);
			if (plik_users.is_open()) {
				while (std::getline(plik_users, get_line)) {
					ss << get_line;
					ss >> tmp_login >> tmp_password >> number >> first_borrowed >> second_borrowed >> th_borrowed;
					if (tmp_login == login) {
						switch (number) {
						case 1:

							break;
						case 2:

							break;
						case 3:

							break;
						case 0:
							std::cout << "you did not borrowed any object yet\n";
							_getch();
							break;
						}
					}
					ss = std::stringstream("");

				}
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

		void borrow() {
			if (number_of_objects < 3) {
				std::string input = "";
				bool correct = true;
				int id = 0;
				std::cout << "type number of object, wchich you want to borrow\n";

				while (id == 0) {
					std::cin >> id;
					std::cout << "it is not a corect number! try again\n";
					std::cin.clear();
					if (id < 1000 or id> 3000)
						id = 0;

				}
				system("cls");
				borrow_object(id);
				Menu_start();
			}
			else {
				std::cout << "you can not borrow more than 3 objects in the same time\n";
				_getch();
				system("cls");
				Menu_start();
			}
		}

		void borrow_object(int id) {
			//std::fstream plik_status, plik_users;
			//std::string get_line, status, user;
			//int number;
			//std::stringstream ss;
			//size_t last = 0, present = 0, total, enter_number = 0, enter_number_2 = 0;

			//plik_status.open("status.txt", std::ios::in);
			//if (plik_status.is_open()) {
			//	plik_status.seekp(0);
			//	while (std::getline(plik_status, get_line)) {
			//		enter_number++;
			//		last = present;
			//		present = plik_status.tellp();
			//		ss << get_line;
			//		ss >> number >> status >> user;
			//		if (number == id) {
			//			if (status == "n") {
			//				std::cout << "this item is already borrowed by " << user << "\n";
			//				_getch();
			//				system("cls");
			//				Menu_start();
			//			}
			//			else if (status == "a") {
			//				plik_users.open("users.txt", std::ios::in);
			//				if (plik_users.is_open()) {
 		//						status = "n";
			//					char* buf_first_part_status = new char[last + 1];
			//					plik_status.seekp(0, std::ios::end);
			//					total = plik_status.tellp();
			//					char* buf_second_part_status = new char[total];
			//					plik_status.seekp(0);
			//					plik_status.read(buf_first_part_status, (last+ 1));
			//					plik_status.seekp(std::ios::beg + present);
			//					plik_status.read(buf_second_part_status, total + 1);
			//					plik_status.close();

			//					plik_status.open("status.txt", std::ios::in);

			//					std::string a;
			//					plik_status.seekp(present);
			//					while (std::getline(plik_status, a)) {
			//						enter_number_2++;
			//					}
			//					plik_status.close();
			//					plik_status.open("status2.txt", std::ios::trunc | std::ios::out);
			//					plik_status.write(buf_first_part_status, last- enter_number + 1);
			//					plik_status << number << ' '<< status << ' ' << login << std::endl;
			//					plik_status.write(buf_second_part_status, (total - present - enter_number_2 - enter_number + 3));

			//					delete[] buf_second_part_status;
			//					delete[] buf_first_part_status;
			//					//------------------------------------------------------
			//					number_of_objects++;
			//					enter_number = 0;
			//					enter_number_2 = 0;
			//					last = 0;
			//					present = 0;
			//					get_line = "";
			//					ss = std::stringstream("");
			//					std::string tmp_login, tmp_password;
			//					int tmp_amount_of_objects, first_borrowed, second_borrowed, th_borrowed;

			//					plik_users.seekp(0);
			//					while (std::getline(plik_users, get_line)) {
			//						enter_number++;
			//						last = present;
			//						present = plik_users.tellp();
			//						ss << get_line;
			//						ss >> tmp_login >> tmp_password >> tmp_amount_of_objects >> first_borrowed >> second_borrowed >> th_borrowed;
			//						if (tmp_login == login) {
			//							tmp_amount_of_objects = number_of_objects;
			//							char* buf_first_part_users = new char[last +1];
			//							plik_users.seekg(0, std::ios::end);
			//							total = plik_users.tellp();
			//							char* buf_second_part_users = new char[total];
			//							plik_users.seekg(0);
			//							plik_users.read(buf_first_part_users, (last - enter_number + 2));
			//							plik_users.seekg(std::ios::beg + present);
			//							plik_users.read(buf_second_part_users, total - present - enter_number - enter_number_2 + 3);
			//							plik_users.close();
			//							plik_users.open("users.txt", std::ios::in);
			//							plik_users.seekg(present);
			//							std::string a;
			//							while (std::getline(plik_users, a)) {
			//								enter_number_2++;
			//							}
			//							plik_users.close();
			//							plik_users.open("users2.txt", std::ios::trunc | std::ios::out);
			//							plik_users.write(buf_first_part_users, last);
			//							if (first_borrowed == 0) {
			//								plik_users << tmp_login << ' ' << tmp_password << ' ' << tmp_amount_of_objects << ' ' << number << ' ' << second_borrowed
			//									<< ' ' << th_borrowed << std::endl;
			//							}
			//							else if (second_borrowed == 0) {
			//								plik_users << tmp_login << ' ' << tmp_password << ' ' << tmp_amount_of_objects << ' ' << first_borrowed << ' ' << number
			//									<< ' ' << th_borrowed << std::endl;
			//							}
			//							else {
			//								plik_users << tmp_login << ' ' << tmp_password << ' ' << tmp_amount_of_objects << ' ' << first_borrowed << ' ' << second_borrowed
			//									<< ' ' << number << std::endl;
			//							}
			//							plik_users.write(buf_second_part_users, (total - present - enter_number_2));
			//							plik_users << std::endl << std::endl;

			//							delete[] buf_second_part_users;
			//							delete[] buf_first_part_users;
			//						}
			//						ss = std::stringstream("");
			//					}

			//					std::cout << "everything went corently\n";
			//					_getch();
			//					return;
			//				}
			//			}
			//		}
			//		ss = std::stringstream("");

			//	}
			//}
		}

		void return_items() {
			_getch();
			Menu_start();
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