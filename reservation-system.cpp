#include <iostream> 
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class password
{
private:
	int i, a;
public:
	password()
	{
		a = 0;
	}
	void reseta()
	{
		a = 0;
	}
	void seta()
	{
		unsigned seed;
		seed = (unsigned)time(NULL);
		srand(seed);
		a = rand() % 10000;
		for (i = 0; i < 10; i++)
		{
			if (a < 999)
			{
				a = rand() % 10000;
			}
			else
			{
				break;
			}
		}
	}
	int geta()
	{
		return a;
	}
};

void main(void)
{
	password r;
	int secs, p = 0, s, n;
	while (p == 0)
	{
		cout << "�O�_�n�w��(1:�O 0:�_) : ";
		cin >> n;
		if (n == 0)
		{
			break;
		}
		secs = 10;
		r.reseta();
		r.seta();
		p = r.geta();
		if (p > 0)
		{
			while (secs >= 0)
			{
				system("cls");
				cout << "�z���w���K�X��" << p << "\n";
				printf("�ѤU %d �����\n", secs--);
				Sleep(1000);
			}
			secs = 5;
			while (secs >= 0)
			{
				system("cls");
				printf("�ѤU %d �����U�@��\n", secs--);
				Sleep(1000);
			}
			system("cls");
			cout << "�п�J�w���K�X" << "\n";
			cout << "�K�X : ";
			cin >> s;
		}
		if (p == s)
		{
			cout << "�w��ϥ�" << "\n";
			Sleep(1000);
		}
		else
		{
			while (p != s)
			{
				system("cls");
				cout << "���~ ! �Э��s��J�w���K�X" << "\n";
				cout << "�K�X : ";
				cin >> s;
			}
			cout << "�w��ϥ�" << "\n";
		}
		p = 0;
		system("cls");
	}
	system("PAUSE");
}