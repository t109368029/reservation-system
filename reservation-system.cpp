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
		cout << "是否要預約(1:是 0:否) : ";
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
				cout << "您的預約密碼為" << p << "\n";
				printf("剩下 %d 秒消失\n", secs--);
				Sleep(1000);
			}
			secs = 5;
			while (secs >= 0)
			{
				system("cls");
				printf("剩下 %d 秒輪到下一位\n", secs--);
				Sleep(1000);
			}
			system("cls");
			cout << "請輸入預約密碼" << "\n";
			cout << "密碼 : ";
			cin >> s;
		}
		if (p == s)
		{
			cout << "歡迎使用" << "\n";
			Sleep(1000);
		}
		else
		{
			while (p != s)
			{
				system("cls");
				cout << "錯誤 ! 請重新輸入預約密碼" << "\n";
				cout << "密碼 : ";
				cin >> s;
			}
			cout << "歡迎使用" << "\n";
		}
		p = 0;
		system("cls");
	}
	system("PAUSE");
}