#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
void add_diary();
void view_diary();
void search_diary();
void delete_diary();
struct detail{
	int date;
	char day[10];
	char data[3000];
};
typedef struct detail diary;
FILE *fp;
diary d;
int main()
{
	int n,i;
	while(1)
	{
	system("COLOR 0E");
	cout<<"\t\t==================================\n";
	cout<<"\t\t\tYOUR PERSONEL DIARY"<<endl;
	cout<<"\t\t==================================\n";
	cout<<"\n\t\t\tADD DIARY      [1]\n\t\t\tVIEW DIARY     [2]\n\t\t\tSEARCH DIARY   [3]\n\t\t\tDELETE DIARY   [4]\n\t\t\tEXIT DIARY     [5]";
	cout<<"\n\t\t--------------------------------\n";
	cout<<"\t\t--------------------------------\n";
	cout<<"\t\tENTER VALID CHOICE: -\n\t\t";
	cin>>n;
	switch(n)
	{
		case 1:
			add_diary();
			break;
		case 2:
		    view_diary();
			break;
		case 3:
		    search_diary();
			break;
		case 4:
		    delete_diary();
			break;
		case 5:
			cout<<"\t\t\tPress Any Key To Exit\n";
			cout<<"\t\t====================================\n";
		    exit(0);
			break;
		default:
		    cout<<"\t\tInvalid Choice!\n\t\tTry Again......\n\n";
	}
	system("cls");
}
getch();
}
void add_diary()
{
	cout<<"\n\t\t       WELCOME TO ADD MENU";
	cout<<"\n\t\t--------------------------------\n";
	fp=fopen("diaryd.dat","ab")	;
	cout<<"\n\t\tEnter Date:- ";
    cin>>d.date;
    cout<<"\n\t\tEnter Day:- ";
    fflush(stdin);
    gets(d.day);
    cout<<"\n\t\tEnter Your Diary Content:- \n\t\t";
	gets(d.data);
	fwrite(&d,sizeof(d),1,fp);
	fclose(fp);
	cout<<"\n\t\t_______________________________\n";
	cout<<"\n\t\t\tADDED SUCCESSFULLY";
    getch();	
}
void view_diary()
{
	system("color 0A");
	cout<<"\n\t\t       WELCOME TO VIEW MENU";
	cout<<"\n\t\t--------------------------------\n";
	fp=fopen("diaryd.dat","rb")	;
	if(fp==NULL)
	cout<<"\t\t\t Diary Is empty";
	while(fread(&d,sizeof(d),1,fp)>0)
	{
		cout<<"\t\tDate: "<<d.date<<endl;
		cout<<"\t\tDay: "<<d.day<<endl;
		cout<<"\t\tDiary Content: "<<d.data<<endl;
	}
	 fclose(fp);
     cout<<"\n\n\t\t\tPRESS ANY KEY TO PROCEED NEXT--";
     cout<<"\n\t\t___________________________________________________\n\t\t";
    getch();
	
}
void search_diary()
{
	system("color 0b");
	int da,m=0;
	cout<<"\n\t\t       WELCOME TO SEARCH MENU";
	cout<<"\n\t\t--------------------------------\n";
	fp=fopen("diaryd.dat","rb")	;
	if(fp==NULL)
	cout<<"\t\t\t Diary Is empty";
	cout<<"\t\tEnter Date: ";
	cin>>da;
	while(fread(&d,sizeof(d),1,fp)>0)
	{
		if(da==d.date)
		{
        cout<<"\t\tDate: "<<d.date<<endl;
		cout<<"\t\tDay: "<<d.day<<endl;
		cout<<"\t\tDiary Content: "<<d.data<<endl;
		m=1;
		}
	}
	if(m==0)
	cout<<"\n\t\t\tDiary Not Found\n ";
	fclose(fp);
	cout<<"\n\t\t\tPRESS ANY KEY TO PROCEED NEXT--";
    cout<<"\n\t\t___________________________________________________\n\t\t";
    getch();	
}
void delete_diary()
{
	system("color 0C");
	int da,m=0,a=1;
	FILE *fp1;
	cout<<"\n\t\t       WELCOME TO DELETE MENU";
	cout<<"\n\t\t--------------------------------\n";
	fp=fopen("diaryd.dat","rb+");
	fp1=fopen("temp.dat","wb");
	if(fp==NULL)
	cout<<"\t\t\t Diary Is empty";
	cout<<"\t\tDelete Whole Diary  [1] \n";
	cout<<"\t\tDelete A Diary      [2]\n\n";
	cout<<"\t\tEnter Your Choice: -\n\t\t";
	cin>>da;
		if(da==1)
		{
			fclose(fp);
	        fclose(fp1);
         a=remove("diaryd.dat");
        
		}
		else if(da==2){
			cout<<"\n\t\tEnter Date: ";
			cin>>m;
	while(fread(&d,sizeof(d),1,fp)>0)
	{
		if(d.date==m)
	    	a=0;
		else
		fwrite(&d,sizeof(d),1,fp1);				
	}
	fclose(fp);
	fclose(fp1);
	if(a==0)
	{
		fp=fopen("diaryd.dat","wb");
	    fp1=fopen("temp.dat","rb");	
	    while(fread(&d,sizeof(d),1,fp1))
	    {
	    	fwrite(&d,sizeof(d),1,fp);
		}
		fclose(fp);
	    fclose(fp1);	
	}
}
	if(a==1)
	{
	cout<<"\n\t\t\tUnable To Delete";
	fclose(fp);
	fclose(fp1);
    }
    else
    cout<<"\n\t\t\tDeleted Successfully";
    cout<<"\n\t\t______________________________________\n\t\t";
    getch();	
}
