#pragma once
#include<string>
using namespace std;

class RLogin //���� � ������� �������������� � ������� ����� ������
{
public:
	RLogin();
	RLogin(string login, string password);
	RLogin(string login, string password, string name);
	void updateLogin(string login); // ��������� _login, ����� ����� �����
	void updateName(string name); // ��������� _name, ����� ����� ���
	void updatePassword(string password); // ��������� _password, ����� ����� ������
	bool getCheck(); // ������� ������������
	string getCurrentUser(); // ���������� ����� �������� ������������
	string getCurrentUserName(); // ���������� ��� �������� ������������
	int getIn(); // ���������� ����� �������� ������������
	~RLogin() = default;
protected:
	int users = 0; // ���-�� �������������
	bool check = false; // �������� �� ���������� � _login
	int index = 0; // ����� ������������� �������� � _login � _password
	int in = 0; // ����� �������� ������������
	string* _login = new string[0]; // ������ �������
	string* _name = new string[0]; // ������ ���
	string *_password = new string[0]; // ������ �������
};
class Message
{
public:
	Message();
	Message(string msg, string sender, string sendern);
	void updateArrays(string msg, string sender, string sendern); // ���������� �������� _to, _sender, _sendern, _msg
	void updateTo(string to); // ���������� ������� ���������
	void updateSender(string sender); // ���������� ������� ������������
	void updateSenderName(string sendern); // ���������� ������� ��� ������������
	void updateMsg(string msg); // ���������� ������� ���������
	void showMessages(string user); // ����� ���������
	~Message() = default;
protected:
	int count_messages = 0; // ������� ���������
	int msgs_to_current_user = 0; // ������� ��������� ��� ����������� ������������
	string* _to = new string[0]; // ������ ���������
	string* _sender = new string[0]; // ������ ������������
	string* _sendern = new string[0];// ������ ��� ������������
	string* _msg = new string[0]; // ������ ���������
};