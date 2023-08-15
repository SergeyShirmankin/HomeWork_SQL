#pragma once
#include <iostream>
#include <string>

class Log_pass
{
public:
	Log_pass();//Конструктор по умолчанию
	void parserMessage(char arrChar[]);
	void set_PasswUser(const std::string&);
	void set_NameUserSend(const std::string&);
	void set_NameUserRecive(const std::string&);
	void set_Request(const std::string&);
	void set_CurrentState(const std::string&);
	void set_Messaqge(const std::string&);
	void set_NumMess(const std::string&);  //количество сообщени
	void set_NumCurrMess(const std::string&); //номер сообщения
	void set_StateProgram(int);
	void addLogPass();

	std::string& get_PasswordUser();
	std::string& get_NameUserSend();
	std::string& get_NameUserRecive();
	std::string& get_Request();
	std::string& get_CurrentState();
	std::string& get_Messaqge();
	std::string get_StateProgram();
	std::string& get_NumMess();  //количество сообщени
	std::string& get_NumCurrMess(); //номер сообщения
//-----------------------------------------------------------------------
private:
	int countObjectLogPass;//счетчик обьектов логов и паролей
	std::string StateProgram;

	std::string PasswordUser;//Пароль пользователя  отправителя сообщения
	std::string NameUserSend;// Имя пользователя  отправителя сообщения
	std::string NameUserRecive;//  Имя пользователя принимающего сообщения
	std::string Request;// Запрос на измененимя состояния (команда)
	std::string CurrentState;//Текущее состояние программы
	std::string NumCurrMess; //номер сообщения
	std::string NumMess;  //количество сообщени
	std::string Messaqge;
};
