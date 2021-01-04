//class.h
#ifndef _CLASS_H
#define _CLASS_H
#include<mysql.h>
#include <winsock.h>
#include <iostream>
using namespace std;

MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
MYSQL_RES *res;       // ��ѯ��������ṹ����
MYSQL_FIELD *fd ;     // �����ֶ���Ϣ�Ľṹ
MYSQL_ROW row ;       // ���һ�в�ѯ������ַ�������

class Database
{
	public :
		void input_all_data()
		{
		   char qbuf[500];
		   sprintf(qbuf, "use drug_management_system;");//�����ݿ����ָ��Ƶ��ַ�������
		   mysql_query(&mysql, qbuf);//�����ݿ���в���
		   sprintf(qbuf, "CREATE TABLE drug(drug_id VARCHAR(100) NOT NULL,drug_title NVARCHAR(100) NOT NULL,Manufacturers NVARCHAR(100) NOT NULL,Date_of_production date default NULL,shelf_life INT NOT NULL,purposes NVARCHAR(100) NOT NULL,price INT NOT NULL,num INT NOT NULL,hands_on NVARCHAR(100) NOT NULL,PRIMARY KEY (drug_id));");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('001','essential balm','Tianjin Pharmaceutical Factory','2020-10-18','24','External','14','24','Li ming' );");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('002','Quick','Shanghai Pharmaceutical Factory','2020-10-22','24','Cold medicine','11','10','Wang fei');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('003','wuji baifeng pills','Beijing Pharmaceutical Factory','2020-9-30','12','Gynaecological drugs','15','23','Wang Wei');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('004','BABY COLD GRANULES','Beijing Pharmaceutical Factory','2020-10-11','12','Cold medicine','12','30','Wang Yong');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('005','Zinc glucosate oral solution','Harbin Pharmaceutical Factory','2020-10-22','24','Health care medicine','110','8','Li ming');");
		   mysql_query(&mysql, qbuf);
		};
		void print_all_data()
		{
		   char qbuf[500];
		   sprintf(qbuf, "SELECT * FROM drug;");
		   mysql_query(&mysql, qbuf);
		   mysql_query(&mysql, "select * from drug");//��������
		   res=mysql_store_result(&mysql);
		   int n;
		   n=mysql_field_count(&mysql);//��ȡ�ֶ���
		   cout<<"ҩƷ���       ҩƷ����        ��������                      ��������       ������     ��;     �۸�    ����       ������"<<endl;
		   while (row = mysql_fetch_row(res))
		   {				  
			for(int i=0;i<n;i++)
				printf("%s     ",row[i]);
				cout<<endl;		
		   };
		}

		void drug_input_data()
		{
			system("cls");
			getchar();//��ֹ��ȡ��������
			//���ҩƷ��Ϣ
			cout<<"������Ҫ��ӵ�ҩƷ���"<<endl;
			cin.getline(drug_id,10);
			cout<<"������Ҫ��ӵ�ҩƷ����"<<endl;
			cin.getline(drug_title,20);
			cout<<"������Ҫ��ӵ�ҩƷ��������"<<endl;
			cin.getline(Manufacturers,100);
			cout<<"������Ҫ��ӵ�ҩƷ��������"<<endl;
			cin.getline(Date_of_production,50);
			cout<<"������Ҫ��ӵ�ҩƷ������"<<endl;
			cin>>shelf_life;
			getchar();//��ֹ��ȡ��������
			cout<<"������Ҫ��ӵ�ҩƷ��;"<<endl;
			cin.getline(purposes,50);
			cout<<"������Ҫ��ӵ�ҩƷ�۸�"<<endl;
			cin>>price;
			cout<<"������Ҫ��ӵ�ҩƷ����"<<endl;
			cin>>num;
			getchar();//��ֹ��ȡ��������
			cout<<"������Ҫ��ӵ�ҩƷ������"<<endl;
			cin.getline(hands_on,30);
			//д�����ݿ�
			sprintf(qbuf, "INSERT INTO drug VALUES('%s','%s','%s','%s','%d','%s','%d','%d','%s');",drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on);
			mysql_query(&mysql, qbuf);
		
		};
		void change_data()
		  {
			  char qbuf[200],id_title[50];
			  char temp[50],temp1[50];
			  int t;
			  cout<<"������Ҫ�޸ĵ�ҩƷ��Ż�����: "<<endl;
			  cin>>id_title;
			  sprintf(qbuf, "select * from  drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);
	          mysql_query(&mysql, qbuf);
			  cout<<"������Ҫ�޸ĵ�������: "<<endl;
			  cin>>temp;
			  cout<<"������Ҫ�޸ĵ�ֵ: "<<endl;
			  if(temp[0]=='s' || (temp[0]=='p' && temp[1]=='r') || temp[0]=='n')//�޸�Ԫ�����ԶԱ�
			   {
				   cin>>t;
				   sprintf(qbuf, "UPDATE drug SET %s='%d' where drug_id='%s' or drug_title ='%s';",temp,t,id_title,id_title);
	               mysql_query(&mysql, qbuf);
				   cout<<"�޸ĳɹ�!  "<<endl;
			   }
			   else
			   {
				   cin>>temp1;
				   sprintf(qbuf, "UPDATE drug SET %s='%s' where drug_id=%s or drug_title =%s;",temp,temp1,id_title,id_title);
				   mysql_query(&mysql, qbuf);
				   cout<<"�޸ĳɹ�!  "<<endl;
			   }
		  };
		  void delete_data()
		  {
			  char qbuf[200],id_title[50];
			  cout<<"������Ҫɾ����ҩƷ��Ż�����: "<<endl;
			  cin>>id_title;
			  sprintf(qbuf, "delete from  drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);
	          mysql_query(&mysql, qbuf);
		  };
private:
	char drug_id[10],drug_title[20],Manufacturers[100],Date_of_production[50],purposes[50],hands_on[30],qbuf[500];
	int shelf_life,price,num;


};

class Drug :public Database
{
  public:
		void print_data()
		{
		  char qbuf[500],id_title[50];
		  system("cls");
		  cout<<"������Ҫ��ѯ��ҩƷ��Ż�����: "<<endl;
		  cin>>id_title;//��ȡҪ��ѯ��ҩƷ��Ϣ�ؼ���
		  sprintf(qbuf, "SELECT * FROM drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);//ͨ�����ݿ���в�ѯ
		  mysql_query(&mysql, qbuf);
		  mysql_query(&mysql, "select * from drug;");//��������
		  res=mysql_store_result(&mysql);
		  int n;
		  n=mysql_field_count(&mysql);//��ȡ�ֶ���
		  cout<<"ҩƷ���       ҩƷ����        ��������                      ��������       ������     ��;     �۸�    ����       ������"<<endl;
		  while (row = mysql_fetch_row(res))
		  {
			for(int i=0;i<n;i++)
			 printf("%s     ",row[i]);
			cout<<endl;
		  }
		};
		    
private:
	char drug_id[10],drug_title[20],Manufacturers[100],Date_of_production[50],purposes[50],hands_on[30],qbuf[500];
	int shelf_life,price,num;

};


#endif