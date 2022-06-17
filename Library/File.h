#pragma once
#include<string>
#include<vector>
#include<fstream>
namespace nw {
	class File
	{
	public:
		virtual void Add_line(const std::string& line) = 0;
		virtual void Create_line(const std::vector<std::string>& elements) = 0;
		virtual void out_write(const std::string& plik) = 0;
	};

	class Status_file : public File {
		std::vector <std::string> files;
	public:
		void Add_line(const std::string& line) {
			files.push_back(line);
		}

		void Create_line(const std::vector<std::string>& elements) {
			std::string new_line = elements[0] + ' ' + elements[1] + ' ' + elements[2];
			files.push_back(new_line);
		}
		void out_write(const std::string& plik){
			std::fstream file;
			file.open(plik, std::ios::trunc | std::ios::out);
			if (file.is_open()) {
				for (size_t i = 0; i < size(files); i++) {
					file << files[i] << std::endl;
				}
			}
			file.close();
		}
	};
	class Users_file : public File {
		std::vector <std::string> files;
	public:
		virtual void Add_line(const std::string& line) {
			files.push_back(line);
		}
		virtual void Create_line(const std::vector<std::string>& elements) {
			std::string new_line = elements[0] + ' ' + elements[1] + ' ' + elements[2] + ' ' + elements[3] + ' ' + elements[4] + ' ' + elements[5];
			files.push_back(new_line);
		}
		virtual void out_write(const std::string& plik){
			std::fstream file;
			file.open(plik, std::ios::trunc | std::ios::out);
			if (file.is_open()) {
				for (size_t i = 0; i < size(files); i++) {
					file << files[i] << std::endl;
				}
			}
			file.close();
		}
	};
}

