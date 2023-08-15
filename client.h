#pragma once
#pragma once
#include <iostream>
// Максимальный размер буфера для приема и передачи
#define MESSAGE_BUFFER 4096
#define PORT 7777 // номер порта, который будем использовать для приема и передачи
void sendMess(std::string clientMessage); // формирование строки для  отправки сообщения серверу
std::string  recivMess(char arryChar[]);  //формирование сообщения для полученная с сервера
void sendRequest();
