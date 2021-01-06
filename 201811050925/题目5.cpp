#include "iostream"
using namespace std;

int main()
{
	double a, b;
	char op;
	cin>>a;
	while (cin>>op&&op!='=')
	{
		cin>>b;
		if (op == '+')
		{
			a = a+b;
		}
		else if (op == '-')
		{
			a = a-b;
		}
		else if (op == '*')
		{
			a = a*b;
		}
		else if (op == '/')
		{
			a = a/b;
		}
	}
	cout<<a<<endl;
	return 0;
}
