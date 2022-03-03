#include <iostream>
#include <string>
using namespace std;

struct App
{
	bool custom_sys;
};

void reverse(string & s)
{
	int n = s.size() - 1;
	for (int i = 0; i <= n / 2; i++)
	{
		swap(s[i], s[n - i]);
	}
}

string itostr(int a)
{
	string res;
	while (a > 9)
	{
		int b = a % 10;
		b += 48;
		res.push_back(b);
		a /= 10;
	}
	a += 48;
	res.push_back(a);
	reverse(res);
	return res;
}

void settings(App & app)
{
	bool set = 1;
	while (set)
	{
		cout << "\t SETTINGS MENU" << endl;
		cout << "1. Use custom number system = " << app.custom_sys << endl;
		cout << "0. Exit" << endl;
		cout << "Input number to change a flag: " << endl;
		int a;
		cin >> a;
		switch (a)
		{
		case 1:
			app.custom_sys = !app.custom_sys;
			break;
		case 0:
			set = 0;
			break;
		default:
			cout << "Input error try again!" << endl;
		}
	}
}

string f(int x, int y)
{
	string result;
	if (y > 1 && y < 17)
	{
		while (x >= y)
		{
			int temp = x % y;
			if (temp > 9)
			{
				char chars []= "ABCDEFGHIJKLMNOPQRSTUVWXYS";
				result += chars[temp - 10];
			}
			else
			{
				result += itostr(x % y);
			}
			x /= y;
		}

	}
	else
	{
		result = "Unavailable number system. Try another.";
		return result;
	}
	if (x > 9)
	{
		switch (x)
		{
		case 10:
			result += 'A';
			break;
		case 11:
			result += 'B';
			break;
		case 12:
			result += 'C';
			break;
		case 13:
			result += 'D';
			break;
		case 14:
			result += 'E';
			break;
		case 15:
			result += 'F';
			break;
		}
	}
	else
	{
		result += itostr(x);
	}
	reverse(result);
	return result;
}

void view_result(App app, int num, int sys)
{
	if (!app.custom_sys)
	{
		cout << "=============" << endl;
		cout << "10 sys : " << num << endl;
		cout << "2 sys  : " << f(num, 2) << endl;
		cout << "8 sys  : " << f(num, 8) << endl;
		cout << "16 sys : " << f(num, 16) << endl;
		cout << "=============" << endl;
	}
	else
	{
		cout << "Result = " << f(num, sys) << endl;
	}
}

int main()
{
	App app;
	app.custom_sys = false;
	int num, sys(2);
	while (true)
	{
		cout << "Input a number in 10 system or input 0 to go settings:" << endl;
		cin >> num;
		if (num == 0)
		{
			settings(app);
			continue;
		}
		if (app.custom_sys)
		{
			cout << "Input a number of system: " << endl;
			cin >> sys;
		}
		view_result(app, num, sys);
	}
	return 0;
}
