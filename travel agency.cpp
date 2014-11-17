
#include<conio.h>
#include<ctype.h>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string.h>

struct location
{
    int x;
    int y;
    char cityname[20];
};
struct location cities[8];
int id=1101;
int flag=1,flag1=0;
int telcheck(char *tel); void intascii(char *str);
char underline=175;



void assignlocation()    //x,y assigned based on longitude and latitude
{
		strcpy(cities[0].cityname,"DELHI");
		cities[0].x=28;
		cities[0].y=77;

		strcpy(cities[1].cityname,"MUMBAI");
		cities[1].x=17;
		cities[1].y=72;

		strcpy(cities[2].cityname,"CHENNAI");
		cities[2].x=13;
		cities[2].y=80;

		strcpy(cities[3].cityname,"KOLKATA");
		cities[3].x=21;
		cities[3].y=88;

		strcpy(cities[4].cityname,"BANGALORE");
		cities[4].x=14;
		cities[4].y=74;

	
		strcpy(cities[5].cityname,"HYDERABAD");
		cities[5].x=14;
		cities[5].y=78;

		strcpy(cities[6].cityname,"CHANDIGARH");
		cities[6].x=30;
		cities[6].y=76;

		strcpy(cities[7].cityname,"AHEMEDABAD");
		cities[7].x=22;
		cities[7].y=71;
}
struct date
{
    double day;
    double month;
    double year;
}date_travel;

class customer
{
    protected:
		int cid;
		char cname[50],telephone[11],address[100];
		int nooftrans,type,status;
		void calc_type()
    	{
        if (nooftrans>0)
			if (nooftrans<3)
				type=1;
             else
				if (nooftrans<7)
					type=2;
				else
					type=3;
		else
        	type=0;
	  	}
        public:

            customer()
			{
				status=1;
			}

            void change_status()
            {
            	status=0;
            }

			int getstatus()
			{
				if(status==1)
					return 1;
				else
				return 0;
			}
			
			void initial(int a)
			{
                cid=a;
                nooftrans=0;
				calc_type();
          	}

        

			void setdata();
            void incr_trans()
				{
                    nooftrans++;
							calc_type();
				}

            void showdata()
	
			{
                    std::cout<<"ID:\t"<<cid;
					std::cout<<"\nNAME:\t";
                    puts(cname);
					std::cout<<"\nTELEPHONE NO:\t";
					intascii(telephone);
					std::cout<<"\nADDRESS:\t";
					puts(address);
					std::cout<<"\nNO OF TRANSACTIONS:\t"<<nooftrans;
                    std::cout<<"\nTYPE:"<<type;

            }

            int getid()
			{
                    return cid;
            }

			char* getname()
            {
					return cname;
            }
};

void customer::setdata()
{
		std::cout<<"Enter name: ";
        gets(cname);
        cname[0]=toupper(cname[0]);
        do
			{
                std::cout<<"\nEnter your telephone no....(11 digits with std code)\t";
				std::cin>>telephone;
        	}while (telcheck(telephone));
        std::cout<<"\nEnter Address\t";
        gets(address);

}
int telcheck(char *tel)            //checks for a valid telephone no..
{
        int i=0;
        while (tel[i]!='\0')
		{
            if (!isdigit(tel[i]))
				{
                    std::cout<<"\nINVALID NO.";
                    return 1;
				}
			i++;
		}
		if (i<=11)
            return 0;
		else
        {
         	std::cout<<"\nINVALID NO.";
        	return 1;
		}
}

class ticket:public customer        //INHERITANCE
{
    public:
		
		char origin[20],destination[20];
        float distance;
        float fare;
        date dte;
			int o,d;


        float dist_calc(int o,int d)
        {
            float dis;
			
			dis=sqrt(float((cities[o-1].x-cities[d-1].x)*(cities[o-1].x-cities[d-1].x)+(cities[o-1].y-cities[d-1].y)*(cities[o-1].y-cities[d-1].y)))*125;
            return dis;
		}
        void set (int orgn,int dest)
        {
            o=orgn;d=dest;
			strcpy(origin,cities[o-1].cityname);
           	strcpy(destination,cities[d-1].cityname);
			distance=dist_calc(o,d);
		}

        void f_train()
		{
            fare=distance/1.710*(1-(type*0.05));
			std::cout<<"\n\nMODE:\t\t  TRAIN\n\n"<<"GROSS=\t\t  Rs."<<distance/1.710<<"\nDISCOUNT=\t  "<<type*5<<"%\nNET=\t\t  Rs."<<fare;

        }
        void f_air()
		{
            fare=2.3*distance*(1-(type*0.05));
			std::cout<<"\n\nMODE:\t\t  AIR\n\n"<<"GROSS=\t\t  Rs."<<2.3*distance<<"\nDISCOUNT=\t  "<<type*5<<"%\nNET=\t\t  Rs."<<fare;

        }

     	void show()
        {
			std::cout<<"CUSTOMER ID:\t  "<<cid;
            std::cout<<"\nCUSTOMER NAME:\t  ";
            puts(cname);
            std::cout<<"\nTELEPHONE NO:\t  ";
			intascii(telephone);
            std::cout<<"\nADDRESS:\t  ";
			puts(address);
            std::cout<<"\n\nORIGIN:\t\t  ";
            puts(origin);
            std::cout<<"DESTINATION:\t  ";
			puts(destination);
            std::cout<<"\nDISTANCE:\t  "<<distance<<"km";
			std::cout<<"\n\nDATE OF JOURNEY:  ";
            std::cout<<dte.day<<"/"<<dte.month<<"/"<<dte.year;
            if (flag==1)
                f_air();
				else
                if (flag==0)
					f_train();

            if (flag1==1)
            {
				std::cout<<"\n\nSTATUS:\t\t  ";
				if(status==1)
					std::cout<<"MEMBER";
				else
                    std::cout<<"NOT A MEMBER ANY MORE";
            }
     	}

    void set_date()
        {
            dte.day=date_travel.day;
            dte.month=date_travel.month;
			dte.year=date_travel.year;
        }

};

void exit_menu()
{
        system("cls");
		  std::cout<<"\n\n\n\n\n\n\n\n\n\t\t      Thank you for using this program.\n\n"
                    <<"\t\t\t       Made by:\n\n"
                    <<"\t\t\t      -Rajeev Atmakuri (XII B)\n"
                    <<"\t\t\t      -Deeksha Adil    (XII B)";
		  exit(0);
}
void intascii(char *str)
{
        int i,j=0;
        for(j=0;j<11;j++)
		{
            i=(int)str[j]-48;
				std::cout<<i;

        }
}

int leap (double y)
{
        int n,year;
        year=(int)y;
        n=year/100;
        if (year%100==0)
			{
            if (n%4==0)
            	return 1;
            else
               return 0;
			}
			else
        	{
				if (year%4==0)
                    return 1;
            	else
                    return 0;
			}
}
int datevalidity(date d)
{

    int flagy=0,flagdte=0;
    system("cls");
   	if (d.month==1 || d.month==3 || d.month==5 || d.month==7|| d.month==8|| d.month==10|| d.month==12)
	{
        if (d.day<=31 && d.day>=1)
            flagdte=1;
    }
		else
    {
		if (d.month==4 || d.month==6 || d.month==9 || d.month==11)
        {
            if (d.day<=30 && d.day>=1)
                flagdte=1;
		}

		else
        {
            if (d.month==2 && !leap(d.year))
                if (d.day<=28 && d.day>=1)
					flagdte=1;
            if (d.month==2 && leap(d.year))
				if (d.day<=29 && d.day>=1)
                    flagdte=1;
        }
     }

    if (d.year<2012 || d.year>2013)
	{
        flagy=1;
    }

	if (flagdte==0)
    {
        std::cout<<"\nInvalid date entry. Please enter again.";
        getch();
        return 0;
	}
    else
     	if (flagdte==1)
        {
			if (flagy==1)
			{
				std::cout<<"\nYou can book only for 2012 and 2013";
				getch();
				return 0;
			}
			else
			return 1;
		}
        else
        return 1;
}

void add_cust()        //NEW CUSTOMER
{
	system("cls");
	customer c;
	std::ofstream fout("customer.dat",std::ios::binary | std::ios::app);
	c.setdata();
	c.initial(id);
	fout.write ((char*)&c,sizeof(customer));
	fout.close();
	std::cout<<"\n\nThank you for registering with our agency...\n\n\n"<<"YOUR CUSTOMER ID IS: "<<id<<"\n\nNote: Kindly remember your costomer id for exploring our features.";
	getch();
	id++;
}

void show_cust()    //PRINTS CUSTOMER.DAT ON OUTPUT SCREEN
{
	system("cls");
	std::ifstream fin("customer.dat",std::ios::binary);
	customer c;
	while(fin.read((char *)&c, sizeof(customer)))
	{
		c.showdata();
		std::cout<<"\n";
		for(int i=0;i<80;i++)
			std::cout<<"_";
		std::cout<<"\n";
	}
	fin.close();
}

void add_trans(ticket &tkt)    //TO ADD A TRANSACTION TO TRANS.DAT
{
	std::ofstream fout("trans.dat",std::ios::binary | std::ios::app);
	fout.write((char *)&tkt,sizeof(ticket));
	fout.close();
}

void show_trans()        //TO SHOW CONTENTS OF TRANS.DAT
{
	system("cls");
	ticket temp;
	std::ifstream fin("trans.dat", std::ios::binary);
	while(fin.read((char *)&temp, sizeof(ticket)))
	{
		flag1=1;
		temp.show();
		std::cout<<"\n";
		for(int i=0;i<80;i++)
			std::cout<<"_";
		std::cout<<"\n";
	}
	fin.close();
}
int search(int id,customer &cust);

void modify(int &proceed)    //POLYMORPHISM
	{
	system("cls");
	int id,escape=1;
	float temp;
	customer cust;
	do
	{
		system("cls");
		std::cout<<"\nENTER ID: (Enter 0 to go back to menu):\t";
		id=-1;
		if(!(std::cin>>temp))
		{
			std::cin.clear();
			std::cin.ignore(10000,'\n');
		}
		else
			if(temp==floor(temp))
				id=int(temp);
		if(id==0)
		{
			proceed=1;
			return;
		}
		escape=search(id,cust);

	}while(!escape);
	if(escape==2)
	{
		proceed=1;
		return;
	}

	std::ofstream fout("temp.dat",std::ios::binary);
	std::ifstream fin("customer.dat",std::ios::binary);
	customer c;
	while (fin.read((char*)&c,sizeof(customer)))
	{
		if (id==c.getid())
		{  
			system("cls");
			std::cout<<"Data to be modified is:\n\n";
			c.showdata();
			std::cout<<"\n\nEnter modified data:\n\n";
			c.setdata();
		}
		fout.write((char*)&c,sizeof(customer));

	}
	remove ("customer.dat");
	rename ("temp.dat","customer.dat");
	fout.close();
}

void modify(customer &cust)                              //IMPLICIT MODIFICATION (cross transaction)
{
	std::ofstream fout("temp.dat",std::ios::binary);
	std::ifstream fin("customer.dat",std::ios::binary);
	customer temp;
	while (fin.read((char*)&temp,sizeof(customer)))
	{
		if (cust.getid()==temp.getid())
			fout.write ((char*)&cust,sizeof(customer));
		else
			fout.write ((char*)&temp,sizeof(customer));
	}
	remove ("customer.dat");
	rename ("temp.dat","customer.dat");
	fout.close();
}

void modify_trans(int id)
{
	std::ofstream fout("temp1.dat",std::ios::binary);
	std::ifstream fin("trans.dat",std::ios::binary);
	ticket t;
	while (fin.read((char*)&t,sizeof(ticket)))
	{
		if(id==t.getid())
			t.change_status();
		fout.write((char*)&t,sizeof(ticket));
	}
	remove ("trans.dat");
	fin.close();
	rename ("temp1.dat","trans.dat");
	fout.close();
}


void delete_record(int &back)
{
	system("cls");
	int id,escape=1;char opt;
	customer cust;
	float temp;
	do
	{
		system("cls");
		std::cout<<"\nENTER ID(enter 0 if you want to go back):\t";
		id=-1;
		if(!(std::cin>>temp))
		{
			std::cin.clear();
			std::cin.ignore(10000,'\n');
		}
		else
			if(temp==floor(temp))
				id=(int)temp;
		
		if(id==0)
		{
			back=1;
			return;
		}
		escape=search(id,cust);

	}while(!escape);
	
	if(escape==2)
	{
		back=1;
		return;
	}
	std::ofstream fout("temp.dat",std::ios::binary);

	std::ifstream fin("customer.dat",std::ios::binary);

	customer c;

	while (fin.read((char*)&c,sizeof(customer)))
	{
		if (id==c.getid())
		{
			std::cout<<"\n\n";
			c.showdata();
			std::cout<<"\n\nAre you sure that you want to delete the record?"
				<<"\n1)Yes (y)."
				<<"\n2)No(n).";
		  	do{opt=getch();}while(opt!='y' && opt!='n');
			if(opt=='y')
			{
		    	modify_trans(id);
				continue;
			}
			else
			{
				fin.close();
				remove ("temp.dat");
				fout.close();
				back=1;
				return;
			}
		}
		fout.write((char*)&c,sizeof(customer));
	}
	delete ("customer.dat");
	fin.close();
	rename ("temp.dat","customer.dat");
	fout.close();
}

int search(int id,customer &cust)
{
	int flag=0;char opt;
	if(id!=0)
	{
		std::ifstream fin("customer.dat", std::ios::binary);
		while(fin.read((char *)&cust, sizeof(customer)))
		{
			if(id==cust.getid())
			{
				flag=1;
				return flag;
			}
		}
		fin.close();
	}
	system("cls");
	std::cout<<"\n\n\n\n\n\n\n\n\t\t             Invalid id.\n\n"
		<<"\t\t             1)Enter again.\n"
		<<"\t\t             2)Go back to menu.\n\n"
		<<"\t\t             3)Exit.";
	do
	{
		opt=getch();
	}while(opt<'1' || opt>'3');

	if(opt=='3')
		exit_menu();
	else
		if(opt=='2')
			return 2;

	return flag;
}

void cust_menu();

void cust_trans(int &proceed)
{
	int id,again;
	ticket t;
	char opt;
	float temp;
	std::ifstream cust("trans.dat");
	cust.close();
	do
	{
	cust.open("trans.dat",std::ios::in|std::ios::binary);
	cust.seekg(0);
	system("cls");
	again=0;

	std::cout<<"\nEnter id (enter 0 if you want to go back):";
	id=-1;
	if(!(std::cin>>temp))
	{
		std::cin.clear();
		std::cin.ignore(10000,'\n');
	}
	else
	if(temp==floor(temp))
		id=(int)temp;
	system("cls");
	if(id==0)
	{
		proceed=1;
		return;
	}

	if(id!=-1)
	{
		while (cust.read((char*)&t,sizeof(ticket)))
		{
			if (id==t.getid() && t.getstatus())
			{
				flag1=0;
				t.show();
				std::cout<<"\n";
				for (int i=0;i<80;i++)
					std::cout<<"_";
				return;
			}
		}
	}
	cust.close();


	system("cls");
	std::cout<<"\n\n\n\n\n\n\n\n              Incorrect id or you havent made a transaction yet.\n\n"
		<<"\t\t             1)Enter again.\n"
		<<"\t\t             2)Go back to menu.\n\n"
		<<"\t\t             3)Exit.";
	do
	{
		opt=getch();
	}while(opt<'1' || opt>'3');
	
	if(opt=='3')
		exit_menu();
	else
		if(opt=='2')
		{
			proceed=1;
			return;
		}
	if (opt=='1')
		again=1;
	}while(again==1);
}

void book_tkts(int &proceed)
{
	system("cls");
	customer cust;
	ticket tkt;
	int id,escape=1,i,validity=1;
	char opt,orgn,dest,mode;
	float temp;

	do
	{
		system("cls");
		std::cout<<"\nENTER ID (enter 0 if you want to go back)\n\n";
		id=-1;

		if(!(std::cin>>temp))
		{
			std::cin.clear();
			std::cin.ignore(10000,'\n');
		}
		else
			if(temp==floor(temp))
				id=int(temp);

		if(id==0)
		{
			proceed=1;
			return;
		}
		escape=search(id,cust);

	}while(!escape);

	if(escape==2)
	{
		proceed=1;
		return;
	}
	system("cls");

	std::ifstream fin("customer.dat",std::ios::binary);
	while(fin.read((char *)&tkt, sizeof(customer)))
	{
		if(tkt.getid()==cust.getid())
		break;
	}

	do
	{
		system("cls");
		system("cls");
		std::cout<<"Hello "<<cust.getname();
		while(1)
		{
			std::cout<<"\n\nEnter your origin:\n\n";
			for(i=0;i<8;i++)
				std::cout<<(i+1)<<")"<<(cities[i].cityname)<<"\n\n";

			do
			{
				orgn=getch();
			}while(orgn<'1' || orgn>'8');
			
			system("cls");
			std::cout<<"\nEnter your destination:\n"
				<<"\nFROM "<<cities[int(orgn)-49].cityname<<" TO:\n\n";
			for(i=0;i<8;i++)
				std::cout<<(i+1)<<")"<<(cities[i].cityname)<<"\n\n";
			do
			{
				dest=getch();
			}while(dest<'1' || dest>'8');

			if (orgn==dest)
			{
				std::cout<<"\nChose a destination different from the origin.\nPress any key to enter origin and destination again.";
				getch();
				system("cls");
				continue;
			}
			else
			break;

		}

		system("cls");
		std::cout<<"FROM "<<cities[int(orgn)-49].cityname<<" TO "<<cities[int(dest)-49].cityname;
		tkt.set(int(orgn)-48,int(dest)-48);
		do
		{
			system("cls");
			char ch;
			int x,f;
			date_travel.day=0;
			date_travel.month=0;
			date_travel.year=0;
			system("cls");
			std::cout<<"\n\nEnter date in format(DD/MM/YYYY)"  ;
			for (f=1;f<=2;f++)
			{
				ch=getch();
				if(!isdigit(ch))
				{
				  	f--;
				  	continue;
				}
				x=ch-48;
				date_travel.day+=x*pow((double)10,2-f);
				std::cout<<x;

			}
			std::cout<<"/";
			for (f=1;f<=2;f++)
			{
				ch=getch();
				if(!isdigit(ch))
				{
				  f--;continue;
				}
				x=ch-48;
				date_travel.month+=x*pow((double)10,2-f);
				std::cout<<x;
			}
			std::cout<<"/";
			for (f=1;f<=4;f++)
			{
				ch=getch();
				if(!isdigit(ch))
				{
					f--;
					continue;
				}
				x=ch-48;
				date_travel.year+=x*pow((double)10,4-f);
				std::cout<<x;
			}
			getch();
			validity=datevalidity(date_travel);
		}while(!validity);
		tkt.set_date();
		std::cout<<"\nFARE:";
		tkt.f_train();
		tkt.f_air();
		std::cout<<"\n\n\nIf this is your first transaction, you win a discount coupon for your next one! ";
		std::cout<<"\n\n\nENTER UR MODE(Train (t), Air (a))\t";
		do
		{
			mode=getch();
		}while(mode!='a' && mode!='t');
		
		if (mode=='a')
			flag=1;
		else
			if(mode=='t')
				flag=0;
		
		system("cls");
		tkt.show();

		std::cout<<"\n\nKINDLY CONFIRM YOUR BOOKING";
		std::cout<<"\n\n1)Confirm."
			<<"\n2)Make changes."
			<<"\n3)Go to customer menu. (skip tkt booking)";
		do
		{
			opt=getch();
		}while(opt<'1' || opt>'3');

	}while(opt=='2');
	if(opt=='1')
	{
		cust.incr_trans();
		modify(cust);
		add_trans(tkt);
	}
	else
		cust_menu();
}

void cust_menu()
{
	
	system("cls");
	char opt;
	int proceed=0;
	while(1)
	{
		system("cls");
		proceed=0;
		std::cout<<"\n\n\n\n\n\n\t                       CUSTOMER MENU\n"
			<<"\t                       ";
		for(int z=1;z<=13;z++)
			std::cout<<underline;
		std::cout<<"\n";
		std::cout<<"\t\t       Select option:\n\n"
			<<"\t\t       1)Add record. (new customer).\n"
			<<"\t\t       2)Modify record. (existing customer).\n"
			<<"\t\t       3)Make my trip. (book tickets).\n"
			<<"\t\t       4)View your transactions.\n"
			<<"\t\t       5)Go to main menu.\n"
			<<"\t\t       6)EXIT.";

		do
		{
			opt=getch();
		}while(opt<'1' || opt>'6');

		switch(opt)
		{
			case '1':
				add_cust();
				break;

			case '2':
				modify(proceed);
				if(proceed==1)
					continue;
				break;

			case '3':
				book_tkts(proceed);
				if(proceed==1)
					continue;
				break;

			case '4':
				cust_trans(proceed);
				if(proceed==1)
					continue;
				getch();
				break;

			case '5':
				return;

			case '6':
				exit_menu();
		}

		system("cls");
		std::cout<<"\n\n\n\n\n\n\n\n\t         Your operation was successful.\n\n\t\t\t Select option:\n\n";
		std::cout<<"\t         1)Continue to customer menu.\n"
			<<"\t         2)Go to main menu.\n\n"
			<<"\t         3)Exit.";
		do
		{
			opt=getch();
			if(opt=='3')
				exit_menu();
			else
				if(opt=='2')
					return;
		}while(opt!='1');

	}
}

void staff_menu()
{
	system("cls");
	char opt, password[]="computer",check[15];
	int pass=0,back=0,repeat=0,passctr=0;
	system("cls");

	std::cout<<"\n\n\n\n\n\n\n\n\t\t              Select option:\n\n"
		<<"\t\t              1)Staff login.\n"
		<<"\t\t              2)Go to main menu.\n\n"
		<<"\t\t              3)Exit.\n";
	do
	{
		opt=getch();
	}while(opt<'1' || opt>'3');

	system("cls");
	switch(opt)
	{
	case '1':
	{
		do
		{
			system("cls");
			repeat=0;
			std::cout<<"\n\n\n\n\n\n\n\n\n\t               Enter staff password (max 10 char):\n\n\t\t                   ";
			for(int i=0;i<11;i++)
			{
				check[i]=getch();
				if(check[i]==8 && i>=1)
				{
					check[i]='\0';
					std::cout<<"\b"<<" "<<"\b";
					i=i-2;
					continue;
				}
				else
					if(check[i]==8)
					{
						i=-1;
						continue;
					}
				if(check[i]==13)
				{
					check[i]='\0';
					break;
				}
				std::cout<<"*";
			}
			system("cls");
			if(strcmp(password,check)==0)
			{
				std::cout<<"\n\n\n\n\n\n\n\n\n\t\t       Correct password.You may proceed.\n\n"
					<<"\t\t                press any key.";
				getch();
				pass=1;
			}
			else
			{
				passctr++;
				if (passctr>=3)
				{
					std::cout<<"\n\n Login failed. Restart your session";
					getch();
					return;
				}
				std::cout<<"\n\n\n\n\n\n\n\n\n\t\t            Incorrect password.\n"
			    	<<"\n\t\t            1)Try again."
			    	<<"\n\t\t            2)Go to main menu.\n"
			    	<<"\n\t\t            3)Exit.";
				do
				{
					opt=getch();
				}while(opt!='1' && opt!='2' && opt!='3');
				if(opt=='1')
					repeat=1;
				else
					if(opt=='2')
						return;
					else
						exit_menu();

			}
		}while(repeat==1);
		break;

	}
	case '2':
		return;

	case '3':
		exit_menu();


	}

	while(pass)
	{
		system("cls");
		back=0;
		std::cout<<"\n\n\n\n\n\n\t                         STAFF MENU\n"
			<<"\t                         ";
		for(int z=1;z<=10;z++)
			std::cout<<underline;
		std::cout<<"\n";
		std::cout<<"\t\t        Select option:\n\n"
			<<"\t\t        1)View all customer records.\n"
			<<"\t\t        2)View all transaction records.\n"
			<<"\t\t        3)Delete a customer record.\n"
			<<"\t\t        4)Delete transaction history.\n"
			<<"\t\t        5)Truncate Database.\n"
			<<"\t\t        6)Go to main menu.\n"
			<<"\t\t        7)EXIT.\n";

		do
		{
			opt=getch();
		}while(opt<'1' || opt>'7');

		switch(opt)
		{
			case '1':
				show_cust();
				getch();
				break;                

			case '2':
				show_trans();
				getch();
				break;

			case '3':
				delete_record(back);
				if(back)
					continue;
				break;            

			case '4':
			{
				std::ofstream fout("trans.dat", std::ios::binary | std::ios::trunc);
				fout.close();
				break;
			}
			case '5':
				{
					system("cls");
					std::cout<<"\n\n\n\n\n\n\n\n\t         Are you Sure you want to truncate database? y/n";
					do{opt=getch();}while(opt!='y' && opt!='n');
					if(opt=='n')
						break;
					std::ofstream fout1("customer.dat", std::ios::binary | std::ios::trunc);
					fout1.close();
					std::ofstream fout2("trans.dat", std::ios::binary | std::ios::trunc);
					fout2.close();
					id=1101;
					break;
				}
			
			case '6':
					return;

			case '7':
				exit_menu();

			default:
				continue;
		}
		system("cls");
		std::cout<<"\n\n\n\n\n\n\n\n\t         Your operation was successful. Select option:\n\n";
		std::cout<<"\t         1)Continue to staff menu.\n"
			<<"\t         2)Go to main menu.\n\n"
			<<"\t         3)Exit.";
		do
		{
			opt=getch();
			if(opt=='3')
				exit_menu();
			else
				if(opt=='2')
					return;
		}while(opt!='1');

	}

}


int main()
{
	assignlocation();
	char opt;customer c;
	std::ifstream fin("customer.dat", std::ios::binary);
	while(fin.read((char *)&c,sizeof(customer)))
		if(c.getid()>=1000 && c.getid()<=2000)
			id=c.getid() + 1;

	fin.close();
	std::cout<<id;
	getch();
	while(1)
	{
		system("cls");
		std::cout<<"\n\n\n\n\n\n\t                         MAIN MENU\n"
			<<"\t                         ";
		for(int z=1;z<=9;z++)
			std::cout<<underline;
		std::cout<<"\n\n";
		std::cout<<"\t          Welcome to the ABC travel agency. Are you a:\n\n"
			<<"\t          1)Customer.\n"
			<<"\t          2)Staff Member.\n\n"
			<<"\t          Enter 3 if you wish to exit.\n";

		opt=getch();
		switch(opt)
		{
		case '1':
			cust_menu();
			continue;

		case '2':
			staff_menu();
			continue;

		case '3':
			exit_menu();

		default:
			continue;
		}
	}
	return 0;
}