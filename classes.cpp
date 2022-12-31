#include<iostream>
#include<string>
#include"classes.h"
using namespace std;

void RLogin::updateLogin(string login) // ��������� ������ _login
{
	if (check == false) // �������� �� ���������� � "���� ������"
	{
		for (int i = 0; i < users; i++)
		{
			if (_login[i] == login)
			{
				check = true;
				index = i;
				return;
			}
		}
	}

	string* temp = new string[users]; // �������� ���������� ������� ��� ���������� _login
	for (int i = 0; i < users; i++)
	{
		temp[i] = _login[i]; // �������� ������ �� ��������� ������
	}
	delete[] _login; // ������� ������ _login
	_login = new string[users + 1]; // ������ ����������� _login
	for (int i = 0; i < users; i++)
	{
		_login[i] = temp[i]; // �������� ������ � �������� ������
	}
	_login[users] = login; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void RLogin::updateName(string name) // ��������� ������ _name
{
	if (check == true) // �������� �� ���������� � "���� ������"
	{
		return;
	}
	string* temp = new string[users]; // �������� ���������� ������� ��� ���������� _name
	for (int i = 0; i < users; i++)
	{
		temp[i] = _name[i]; // �������� ������ �� ��������� ������
	}
	delete[] _name; // ������� ������ _name
	_name = new string[users + 1]; // ������ ����������� _name
	for (int i = 0; i < users; i++)
	{
		_name[i] = temp[i]; // �������� ������ � �������� ������
	}
	_name[users] = name; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void RLogin::updatePassword(string password) // ��������� ������ _password
{
	if (check == true) // �������� �� ���������� � "���� ������"
	{
		if (_password[index] == password) // ��������� ������
		{
			cout << "���� �������� �������!" << "\n";
			check = false;
			in = index;
		}
		else
		{
			cout << "�������� ������!" << "\n";
		}
	}
	else
	{
		string* temp = new string[users]; // �������� ���������� �������
		for (int i = 0; i < users; i++)
		{
			temp[i] = _password[i]; // �������� ������ �� ��������� ������
		}
		delete[] _password; // ������� ������ _password
		_password = new string[users + 1]; // ����������� ������ _password
		for (int i = 0; i < users; i++) 
		{
			_password[i] = temp[i]; // �������� ������ �� ���������� ������� � ��������
		}
		_password[users] = password; // ��������� _password
		delete[] temp; // ������� ��������� ������
		users += 1; // ����������� ���-�� �������������
		in = users - 1; // ��������� ����� �������� ������������
	}
}
bool RLogin::getCheck() // ������ ���������� check (��� �������� �� ����������)
{
	return check; // ���������� 
}
int RLogin::getIn() // ������ ���������� in (��� ��������� ������� �������� ������������)
{
	return in;
}
string RLogin::getCurrentUser() // ������ ������ �������� ������������
{
	return _login[in];
}
string RLogin::getCurrentUserName() // ������ ����� �������� ������������
{
	return _name[in];
}
RLogin::RLogin() // ����������� ��� �������� ����������
{

}
RLogin::RLogin(string login, string password) // ����������� ��� ����� � �������
{
	setlocale(LC_ALL, "rus"); // ������������� ����� � ������� �� ������� �����

	updateLogin(login); // ��������� ����� RLogin ������� ��� ������ � �������
	updatePassword(password); // ��������� ����� RLogin ������� ��� ������ � �������
}
RLogin::RLogin(string login, string password, string name) // ����������� ��� ���������� ������ �������������
{
	setlocale(LC_ALL, "rus"); // ������������� ����� � ������� �� ������� �����

	updateLogin(login); // ��������� ����� RLogin ������� ��� ������ � �������
	updateName(name); // ��������� ����� RLogin ������ ��� ������ � �������
	updatePassword(password); // ��������� ����� RLogin ������� ��� ������ � �������
}

void Message::updateMsg(string msg) // ��������� ������ _msg
{
	string* temp = new string[count_messages]; // �������� ���������� ������� ��� ���������� _msg
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _msg[i]; // �������� ������ �� ��������� ������
	}
	delete[] _msg; // ������� ������ _msg
	_msg = new string[count_messages + 1]; // ������ ����������� _msg
	for (int i = 0; i < count_messages; i++)
	{
		_msg[i] = temp[i]; // �������� ������ � �������� ������
	}
	_msg[count_messages] = msg; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void Message::updateTo(string to) // ��������� ������ _to
{
	string* temp = new string[count_messages]; // �������� ���������� ������� ��� ���������� _to
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _to[i]; // �������� ������ �� ��������� ������
	}
	delete[] _to; // ������� ������ _msg
	_to = new string[count_messages + 1]; // ������ ����������� _to
	for (int i = 0; i < count_messages; i++)
	{
		_to[i] = temp[i]; // �������� ������ � �������� ������
	}
	_to[count_messages] = to; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void Message::updateSender(string sender) // ��������� ������ _sender
{
	string* temp = new string[count_messages]; // �������� ���������� ������� ��� ���������� _sender
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _sender[i]; // �������� ������ �� ��������� ������
	}
	delete[] _sender; // ������� ������ _sender
	_sender = new string[count_messages + 1]; // ������ ����������� _sender
	for (int i = 0; i < count_messages; i++)
	{
		_sender[i] = temp[i]; // �������� ������ � �������� ������
	}
	_sender[count_messages] = sender; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void Message::updateSenderName(string sendern) // ��������� ������ _sendern
{
	string* temp = new string[count_messages]; // �������� ���������� ������� ��� ���������� _sendern
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _sendern[i]; // �������� ������ �� ��������� ������
	}
	delete[] _sendern; // ������� ������ _sender
	_sendern = new string[count_messages + 1]; // ������ ����������� _sendern
	for (int i = 0; i < count_messages; i++)
	{
		_sendern[i] = temp[i]; // �������� ������ � �������� ������
	}
	_sendern[count_messages] = sendern; // ��������� �������� ������

	delete[] temp; // ������� ��������� ������
}
void Message::updateArrays(string msg, string sender, string sendern) // ��������� ��� ������� � ��������� ������ �� �������� � ���������
{
	string user; // ���������� ��� �������� ��������
	string message; // ���������� ��� �������� ������ ���������
	int ctrl = 0; // ���������� ��� �������� ������� :
	for (short i = 0; i < msg.length(); i++) // ����� :
	{
		if (msg[i] == ':')
		{
			ctrl = i;
			break;
		}
	}
	for (short i = 0; i < ctrl; i++) // ���������� �� �������� � ���������
	{
		user += msg[i];
	}
	for (short i = ctrl + 2; i < msg.length(); i++)// ���������� �� �������� � ���������
	{
		message += msg[i];
	}
	updateTo(user); // ��������� ������ ���������
	updateMsg(message); // ��������� ������ ���������
	updateSender(sender); // ���������� ������� ������������
	updateSenderName(sendern); // ���������� ������� ��� ������������
	count_messages++; // ���������� ���-�� ���������
}
void Message::showMessages(string user) // ���������� ��������� ������������
{
	for (int i = 0; i < count_messages; i++) // ���������� �� ���� ����������
	{
		if (_to[i] == user || (_sender[i] == user && _to[i] != "everyone")) // ����� ������ ���������, ��������� ������ ����
		{
			if (_sender[i] == user)
			{
				cout << "(��� " << _to[i] << ") " << _sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
				continue;
			}
			cout <<_sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
		}
		else if (_to[i] == "everyone" || (_sender[i] == user && _to[i] == "everyone")) // ����� ��������� ��� ����
		{
			cout << "(everyone) " << _sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
		}
	}
}
Message::Message(string msg, string sender, string sendern) // ����������� ��� �����-������ ���������
{
	updateArrays(msg, sender, sendern); // ���������� ���� ��������
}
Message::Message() // ����������� ��� �������� ����������
{

}