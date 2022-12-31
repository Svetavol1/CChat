#include<iostream>
#include<string>
#include <windows.h>
#include"classes.h"
using namespace std;

int main()
{
	SetConsoleCP(1251); // установка ввода-вывода русского языка в консоль
	SetConsoleOutputCP(1251); // установка ввода-вывода русского языка в консоль
	setlocale(LC_ALL, "rus"); // установка ввода-вывода русского языка в консоль

	RLogin rlogs; // создаём хранилище данных пользователей
	Message msgs; // создаём хранилище сообщений пользователей

	while (true)
	{
		string login, password, name, msg; // создаём переменные для ввода данных
		bool check = false; // создаём переменную для хранения результата проверки на наличие в сообщении :
		while (login == "" || login == "everyone") // обработка пустого логина
		{
			cout << "Введите логин: ";
			getline(cin, login);
			if (login == "")
			{
				cout << "Поле <логин> не может быть пустым!\n";
			}
			if (login == "everyone")
			{
				cout << "Невозможно создать пользователя с таким логином!\n";
			}
		}
		if (login == "q") // выход из консоли
		{
			break;
		}
		rlogs.updateLogin(login); // заносим логин в "базу данных"
		if (rlogs.getCheck() == false) // проверяем на присутсвие в "базе данных" пользователя
		{
			while (name == "") // обработка пустого имени
			{
				cout << "Введите имя: ";
				getline(cin, name);
				if (name == "")
				{
					cout << "Поле <имя> не может быть пустым!\n";
				}
			}
		}
		rlogs.updateName(name); // заносим имя в "базу данных"
		while (password == "") // обработка пустого пароля
		{
			cout << "Введите пароль: ";
			getline(cin, password);
			if (password == "")
			{
				cout << "Поле <пароль> не может быть пустым!\n";
			}
		}
		rlogs.updatePassword(password); // заносим пароль в "базу данных"
		cout << "\n"; // для красоты

		msgs.showMessages(rlogs.getCurrentUser()); // показываем сообщения пользователю
		cout << "Для помощи введите help\n";
		while (msg != "q")
		{
			check = false; // обнуляем проверку сообщения
			cout << "Введите сообщение: ";
			try // обработка неверного ввода сообщения
			{
				getline(cin, msg);
				for (int i = 0; i < msg.length(); i++)
				{
					if (msg[i] == ':')
					{
						check = true;
						break;
					}
				}
				if (check == false)
				{
					throw "Неверно введено сообщение!\n";
				}
			}
			catch (...)
			{
				if (msg != "q" && msg != "help")
				{
					cout << "Неверно введено сообщение!\n";
					continue;
				}
			}
			if (msg != "q" && msg != "help")
			{
				msgs.updateArrays(msg, rlogs.getCurrentUser(), rlogs.getCurrentUserName()); // обновление хранилища сообщений
			}
			if (msg == "help")
			{
				cout << "\nОтправка сообщений происходит следующим образом:\n<логин пользователя>: <сообщение>\nДля отправки сообщения сразу всем пользователям:\neveryone: <сообщение>\nДля выхода из аккаунта введите q в поле <Введите сообщение:>, для выхода из консоли введите q в поле <Введите логин:>\n\n";
			}
		}
		cout << "\n"; // для красоты
	}

	return 0;
}