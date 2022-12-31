#pragma once
#include<string>
using namespace std;

class RLogin //вход в систему осуществляется с помощью этого класса
{
public:
	RLogin();
	RLogin(string login, string password);
	RLogin(string login, string password, string name);
	void updateLogin(string login); // обновляет _login, внося новый логин
	void updateName(string name); // обновляет _name, внося новое имя
	void updatePassword(string password); // обновляет _password, внося новый пароль
	bool getCheck(); // наличие пользователя
	string getCurrentUser(); // возвращает логин текущего пользователя
	string getCurrentUserName(); // возвращает имя текущего пользователя
	int getIn(); // возвращает номер текущего пользователя
	~RLogin() = default;
protected:
	int users = 0; // кол-во пользователей
	bool check = false; // проверка на присутсвие в _login
	int index = 0; // номер существующего элемента в _login и _password
	int in = 0; // номер текущего пользователя
	string* _login = new string[0]; // массив логинов
	string* _name = new string[0]; // массив имён
	string *_password = new string[0]; // массив паролей
};
class Message
{
public:
	Message();
	Message(string msg, string sender, string sendern);
	void updateArrays(string msg, string sender, string sendern); // обновление массивов _to, _sender, _sendern, _msg
	void updateTo(string to); // обновление массива адресатов
	void updateSender(string sender); // обновление массива отправителей
	void updateSenderName(string sendern); // обновление массива имён отправителей
	void updateMsg(string msg); // обновление массива сообщений
	void showMessages(string user); // вывод сообщений
	~Message() = default;
protected:
	int count_messages = 0; // счётчик сообщений
	int msgs_to_current_user = 0; // счётчик сообщений для конкретного пользователя
	string* _to = new string[0]; // массив адресатов
	string* _sender = new string[0]; // массив отправителей
	string* _sendern = new string[0];// массив имён отправителей
	string* _msg = new string[0]; // массив сообщений
};