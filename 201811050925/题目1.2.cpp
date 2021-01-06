#include"stdio.h"
#include"iostream"
using namespace std;

void function_connect(int &a,int &b,int &c)
{
	int temp_Thousand,temp_Hundred,temp_Ten,temp_Ones;
	temp_Ten=a/10;
	temp_Thousand=a%10;
	temp_Hundred=b%10;
	temp_Ones=b/10;
	
	c=temp_Thousand*1000+temp_Hundred*100+temp_Ten*10+temp_Ones;
 } 
 
 int main()
 {
 	int a,b,com;
 	cin>>a>>b;
 	function_connect(a,b,com);
 	cout<<com<<endl;
 }
 
