#include "stdio.h"
#include "iostream"
using namespace std;

main()
{
	new char;
	int M,N,i,j;
	cin>>M>>N;
	char a[M][N];
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(i==1&&j==1) a[i][j]='X';
			else if(j==7)  a[i][j]='P';
			else a[i][j]='O';
		}
	}
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	//输入周期
    int T=0;
    cin>>T;
    while(T)
    {
        //前四个for循环处理四周的边界的传染状态更新
        for(int i=0;i<M;i++)
        {
            if(a[1][i]=='X')
            {
                if (a[0][i]!='P')
                {
                    a[0][i]='X';
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(a[M][i]=='X')
            {
                if(a[M-1][i]!='P')
                {
                    a[M-1][i]='X';
                }
            }
        }
        for(int i=0;i<M;i++)
        {
            if(a[i][1]=='X')
            {
                if(a[i][0]!='P')
                {
                    a[i][0]='X';
                }
            }
        }
        for(int i=0;i<M;i++)
        {
            if(a[i][N]=='X')
            {
                if(a[i][N-1]!='P')
                {
                    a[i][N-1]='X';
                }
            }
        }
        //区域内传染状态更新
        for(int i=1;i<M-1;i++)
        {
            for(int j=1;j<N-1;j++)
            {
                if (a[i][j]=='X')
                {
                    if(a[i-1][j]!='P')
                    {
                      a[i-1][j]='X';
                    }
                    if(a[i][j-1]!='P')
                    {
                      a[i][j-1]='X';
                    }
                    if(a[i][j+1]!='P')
                    {
                      a[i][j+1]='X';
                    }
                    if(a[i+1][j]!='P')
                    {
                      a[i+1][j]='X';
                    }
                }
            }
        }
        T=T-1;
    }
    //输出更新后的传染状态
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

