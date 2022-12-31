#include<iostream>
#include<string>
#include <windows.h>
#include"classes.h"
using namespace std;

int main()
{
	SetConsoleCP(1251); // ��������� �����-������ �������� ����� � �������
	SetConsoleOutputCP(1251); // ��������� �����-������ �������� ����� � �������
	setlocale(LC_ALL, "rus"); // ��������� �����-������ �������� ����� � �������

	RLogin rlogs; // ������ ��������� ������ �������������
	Message msgs; // ������ ��������� ��������� �������������

	while (true)
	{
		string login, password, name, msg; // ������ ���������� ��� ����� ������
		bool check = false; // ������ ���������� ��� �������� ���������� �������� �� ������� � ��������� :
		while (login == "" || login == "everyone") // ��������� ������� ������
		{
			cout << "������� �����: ";
			getline(cin, login);
			if (login == "")
			{
				cout << "���� <�����> �� ����� ���� ������!\n";
			}
			if (login == "everyone")
			{
				cout << "���������� ������� ������������ � ����� �������!\n";
			}
		}
		if (login == "q") // ����� �� �������
		{
			break;
		}
		rlogs.updateLogin(login); // ������� ����� � "���� ������"
		if (rlogs.getCheck() == false) // ��������� �� ���������� � "���� ������" ������������
		{
			while (name == "") // ��������� ������� �����
			{
				cout << "������� ���: ";
				getline(cin, name);
				if (name == "")
				{
					cout << "���� <���> �� ����� ���� ������!\n";
				}
			}
		}
		rlogs.updateName(name); // ������� ��� � "���� ������"
		while (password == "") // ��������� ������� ������
		{
			cout << "������� ������: ";
			getline(cin, password);
			if (password == "")
			{
				cout << "���� <������> �� ����� ���� ������!\n";
			}
		}
		rlogs.updatePassword(password); // ������� ������ � "���� ������"
		cout << "\n"; // ��� �������

		msgs.showMessages(rlogs.getCurrentUser()); // ���������� ��������� ������������
		cout << "��� ������ ������� help\n";
		while (msg != "q")
		{
			check = false; // �������� �������� ���������
			cout << "������� ���������: ";
			try // ��������� ��������� ����� ���������
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
					throw "������� ������� ���������!\n";
				}
			}
			catch (...)
			{
				if (msg != "q" && msg != "help")
				{
					cout << "������� ������� ���������!\n";
					continue;
				}
			}
			if (msg != "q" && msg != "help")
			{
				msgs.updateArrays(msg, rlogs.getCurrentUser(), rlogs.getCurrentUserName()); // ���������� ��������� ���������
			}
			if (msg == "help")
			{
				cout << "\n�������� ��������� ���������� ��������� �������:\n<����� ������������>: <���������>\n��� �������� ��������� ����� ���� �������������:\neveryone: <���������>\n��� ������ �� �������� ������� q � ���� <������� ���������:>, ��� ������ �� ������� ������� q � ���� <������� �����:>\n\n";
			}
		}
		cout << "\n"; // ��� �������
	}

	return 0;
}