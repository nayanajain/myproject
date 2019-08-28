 //***************************************************************
//                   HEADER   FILES
//****************************************************************

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
int a=0;
char name[100];
class book
{
public:
int bno;
char bname[50];
char aname[20];
int price,copy;
public:

	char *getn()
	{
	 return bname;
	}
void input();
void show();
};book fileobj;

void book::input()
{
	cout<<"\nEnter the bookno\t";
	cin>>bno;
	cout<<"\nEnter the price\t";
	cin>>price;
	cout<<"\nEnter the name of book\t";
	gets(bname);
	cout<<"\nEnter the name of author of this book\t";
	gets(aname);
	cout<<"Enter the amount of copies";
	cin>>copy;
}
void book::show()
{
	cout<<"\t\tbookno==> "<<bno<<endl;
	cout<<"\t\tprice ==> "<<price<<endl;
	cout<<"\t\tbookname==> "<<bname<<endl;
	cout<<"\t\tauthorname==> "<<aname<<endl;
	cout<<"\t\tno of copies==>"<<copy<<endl;
	cout<<"\n\n";
}


void Create();
void Add();
void Display();
void Modify();
void Delete();
void DisplayP();
void writest();

fstream fil,fp;
//***************************************************************
//    	  function  for  introduction
//****************************************************************

  void Intro()
{
cout<<"***************************************************************";
cout<<"\n\n\n\n********************Welcome******************************";
cout<<"\n\n\n\n\t\t*MANAGEMENT*";
cout<<"\n\n\t\t*OF BOOKS*";
cout<<"\n\n\t\t*IN LIBRARYx*";
cout<<"\n\n\n\n\n Press any key\t\t";
getch();
}

//***************************************************************
//                   MAIN FUNCTION
//****************************************************************


int main()
{
int ch2,ch3,id;
char b2[30];
textcolor(3);
textbackground(6);
clrscr();
Intro();

	int option;
	 clrscr();
	     cout<<"1.  Admin panel\n";
	     cout<<"2.  Student panel\n";
	     cout<<"3. Exit\n";
	     cout<<"Enter your choice\n";
	     cin>>ch2;
	     if(ch2==1)
	     {
	while(1)
	{

		clrscr();
		cout<<"\n\t\t\t***********************************";
		cout<<"\n\t\t\t1.Create Data File"<<endl;
		cout<<"\n\t\t\t2.Add New Record in Data File"<<endl;
		cout<<"\n\t\t\t3.Display Record From Data File"<<endl;
		cout<<"\n\t\t\t4.Display Particular Record From Data File"<<endl;
		cout<<"\n\t\t\t5.Modify Paricular Record From Data File"<<endl;
		cout<<"\n\t\t\t6.Delete Particular Record From Data File"<<endl;
		cout<<"\n\t\t\t7.Exit From the Program"<<endl;
		cout<<"\t\t\t**********************************************";
		cout<<"\n\nEnter your Option : "<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
			{      clrscr();
				Create();
				cout<<"Record  Created"<<endl;
				getch();
				break;
			}
				case 2:
			{
				 clrscr();
				Add();
				cout<<"Display Main Menu"<<endl;
				getch();
				break;
			}
				case 3:
			{
				clrscr();
				Display();
				cout<<"All Record Displayed"<<endl;
				getch();
				break;
			}
			case 4:
			{
				 clrscr();
				DisplayP();
				if(a==0)
				{
				cout<<"\nrec. not found\n";
				}
				cout<<" Disply Main Menu"<<endl;
				getch();
				break;
			}
			case 5:
			{
				 clrscr();
				Modify();
				if(a==0)
				{
				cout<<"\nrec. not found\n";
				}
				cout<<"Record Modified"<<endl;
				getch();
				break;
			}
			case 6:
			{
				 clrscr();
				Delete();
				if(a==0)
				{
				cout<<"\nrec. not found\n";
				}
				cout<<"\nPress any key to Display main Menu"<<endl;
				getch();
				break;
			}
			case 7:
			{

				exit(0);
			}
			default:
			{
				cout<<"Wrong Choice....Press Key For View the Main Menu";
				getch();
				clrscr();
			}
		}
	}

}
else if(ch2==2)
{
clrscr();
cout<<"1. Issue a book\n";
cout<<"2. Submit a book\n";
cout<<"3. Exit";
cin>>ch3;
switch(ch3)
{
case 3: exit(0);
case 1 :   cout<<"enter the id";
	   cin>>id;
	   if((id>0)&&(id<500))
	   {

		fil.open("b.dat",ios::in|ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
	       cout<<"enter the name of the book";
	   gets(b2);
		while(!fil.eof())
		{

	  //puts(fileobj.getn()) ;
	   if(strcmp(fileobj.getn(),b2)==0)
	   {
	   cout<<"book available";
	   cout<<"\nbook issued to "<<id;
	   fileobj.copy--;
	   fil.seekg(0,ios::cur);
	   fil.seekp(fil.tellg()-sizeof(fileobj));
	   fil.write((char*)&fileobj, sizeof(fileobj));
	    getch();
	   break;
	   }
	   else
	   {
	   fil.read((char*)&fileobj,sizeof(fileobj) );
	   cout<<"press any key...";
	   if(fil.eof())
	   {
	   cout<<"book not available";
	   break;
	   }
	   getch();
	   }
	   }
	   }
	   }
	   else
	   {
	   cout<<"Invalid id";
	   }
	   break;
//default: cout<<"Wrong choice";
case 2: cout<<"enter the id";
	cin>>id;
	if((id>0)&&(id<500))
	{
	fil.open("b.dat",ios::in|ios::out|ios::app| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
	 fil.read((char*)&fileobj, sizeof(fileobj));

		cout<<"enter the name of the book";
	   gets(b2);
		while(!fil.eof())
		{


	   puts(fileobj.getn()) ;
	   if(strcmp(fileobj.getn(),b2)==0)
	   {

	   cout<<"\nbook submitted by "<<id;
	   fileobj.copy++;
	   fil.seekg(0,ios::cur);
	   fil.seekp(fil.tellg()-sizeof(fileobj));
	  // cout<<fileobj.copy;
	  fil.write((char*)&fileobj, sizeof(fileobj));
	   getch();
	   break;
	   //copy--;
	   }
	   else
	   {
	   cout<<"press any key....for next record";
	   if(fil.eof())
	   cout<<"book not available";
	   getch();
	   //break;
	   }
		fil.read((char*)&fileobj, sizeof(fileobj));
	   }
	   }
	   }



//case 3:  exit(0);

default: cout<<"Wrong choice";
}
}
  else if(ch2==3)
  {
  exit(0);
  }

}



//***************************************************************
//          Function to Create a record in a Data File
//****************************************************************



void Create()
{
	char ch='y';
	fil.open("b.dat",ios::out| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}
	fil.close();
}

//***************************************************************
//          Function to Add a record in a Data File
//****************************************************************


void Add()
{
	char ch='y';
	fil.open("b.dat",ios::out|ios::app| ios::binary);
	while(ch=='y' || ch =='Y')
	{
		fileobj.input();
		fil.write((char*)&fileobj, sizeof(fileobj));
		cout<<"Want to Continue.....";
		cin>>ch;
	}
	fil.close();
	}

//***************************************************************
//               Function to Display all record from a Data File
//****************************************************************



void Display()
{
	fil.open("b.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			fileobj.show();
			cout<<"Press Any Key....For Next Record"<<endl;
			getch();
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}

//***************************************************************
//   Function to Display a particular record from a Data File
//****************************************************************


void DisplayP()
{       a=0;
	char n[100];
	cout<<"\t\t**********************************";
	cout<<"\n\t\tEnter Name that should be searched:";
	gets(n);
		strcpy(name,n);
	fil.open("b.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
			a++;
				fileobj.show();
				cout<<"Press Any Key...."<<endl;
				getch();
				break;
			}
			else
			{
			if(fil.eof())
			{
			cout<<" Record not found"<<endl;
				cout<<"Press Any Key....For Search"<<endl;
				 getch();
			}
			}
			fil.read((char*)&fileobj, sizeof(fileobj));
		}
	}
	fil.close();
}

//************************-***************************************
//           Function to Modify a record from a Data File
//****************************************************************

void Modify()
{
	char n[100];
	DisplayP();
	strcpy(n,name);

	fil.open("b.dat",ios::in| ios::out|ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())==0)
			{
			     //	fil.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				fileobj.input();
				fil.seekp(fil.tellg() - sizeof(fileobj));
				fil.write((char*)&fileobj, sizeof(fileobj));
	       }
			fil.read((char*)&fileobj, sizeof(fileobj));
		}


	}
	fil.close();
}


//***************************************************************
//          Function to Delete a record from a Data File
//****************************************************************


void Delete()
{
a=0;
	char n[100];
	char y;
	int p=0;
      DisplayP();

       if(a>=1)
       {
       cout<<"Are you sure"<<endl;
       cin>>y;
       if(y=='y')
       {
       strcpy(n,name);
	ofstream o;
	o.open("new.dat",ios::out|ios::binary);
	fil.open("b.dat",ios::in| ios::binary);
	if(!fil)
	{
		cout<<"File not Found";
		exit(0);
	}
	else
	{
		fil.read((char*)&fileobj, sizeof(fileobj));
		while(!fil.eof())
		{
			if(strcmp(n,fileobj.getn())!=0)
			{
				o.write((char*)&fileobj, sizeof(fileobj));
				p++;
			}


			if(strcmp(n,fileobj.getn())==0)
				{
				cout<<"rec. deleted";
			      }
			fil.read((char*)&fileobj, sizeof(fileobj));
		}

	}
	o.close();
	fil.close();
	remove("b.dat");
	rename("new.dat", "b.dat");
	}
	}
}
//***************************************************************
//                 End of program
//****************************************************************
