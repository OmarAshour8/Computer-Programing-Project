#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
using namespace std;
int main() {
	float x[100][100], y[100][100], z[100][100];
	string s, supp, s1, supp1, sout = "[";
	char o;
	getline(cin, s);
	cin>> o;
	cin.ignore();
	getline(cin, s1);
	int l = s.length(), p, c = 0, r = 0, l1 = s1.length(), p1, c1 = 0, r1 = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '[')
		{
			p = s.find(' ', i + 1);
			supp = s.substr(i + 1, p);
			x[r][c] = atof(supp.c_str());
			c++;
		}
		if (s[i] == ' ')
		{
			p = s.find(' ', i + 1) | s.find(';', i + 1) | s.find(']', i + 1);
			supp = s.substr(i + 1, p - i);
			x[r][c] = atof(supp.c_str());
			c++;
		}
		if (s[i] == ';')
		{
			c = 0;
			r++;
			p = s.find(' ', i + 1) | s.find(']', i + 1);
			supp = s.substr(i + 1, p - i);
			x[r][c] = atof(supp.c_str());
			c++;
		}
	}r++;
	for (int i = 0; i < l1; i++)
	{
		if (s1[i] == '[')
		{
			p1 = s1.find(' ', i + 1);
			supp1 = s1.substr(i + 1, p1);
			y[r1][c1] = atof(supp1.c_str());
			c1++;
		}
		if (s1[i] == ' ')
		{
			p1 = s1.find(' ', i + 1) | s1.find(';', i + 1) | s1.find(']', i + 1);
			supp1 = s1.substr(i + 1, p1 - i);
			y[r1][c1] = atof(supp1.c_str());
			c1++;
		}
		if (s1[i] == ';')
		{
			c1 = 0;
			r1++;
			p1 = s1.find(' ', i + 1) | s1.find(']', i + 1);
			supp1 = s1.substr(i + 1, p1 - i);
			y[r1][c1] = atof(supp1.c_str());
			c1++;
		}
	}r1++;
	if (o == '+')
	{
		if ((c == c1) && (r == r1))
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					ostringstream t;
					z[i][j] = x[i][j] + y[i][j];
					if (j == c - 1)
					{
						t << z[i][j];
						sout = sout + t.str();
					}
					else
					{
						t << z[i][j];
						sout = sout + t.str() + " ";
					}
				}
				if (i == r - 1)
				{
					sout = sout + "]";
				}
				else
				{
					sout = sout + ";";
				}
			}
			cout << sout;
		}
		else
		{
			cout << "ERORR";
		}
	}
	else if (o == '-')
	{
		if ((c == c1) && (r == r1))
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					ostringstream t;
					z[i][j] = x[i][j] - y[i][j];
					if (j == c - 1)
					{
						t << z[i][j];
						sout = sout + t.str();
					}
					else
					{
						t << z[i][j];
						sout = sout + t.str() + " ";
					}
				}
				if (i == r - 1)
				{
					sout = sout + "]";
				}
				else
				{
					sout = sout + ";";
				}
			}
			cout << sout;
		}
		else
		{
			cout << "ERORR";
		}
	}
	else if (o == '*')
	{
		if (c == r1)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c1; j++)
				{
					ostringstream t;
					float sum = 0;
					for (int k = 0; k < c; k++)
					{
						sum = sum + (x[i][k] * y[k][j]);
					}
					z[i][j] = sum;
					if (j == c1 - 1)
					{
						t << z[i][j];
						sout = sout + t.str();
					}
					else
					{
						t << z[i][j];
						sout = sout + t.str() + " ";
					}
				}
				if (i == r - 1)
				{
					sout = sout + "]";
				}
				else
				{
					sout = sout + ";";
				}
			}
			cout << sout;
		}
		else
		{
			cout << "ERORR";
		}

	}
	else
	{
		cout << "ERORR";
	}
	system("pause");
	return 0;

}

