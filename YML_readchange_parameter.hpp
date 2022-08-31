#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>



//C++17 needed
using std::filesystem::directory_iterator;


std::string readvaluefromfile(std::string target, std::string path, std::string filename)
{
	bool finded = false;
	std::string value = "";

	std::string path_string = (path + "/" + filename);

	if (path_string.find(".yml") < 500)
	{
		const char* path = path_string.c_str();
		std::stringstream buffer;
		std::fstream file(path, std::fstream::in);
		for (std::string line; getline(file, line); ) {
			if (line.substr(0, line.find(":")) == target) {
				finded = true;
				value = line.substr(line.find(":") + 2);
				//std::cout << "Valor" << line.substr(line.find(":" )+2);
			}
		}
		file.close();
		/*if (finded == false)
		{

		}*/
	}

	return value;
}


std::string readvalue(std::string target, std::string path)
{
	bool finded = false;
	std::string value = "";
	for (const auto& file : directory_iterator(path))
	{
		std::string filename{ file.path().filename().u8string() };
		std::string path_string = (path + "/" + filename);

		if (path_string.find(".yml") < 500)
		{
			const char* path = path_string.c_str();
			std::stringstream buffer;
			std::fstream file(path, std::fstream::in);
			for (std::string line; getline(file, line); ) {
				if (line.substr(0, line.find(":")) == target) {

					finded = true;
					value = line.substr(line.find(":") + 2);
					//std::cout << "Valor" << line.substr(line.find(":" )+1);
				}

			}
			file.close();
			if (finded == false)
			{

			}

		}
	}
	return value;

}

void changeparameterinfile(std::string target, std::string newvalue, std::string path)

{
	std::string filename = path;
	bool finded = false;
	std::stringstream buffer;
	std::fstream file(filename, std::fstream::in);
	for (std::string line; getline(file, line); ) {
		if (line.substr(0, line.find(":")) == target) {
			buffer << target << ": " << newvalue;
			finded = true;
		}
		else {
			buffer << line;
		}
		buffer << std::endl;
	}
	file.close();
	if (finded == false)
	{
		std::cout << "Parámetro no encontrado";
	}
	file.open(filename, std::fstream::out);
	file << buffer.str();
	file.close();
}

void changeparameter(std::string target, std::string newvalue, std::string path)

{
	bool finded = false;
	for (const auto& file : directory_iterator(path))
	{
		std::string path_string1{ file.path().filename().u8string() };
		std::string path_string = (path + "/" + path_string1);
		if (path_string1.find(".yml") < 500)
		{
			const char* filename = path_string.c_str();
			/* Read the whole file into a stringstream. */
			std::stringstream buffer;
			std::fstream file(filename, std::fstream::in);
			for (std::string line; getline(file, line); ) {
				/* Do the replacement while we read the file. */
				if (line.substr(0, line.find(":")) == target) {
					buffer << target << ": " << newvalue;
					finded = true;
				}
				else {
					buffer << line;
				}
				buffer << std::endl;
			}
			file.close();
			/*
			if (finded == false)
			{
				std::cout << "Parámetro no encontrado";
			}*/
			/* Write the whole stringstream back to the file */
			file.open(filename, std::fstream::out);
			file << buffer.str();
			file.close();
		}
	}

}