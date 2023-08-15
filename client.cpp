//---------------------------------------------------------------------------
void sendRequest() {
	bool autorization = false;//���������� ��� ������������
	 // ������ ����� �������
	serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	// ������� ����� ����� ��� ���������� � ��������
	serveraddress.sin_port = htons(PORT);
	// ���������� IPv4
	serveraddress.sin_family = AF_INET;
	// �������� �����
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	// ��������� ���������� � ��������
	PrevMess objPrevMess;
	bool breakCicle = false;
	Logic shema1;

	if (connect(socket_descriptor, (struct sockaddr*) & serveraddress, sizeof(serveraddress)) < 0)
	{
		std::cout << std::endl << " Something went wrong Connection Failed" << std::endl;
		exit(1);
	}

	while (1)
	{
		if (autorization == false)
		{
			std::cout << "��� ���������� ������ ��������  --end--   ���  --log--  ��� �������� ������ � ������  --enter-- ����������� �� ������� " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			if (tempMessage.compare("end ") == 0)
			{ //��������� ���������� ��� ������� ��������� "end"
				sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));
				std::cout << "������ ������  ������.!" << std::endl;
				close(socket_descriptor);
				exit(0);
			}
			else if (tempMessage.compare("log ") == 0)
			{
				tempMessage = objPrevMess.InterfaceLogPass(objPrevMess.managerInterLogPass);//�������� ��������� ���� ��� �������� ������ � ������ ��� ����������� �� �������
				strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			}
			else if (tempMessage.compare("enter ") == 0)
			{
				tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//����������� ��� ������� � �������
				strcpy(message, tempMessage.c_str());
			}
		}
		else
			//-------------------------------------------------------------------------------------------------------------------------
			//-----------------------------��������� ������ ������������---------------------------------------------------------------
			//-------------------------------------------------------------------------------------------------------------------------
		{
			//  activatedUser(shema1);

			char key;
			int countUsers = -1;
			while (shema1.temp1 == true)
			{
				// breakCicle=false;
				std::cout << "\n��� ������ ������� ������� '1' ��� ����������� ������� ����� �� � ent";
				std::cout << "\n>> ";
				std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
				tempMessage = tempCin + " " + tempMessage;
				if (tempMessage.compare("1 ") == 0)
				{
					shema1.signal1 = true;
					treeger(shema1);
					shema1.signal1 = false;
				}
				if (shema1.temp1 == false)
				{
					tempMessage = "*--:--:--:--:--:--:--:--&";//��������� ������ ���������
					strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
					break;
				}
				else
				{
					shema1.signal2 = true;
					treeger(shema1);
					shema1.signal2 = false;

					if (shema1.temp1 == false)
					{
						tempMessage = "*--:--:--:--:--:--:--:--&";//��������� ������ ���������
						strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
						break;
					}
					std::string resultStr = "*--:--:--:9:--:1:1:--&";
					strcpy(message, resultStr.c_str());//����������� ������ � ������ char
					sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));//�������� ��������� �������
				   // std::cout << "��������� ������� ���� ����������� �� ������:  " <<  message << std::endl;
					std::cout << "��������� ������� ���� ����������� �� ������:  " << std::endl;
					std::cout << "��������� ������ �� ������� ..." << std::endl;
					recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr); //��������� ��������� �� �������
					objLogPass.parserMessage(buffer);
					tempStateProgram = objLogPass.get_CurrentState();
					int res = std::stoi(objLogPass.get_NumMess());
					if (tempStateProgram.compare("10") == 0)// �������� �������� ���� � ������
					{
						for (int localTemp = 0; localTemp < res; localTemp++)
						{
							std::cout << "\n>> ��������� ��������� �� �������\n ";
							std::cout << ">> Online users " << objLogPass.get_Messaqge() << std::endl;
							std::string    resultStr = "*--:--:--:--:--:--:--:--&";
							strcpy(message, resultStr.c_str());//����������� ������ � ������ char
							sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));
							recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr);  //������������� ���������
							objLogPass.parserMessage(buffer);//������� ���������
						}
						std::cout << "\nStart Session[" << objLogPass.get_NameUserSend() << "]:\n";
						std::cout << "Hello " << objLogPass.get_NameUserSend() << "\n";
					}
				}
			}

		}
		//--------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------------------------------------


		sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));//�������� ��������� �������
		std::cout << "��������� ������� ���� ����������� �� ������:  " << message << std::endl;
		std::cout << "��������� ������ �� ������� ..." << std::endl;

		//std::cout << "��������� ��������� �� ������� " << std::endl;
		recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr); //��������� ��������� �� �������
		objLogPass.parserMessage(buffer);
		//std::cout << "��������� ��������� �� ������� " << std::endl;

		tempStateProgram = objLogPass.get_CurrentState();
		std::string  tempRequestProgram = objLogPass.get_Request();
		if (tempStateProgram.compare("3") == 0)// �������� �������� ���� � ������
		{
			std::cout << "\n>> ��������� ��������� �� �������\n ";
			std::cout << ">> �������� �������� ���� � �������!!!\n";
		}
		else if (tempStateProgram.compare("4") == 0)//�� ������� �������  ��� �������
		{
			std::cout << "\n>> ��������� ��������� �� �������\n ";
			std::cout << ">> �� ������� ������� ����� �������!!!\n ";
		}
		else if (tempStateProgram.compare("5") == 0)//����� ����� � ������ ��� ����
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> ����� ������ ��� ����!!!\n";
		}
		else if (tempStateProgram.compare("7") == 0 && tempRequestProgram.compare("6") == 0)//�������� �����������
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> �������� �����������!!!!\n";
			autorization = true;
			//             objLogPass.set_CurrentState("--");
		}
		else if (tempStateProgram.compare("8") == 0)//���� �������
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> ���� �������!!!\n";
		}
		else
		{
			std::cout << "������ �� �������� " << std::endl;;
		}
		// objLogPass.addLogPass();
		// std::cout << "��������� ��������� �� ������� >> " << buffer << std::endl;
		// std::cout <<  buffer << std::endl;
	}

	// ��������� �����, ��������� ����������
	close(socket_descriptor);
}

//---------------------------------------------------------------------------
void sendRequest() {
	bool autorization = false;//���������� ��� ������������
	 // ������ ����� �������
	serveraddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	// ������� ����� ����� ��� ���������� � ��������
	serveraddress.sin_port = htons(PORT);
	// ���������� IPv4
	serveraddress.sin_family = AF_INET;
	// �������� �����
	socket_descriptor = socket(AF_INET, SOCK_DGRAM, 0);
	// ��������� ���������� � ��������
	PrevMess objPrevMess;
	bool breakCicle = false;
	Logic shema1;

	if (connect(socket_descriptor, (struct sockaddr*) & serveraddress, sizeof(serveraddress)) < 0)
	{
		std::cout << std::endl << " Something went wrong Connection Failed" << std::endl;
		exit(1);
	}

	while (1)
	{
		if (autorization == false)
		{
			std::cout << "��� ���������� ������ ��������  --end--   ���  --log--  ��� �������� ������ � ������  --enter-- ����������� �� ������� " << std::endl;
			std::cout << ">>" << std::endl;
			std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
			tempMessage = tempCin + " " + tempMessage;
			strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			if (tempMessage.compare("end ") == 0)
			{ //��������� ���������� ��� ������� ��������� "end"
				sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));
				std::cout << "������ ������  ������.!" << std::endl;
				close(socket_descriptor);
				exit(0);
			}
			else if (tempMessage.compare("log ") == 0)
			{
				tempMessage = objPrevMess.InterfaceLogPass(objPrevMess.managerInterLogPass);//�������� ��������� ���� ��� �������� ������ � ������ ��� ����������� �� �������
				strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
			}
			else if (tempMessage.compare("enter ") == 0)
			{
				tempMessage = objPrevMess.enterLogPass(objLogPass.get_StateProgram());//����������� ��� ������� � �������
				strcpy(message, tempMessage.c_str());
			}
		}
		else
			//-------------------------------------------------------------------------------------------------------------------------
			//-----------------------------��������� ������ ������������---------------------------------------------------------------
			//-------------------------------------------------------------------------------------------------------------------------
		{
			//  activatedUser(shema1);

			char key;
			int countUsers = -1;
			while (shema1.temp1 == true)
			{
				// breakCicle=false;
				std::cout << "\n��� ������ ������� ������� '1' ��� ����������� ������� ����� �� � ent";
				std::cout << "\n>> ";
				std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
				tempMessage = tempCin + " " + tempMessage;
				if (tempMessage.compare("1 ") == 0)
				{
					shema1.signal1 = true;
					treeger(shema1);
					shema1.signal1 = false;
				}
				if (shema1.temp1 == false)
				{
					tempMessage = "*--:--:--:--:--:--:--:--&";//��������� ������ ���������
					strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
					break;
				}
				else
				{
					shema1.signal2 = true;
					treeger(shema1);
					shema1.signal2 = false;

					if (shema1.temp1 == false)
					{
						tempMessage = "*--:--:--:--:--:--:--:--&";//��������� ������ ���������
						strcpy(message, tempMessage.c_str());//����������� ������ � ������ char
						break;
					}
					std::string resultStr = "*--:--:--:9:--:1:1:--&";
					strcpy(message, resultStr.c_str());//����������� ������ � ������ char
					sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));//�������� ��������� �������
				   // std::cout << "��������� ������� ���� ����������� �� ������:  " <<  message << std::endl;
					std::cout << "��������� ������� ���� ����������� �� ������:  " << std::endl;
					std::cout << "��������� ������ �� ������� ..." << std::endl;
					recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr); //��������� ��������� �� �������
					objLogPass.parserMessage(buffer);
					tempStateProgram = objLogPass.get_CurrentState();
					int res = std::stoi(objLogPass.get_NumMess());
					if (tempStateProgram.compare("10") == 0)// �������� �������� ���� � ������
					{
						for (int localTemp = 0; localTemp < res; localTemp++)
						{
							std::cout << "\n>> ��������� ��������� �� �������\n ";
							std::cout << ">> Online users " << objLogPass.get_Messaqge() << std::endl;
							std::string    resultStr = "*--:--:--:--:--:--:--:--&";
							strcpy(message, resultStr.c_str());//����������� ������ � ������ char
							sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));
							recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr);  //������������� ���������
							objLogPass.parserMessage(buffer);//������� ���������
						}
						std::cout << "\nStart Session[" << objLogPass.get_NameUserSend() << "]:\n";
						std::cout << "Hello " << objLogPass.get_NameUserSend() << "\n";
					}
				}
			}

		}
		//--------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------------------------------------
		//--------------------------------------------------------------------------------------------------------------------------


		sendto(socket_descriptor, message, MESSAGE_BUFFER, 0, nullptr, sizeof(serveraddress));//�������� ��������� �������
		std::cout << "��������� ������� ���� ����������� �� ������:  " << message << std::endl;
		std::cout << "��������� ������ �� ������� ..." << std::endl;

		//std::cout << "��������� ��������� �� ������� " << std::endl;
		recvfrom(socket_descriptor, buffer, sizeof(buffer), 0, nullptr, nullptr); //��������� ��������� �� �������
		objLogPass.parserMessage(buffer);
		//std::cout << "��������� ��������� �� ������� " << std::endl;

		tempStateProgram = objLogPass.get_CurrentState();
		std::string  tempRequestProgram = objLogPass.get_Request();
		if (tempStateProgram.compare("3") == 0)// �������� �������� ���� � ������
		{
			std::cout << "\n>> ��������� ��������� �� �������\n ";
			std::cout << ">> �������� �������� ���� � �������!!!\n";
		}
		else if (tempStateProgram.compare("4") == 0)//�� ������� �������  ��� �������
		{
			std::cout << "\n>> ��������� ��������� �� �������\n ";
			std::cout << ">> �� ������� ������� ����� �������!!!\n ";
		}
		else if (tempStateProgram.compare("5") == 0)//����� ����� � ������ ��� ����
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> ����� ������ ��� ����!!!\n";
		}
		else if (tempStateProgram.compare("7") == 0 && tempRequestProgram.compare("6") == 0)//�������� �����������
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> �������� �����������!!!!\n";
			autorization = true;
			//             objLogPass.set_CurrentState("--");
		}
		else if (tempStateProgram.compare("8") == 0)//���� �������
		{
			std::cout << "\n>> ��������� ��������� �� ������� \n";
			std::cout << ">> ���� �������!!!\n";
		}
		else
		{
			std::cout << "������ �� �������� " << std::endl;;
		}
		// objLogPass.addLogPass();
		// std::cout << "��������� ��������� �� ������� >> " << buffer << std::endl;
		// std::cout <<  buffer << std::endl;
	}

	// ��������� �����, ��������� ����������
	close(socket_descriptor);
}

