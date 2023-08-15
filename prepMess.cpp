#include <iostream>
#include "prepMess.h"
#include <vector>
#include "client.h"


PrevMess::PrevMess()//конструктор по умолчанию
{
	managerInterLogPass = true;
}

/*
std::string Log_pass::getLog()
{
		return login;
}

std::string Log_pass::getPass()
{
		return password;
}
*/

std::string PrevMess::addLogPass()
{
	std::cout << " ђведите логин нового пользовател§: " << std::endl;
	std::cout << ">> ";
	std::cin >> login;//ђводим новый логин
	std::cout << "ђведите нового парол§: " << std::endl;
	std::cout << ">> ";
	std::cin >> password;
	std::string resultStr = password + ":" + login;
	return resultStr;
}

std::string PrevMess::InterfaceLogPass(bool StartFunction)//Чоздаесм стартовое окно дл§ создани§ логина и парол§ или авторизаци§ на сервере
{
	std::string tempStr;
	std::string tempOP;
	char* op;//запись символа операции
//----------------------------------------------------------------------
	if (StartFunction)
	{
		std::cout << "Press key:''n'-create ";
		std::cout << ">> ";
		std::cin >> tempOP;
		if (tempOP.size() == 1)
		{
			std::vector<char>chars(tempOP.begin(), tempOP.end());//преобразователь string ->char
			chars.push_back('\0');
			op = &chars[0];
			switch (*op)
			{
			case'n':
				tempStr = addLogPass();
				tempStr = "*" + tempStr + ":--:2:1:1:1:--&";
				return tempStr;
			defalt:
				std::cout << "Неправильно выбрали букву";
			}
		}
	}
	//----------------------------------------------------------------------

}

//-----------------------------------------------------------------------------------------------
// ----------------------------Сункци§ авторизациии---------------------------------------------
//---------------------------------------------------------------------------------------------
std::string PrevMess::enterLogPass(std::string _stateProgram)
{
	std::string _password;
	std::string _login;
	std::string  resultStr;
	std::cout << " ђведите логин нового пользовател§: " << std::endl;
	std::cout << ">> ";
	std::cin >> _login;//ђводим новый логин
	std::cout << "ђведите пароль\n";
	std::cout << ">> ";
	std::cin >> _password;
	resultStr = "*" + _password + ":" + _login + ":--:6:" + _stateProgram + ":1:1:--&";
	return resultStr;
}
void  PrevMess::showMessages()
{
	int a = 5;
}