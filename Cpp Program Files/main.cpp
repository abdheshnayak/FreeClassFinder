

#include"help.cpp"
int pw;


class branch	//Class for names of the branch
{
	public:
	char brname[100][20];
	int brn;
	branch()
	{
		brn=0;
	}
	int addBranch(int i)
	{
		cout<<"\nUse \"Underscor(_)\" Instead of Space\n\tEnter The Name of The Branch without Any Space :";
		cin>>brname[i];
		brn++;
	}
	int showBranch()
	{
		for(int i=0;i<brn;i++)
		{
			cout<<"\n"<<i+1<<"."<<brname[i];
		}
	}
	
}br;

class room //Class to store all the rooms
{
	public:
	int ptr;
	room()
	{
		ptr=0;
	}
	char roomn[100][20];
	int rn;	
	int roomallocate() //Function to allocate the rooms
	{
		cout<<"\nInitialize The Classes:"<<endl;
		cout<<"Enter The No Of Class In Department:";
		cin>>rn;
		cout<<"Enter The Number/Name To Allocated All The Classes In The Department Respectively:\n";
		for(int i=0;i<rn;i++)
		{
			cout<<"Enter The Room Number "<<i+1<<": ";
			cin>>roomn[i];
		}
		ptr=1;
		room:show();
	}
	show()		//Function to show the allocated roooms
	{
		setcolor(2);
		cout<<"\nAllocated Room/Class List :";
		setcolor(5);
		for(int i=0;i<rn;i++)
		{
			cout<<"\t"<<roomn[i];
		}
		setcolor(0);
	}		

}ob1;

class routine //Class to store all the Routines of sections
{
	public:
		char rooms[35][20]; //It store rooms of all the lecture....if there is class in 202 romm no. int routine 202 will be a element of rooms variable
		int routinenum;
		int classroutine()
		{
			char temp2[20];
			int j,temp,ptr=0;
			int lecture=7,day=5;
			string daylist[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};	//Just for show the user
			cout<<"Enter The Class Number/Name According To The Routine Of The Class And Enter '0' for Free Lectures"<<endl;
			for(int i=0;i<lecture*day;i++)
			{
				temp=(i+1)%7;
				start:
				cout<<"Enter The Routine Of "<<daylist[i/7]<<" Lecture No."<<(temp==0?7:temp)<<endl;
				cin>>temp2;
				ptr=0;
				for(j=0;j<ob1.rn;j++)
				{
					if(((strcmp(temp2,ob1.roomn[j]))==0)||(strcmp(temp2,"0")==0))
					{
						ptr=1;
					}
				}	
				if(ptr!=1)
				{
					cout<<"Wrong Room Number Entered Try Again :"<<endl;
					goto start;
				}
				strcpy(rooms[i],temp2);
			}
			routine:show();
		}
		void show()	//For show the routines stored in class
		{
			setcolor(10);
			int i,j,k,lecture=7,day=5;
			string daylist[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
			cout<<"Lec.N\t";
			for(i=0;i<5;i++)
			{
				cout<<daylist[i]<<"\t\t";
			}
			cout<<endl;
			j=0;k=0;
			cout<<k+1<<"\t";
			k++;
			for(i=0;i<50;i=i+7)
			{ 
				if((i>28+j)&&(k<7))
				{
					cout<<endl;
					cout<<k+1<<"\t";
					k++;
				}
				if(i>=35+j){j++;i=j;}
				if(j>6){break;}
					cout<<rooms[i]<<"\t\t";	
			}
			setcolor(0);
		}
}ob2[200];
class check	//To check the free classes
{
	public:
		int rn;
		char lecture[35][10];	//to store the avilable lecture
		int checkempty(int y,int i)	//function to check availity of class
		{
			char temp2[10];
			int j,temp,ptr=0;
			int lectur=7,day=5,routinenumber=y;
			string daylist[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};	
			for(int m=0;m<35;m++)
			{
				strcpy(temp2,"0");
				for(int l=0;l<routinenumber;l++)
				{
						if(strcmp(ob1.roomn[i],ob2[l].rooms[m])==0)
						{
							strcpy(temp2,"1");
							break;
						}	
				}
				strcpy(lecture[m],temp2);
			}
		}
		void show()	//show the available free rooms
		{
			int i,j,k,lectur=7,day=5;
			string daylist[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};
			cout<<"\nLec.N\t";
			for(i=0;i<5;i++)
			{
				cout<<daylist[i]<<"\t\t";
			}
			cout<<endl;
			j=0;k=0;
			cout<<k+1<<"\t";
			k++;
			for(i=0;i<50;i=i+7)
			{ 
				if((i>28+j)&&(k<7))
				{
					cout<<endl;
					cout<<k+1<<"\t";
					k++;
				}
				if(i>=35+j){j++;i=j;}
				if(j>6){break;}
				cout<<lecture[i]<<"\t\t";	
			}
		}
		
}ob3[200];


char str[50],str2[50]; //Temparary Strings

int exportdata()	//For Exporting to Html file
{
			int chh;
			char temp1[50],temp2[50],temp3[50],temp4[50];
			char time[7][15]={"9:00-9:55","9:55-10:50","10:50-11:45","11:45-12:35","1:35-2:30","2:30-3:25","3:25-4:15"};	
			ifstream t5;
			t5.open("classrecord/BasicData/BranchDetail.jpg");
			t5.seekg(0);		
			t5.read((char*)&br,sizeof(br));
			t5.close();
					
			
			clrscr();
			mainstart:
			cout<<"\nSelect A Branch To Continue\n";
			br.showBranch();
			cout<<endl<<br.brn+1<<".Cancel";
			cout<<"\n\tEnter Your Choice : ";
			cin>>chh;
		//	cout<<br.brn;
		//	cout<<ch;
			if(chh<0||chh>br.brn+1)
			{
				cout<<"Wrong Choice Try Again";
				goto mainstart;	
			}
			else if(chh==br.brn+1)
			{
				return 0;
			}
			strcpy(temp1,"classrecord/");
			strcat(temp1,br.brname[chh-1]);
	
	int x;
	int day,lect;
	char daylist[5][10]={"MONDAY","TUESDAY","WEDNESDAY","THRUSSDAY","FRIDAY"};
	char ch;
	char temp[50];
	start:
	cout<<"\nTo See Current Free Lectures Select a Working Day\n\t1.Monday\n\t2.Tuesday\n\t3.Wednesday\n\t4.Thursday\n\t5.Friday\n\t\tEnter Current Day :";
	cin>>day;
	if(day<1||day>5)
	{
		setcolor(4);
		cout<<"The wrong Day Selected Try Again:\n\n";
		setcolor(0);
		goto start;
	}
	//clrscr();
	fstream t1;
	int length,studentcount=0;
	remove("FreeClassList.html");							//Deletion Of old file
	ofstream expdata("FreeClassList.html");					//Creatation of New file
	t1.open("FreeClassList.html",ios::in|ios::out|ios::ate);
	
	ifstream t3;
	strcpy(temp2,temp1);
	strcat(temp2,"/doc2.jpg");
	t3.open(temp2);
	t3.seekg(0);
	while(t3.read((char*)&ob1,sizeof(ob1)))
	{	}
	t3.close();
	
	
	ifstream t2;
	t2.seekg(0);
	strcpy(temp4,temp1);
	strcat(temp4,"/doc4.jpg");
	t2.open(temp4);
	t2.read((char*)&ob3,sizeof(ob3));
	
		strcpy(str,"<!DOCTYPE html><html><head><style>table {font-family: arial, sans-serif;border-collapse:collapse; collapsewidth: 100%;} td, th {border: 1px solid black;text-align: left;padding: 10px;}tr:nth-child(even) {background-color: #dddddd;}</style></head><body><h1 style=\"color:green\" align=\"center\";>Amritsar College of Engineering And Technology</h1><h2 style=\"color:#ff008d\">");
		strcat(str,br.brname[chh-1]);
		strcat(str,"</h2><h3 style=\"color:blue\">");
		strcat(str,daylist[day-1]);
		strcat(str,"</h3>");
		strcat(str,"<table><tr><th>Lecture No.</th><th>Lecture Duration</th>");
			for(int i=0;i<ob1.rn;i++)
		{
			strcat(str,"<th>");
			//sprintf(temp,"%d",i+1);
			strcpy(temp,ob1.roomn[i]);
			strcat(temp,"</th>");
			strcat(str,temp);	
		}
		strcat(str,"</tr>");
		for(lect=1;lect<=7;lect++)
		{
			strcat(str,"<tr>");
		strcat(str,"<td><b>Lecture ");
		sprintf(temp,"%d",lect);
		strcat(temp,"</b></td><td><b>");
		strcat(temp,time[lect-1]);
		strcat(temp,"</b></td>");
		strcat(str,temp);
		
		char temp2[5];
		strcpy(temp2,"0");
		
		x=((day-1)*7)+((lect-1));
		
		for(int i=0;i<ob1.rn;i++)
		{
			
			if(strcmp(temp2,ob3[i].lecture[x])==0)
			{
				strcpy(temp,"<td style=\"color:Green\";>");
				//strcat(temp,ob1.roomn[i]);
				strcat(temp,"Free</td>");
				strcat(str,temp);
			//	cout<<ob1.roomn[i]<<"\t";
			}
			else
			{
				strcat(str,"<td style=\"color:Red\";>Pack</td>");
			}
	 	}
				strcpy(temp,"</tr>");
				strcat(str,temp);
				
			}
		strcat(str,"</table></body></html>");
	
		length=strlen(str);
		t1.write((char*)&str,length);
		char temp5[60];
		exporting(5,10);
		setcolor(0);
		strcpy(temp5,"\n\n\t+++++++++++++++++++++++++++++++++++++++\n\t\tEXPORTING COMPLETE\n\t+++++++++++++++++++++++++++++++++++++++\n");
		int l=strlen(temp5);
		for(int i=0;i<l;i++)
		{
			cout<<temp5[i];
			Delay();
		}
		t1.clear();
		t1.close();
		t2.close();
		t3.close();
		cout<<"\n\tOpen The FreeClassList File Which is In the Same Directory of The Application(exe) To See The Exported List\n";
	//	getch();
		return 0;
}



int branchfun()
{
	char choice;
do
{
	mainstart:
			ifstream t1;
			t1.open("classrecord/BasicData/BranchDetail.jpg");
			t1.seekg(0);
			t1.read((char*)&br,sizeof(br));
			t1.close();
			clrscr();
	
	char temp[50],temp2[50],temp3[50],temp4[50];
	int ch;

	cout<<"\nSelect A Operation\n\n\t1.Add a Branch\n\t2.Display All Branch Added\n\t3.Delete A Branch\n\t4.Exit\n\t\tSelect A Choice :";
	cin>>choice;
	switch(choice)
	{
		case '1':
		{
			clrscr();
			br.addBranch(br.brn);
						
			ofstream t2;
			t2.open("classrecord/BasicData/BranchDetail.jpg");
			t2.seekp(0);
			t2.write((char*)&br,sizeof(br));
			t2.close();
			strcpy(temp,"classrecord/");
			strcat(temp,br.brname[br.brn-1]);
			mkdir(temp);
			cout<<"\nRecord is Added";
			getch();	
		}
		break;
		case '2':
		{
			br.showBranch();
			getch();
		}
		break;
		case '3':
		{
					
			clrscr();
			start:
			cout<<"\nSelect A Branch To Continue\n";
			br.showBranch();
			cout<<endl<<br.brn+1<<".Cancel Deletion";
			cout<<"\n\tEnter Your Choice : ";
			cin>>ch;
		//	cout<<br.brn;
		//	cout<<ch;
			if(ch<0||ch>br.brn+1)
			{
				cout<<"Wrong Choice Try Again";
				goto start;	
			}
			else if(ch==br.brn+1)
			{
				return 0;
			}
			strcpy(temp,"classrecord/");
			strcat(temp,br.brname[ch-1]);
		//	cout<<temp;
						
						
			for(int i=ch;i<=br.brn;i++)
			{
				strcpy(br.brname[ch-1],br.brname[ch]);
			}
			if (ch >= br.brn+1)
			{
    			printf("Deletion not possible.\n");
   				goto mainstart;
			}
			else
 			{
   			   for (int c = ch - 1; c < br.brn - 1; c++)
				{
					strcpy(br.brname[c],br.brname[c+1]);
			//		br.showBranch();
				}
			}
				br.brn=br.brn-1;
				rmdir(temp);
				strcpy(temp2,temp);
				strcpy(temp3,temp);
				strcpy(temp4,temp);
				strcat(temp2,"/doc2.jpg");
				strcat(temp3,"/doc3.jpg");
				strcat(temp4,"/doc4.jpg");
				remove(temp4);
				remove(temp3);
				remove(temp2);
				rmdir(temp);
				
				ofstream t2;
				t2.open("classrecord/BasicData/BranchDetail.jpg");
				t2.seekp(0);
				t2.write((char*)&br,sizeof(br));
				t2.close();
				cout<<"\nRemoved";
				getch();
			}
			
			break;
			case '4':
			{
				clrscr();
				return 0;
			}
			default:
			{
				cout<<"\n### THE WRONG CHOICE TRY AGAIN ###\n\n";
				getch();
			}
		}
	}while(choice!='4');
}


int admin()		//for admin use
{
	int routinenum;
	char choice;
	int ch;
	char temp[50],temp2[50],temp3[50],temp4[50];
	fstream t1;
	do{
		mainstart:
		clrscr();
		system("color 70");
		cout<<"\nSelect A Operation:\n\n\t1.Branch Operations\n\t2.Initialize All Rooms of a Branch\n\t3.Show Allocated Rooms of a Branch\n\t4.Initialize All The Routines of a Branch\n\t5.Display All Routines of a Branch\n\t6.Goto Main Menu\n\t\tEnter Your Choice: ";
		cin>>choice;
		if((choice!='6')&&(choice!='1'))
		{
			ifstream t1;
			t1.open("classrecord/BasicData/BranchDetail.jpg");
			t1.seekg(0);		
			t1.read((char*)&br,sizeof(br));
			t1.close();
					
			
			clrscr();
			start:
			cout<<"\nSelect A Branch To Continue\n";
			br.showBranch();
			cout<<endl<<br.brn+1<<".Cancel";
			cout<<"\n\tEnter Your Choice : ";
			cin>>ch;
		//	cout<<br.brn;
		//	cout<<ch;
			if(ch<0||ch>br.brn+1)
			{
				cout<<"Wrong Choice Try Again";
				goto start;	
			}
			else if(ch==br.brn+1)
			{
				goto mainstart;
			}
			strcpy(temp,"classrecord/");
			strcat(temp,br.brname[ch-1]);
		//	cout<<temp;
		}	
		switch(choice)
		{
			case '1':
				{
					branchfun();
				}
			break;
			case '2':
			{
				ofstream t1;
				strcat(temp,"/doc2.jpg");
				t1.open(temp);
				t1.seekp(0);
				ob1.roomallocate();
				t1.write((char*)&ob1,sizeof(ob1));
				t1.close();
				getch();
			}	break;
			case '3':
			{	
				ifstream t1;
				strcat(temp,"/doc2.jpg");
				t1.open(temp);
				t1.seekg(0);
				t1.read((char*)&ob1,sizeof(ob1));
				{
					ob1.show();
				}
				t1.close();
				getch();
			}	break;
			case '4':
			{
				ifstream t2;
				ofstream t1;
				strcpy(temp2,temp);
				strcat(temp2,"/doc2.jpg");
				t2.open(temp2);
				while(t2.read((char*)&ob1,sizeof(ob1)));
				t2.close();
				strcpy(temp3,temp);
				strcat(temp3,"/doc3.jpg");
				t1.open(temp3);
				t1.seekp(0);		
				cout<<"Enter the Number of Routines";
				cin>>routinenum;
				ob2[0].routinenum=routinenum;
				for(int i=0;i<routinenum;i++)
				{
					cout<<"\n\n\tRoutine :"<<i+1<<endl<<endl;	
					ob2[i].classroutine();
				}
				t1.write((char*)&ob2,sizeof(ob2));
				t1.close();
				for(int i=0;i<ob1.rn;i++)
				{		
					ob3[i].checkempty(routinenum,i);
				}
				strcpy(temp4,temp);
				strcat(temp4,"/doc4.jpg");
				
				t1.open(temp4);
				t1.write((char*)&ob3,sizeof(ob3));
				t1.close();
				getch();
			}break;
			case '5':
			{	
				ifstream t2;
				routinenum=5;
				strcpy(temp2,temp);
				strcat(temp2,"/doc3.jpg");
				t2.open(temp2);
				t2.read((char*)&ob2,sizeof(ob2));
				routinenum=ob2[0].routinenum;
				for(int i=0;i<routinenum;i++)
				{
					cout<<"\n\n\tRoutine :"<<i+1<<endl<<endl;	
					ob2[i].show();
				}
				getch();
			}break;
			case '6':
			{
				clrscr();
				return 0;
			}
			default:
			{
				cout<<"\n### THE WRONG CHOICE TRY AGAIN ###\n\n";
				getch();
			}
		}
	}while(choice!='6');
}
int calculate(int day,int lect)	//To calculate all the free classes after reading the file stored in classrecoard file
{
			char temp[50],temp2[50],temp3[50],temp4[50];
			int ch;
			ifstream t1;
			t1.open("classrecord/BasicData/BranchDetail.jpg");
			t1.seekg(0);		
			t1.read((char*)&br,sizeof(br));
			t1.close();
					
			
			clrscr();
			start:
			cout<<"\nSelect A Branch To Continue\n";
			br.showBranch();
			cout<<endl<<br.brn+1<<".Exit";
			cout<<"\n\tEnter Your Choice : ";
			cin>>ch;
		//	cout<<br.brn;
		//	cout<<ch;
			if(ch<0||ch>br.brn+1)
			{
				cout<<"Wrong Choice Try Again";
				goto start;	
			}
			else if(ch==br.brn+1)
			{
				return 0;
			}
			strcpy(temp,"classrecord/");
			strcat(temp,br.brname[ch-1]);
	strcpy(temp2,temp);
	strcat(temp2,"/doc2.jpg");
	ifstream t3;
	t3.open(temp2);
	while(t3.read((char*)&ob1,sizeof(ob1)))
	{	}
	t3.close();
	int x,ptr;
	ifstream t8;
	strcpy(temp4,temp);
	strcat(temp4,"/doc4.jpg");
	t8.open(temp4);
	t8.read((char*)&ob3,sizeof(ob3));
	//ob3[1].show();
//	getch();
	char temp1[5];
	strcpy(temp1,"0");
	x=((day-1)*7)+((lect-1));
	loading(5,10);
	system("color 70");
	setcolor(2);
	clrscr();
	cout<<"\n\n\t\tFree Classes :";
	ptr=0;
	setcolor(5);
	for(int i=0;i<ob1.rn;i++)
	{	}
	for(int i=0;i<ob1.rn;i++)
	{
		if(strcmp(temp1,ob3[i].lecture[x])==0)
		{
			cout<<ob1.roomn[i]<<"\t";
			ptr++;
		}
	}
	if(ptr==0)
	{
		cout<<"No Free Class Available";;
	}
			setcolor(0);
}
int user()		//function for teachers and studenst use
{
	int day,lect;
	start:
	cout<<"\nTo See Current Free Lectures Select a Working Day\n\t1.Monday\n\t2.Tuesday\n\t3.Wednesday\n\t4.Thursday\n\t5.Friday\n\t\tEnter Current Day :";
	cin>>day;
	if(day<1||day>5)
	{
		setcolor(4);
		cout<<"The wrong Day Selected Try Again:\n\n";
		setcolor(0);
		goto start;
	}
	cout<<"\nEnter The current Lecture Period 1-7 :";
	cin>>lect;
	if(lect<1||lect>7)
	{
		setcolor(4);
		cout<<"Wrong Day Selected Try Again:\n\n";
		setcolor(0);
		goto start;
	}
	calculate(day,lect);
	getch();
}
int main()
{
	system("color f2");
	file();	//to create files abn initialize password  if there is not preasent ¦	
	front();	//for intro of program
	system("color f0");
	loading(5,10);	//for loading animation 
	clrscr();
	mainstart();	//for start main part of the program
}
int mainstart()	//The main part of the program
{
	char choice;
	do{
		start:
		system("color f0");
		clrscr();
		cout<<"\n\nEnter The Mode In Which You Want To Open The Program:\n\n\t1.User Mode\n\t2.Export All Free Classes of A Day\n\t3.Admin Mode\n\t4.Exit\n\t\tEnter Your Choice :";
		cin>>choice;
		switch(choice)
		{
			case '1':
				system("color 70");
				clrscr();
				user();
			break;
			case '2':
				{
				system("color 70");
				exportdata();
				system("start FreeClassList.html");
				getch();
				}
			break;
			case '3':
				pw=1;
				pw=password();
				if(pw==0)
				{
					goto start;
				}
				admin();
			break;
			case '4':
				return 0;
			break;
			default:
			{
				cout<<"\n### THE WRONG CHOICE TRY AGAIN ###\n\n";
			}
		}
	}while(choice!='4');
}

