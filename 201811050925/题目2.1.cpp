#include "iostream"
using namespace std;
int main()
{
	int m,n,last,count=1;		//last记猴子剩余个数，count记当前报数
	int monkey[999];
	int t;						//t记数组下标
	int i;
	cout<<"请输入猴子个数 m 和数数个数 n "<<endl;
    cin>>m>>n;
	last=m;
	for(i=0;i<m;i++)
		monkey[i]=i+1;
	t=0;
	while(last>1)
	{
		if(monkey[t]>0)
		{
			if(count!=n)
			{
				count++;
				t=(t+1)%m;		//t=(t+1)%m实现数组下标加1
			}
			else
			{
				monkey[t]=0;
				count=1;
				last--;
				t=(t+1)%m;
			}
		}
		else
		{
			t=(t+1)%m;
		}
	}
	for(i=0;i<m;i++)
	{
		if(monkey[i]>0)
			cout<<"所选猴子序号:"<<monkey[i]<<endl;
	}
	return 0;
}

