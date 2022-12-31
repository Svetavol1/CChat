#include<iostream>
#include<string>
#include"classes.h"
using namespace std;

void RLogin::updateLogin(string login) // обновляет массив _login
{
	if (check == false) // проверка на присутсвие в "базе данных"
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

	string* temp = new string[users]; // создание временного массива для обновления _login
	for (int i = 0; i < users; i++)
	{
		temp[i] = _login[i]; // копируем данные во временный массив
	}
	delete[] _login; // очищаем старый _login
	_login = new string[users + 1]; // создаём увеличенный _login
	for (int i = 0; i < users; i++)
	{
		_login[i] = temp[i]; // копируем данные в основной массив
	}
	_login[users] = login; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void RLogin::updateName(string name) // обновляет массив _name
{
	if (check == true) // проверка на присутсвие в "базе данных"
	{
		return;
	}
	string* temp = new string[users]; // создание временного массива для обновления _name
	for (int i = 0; i < users; i++)
	{
		temp[i] = _name[i]; // копируем данные во временный массив
	}
	delete[] _name; // очищаем старый _name
	_name = new string[users + 1]; // создаём увеличенный _name
	for (int i = 0; i < users; i++)
	{
		_name[i] = temp[i]; // копируем данные в основной массив
	}
	_name[users] = name; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void RLogin::updatePassword(string password) // обновляет массив _password
{
	if (check == true) // проверка на присутсвие в "базе данных"
	{
		if (_password[index] == password) // проверяем пароль
		{
			cout << "Вход выполнен успешно!" << "\n";
			check = false;
			in = index;
		}
		else
		{
			cout << "Неверный пароль!" << "\n";
		}
	}
	else
	{
		string* temp = new string[users]; // создание временного массива
		for (int i = 0; i < users; i++)
		{
			temp[i] = _password[i]; // копируем данные во временный массив
		}
		delete[] _password; // очищаем старый _password
		_password = new string[users + 1]; // увеличиваем старый _password
		for (int i = 0; i < users; i++) 
		{
			_password[i] = temp[i]; // копируем данные из временного массива в основной
		}
		_password[users] = password; // дополняем _password
		delete[] temp; // удаляем временный массив
		users += 1; // увеличиваем кол-во пользователей
		in = users - 1; // указываем номер текущего пользователя
	}
}
bool RLogin::getCheck() // геттер переменной check (для проверки на присутсвие)
{
	return check; // возвращает 
}
int RLogin::getIn() // геттер переменной in (для получения индекса текущего пользователя)
{
	return in;
}
string RLogin::getCurrentUser() // геттер логина текущего пользователя
{
	return _login[in];
}
string RLogin::getCurrentUserName() // геттер имени текущего пользователя
{
	return _name[in];
}
RLogin::RLogin() // конструктор для создания переменной
{

}
RLogin::RLogin(string login, string password) // конструктор для входа в систему
{
	setlocale(LC_ALL, "rus"); // устанавливаем вывод в консоль на русском языке

	updateLogin(login); // заполняем класс RLogin логином или входим в аккаунт
	updatePassword(password); // заполняем класс RLogin логином или входим в аккаунт
}
RLogin::RLogin(string login, string password, string name) // конструктор для обновления списка пользователей
{
	setlocale(LC_ALL, "rus"); // устанавливаем вывод в консоль на русском языке

	updateLogin(login); // заполняем класс RLogin логином или входим в аккаунт
	updateName(name); // заполняем класс RLogin именем или входим в аккаунт
	updatePassword(password); // заполняем класс RLogin паролем или входим в аккаунт
}

void Message::updateMsg(string msg) // обновляет массив _msg
{
	string* temp = new string[count_messages]; // создание временного массива для обновления _msg
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _msg[i]; // копируем данные во временный массив
	}
	delete[] _msg; // очищаем старый _msg
	_msg = new string[count_messages + 1]; // создаём увеличенный _msg
	for (int i = 0; i < count_messages; i++)
	{
		_msg[i] = temp[i]; // копируем данные в основной массив
	}
	_msg[count_messages] = msg; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void Message::updateTo(string to) // обновляет массив _to
{
	string* temp = new string[count_messages]; // создание временного массива для обновления _to
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _to[i]; // копируем данные во временный массив
	}
	delete[] _to; // очищаем старый _msg
	_to = new string[count_messages + 1]; // создаём увеличенный _to
	for (int i = 0; i < count_messages; i++)
	{
		_to[i] = temp[i]; // копируем данные в основной массив
	}
	_to[count_messages] = to; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void Message::updateSender(string sender) // обновляет массив _sender
{
	string* temp = new string[count_messages]; // создание временного массива для обновления _sender
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _sender[i]; // копируем данные во временный массив
	}
	delete[] _sender; // очищаем старый _sender
	_sender = new string[count_messages + 1]; // создаём увеличенный _sender
	for (int i = 0; i < count_messages; i++)
	{
		_sender[i] = temp[i]; // копируем данные в основной массив
	}
	_sender[count_messages] = sender; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void Message::updateSenderName(string sendern) // обновляет массив _sendern
{
	string* temp = new string[count_messages]; // создание временного массива для обновления _sendern
	for (int i = 0; i < count_messages; i++)
	{
		temp[i] = _sendern[i]; // копируем данные во временный массив
	}
	delete[] _sendern; // очищаем старый _sender
	_sendern = new string[count_messages + 1]; // создаём увеличенный _sendern
	for (int i = 0; i < count_messages; i++)
	{
		_sendern[i] = temp[i]; // копируем данные в основной массив
	}
	_sendern[count_messages] = sendern; // дополняем основной массив

	delete[] temp; // удаляем временный массив
}
void Message::updateArrays(string msg, string sender, string sendern) // обновляет все массивы и разделяет строку на адресата и сообщение
{
	string user; // переменная для хранения адресата
	string message; // переменная для хранения самого сообщения
	int ctrl = 0; // переменная для хранения индекса :
	for (short i = 0; i < msg.length(); i++) // поиск :
	{
		if (msg[i] == ':')
		{
			ctrl = i;
			break;
		}
	}
	for (short i = 0; i < ctrl; i++) // разделение на адресата и сообщение
	{
		user += msg[i];
	}
	for (short i = ctrl + 2; i < msg.length(); i++)// разделение на адресата и сообщение
	{
		message += msg[i];
	}
	updateTo(user); // обновляем массив адресатов
	updateMsg(message); // обновляем массив сообщений
	updateSender(sender); // обновление массива отправителей
	updateSenderName(sendern); // обновление массива имён отправителей
	count_messages++; // увеличение кол-ва сообщений
}
void Message::showMessages(string user) // показывает сообщения пользователю
{
	for (int i = 0; i < count_messages; i++) // проходимся по всем сообщениям
	{
		if (_to[i] == user || (_sender[i] == user && _to[i] != "everyone")) // отбор личных сообщений, сообщений самому себе
		{
			if (_sender[i] == user)
			{
				cout << "(для " << _to[i] << ") " << _sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
				continue;
			}
			cout <<_sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
		}
		else if (_to[i] == "everyone" || (_sender[i] == user && _to[i] == "everyone")) // отбор сообщений для всех
		{
			cout << "(everyone) " << _sender[i] << " (" << _sendern[i] << ")" << ": " << _msg[i] << "\n";
		}
	}
}
Message::Message(string msg, string sender, string sendern) // конструктор для каких-нибудь сообщений
{
	updateArrays(msg, sender, sendern); // обновление всех массивов
}
Message::Message() // конструктор для создания переменной
{

}