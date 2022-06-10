#pragma once
#include<string>
#include <fstream>
#include<iostream>
#include <sstream>
#include <conio.h>

namespace nw {
	class Start {

		std::string login = "&";
		std::string password;
		int number_of_objects;

	public:

		void start() {
			std::cout << "press number of activity u want to do:" << std::endl;
			std::cout << "1. Login" << std::endl;
			std::cout << "2. Registration" << std::endl;
			std::cout << "3. Exit" << std::endl;
			char choice = 0;
			while(choice ==0) {
				choice = _getch();
					switch (choice) {
					case 49://1
						system("cls");
						start_login();
						break;
					case 50://2
						system("cls");
						start_registration();
						break;
					case 51://3
						system("cls");
						exit(0);
						break;
					default:
						std::cout << "type 1/2/3!" << std::endl;
						choice = 0;
					}			
			} 
			
		}

		void start_login() {
			std::fstream plik;
			std::string login_in = "", password_in = "";
			std::string login_out, password_out;
			std::string get_line;
			std::stringstream ss;
			int number = 0;

			std::cout << "login:" << std::endl;
			std::cin >> login_in;
			system("cls");
			std::cout << "password:" << std::endl;
			std::cin >> password_in;
			system("cls");
			plik.open("users.txt");
			if (plik.is_open()) {
				while (std::getline(plik, get_line)) {
					ss << get_line;
					ss >> login_out >> password_out >> number;
					if (login_in == login_out) {
						if (password_in == password_out) {
							login = login_in;
							password = password_in;
							number_of_objects = number;
						}
						else {
							//throw std::exception("fail password");
							std::cout << "zle haslon\n";

							plik.close();
							return;
						}
					}
					ss = std::stringstream("");
				}
				if (login == "&") {

					std::cout << "taki login nie istnieje\n";
					//throw std::exception("login does not exist");
				}
				plik.close();
				return;
			}
		}

		void start_registration() {
			std::string new_login, new_password, empty;
			std::string login_out, password_out;
			std::fstream plik;
			std::string get_line;
			std::stringstream ss;
			std::cout << "login:" << std::endl;
			std::cin >> new_login;
			for (size_t i = 0; i, new_login.size(); i++) {
				if (char(new_login[i]) < 48 or char(new_login[i]) > 122) {
					std::cout << "use only english alphabet and numbers!\n";
					_getch();
					system("cls");
					start_registration();
				}
			}
			system("cls");
			std::cout << "password:" << std::endl;
			std::cin >> new_password;
			for (size_t i = 0; i, new_password.size(); i++) {
				if (char(new_password[i]) < 48 or char(new_password[i]) > 122) {
					std::cout << "use only english alphabet and numbers!\n";
					_getch();
					system("cls");
					start_registration();
				}
			}
			system("cls");
			plik.open("users.txt", std::ios::in);
			if (plik.is_open()) {
				while (std::getline(plik, get_line)) {
					ss << get_line;
					ss >> login_out >> password_out;
					if (new_login == login_out) {
						std::cout << "use other login\n";
						return;
					}
					ss = std::stringstream("");
				}

				std::cout << "You are registered succesfully";
				_getch();
				login = new_login;
				password = new_password;
				number_of_objects = 0;
			}
			plik.close();
			plik.open("users.txt", std::ios::app);
			if (plik.is_open()) {
				plik << '\n' << new_login << ' ' << new_password << ' '<< number_of_objects << ' ' << "0" << ' ' << "0" << ' ' << "0";
			}
			plik.close();
		}
		std::string loginGet() {
			return login;
		}
		int getNumber() {
			return number_of_objects;
		}
	};
}