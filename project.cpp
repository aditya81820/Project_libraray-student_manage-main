#include<iostream>
#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include<stdlib.h>
#include "book.cpp"
#include<string.h>
#include<conio.h>
#include "student.cpp"
using namespace std;
class book books[200];
class student s[200];

void searchbook();
void addbook();
int displaybook();
void library();
void studentmanage();
void deletebook();
void updatebook();

void addrecord();
void searchrecord();
void displayrecord();
void deleterecord();
void updaterecord();
int n=0;

void addrecord()
{
	FILE *fp;
		fp=fopen("studentdata.dat","w");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	}
	int i=0;
	int n=0;
	
	
	
	char ch;
	char id[5],year[4];
	
	while(1)
	{
		
		system("CLS");
		cout<<"\t\t\t\tADD STUDENT RECORD"<<endl;
		cout<<"\t\t\t\t__________________"<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"\t\t\t\tEnter student name:";
		cin>>s[i].name;
		cout<<"\t\t\t\tEnter student Phone no:";
		cin>>s[i].phoneno;
		cout<<"\t\t\t\tEnter student Roll no:";
		cin>>s[i].rollno;
		cout<<"\t\t\t\tEnter student course:";
		cin>>s[i].course;
		cout<<"\t\t\t\tEnter course branch:";
		cin>>s[i].branch;
		cout<<"\t\t\t\tEnter student year:";
		cin>>s[i].year;
		
		fwrite(&s[i],sizeof(struct student),1,fp);
		i++;
		n++;
		
		cout<<endl<<endl;
		
		printf("Record  added successfully.");
		
		cout<<endl<<"Want to add more books??[Y/N]: ";
		cin>>ch;
		if(ch=='N' || ch=='n')
		{
			system("CLS");
			break;
		}
		else
		{
			cout<<"Enter given characters only:";
		}
	}
	fclose(fp);
	return;
}

void searchrecord()
{
	system("CLS");
    FILE *fp;
		fp=fopen("studentdata.dat","r");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	} 
	char rollid[15];
	int i=0;
	cout<<"\t\t\t\tSEARCH STUDENT DETAILS"<<endl;
	cout<<"                                                       ___________________"<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<cout<<"                      Enter Roll Number of to be searched:";
	cin>>rollid;
	while(fread(&s[i],sizeof(struct student),1,fp))
	{
		if(!strcmp(s[i].rollno,rollid))
		{
		cout<<"                      Student name: "<<s[i].name<<endl;
		cout<<"                      student Phone no:: "<<s[i].phoneno<<endl;
		cout<<"                      student course: "<<s[i].course<<endl;
		cout<<"                      course branch: "<<s[i].branch<<endl;
		cout<<"                      book issue year: "<<s[i].year<<endl;
		}
		i++;
	}
	cout<<"Enter any key to return.";
	getch();

}

void displayrecord()
{
	system("CLS");
	int i=0;
		FILE *fp;
		fp=fopen("studentdata.dat","r");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	}
	
	cout<<"\t\t\t\tSTUDENT RECORDS ARE:"<<endl;
    cout<<"\t\t\t\t___________________"<<endl<<endl<<endl<<endl<<endl<<endl;
    
	    while(fread(&s[i],sizeof(struct student),1,fp))
	    {
	    	
	    	
	    	cout<<"                      Student name: "<<s[i].name<<endl;
	    	cout<<"                      Student Phone no: "<<s[i].phoneno<<endl;
	    	cout<<"                      Student Roll no: "<<s[i].rollno<<endl;
	    	cout<<"                      Student Course: "<<s[i].course<<endl;
	    	cout<<"                      Course branch: "<<s[i].branch<<endl;
	    	cout<<"                      Student year: "<<s[i].year<<endl<<endl;
	    	i++;
	    }
	

	fclose(fp);
	cout<<"Enter any key to return.";
	getch();     	
}

void deleterecord()
{
	FILE *fp1,*fp2;
	fp1=fopen("studentdata.dat","r+");
	fp2=fopen("copy2.dat","w+");
	if(fp1==NULL)
	{
		printf("Error in opening a file.");
	}
	
	char ids[20];
	printf("Enter the RoLL no of the student you want to delete record:");
	cin>>ids;
	int i=0;
	while(fread(&s[i],sizeof(struct student),1,fp1)){
		if(strcmp(s[i].rollno,ids))
		{
			fwrite(&s[i],sizeof(struct student),1,fp2);
		}
		i++;
	}
	fclose(fp1);
	fclose(fp2);
	remove("studentdata.dat");
	rename("copy2.dat","studentdata.dat");
	printf("Record updated successfully.");
	displayrecord();
}

void updaterecord()
{
	FILE *fp1,*fp2;
	fp1=fopen("studentdata.dat","r+");
	fp2=fopen("copy2.dat","w+");
	if(fp1==NULL)
	{
		printf("Error in opening a file.");
	}
	
	char ids[20];
	printf("Enter the student Roll No you want to update:");
	cin>>ids;
	int i=0;
	while(fread(&s[i],sizeof(struct student),1,fp1)){
		if(strcmp(s[i].rollno,ids))
		{
			fwrite(&s[i],sizeof(struct student),1,fp2);
		}
		i++;
	}
	struct student s2;
	cout<<"\t\t\t\tADD STUDENT"<<endl;
	cout<<"\t\t\t\t___________"<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                      Enter Student name:";
		cin>>s2.name;
		cout<<"                      Enter Student Phone no:";
		cin>>s2.phoneno;
		cout<<"                      Enter Roll no:";
		cin>>s2.rollno;
		cout<<"                      Enter Student course:";
		cin>>s2.course;
		cout<<"                      Enter Course branch:";
		cin>>s2.branch;
		cout<<"                      Enter student year:";
		cin>>s2.year;
	fwrite(&s2,sizeof(struct student),1,fp2);
	fclose(fp1);
	fclose(fp2);
	remove("studentdata.dat");
	rename("copy2.dat","bookstudent.dat");
	printf("Record updated successfully.");
	displaybook();
}

void updatebook()
{
	FILE *fp1,*fp2;
	fp1=fopen("bookdata.dat","r+");
	fp2=fopen("copy.dat","w+");
	if(fp1==NULL)
	{
		printf("Error in opening a file.");
	}
	
	char ids[20];
	printf("Enter the book ID you want to update:");
	cin>>ids;
	int i=0;
	while(fread(&books[i],sizeof(struct book),1,fp1)){
		if(strcmp(books[i].bookid,ids))
		{
			fwrite(&books[i],sizeof(struct book),1,fp2);
		}
		i++;
	}
	struct book s2;
	cout<<"\t\t\t\tADD BOOK"<<endl;
	cout<<"\t\t\t\t________"<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                      Enter book id:";
		cin>>s2.bookid;
		cout<<"                      Enter book name:";
		cin>>s2.bookname;
		cout<<"                      Enter book author:";
		cin>>s2.bookauthor;
		cout<<"                      Enter book issue date:";
		cin>>s2.bookpubdate;
		cout<<"                      Enter book issue month:";
		cin>>s2.bookpubmonth;
		cout<<"                      Enter book year:";
		cin>>s2.bookpubyear;
	fwrite(&s2,sizeof(struct book),1,fp2);
	fclose(fp1);
	fclose(fp2);
	remove("bookdata.dat");
	rename("copy.dat","bookdata.dat");
	printf("Record updated successfully.");
	displaybook();
}

void deletebook()
{
	FILE *fp1,*fp2;
	fp1=fopen("bookdata.dat","r+");
	fp2=fopen("copy.dat","w+");
	if(fp1==NULL)
	{
		printf("Error in opening a file.");
	}
	
	char ids[20];
	printf("Enter the book ID you want to delete:");
	cin>>ids;
	int i=0;
	while(fread(&books[i],sizeof(struct book),1,fp1)){
		if(strcmp(books[i].bookid,ids))
		{
			fwrite(&books[i],sizeof(struct book),1,fp2);
		}
		i++;
	}
	fclose(fp1);
	fclose(fp2);
	remove("bookdata.dat");
	rename("copy.dat","bookdata.dat");
	printf("Record updated successfully.");
	displaybook();
}


void searchbook()
{
	
    system("CLS");
    FILE *fp;
		fp=fopen("bookdata.dat","r");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	} 
	char keyid[20];
	int i=0;
	cout<<"\t\t\t\tSEARCH BOOK DETAILS"<<endl;
	cout<<"\t\t\t\t___________________"<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<cout<<"                      Enter book id to be searched:";
	cin>>keyid;
	while(fread(&books[i],sizeof(struct book),1,fp))
	{
		if(!strcmp(books[i].bookid,keyid))
		{
		cout<<"                      book name: "<<books[i].bookname<<endl;
		cout<<"                      book author: "<<books[i].bookauthor<<endl;
		cout<<"                      book issue date: "<<books[i].bookpubdate<<endl;
		cout<<"                      book issue month: "<<books[i].bookpubyear<<endl;
		cout<<"                      book issue year: "<<books[i].bookpubmonth<<endl;
		}
		i++;
	}
	cout<<"Enter any key to return.";
	getch();
}
void addbook()
{
	FILE *fp;
		fp=fopen("bookdata.dat","w");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	}
	int i=0;
	int n=0;
	
	
	
	char ch;
	char id[5],year[4];
	
	while(1)
	{
		
		system("CLS");
		cout<<"\t\t\t\t\tADD BOOK"<<endl;
		cout<<"\t\t\t\t\t________"<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<"                      Enter book id:";
		cin>>books[i].bookid;
		cout<<"                      Enter book name:";
		cin>>books[i].bookname;
		cout<<"                      Enter book author:";
		cin>>books[i].bookauthor;
		cout<<"                      Enter book issue date:";
		cin>>books[i].bookpubdate;
		cout<<"                      Enter book issue month:";
		cin>>books[i].bookpubmonth;
		cout<<"                      Enter book year:";
		cin>>books[i].bookpubyear;
		
		fwrite(&books[i],sizeof(struct book),1,fp);
		i++;
		n++;
		
		cout<<endl<<endl;
		
		printf("Record  added successfully.");
		
		cout<<endl<<"Want to add more books??[Y/N]: ";
		cin>>ch;
		if(ch=='N' || ch=='n')
		{
			system("CLS");
			break;
		}
		else
		{
			cout<<"Enter given characters only:";
		}
	}
	fclose(fp);
	return;
	
}
int displaybook()
{
	system("CLS");
	int i=0;
		FILE *fp;
		fp=fopen("bookdata.dat","r");
	
	if(fp==NULL)
    	{
	    	printf("File can'nt be open");
	    	exit(1);
    	}
	
	cout<<"\t\t\t\tYour books are"<<endl;
    cout<<"\t\t\t\t______________"<<endl<<endl<<endl<<endl<<endl<<endl;
    
	    while(fread(&books[i],sizeof(struct book),1,fp))
	    {
	    	
	    	
	    	cout<<"                      book id: "<<books[i].bookid<<endl;
	    	cout<<"                      book name: "<<books[i].bookname<<endl;
	    	cout<<"                      book author: "<<books[i].bookauthor<<endl;
	    	cout<<"                      book issue date: "<<books[i].bookpubdate<<endl;
	    	cout<<"                      book issue month: "<<books[i].bookpubyear<<endl;
	    	cout<<"                      book issue year: "<<books[i].bookpubmonth<<endl<<endl;
	    	i++;
	    }
	

	fclose(fp);
	cout<<"Enter any key to return.";
	getch();
}
void library()
{
	while(1)
	{
		system("CLS");
		cout<<"\t\t\t\tLIBRARY MANAGEMENT";
   	    cout<<endl;
    	cout<<"\t\t\t\t__________________"<<endl<<endl<<endl<<endl<<endl<<endl;
    	cout<<"\t\t\t\tchoose the option below"<<endl;
    	cout<<"\t\t\t\t1: ADD A BOOK"<<endl;
      	
     	cout<<"\t\t\t\t2: SEARCH ANY BOOKS"<<endl;
    	cout<<"\t\t\t\t3: DISPLAY ALL BOOKS"<<endl;
    	cout<<"\t\t\t\t4: DELETE A BOOK"<<endl;
    	cout<<"\t\t\t\t5: UPDATE BOOK INFORMATION"<<endl;
    	cout<<"\t\t\t\t6: QUIT"<<endl<<endl<<endl;
    	cout<<"\t\t\t\tEnter your choice here: ";
    	char no;
    	cin>>no;
    	switch(no)
     	{
	    	case '1':
		    	addbook();
		    	break;	
	    	case '2':
		    	searchbook();
		     	break;
	    	case '3':
		     	displaybook();
		    	break;
	    	case '4':
		    	deletebook();
		    	break;
	        case '5':
		    	updatebook();
			    break;
	    	case '6':
		    	exit(1);
	     	default:
		     	{
				    system("CLS");
		         	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		        	cout<<"You have entered a wrong key.";
		        	cout<<"Enter any button to reinput your choice:";
		        	char c;
		        	cin>>c;
		    	}
			    system("CLS");
		        cout<<endl<<"                                             Returning back to menu.";
		        sleep(2);
		        continue;
	    }
	    
	}
	
}
void studentmanage()
{
		while(1)
	{
		system("CLS");
		cout<<"\t\t\t\tSTUDENT MANAGEMENT SYSTEM";
   	    cout<<endl;
    	cout<<"\t\t\t\t__________________"<<endl<<endl<<endl<<endl<<endl<<endl;
    	cout<<"\t\t\t\tchoose the option below"<<endl;
    	cout<<"\t\t\t\t1: ADD STUDENT RECORD"<<endl;
      	
     	cout<<"\t\t\t\t2: SEARCH STUDENT RECORD"<<endl;
    	cout<<"\t\t\t\t3: DISPLAY ALL RECORD"<<endl;
    	cout<<"\t\t\t\t4: DELETE A RECORD"<<endl;
    	cout<<"\t\t\t\t5: UPDATE ANY RECORD"<<endl;
    	cout<<"\t\t\t\t6: QUIT"<<endl<<endl<<endl;
    	cout<<"\t\t\t\tEnter your choice here: ";
    	char no;
    	cin>>no;
    	switch(no)
     	{
	    	case '1':
		    	addrecord();
		    	break;	
	    	case '2':
		    	searchrecord();
		     	break;
	    	case '3':
		     	displayrecord();
		    	break;
	    	case '4':
		    	deleterecord();
		    	break;
	        case '5':
		    	updaterecord();
			    break;
	    	case '6':
		    	exit(1);
	     	default:
		     	{
				    system("CLS");
		         	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		        	cout<<"You have entered a wrong key.";
		        	cout<<"Enter any button to reinput your choice:";
		        	char c;
		        	cin>>c;
		    	}
			    system("CLS");
		        cout<<endl<<"\t\t\t\tReturning back to menu.";
		        sleep(2);
		        continue;
	    }
	    
	}
}
int main()
{
    int no;
	char str[20],pass[20];
	string username="aditya",password="password";
	cout<<endl<<"\t\t\tWELCOME TO MAHARANA PRATAP ENGINEERING COLLEGE"<<endl;
    cout<<"\t\t\t______________________________________________"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\tLogin:";
    cin>>str;
    cout<<endl<<"\t\t\t\tPassword:";
    cin>>pass;
    if(str==username && password==pass)
    {
    	system("CLS");
    	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\tYou have succefully login";
    	sleep(2);
    	while(1)
    	{
    		
    	    system("CLS");
    	    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    	    printf("\t\t\t\tChoose any option");
        	cout<<endl;
        	cout<<"\t\t\t\t _________________"<<endl;
        	cout<<"\t\t\t\t1: Library management"<<endl;
        	cout<<"\t\t\t\t2: Student record management system"<<endl;
        	cout<<endl<<endl<<endl;
         	cout<<"\t\t\t\tEnter your option here:";
        	
        	cin>>no;
     	
    		switch(no)
         	{
    		   case 1:
    			{
    				system("CLS");
    				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    				cout<<"\t\t\tWait for a while we are processing your data!!";
    				sleep(1);
    				system("CLS");
    				library();
    				break;
				}
			   case 2:
				{
					system("CLS");
    				cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
					cout<<"\t\t\tWait for a while we are processing your data!!";
					sleep(1);
					cout<<"2";
					system("CLS");
					studentmanage();
					break;					
				
				}
			   default:
			    {
				    system("CLS");
    		     	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
				    cout<<"\t\t\t\tSorry you have entered a wrong choice.";
				    cout<<endl<<endl<<"\t\t\t\tEnter any button to reinput your choice: ";
			    	getch();	
					
		        }
		        system("CLS");
		        cout<<endl<<"\t\t\t\tReturning back to menu.";
		       sleep(1);
		        continue;
		        
		   }
		   break;
		}
		   
	}
    	
    	
	
	else
	{
		cout<<"SORRY YOUR ENTERED WRONG LOGIN Id OR PASSWORD";
	}
    
    
    
    
            
}
