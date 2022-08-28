#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
using namespace std;
class Complex
{
	float Mag, Phase;
public:	
	Complex() 
	{
		Mag = 0;
		Phase = 0;
	}
	void SetC(float x,float y)
	{
		Mag = sqrt(x * x + y * y);
		Phase = atan2(y, x);
	}
float	GetReal()
{
	float r;
	r = Mag * cos(Phase);
	return r;
}
float	GetImj()
{
	float i;
	i = Mag * sin(Phase);
	return i;
}
float	GetMag()
{
	return Mag;
}
float	GetPhase()
{
	return Phase;
}
Complex operator +(Complex x)
{
	Complex res;
	res.SetC(Mag * cos(Phase) + x.GetReal(), Mag * sin(Phase) + x.GetImj());
	return res;
}
Complex operator -(Complex x)
{
	Complex res;
	res.SetC(Mag * cos(Phase) - x.GetReal(), Mag * sin(Phase) - x.GetImj());
	return res;
}
Complex operator *(Complex x)
{
	Complex res;
	float mr, pr;
	mr = Mag * x.Mag;
	pr = Phase + x.Phase;
	res.SetC(mr * cos(pr), mr * sin(pr));
	return res;
}
void PrintC()
{
	float r, i;
	r = Mag * cos(Phase);
	i = Mag * sin(Phase);
	if (i>=0)
	{
		cout << r << "+" << i << "i";
	}
	else if (i<0)
	{
		cout << r << "-" << -i << "i";
	}
}
void set_str(string i1) {
	string x;
		float re = atof(i1.c_str());
		int l0;
		ostringstream m;
		m << re;
		string o = m.str();
		l0 = o.length();
		x = i1.substr(l0);
		float imj = atof(x.c_str());
	
	Mag = sqrt(re * re + imj * imj);
	Phase = atan2(imj, re);
	}


};
int main() {
	Complex x[100][100], y[100][100], z[100][100], x1[100][100], y1[100][100], z1[100][100];
	string s, supp, s1, supp1, sout = "[";
	char o;
	getline(cin, s);
	cin >> o;
	cin.ignore();
	getline(cin, s1);
	int l = s.length(), p, c = 0, r = 0, l1 = s1.length(), p1, c1 = 0, r1 = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '[')
		{
			supp = s.substr(i + 1);
			x[r][c].set_str(supp);
			c++;
		}
		if (s[i] == ' ')
		{
			supp = s.substr(i + 1);
			x[r][c].set_str(supp);
			c++;
		}
		if (s[i] == ';')
		{
			c = 0;
			r++;
			supp = s.substr(i + 1);
			x[r][c].set_str(supp);
			c++;
		}
	}r++;
	for (int i = 0; i < l1; i++)
	{
		if (s1[i] == '[')
		{
			supp = s1.substr(i + 1);
			y[r1][c1].set_str(supp);
			c1++;
		}
		if (s1[i] == ' ')
		{
			supp = s1.substr(i + 1);
			y[r1][c1].set_str(supp);
			c1++;
		}
		if (s1[i] == ';')
		{
			c1 = 0;
			r1++;
			supp = s1.substr(i + 1);
			y[r1][c1].set_str(supp);
			c1++;
		}
	}r1++;
	if (o == '+')
	{
		if ((c == c1) && (r == r1))
		{
			cout << "[";
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					z[i][j] = x[i][j] + y[i][j];
					if (j == c - 1)
					{
						 z[i][j].PrintC();
					}
					else
					{
						z[i][j].PrintC();
						cout<< " ";
					}
				}
				if (i == r - 1)
				{
					cout<< "]";
				}
				else
				{
					cout<< ";";
				}
			}
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
			cout << "[";
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					z[i][j] = x[i][j] - y[i][j];
					if (j == c - 1)
					{
						z[i][j].PrintC();
					}
					else
					{
						z[i][j].PrintC();
						cout << " ";
					}
				}
				if (i == r - 1)
				{
					cout << "]";
				}
				else
				{
					cout << ";";
				}
			}
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
			cout << "[";
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c1; j++)
				{
					Complex sum ;
					for (int k = 0; k < c; k++)
					{
						sum = sum + (x[i][k] * y[k][j]);
					}
					z[i][j] = sum;
					if (j == c1 - 1)
					{
						z[i][j].PrintC();
					}
					else
					{
						z[i][j].PrintC();
						cout << " ";
					}
				}
				if (i == r - 1)
				{
					cout<< "]";
				}
				else
				{
					cout<< ";";
				}
			}
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
	return 0;

}


