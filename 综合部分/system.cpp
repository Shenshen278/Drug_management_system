#include<iostream>
#include<mysql.h>
#include <winsock.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <ctime>
#include"class.h"

using namespace std;

int main(int argc, char *argv[])
{
	Database drug_management_system;
	Drug drug_1;
    if (mysql_library_init(0, NULL, NULL))
    {
        printf("could not initialize MySQL library\n");
        getchar();
        exit(1);
    }
    mysql_init(&mysql);
    MYSQL *ret = mysql_real_connect(&mysql, "127.0.0.1", "root","201811050930","Drug_management_system",3306, NULL, 0);
	//MYSQL *ret = mysql_real_connect(&conn, "127.0.0.1", "root","201811050930","student",3306, NULL, 0);
	//                                         ��ַ     �û�����    ����      ���ݿ���  ����0����ֵ������TCP/IP���ӵĶ˿ں�
     if (!ret)
    {
        printf("Failed to connect to database:%s\n", mysql_error(&mysql));
        getchar();
        exit(1);
    }
    else {
        printf("success!\n");
    }

	drug_management_system.input_all_data();//����

	while(1)
	{
		system("cls");
		int operate;
		cout<<"*************************************"<<endl;
		cout<<"*          ҩƷ��Ϣ����ϵͳ         *"<<endl;
		cout<<"*                                   *"<<endl;
		cout<<"*��ѡ��Ҫ���еĲ�����               *"<<endl;
		cout<<"*1.��ѯҩƷ��Ϣ                     *"<<endl;
		cout<<"*2.����ҩƷ��Ϣ                     *"<<endl;
		cout<<"*3.ɾ��ҩƷ��Ϣ                     *"<<endl;
		cout<<"*4.�޸�ҩƷ��Ϣ                     *"<<endl;
		cout<<"*5.��ʾ����ҩƷ��Ϣ                 *"<<endl;
		cout<<"*0.�˳�                             *"<<endl;
		cout<<"*                                   *"<<endl;
		cout<<"*************************************"<<endl;

		cin>>operate;
		system("cls");
		char y_n;
		switch(operate)
		{
		   case 1:{
			   system("cls");
	           drug_1.print_data();
			   cout<<"�Ƿ����(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 2:{
			   system("cls");
	           drug_1.drug_input_data();
			   cout<<"�Ƿ����(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 3:{
			   system("cls");
			   drug_1.delete_data();
			   cout<<"�Ƿ����(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 4:{
			   system("cls");
			   drug_1.change_data();
			   cout<<"�Ƿ����(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 5:{
			   drug_management_system.print_all_data();
			   cout<<"�Ƿ����(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 0:{
			   mysql_close(&mysql);
			   cout<<"���˳�����лʹ�ã�"<<endl;
				  };	   
		   default :
			   cout<<"�����ָ����������������: "<<endl;
		}
	}
    return 0;
}
