#pragma once
#pragma once
#include <iostream>
#include <string>
class PrevMess {
public:
	PrevMess();//Конструктор по умолчанию
	//Стартовое окно для ввода логина пароля
	//Генератор сообщений для сервера так же это выходной параметр
	std::string InterfaceLogPass(bool StartFunction);//Создаесм интефайс для пасворда и логина
	std::string addLogPass();
	std::string enterLogPass(std::string);
	void showMessages();
private:
	//Log_pass* ptrObject;// Указатель на обьект
	std::string login;//поле логина
	std::string password;// поле пароля
public:
	bool managerInterLogPass; //управляем работой функции
}