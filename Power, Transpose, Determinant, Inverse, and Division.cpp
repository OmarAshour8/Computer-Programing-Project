#include <iostream>
#include <math.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
using namespace std;
int main() 
{
	float x[100][100], y[100][100],z[100][100],sum=1,sum1=0;
	string s, supp, sout = "[";
	char o;
	getline(cin, s);
	cin >> o;
	cin.ignore();
	int l = s.length(), p, c = 0, r = 0,f1,f2,fail=0,fail1=0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '[')
		{
			p = s.find(' ', i + 1) | s.find(';', i + 1) | s.find(']', i + 1);
			supp = s.substr(i + 1, p);
			x[r][c] = atof(supp.c_str());
			y[r][c] = x[r][c];
			c++;
		}
		if (s[i] == ' ')
		{
			p = s.find(' ', i + 1) | s.find(';', i + 1) | s.find(']', i + 1);
			supp = s.substr(i + 1, p - i);
			x[r][c] = atof(supp.c_str());
			y[r][c] = x[r][c];
			c++;
		}
		if (s[i]==']')
		{

			if ((r % 2 == 0)&&r>0)
			{
				f1 = c;
				if (f1 != f2)
				{
					fail = 1;
				}
			}
			if (r % 2 == 1)
			{
				f2 = c;
				if (f2 != f1)
				{
					fail = 1;
				}
			}

		}
		if (s[i] == ';')
		{
			if (r==0)
			{
				f1 = c;
			}
			if (r>0)
			{
				if (r%2==0)
				{
					f1 = c;
					if (f1!=f2)
					{
						fail = 1;
					}
				}
				if (r % 2 == 1)
				{
					f2 = c;
					if (f2 != f1)
					{
						fail = 1;
					}
				}
			}
			c = 0;
			r++;
			p = s.find(' ', i + 1) | s.find(']', i + 1);
			supp = s.substr(i + 1, p - i);
			x[r][c] = atof(supp.c_str());
			y[r][c] = x[r][c];
			c++;
		}
	}r++;
	if (o=='^')
	{
		if (r == c)
		{
			int power;
			cin >> power;
			if (power == 0)
			{
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
					{
						ostringstream Tr;
						if (i == j)
						{
							x[i][j] = 1;
						}
						if (i != j)
						{
							x[i][j] = 0;
						}
						Tr << x[i][j];
						if (j < c - 1)
						{
							sout = sout + Tr.str() + " ";
						}
						else if (j == c - 1)
						{
							sout = sout + Tr.str();
						}
					}
					if (i < r - 1)
					{
						sout += ";";
					}
					if (i == r - 1)
					{
						sout += "]";
					}
				}
				cout << sout;
			}
			else if (power == 1)
			{
				for (int i = 0; i < r; i++)
				{
					for (int j = 0; j < c; j++)
					{
						ostringstream Tr;
						Tr << x[i][j];
						if (j < (c - 1))
						{
							sout = sout + Tr.str() + " ";
						}
						else if (j == (c - 1))
						{
							sout = sout + Tr.str();
						}
					}
					if (i < r - 1)
					{
						sout += ";";
					}
					if (i == r - 1)
					{
						sout += "]";
					}
				}
				cout << sout;
			}
			else if (power > 1)
			{
				for (int i = 2; i <= power; i++)
				{
					for (int j = 0; j < r; j++)
					{
						for (int k = 0; k < c; k++)
						{
							float sum0 = 0;
							for (int i1 = 0; i1 < c; i1++)
							{
								sum0 += x[j][i1] * y[i1][k];
							}
							z[j][k] = sum0;
						}
					}
					for (int i2 = 0; i2 < r; i2++)
					{
						for (int i3 = 0; i3 < c; i3++)
						{
							y[i2][i3] = z[i2][i3];
						}
					}
				}
				for (int j1 = 0; j1 < r; j1++)
				{
					for (int j2 = 0; j2 < c; j2++)
					{
						ostringstream Tr;
						Tr << y[j1][j2];
						if (j2 < c - 1)
						{
							sout = sout + Tr.str() + " ";
						}
						if (j2 == c - 1)
						{
							sout += Tr.str();
						}
					}
					if (j1 < r - 1)
					{
						sout += ";";
					}
					if (j1 == r - 1)
					{
						sout += "]";
					}
				}
				cout << sout;
			}
		}
		else
		{
			cout << "ERROR";
		}
	}
	else if (o=='T')
	{	
		if (fail==0)
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					z[j][i] = x[i][j];
				}
			}
			for (int j1 = 0; j1 < c; j1++)
			{
				for (int j2 = 0; j2 < r; j2++)
				{
					ostringstream Tr;
					Tr << z[j1][j2];
					if (j2 < r - 1)
					{
						sout = sout + Tr.str() + " ";
					}
					if (j2 == r - 1)
					{
						sout += Tr.str();
					}
				}
				if (j1 < c - 1)
				{
					sout += ";";
				}
				if (j1 == c - 1)
				{
					sout += "]";
				}
			}cout << sout;
		}
		else if (fail==1)
		{
			cout << "ERROR";
		}
	}
	else if (o=='D')
	{
	if (c!=r)
	{
		cout << "ERROR";
	}
	else
	{
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i>j)
				{
					float k = -1 * (x[i][j] / x[j][j]);
					for (int l = 0; l < c; l++)
					{
						x[i][l] = x[i][l]+ k * x[j][l];
					}
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i==j)
				{
					if (x[i][j]==0)
					{
						sum = 0;
						break;
					}
					else 
					{
						sum *= x[i][j];
					}
				}
				
			}
		}
		cout << sum;
	}
	}
	else if (o=='I')
	{
	if (c!=r)
	{
		cout << "ERROR";
	}
	else
	{
		for (int i = 1; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i > j)
				{
					float k = -1 * (x[i][j] / x[j][j]);
					for (int l = 0; l < c; l++)
					{
						x[i][l] = x[i][l] + k * x[j][l];
					}
				}
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (i == j)
				{
					if (x[i][j] == 0)
					{
						sum = 0;
						fail1 = 1;
						break;
					}
					else
					{
						sum *= x[i][j];
					}
				}

			}
		}
		if (fail1==1)
		{
			cout << "ERROR";
		}
		else
		{
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					float u[100][100];
					for (int i0 = 0; i0 < r; i0++)
					{
						for (int j0 = 0; j0 < c; j0++)
						{
							if ((i0 < i) && (j0 < j))
							{
								u[i0][j0] = y[i0][j0];
							}
							if ((i0 < i) && (j0 > j))
							{
								u[i0][j0 - 1] = y[i0][j0];
							}
							if ((i0 > i) && (j0 < j))
							{
								u[i0 - 1][j0] = y[i0][j0];
							}
							if ((i0 > i) && (j0 > j))
							{
								u[i0 - 1][j0 - 1] = y[i0][j0];
							}
						}
					}
					for (int i1 = 1; i1 < r-1; i1++)
					{
						for (int j1 = 0; j1 < c-1; j1++)
						{
							if (i1 > j1)
							{
								float k = -1 * (u[i1][j1] / u[j1][j1]);
								for (int l1 = 0; l1 < c-1; l1++)
								{
									u[i1][l1] = u[i1][l1] + k * u[j1][l1];
								}
							}
						}
					}
					float sum2 = 1;
					for (int i2 = 0; i2 < r-1; i2++)
					{
						for (int j2 = 0; j2 < c-1; j2++)
						{
							if (i2 == j2)
							{
								if (u[i2][j2] == 0)
								{
									sum2 = 0;
									break;
								}
								else
								{
									sum2 *= u[i2][j2];
								}
							}
						}
					}
					z[i][j] = pow(-1, i + j) * sum2;
				}
			}
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					x[j][i] = z[i][j];
				}
			}
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
				{
					if (x[i][j]==0)
					{
						z[i][j] = 0;
					}
					else 
					{
						z[i][j] = (1 / sum) * x[i][j];
					}
					ostringstream Tr;
					Tr << z[i][j];
					if (j < c - 1)
					{
						sout += Tr.str() + " ";
					}
					if (j == c - 1)
					{
						sout += Tr.str();
					}
				}
				if (i < r - 1)
				{
					sout += ";";
				}
				if (i == r - 1)
				{
					sout += "]";
				}
			}cout << sout;
		}
	}
	}
	else if (o=='/')
	{
	float x1[100][100], y1[100][100], z1[100][100];
	string s1, supp1;
	getline(cin, s1);
	int c1 = 0, r1 = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '[')
		{
			supp1 = s1.substr(i + 1);
			x1[r1][c1] = atof(supp1.c_str());
			y1[r1][c1] = x1[r1][c1];
			c1++;
		}
		if (s1[i] == ' ')
		{
			supp1 = s1.substr(i + 1);
			x1[r1][c1] = atof(supp1.c_str());
			y1[r1][c1] = x1[r1][c1];
			c1++;
		}
		if (s1[i] == ';')
		{
			c1 = 0;
			r1++;
			supp1 = s1.substr(i + 1);
			x1[r1][c1] = atof(supp1.c_str());
			y1[r1][c1] = x1[r1][c1];
			c1++;
		}
	}r1++;
	if (c1 != r1)
	{
		cout << "ERROR";
	}
	else
	{
		for (int i = 1; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				if (i > j)
				{
					float k = -1 * (x1[i][j] / x1[j][j]);
					for (int l = 0; l < c1; l++)
					{
						x1[i][l] = x1[i][l] + k * x1[j][l];
					}
				}
			}
		}
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				if (i == j)
				{
					if (x1[i][j] == 0)
					{
						sum = 0;
						fail1 = 1;
						break;
					}
					else
					{
						sum *= x1[i][j];
					}
				}
			}
		}
		if (fail1 == 1)
		{
			cout << "ERROR";
		}
		else
		{
			for (int i = 0; i < r1; i++)
			{
				for (int j = 0; j < c1; j++)
				{
					float u[100][100];
					for (int i0 = 0; i0 < r1; i0++)
					{
						for (int j0 = 0; j0 < c1; j0++)
						{
							if ((i0 < i) && (j0 < j))
							{
								u[i0][j0] = y1[i0][j0];
							}
							if ((i0 < i) && (j0 > j))
							{
								u[i0][j0 - 1] = y1[i0][j0];
							}
							if ((i0 > i) && (j0 < j))
							{
								u[i0 - 1][j0] = y1[i0][j0];
							}
							if ((i0 > i) && (j0 > j))
							{
								u[i0 - 1][j0 - 1] = y1[i0][j0];
							}
						}
					}
					for (int i1 = 1; i1 < r1 - 1; i1++)
					{
						for (int j1 = 0; j1 < c1 - 1; j1++)
						{
							if (i1 > j1)
							{
								float k = -1 * (u[i1][j1] / u[j1][j1]);
								for (int l1 = 0; l1 < c1 - 1; l1++)
								{
									u[i1][l1] = u[i1][l1] + k * u[j1][l1];
								}
							}
						}
					}
					float sum2 = 1;
					for (int i2 = 0; i2 < r1 - 1; i2++)
					{
						for (int j2 = 0; j2 < c1 - 1; j2++)
						{
							if (i2 == j2)
							{
								if (u[i2][j2] == 0)
								{
									sum2 = 0;
									break;
								}
								else
								{
									sum2 *= u[i2][j2];
								}
							}
						}
					}
					z1[i][j] = pow(-1, i + j) * sum2;
				}
			}
			for (int i = 0; i < r1; i++)
			{
				for (int j = 0; j < c1; j++)
				{
					x1[j][i] = z1[i][j];
				}
			}
			for (int i = 0; i < r1; i++)
			{
				for (int j = 0; j < c1; j++)
				{
					if (x1[i][j] == 0)
					{
						z1[i][j] = 0;
					}
					else
					{
						z1[i][j] = (1 / sum) * x1[i][j];
					}
				}
			}
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
							sum = sum + (x[i][k] * z1[k][j]);
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
	}
	}
	else
	{
		cout << "ERROR";
	}
	system("pause");
	return 0;
}
