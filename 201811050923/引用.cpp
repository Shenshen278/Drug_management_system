#include <iostream>
using namespace std;
int fun_1(int &a,int &b,int &d)//ͨ������ֵ����������������
{
	int temp_1,temp_2,temp_3,temp_4;
	temp_1=a%10;//a��λ
	temp_2=a/10;//aʮλ
	temp_3=b%10;
	temp_4=b/10;
	d=temp_1*1000+temp_3*100+temp_2*10+temp_4;
}
int main()
{
	//ͨ������ֵ����������������
	int figure_1,figure_2;
	int temp;
	cout<<"������������λ��a��b:";
    cin>>figure_1>>figure_2;
	int fun_3(int a,int b);
	fun_1(figure_1,figure_2,temp);
	cout<<"�ϲ������Ϊ:"<<temp<<endl;
}
