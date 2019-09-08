//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
//********************functions names*************************************
void intro();
int checkpass();
void admin_menu();
void intromain();
void customer_info();
void meter_info();
void transcations();
void reports();
void displaytrans();
//********************customer functions*********************************
void write_customer();
void modify_customer_record(int);
void delete_cust_record(int);
int getcustno();
int checkmetergentrans();
//********************customer functions*********************************
//******************meter info***********************
void write_meter();
int getmeterno();
void delete_meter(char mn[25]);
int checkmetergen();
//***************************************************
void write_bills(char mnum[25]);
void  displaycust_meterno(char mnum2[25],int k);
int checkbillpaid(char mn[25]);
void savebillrecord(int r,char mn[25]);
//**********************reports********************
void display_meters();
int getbillno();
void paid_bills(char mnum[25]);
void overwritebillrecord(char mn[25]);
void display_customer();
void display_bills();
void display_billrecords();
void display_custwithbills(char mnum[25]);
void modify_bills(char mnum[25]);
void setoldleftamount(int r,char mn[25],float amtaddnxt,float amtdeduct);
//**************************************************
struct billprevrecord
{
  int bno;
  char mtrno[25];
  float amtadd;
  float amtdud;
  char status;
};
struct billrecord
{
 int billno;
 char mrtno[25];
 char billstatus;
};
struct con_date
{
  int dd;
  int mm;
  int yy;
};
struct prevbillinfo
{
  int meterno;
  int billno;
  char pstatus;
};
//*****************classes name *****************************************
//*********************meter no*********************************8
class meter
{
  int meterno;
  char ser[25];
  char meterreg[25];
  char status;
  public:
  int getmeterno()
  { return meterno; }
  char *getmeterreg(){ return meterreg; }
  char getmeterstatus()
  { return status; }
  char *getseries(){ return ser; }
  void writemeter(int mt,char s[25],char mtreg[25],char st)
  {
	 meterno=mt;
	 strcpy(ser,s);
	 strcpy(meterreg,mtreg);
	 status=st;
  }
  void setmeterstatus()
  { status='Y';  }
  void showallmeters(int c)
	{
	 gotoxy(25,c);
	 cout<<meterreg<<setw(15)<<status;
	 }
	 void showmeters()
	 {
	  gotoxy(7,10);
	  cout<<"METER NO:"<<setw(10)<<meterreg<<setw(10)<<"STATUS:"<<status;
	  gotoxy(5,11);
	  cout<<"===========================================================";
	 }
};
//*********************meter no*********************************8
class trans
{
  int tno;
  char metrno[25];
  int billno;
  con_date ddofpaid;
  float billamt,amtpaid;
  float addtonextamtbill,deductamt;
  char transstatus;
  public:
  int gettno()
  { return tno; }
  char *getmetno(){ return metrno; }
  int getbillno() { return billno; }
  float getprevamt() { return addtonextamtbill;  }
  float getdeductamt() { return deductamt; }
  char getstatus()  { return transstatus;}
  void setstatus(char s1)
  {	transstatus=s1;  }
 void settrans(int t1,char mt1[25],int bl1,con_date d1,float billamt1,float amtpaid1,float amtnxt,float dduct)
 {
  tno=t1;
  strcpy(metrno,mt1);
  billno=bl1;
  ddofpaid=d1;
  billamt=billamt1;
  amtpaid=amtpaid1;
  addtonextamtbill=amtnxt;
  deductamt=dduct;
  transstatus='Y';
 }
  void showalltrans(int c)
{
 gotoxy(3,c);
 cout<<tno<<setw(10)<<metrno<<setw(5)<<billno<<setw(5)<<ddofpaid.dd<<"-"<<ddofpaid.mm<<"-" << ddofpaid.yy << setw(10)<<billamt<<setw(10)<<amtpaid<<setw(10)<<addtonextamtbill<<setw(8)<<deductamt<<setw(10)<<transstatus;
}};
//************************billing class******************************
class billing
{
 int bno;
 char mno[25];
 int curr_reading,prev_reading;
 int unit;
 float amt,otheramt,netamt;
 char status;
 public:
 int getbno()
 { return bno; }
 char *getmtn() { return mno; }
 int getcurrread() { return curr_reading; }
 int getprvread() { return prev_reading; }
 int getunit() { return unit; }
 char getstatus() { return status; }
 float getnetamt() { return netamt;}
 void setstatus(char s)
 { status=s; }
void addbill(int bid,char mtno[25])
{
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(5,8);
  cout<<"BILL NO:";
  bno=bid;
  gotoxy(15,8);
  cout<<bno;
  gotoxy(35,8);
  cout<<"METER NO:";
  gotoxy(55,8);
  strcpy(mno,mtno);cout<<mno;
  gotoxy(5,9);
  cout<<"CURRENT READING  | - |  PREVIOUS READING";
  gotoxy(15,10);
  cin>>curr_reading;
  gotoxy(25,10);
  cin>>prev_reading;
  gotoxy(5,11);
  unit=(curr_reading-prev_reading);
  cout<<"UNITS CONSUMED:";
  gotoxy(35,11);
  cout<<unit;
	if(unit>=0 && unit<=100)
	amt=unit*2.5;
	else if(unit>100 && unit<=200)
	amt=unit*3.0;
	else if(unit>200 && unit<=350)
	amt=unit*3.5;
	else if(unit>350 && unit<=450)
	amt=unit*4.2;
	else if(unit>450)
	amt=unit*5.5;
  gotoxy(55,11);
  cout<<"AMOUNT";
  gotoxy(65,11);
  cout<<amt;
  gotoxy(5,12);
  cout<<"OTHER CHARGES+tax";
  cin>>otheramt;
  netamt=amt+otheramt+250;
  gotoxy(35,12);
  cout<<"TOTAL AMOUNT:";
  gotoxy(55,12);
  cout<<netamt;
  status='Y';
  gotoxy(5,13);
  cout<<"=====================================================================";
}
 void showallbill(int c)
{
 gotoxy(1,c);
 cout<<bno<<setw(12)<<mno<<setw(12)<<curr_reading<<"-" <<prev_reading<< setw(10)<<unit <<setw(10)<<amt << "+" <<otheramt<<"="<<setw(12)<<netamt<<setw(10)<<status;
}
void showbill(int bid)
{
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(5,8);
  cout<<"BILL NO:";
  bno=bid;
  gotoxy(15,8);
  cout<<"BOO"<<bno;
  gotoxy(35,8);
  cout<<"METER NO:";
  gotoxy(55,8);
  cout<<mno;
  gotoxy(5,9);
  cout<<"CURRENT READING    -    PREVIOUS READING";
  gotoxy(5,10);
  cout<<curr_reading<<"-----"<<prev_reading;
  gotoxy(45,10);
  cout<<"UNITS CONSUMED:";
  gotoxy(55,10);
  cout<<unit;
  gotoxy(15,11);
  cout<<"AMOUNT";
  gotoxy(35,11);
  cout<<amt;
  gotoxy(5,12);
  cout<<"OTHER CHARGES";
  gotoxy(25,12);
  cout<<otheramt;
  gotoxy(5,12);
  cout<<"TOTAL AMOUNT:";
  gotoxy(15,12);
  cout<<netamt;
  gotoxy(35,12);
  cout<<"STATUS: "<<status;
  gotoxy(5,13);
  cout<<"=====================================================================";
}
void modifybill(int bid,char mtno[25],int cr,int pr)
{
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(5,8);
  cout<<"BILL NO:";
  bno=bid;
  gotoxy(15,8);
  cout<<"BOO"<<bno;
  gotoxy(35,8);
  cout<<"METER NO:";
  gotoxy(55,8);
  strcpy(mno,mtno);cout<<mno;
  gotoxy(5,9);
  cout<<"CURRENT READING  -  PREVIOUS READING";
  gotoxy(15,9);
  if(cr!=0)
  {
  curr_reading=cr;
  }
  cout<<curr_reading;
  gotoxy(25,9);
  if(pr!=0)
  {
  prev_reading=pr;}
  cout<<prev_reading;
  gotoxy(5,10);
  unit=(curr_reading-prev_reading);
  cout<<"UNITS CONSUMED:";
  gotoxy(25,10);
  cout<<unit;
  gotoxy(5,11);
  if(unit>=0 && unit<=100)
	amt=unit*2.5;
	else if(unit>100 && unit<=200)
	amt=unit*3.0;
	else if(unit>200 && unit<=350)
	amt=unit*3.5;
	else if(unit>350 && unit<=450)
	amt=unit*4.2;
	else if(unit>450)
	amt=unit*5.5;
  gotoxy(15,11);
  cout<<"AMOUNT";
  gotoxy(35,11);
  cout<<amt;
  gotoxy(5,12);
  cout<<"OTHER CHARGES";
  gotoxy(35,12);
  cout<<otheramt;
  netamt=amt+otheramt;
  gotoxy(5,12);
  cout<<"TOTAL AMOUNT:";
  gotoxy(15,12);
  cout<<netamt;
  status='Y';
  gotoxy(5,13);
  cout<<"=====================================================================";
}
void setnewbillreading(int currnt)
{
curr_reading=currnt;
unit=(curr_reading-prev_reading);
   if(unit>=0 && unit<=100)
	amt=unit*2.5;
	else if(unit>100 && unit<=200)
	amt=unit*3.0;
	else if(unit>200 && unit<=350)
	amt=unit*3.5;
	else if(unit>350 && unit<=450)
	amt=unit*4.2;
	else if(unit>450)
	amt=unit*5.5;
	netamt=amt+otheramt;
}};
//*******************************customer details
class customer
{        			int  cust_id;
			char fname[15],lname[15];
			char hn[10],add1[20],add2[20];
			char phno[15];
			char meterno[25];
			con_date dtconn;
 public:
		 char *getmetern(){ return meterno; }
		 int getcustid()		 { return cust_id; }
		 char *getfname()		 { return fname; }
		 char *getlname()		 { return lname; }
		 con_date getdate()	 { return dtconn; }
		 void setdate(con_date d1)
		 { dtconn.dd=d1.dd;	dtconn.mm=d1.mm;  dtconn.yy=d1.yy;	 }
//**************************add the customer details**********************
void addcustomer(int cid,char m[25])
{
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(5,8);
  cout<<"CUST NO:";
  cust_id=cid;
  gotoxy(15,8);
  cout<<cust_id;
  gotoxy(25,8);
  cout<<"FIRST NAME:";
  gotoxy(40,8);
  cin>>fname;
  gotoxy(50,8);
  cout<<"LAST NAME:";
  gotoxy(65,8);
  cin>>lname;
  gotoxy(5,9);
  cout<<"ADDRESS[HNO - ADDRESS1  - ADDRESS2]";
  gotoxy(15,10);
  cin>>hn;
  gotoxy(25,10);
  cin>>add1;
  gotoxy(45,10);
  cin>>add2;
  gotoxy(5,11);
  cout<<"PHONE NUMBER";
  gotoxy(25,11);
  cin>>phno;
  gotoxy(5,12);
  cout<<"METER NO";
  strcpy(meterno,m);
  gotoxy(35,12);
  cout<<meterno;
  gotoxy(5,13);
  cout<<"DATE OF CONNECTION:[DD-MM-YY]";
  gotoxy(5,14);
  cin>>dtconn.dd;
  gotoxy(25,14);
  cin>>dtconn.mm;
  gotoxy(35,14);
  cin>>dtconn.yy;
  gotoxy(5,15);
  cout<<"=====================================================================";
}
void modifydatacust();
//********************modify the customer details ****************************
  void showdatamulti_cust()
  {
  gotoxy(5,7);
  cout<<"======================================================================";
  gotoxy(8,8);
  cout<<"CUST NO:";
  gotoxy(25,8);
  cout<<cust_id;
  gotoxy(35,8);
  cout<<"NAME OF CUSTOMER:";
  gotoxy(55,8);
  cout<<fname<<"-"<<lname;
  gotoxy(8,9);
  cout<<"ADDRESS";
  gotoxy(25,9);
  cout<<hn<<"-"<<add1<<","<<add2;
  gotoxy(40,9);
  cout<<"PHONE NO.:";
  gotoxy(55,9);
  cout<<phno;
  gotoxy(8,10);
  cout<<"METER NO:";
  gotoxy(25,10);
  cout<<meterno;
  gotoxy(35,10);
  cout<<"DATE OF CONNECTION:";
  gotoxy(53,10);
  cout<<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;
  gotoxy(5,11);
  cout<<"=====================================================================";
}
 void showallcust(int c)
{
 gotoxy(1,c);
 cout<<fname<<"-"<<lname<<setw(8)<<hn<<"-"<<add1<<","<<add2<<setw(15) <<phno<<setw(10)<<meterno <<setw(10) <<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;
}
 void showallcustdetails(int c)
	{
 gotoxy(1,c);
 cout<<"FIRST NAME:"<<setw(8)<<fname<<setw(15)<<"LAST NAME:"<<setw(8) <<lname<<setw(15) <<"ADDRESS:" <<setw(8)<<hn<<"-"<<add1<<","<<add2;
 gotoxy(1,c+1);
 cout<<"PHONE NO:"<<setw(10)<<phno<<setw(10)<<"METER NO:"<<setw(10)<<meterno <<setw(15)<<"DATEOFCONN." <<setw(10)<<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;
}};
void customer::modifydatacust()
{
 char tmpnm[25],tmpnm2[25],tmpphno[15],tmpmtno[15],choice='n';
gotoxy(5,14);
  cout<<"===================WANT TO MODIFY ===============================";
  gotoxy(10,15);
  cout<<"CUST NO:";
  gotoxy(25,15);
  cout<<cust_id;
  gotoxy(40,15);
  cout<<"FIRST NAME:";
  gotoxy(60,15);
  cout<<fname;
  gotoxy(10,17);
  cout<<"Want to change the First Name";
  gotoxy(50,17);
  int flag=0;
  while(1)
  {
	  gets(tmpnm);
	  if(strlen(tmpnm)!=0)
	  {
			flag=1;
			break;
	   }
	  if(strlen(tmpnm)==0)
	 { flag=0;
	    break;
	}
  }
  if(flag==1)
  { strcpy(fname,tmpnm);
  }
  gotoxy(5,18);
  //****************COMPANY NAME TO BE MODIFY
  cout<<"LAST NAME:";
  gotoxy(20,18);
  cout<<lname;
  gotoxy(35,18);
  cout<<"Want to change the Last Name";
  gotoxy(65,18);
  flag=0;
  while(1)
  {
	  gets(tmpnm2);
	  if(strlen(tmpnm2)!=0)
	  {
			flag=1;
			break;
  	   }
	  if(strlen(tmpnm2)==0)
		 { flag=0;
		  break;
		}
  }
  if(flag==1)
  { strcpy(lname,tmpnm2);
  }
  //*****************class to be modify
  gotoxy(5,19);
  //****************CLASS NAME TO BE MODIFY
  cout<<"PHONE NO.:";
  gotoxy(20,19);
  cout<<phno;
  gotoxy(35,19);
  cout<<"Want to change the Phone No.";
  gotoxy(65,19);
  flag=0;
  while(1)
  {
	  gets(tmpphno);
	  if(strlen(tmpphno)!=0)
	  {
			flag=1;
			break;
	   }
	  if(strlen(tmpphno)==0)
		 { flag=0;
		  break;
		}
  }
  if(flag==1)
  { strcpy(phno,tmpphno);
  }
	//****************************************************
char mch;
gotoxy(5,20);
cout<<"METER NO.:";
  
//****************CLASS SEC TO BE MODIFY
  gotoxy(20,20);
  cout<<meterno;
  gotoxy(35,20);
  cout<<"Want to change the Meter:[y or n]";
  gotoxy(70,20);
  cin>>mch;
  if(mch=='y')
  {
  //******************get the meter no
	fstream objiff;
	meter mt;
               char meternum[25];
	objiff.open("meter.dat",ios::binary|ios::in|ios::out);
	objiff.seekg(0,ios::beg);
               int pos=0;
	if(!objiff)
	{
	cout<<"File could not be open !! Press any Key...";
	}
	else{
//**************temporary hiding these lines
	 while(objiff.read((char *) &mt, sizeof(meter)))
	{
		if(mt.getmeterstatus()=='N')
		{
		pos=(int)objiff.tellg();
		flag=1;
		break;
		}
	}
	 strcpy(meternum,mt.getmeterreg());
	 mt.setmeterstatus();
	 objiff.seekp(pos-sizeof(meter),ios::beg);
	 objiff.write((char *) &mt, sizeof(meter));
	 }
objiff.close();
 //************************************************************
 strcpy(meterno,tmpmtno);
  }
gotoxy(5,21);
cout<<"ADDRESS:";
gotoxy(20,21);
cout<<hn<<"-"<<add1<<","<<add2;
gotoxy(35,21);
cout<<"Want to change the address[y yes or n no]";
gotoxy(65,21);
cin>>choice;
 if(choice=='y')
  {
  gotoxy(20,22);
  cout<<"hno,address1,address2";
  gotoxy(35,22);
  cin>>hn>>add1>>add2;
  }
//***************************************************
 gotoxy(5,23);
cout<<"=====================================================================";
  }
//*****************classes name ends**************************************
//*********************welcome page*************************************
void intro()
{ clrscr();
 gotoxy(4,2);
 cout<<"***************************ELECTRICITY BILLING**************************";
 gotoxy(12,4);
 cout<<"==============================MANAGEMENT================================";
 gotoxy(5,5);
 cout<<"******************************S=Y=S=T=E=M*******************************";
 gotoxy(50,10);
 cout<<"PROJECT:";
 gotoxy(50,12);
 cout<<"MADE BY : STUDENT NAME";
 gotoxy(8,14);
 cout<<"--------------------DOON PUBLIC SCHOOL,HALDWANI------------------------";
 gotoxy(8,15);
 cout<<"------------------CLASS : XII B ( COMPUTER SCIENCE )-------------------";
 getch();
}
//*********************welcome page*************************************
//************************MAIN STARTS ***************************************
void main()
{
  char ch;
  intro();
  if(checkpass()==0)
  {
  do
	 {
	  //****************TEMPORARY***********************
		clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"=================MAIN MENU====================";
		gotoxy(28,7);
		cout<<"01. REPORT GENERATOR";
		gotoxy(28,8);
		cout<<"02. ADMINISTRATOR";
		gotoxy(28,9);
		cout<<"03. EXIT";
		gotoxy(20,10);
		cout<<"==============================================";
		gotoxy(25,12);
		cout<<"Please Select Your Option (1-3) ";
		gotoxy(30,14);
		ch=getche();
	  switch(ch)
	  {
		 case '1':
		 reports();
				break;
		  case '2': admin_menu();
				 break;
		  case '3':exit(0);
		}
	 }while(ch!='3');
}
else
{exit(0);}
}


//****************************FUNCTIONS STARTS HERE************************
//******************************login name and password****************
int checkpass()
{
  char nm[20];
  char pass[10];
  clrscr();
  intromain();
  gotoxy(20,20);
  cout<<"PLEASE ENTER THE USER NAME:";
  gotoxy(20,21);
  cin>>nm;
  clrscr();
  gotoxy(20,20);
  cout<<"PLEASE ENTER THE PASSWORD:";
  gotoxy(20,21);
  cin>>pass;
  if(strcmp(nm,"admin")==0 && strcmp(pass,"1234")==0)
  {
  return 0;
  }else
  {
  return 1;
  }
}
//*******************introduction
void intromain()
{  clrscr();
	gotoxy(1,2);
	cout<<"*************************ELECTRICITY****BILLING*****SYSTEM**********************";
	gotoxy(1,3);
	cout<<"*************************************PROJECT***********************************";
}
//**************************admin starts**********************************
void admin_menu()
{
  clrscr();
  char ch2='\0';
  //************************************************************
	 clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"=================ADMIN MENU====================";
		gotoxy(22,7);
	cout<<"1.CUSTOMER'S INFORMATION";
	gotoxy(22,8);
	cout<<"2.METER'S INFORMATION";
	gotoxy(22,9);
	cout<<"3.BILLING/TRANSCATIONS";
	gotoxy(22,10);
	cout<<"4.BACK TO MAIN MENU";
	gotoxy(22,12);
	cout<<"Please Enter Your Choice (1-4) ";
	gotoxy(23,16);
	//**********************************************************
  ch2=getche();
  switch(ch2)
  {
		case '1':
			if(checkmetergen()==1)
			{
			customer_info();
			}else
			{
			clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"Please enter the meter information first";
		getch();
			}
		break;
		case '2':
			meter_info();
			break;
		case '3':
               		if(checkmetergentrans()==1)
			{
			transcations();
			}else
			{
                 		clrscr();
			intromain();
			gotoxy(20,6);
			cout<<"Please enter the meter information first";
			}
               getch();
			break;
		case '4':
			break;
		default:
			cout<<"\a";
			admin_menu();
  		}

}
//************************check meter generated for trans
int checkmetergentrans()
{
 ifstream objiff;
 meter mt;
 int count=-1;
 objiff.open("meter.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
		count=-1;
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &mt, sizeof(meter)))
	{
		if(mt.getmeterstatus()=='Y')
		{   count=1;
			 break;
		}
	}
 }
	objiff.close();
	return count;
}
//**************************customer information system*******************
 void customer_info()
 {
  clrscr();
  char ch2='\0';
  int num=0;
  //************************************************************
	 clrscr();
	intromain();
	gotoxy(20,6);
	cout<<"=================CUSTOMER'S INFORMATION====================";
	gotoxy(22,7);
	cout<<"1.ADD CUSTOMER'S INFORMATIONS";
	gotoxy(22,8);
	cout<<"2.MODIFY CUSTOMER'S INFORMATIONS";
	gotoxy(22,9);
	cout<<"3.DELETE CUSTOMER'S INFORMTIONS";
	gotoxy(22,10);
	cout<<"4.BACK TO MENU";
	gotoxy(22,12);
	cout<<"Please Enter Your Choice (1-4) ";
	gotoxy(23,16);
	ch2=getche();
  switch(ch2)
  {
		case '1':
					write_customer();
					break;
		case '2':
					clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE CUST ID TO BE SEARCHED AND MODIFY:";
					gotoxy(55,9);
					cin>>num;
					modify_customer_record(num);
					break;
		case '3':
					clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE CUST ID TO BE SEARCHED AND DELETE:";
					gotoxy(55,9);
					cin>>num;
					delete_cust_record(num);
					break;
		case '4':
					break;
		default:
					cout<<"\a";
					admin_menu();
  } }
//************************customer functions*******************************
//*****************delete the customer records****************************
 void delete_cust_record(int n)
 {
  customer cust;
	ifstream inFile;
	inFile.open("customer.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &cust, sizeof(customer)))
	{
		if(cust.getcustid()==n)
		{   clrscr();
			 intromain();
			 cust.showdatamulti_cust();
			 flag=1;
		}
	}
	inFile.close();
	char ch;
	if(flag==0)
		cout<<"\n\nrecord not exist";
	else
	{
	//*******deletion of the records starts from here
	gotoxy(1,15);
	cout<<"*****************************************************************************";
	gotoxy(5,16);
	cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
	gotoxy(2,17);
	cin>>ch;
	 if (toupper(ch)=='Y')
	 {
		 ofstream outFile;
		 outFile.open("Temp1.dat",ios::binary);
		 ifstream objiff("customer.dat",ios::binary);
		 objiff.seekg(0,ios::beg);
		 while(objiff.read((char *) &cust, sizeof(customer)))
			{
			 if(cust.getcustid()!=n)
			 {
				 outFile.write((char *) &cust, sizeof(customer));
			 }
			}

	outFile.close();
	objiff.close();
	remove("customer.dat");
	rename("Temp2.dat","customer.dat");
	gotoxy(30,20);
	cout<<"----------------------------Record Deleted----------------------------------";
	}
	}
	getch();
}
//*****************delete the customer records****************************
//*****************modify the customer records****************************
void modify_customer_record(int n)
{
	customer cust;
	ifstream inFile;
	int fpos=-1;
	inFile.open("customer.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
	}
	int flag=0;
	while(inFile.read((char *) &cust, sizeof(customer)))
	{
		if(cust.getcustid()==n)
		{   clrscr();
			 intromain();
			 cust.showdatamulti_cust();
			 flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nrecord not exist";
	else
	{
	//*******modifying the records starts here
	fstream File;
	File.open("customer.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	while(File.read((char *) &cust, sizeof(customer)))
	{
		if(cust.getcustid()==n)
		{   fpos=(int)File.tellg();
			 break;
		}
	 }
	File.seekp(fpos-sizeof(customer),ios::beg);
	gotoxy(1,12);
	cout<<"*****************************************************************************";
	gotoxy(1,13);
	cout<<"======ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
	cust.modifydatacust();
	File.write((char *) &cust, sizeof(customer));
	File.close();
  }}
//*****************modify the customer records****************************
//    	function to write in file
//****************************************************************
void write_customer()
	{
	 int flag=-1,pos=0;
	 fstream fp;
	 customer cust;
	 char meternum[25];
	 fp.open("customer.dat",ios::out|ios::app);
	 clrscr();
	 intromain();
	 int rnn=getcustno();
	 if(rnn>10000)
	 {
	 rnn=1;
	 }
	 //******************get the meter no
	fstream objiff;
	meter mt;
	objiff.open("meter.dat",ios::binary|ios::in|ios::out);
	objiff.seekg(0,ios::beg);
	if(!objiff)
	{
	cout<<"File could not be open !! Press any Key...";
	}
	else{
//**************temporary hiding these lines
	 while(objiff.read((char *) &mt, sizeof(meter)))
	{
		if(mt.getmeterstatus()=='N')
		{
		pos=(int)objiff.tellg();
		flag=1;
		break;
		}
	}
	 }
	 //******************get the meter no    mt.getmeterreg()
 if(flag==1)
 {
	 strcpy(meternum,mt.getmeterreg());
	 cust.addcustomer(rnn,meternum);
	 mt.setmeterstatus();
	 objiff.seekp(pos-sizeof(meter),ios::beg);
	 objiff.write((char *) &mt, sizeof(meter));
	 objiff.close();
	 fp.write((char*)&cust,sizeof(customer));
	 fp.close();
	 gotoxy(10,20);
	 cout<<"***************CUSTOMER'S RECORD SAVED******************* ";
	 cin.ignore();
	 getch();
 }else
 {
	 fp.close();
	 gotoxy(10,20);
	 cout<<"****PLEASE ADD METER INFORMATION BEFORE CUSTOMER'S RECORD SAVED**** ";
	 cin.ignore();
	 getch();
 }
}
//********************check the Student roll number already given or not******
int getcustno()
{
 ifstream objiff;
 customer cust;
 int count=0,count2=0;
 objiff.open("customer.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
		count=1;
		getch();
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &cust, sizeof(customer)))
	{
	  count2++;
	}

count=count2;
count++;
}
objiff.close();
return count;
}
//************************customer functions*******************************
//*****************meter_info informations*****************************
void meter_info()
 {
  clrscr();
  char ch2='\0';
  char mnum[25];
  //************************************************************
	 clrscr();
	intromain();
	gotoxy(20,6);
	cout<<"=================METER'S INFORMATION====================";
	gotoxy(22,7);
	cout<<"1.ADD METER'S INFORMATIONS";
	gotoxy(22,8);
	cout<<"2.DELETE METER'S INFORMTIONS";
	gotoxy(22,9);
	cout<<"3.BACK TO MENU";
	gotoxy(22,11);
	cout<<"Please Enter Your Choice (1-3) ";
	gotoxy(23,13);
	ch2=getche();
  switch(ch2)
  {
		case '1':
					write_meter();
					break;
		case '2':
					clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE METER NO TO BE SEARCHED AND DELETE:";
					gotoxy(55,9);
					cin>>mnum;
					delete_meter(mnum);
					break;
		case '3':
					break;
		default:
					cout<<"\a";
					admin_menu();
  } }
//***************************************************************
//            function to delete the meter number
void delete_meter(char mn[25])
{
  meter mt;
	ifstream inFile;
	inFile.open("meter.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		getch();
		return;
	}
	int flag=0;
	while(inFile.read((char *) &mt, sizeof(meter)))
	{
		if((strcmp(mt.getmeterreg(),mn)==0) && mt.getmeterstatus()=='N')
		{   clrscr();
			 intromain();
			 mt.showmeters();
			 flag=1;
		}
	}
	inFile.close();
	char ch;
	if(flag==0)
		cout<<"\n\nrecord not exist";
	else
	{
	//*******deletion of the records starts from here
	gotoxy(1,15);
	cout<<"*****************************************************************************";
	gotoxy(5,16);
	cout<<"==DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
	gotoxy(2,17);
	cin>>ch;
	 if (toupper(ch)=='Y')
	 {
		 ofstream outFile;
		 outFile.open("Temp2.dat",ios::binary);
		 ifstream objiff("meter.dat",ios::binary);
		 objiff.seekg(0,ios::beg);
		 while(objiff.read((char *) &mt, sizeof(meter)))
			{
			 if(strcmp(mt.getmeterreg(),mn)!=0)
			 {
				 outFile.write((char *) &mt, sizeof(meter));
			 }
			}

	outFile.close();
	objiff.close();
	remove("meter.dat");
	rename("Temp2.dat","meter.dat");
	gotoxy(30,20);
	cout<<"----------------------------Record Deleted----------------------------------";
	}
	}
	getch();
}
//    	function to write in file
//****************************************************************
void write_meter()
	{
	 char series[25],mtrno[25],ch,temp[15];
	 fstream fp;
	 meter m;
	 clrscr();
	 intromain();
	 int N,x;
	 gotoxy(10,10);
	 cout<<"new series or old one[y or n]";
	 gotoxy(10,11);
	 cin>>ch;
	 if(ch=='y')
	 {
	 clrscr();
	 intromain();
	 gotoxy(10,10);
	 cout<<"Enter the series starting 4 number:";
	 gotoxy(10,11);
	 cin>>series;
	 clrscr();
	 intromain();
	 gotoxy(10,10);
	 cout<<"Enter number of meter number to be generated:";
	 gotoxy(10,11);
	 cin>>N;
		for(x=1;x<=N;x++)
		{
			int rnn=getmeterno();
			if(rnn>10000)
			{
				rnn=1;
			}
			strcpy(mtrno,series);
			itoa(rnn,temp,10);
			strcat(mtrno,temp);
			cout<<"\nrnn="<<rnn<<" series="<<series<<" mtrno="<<mtrno;
			getch();
			fp.open("meter.dat",ios::binary|ios::out|ios::app);
			m.writemeter(rnn,series,mtrno,'N');
			fp.write((char*)&m,sizeof(m));
			fp.close();
		}
	 }else
	 {
	 strcpy(series,m.getseries());
	 clrscr();
	 intromain();
	 gotoxy(10,10);
	 cout<<"Enter number of meter number to be generated:";
	 gotoxy(10,11);
	 cin>>N;
	for(x=1;x<=N;x++)
	{
		int rnn=getmeterno();
		if(rnn>10000)
		{
		rnn=1;
		}
		strcpy(mtrno,series);
		itoa(rnn,temp,1);
		strcat(mtrno,temp);
		fp.open("meter.dat",ios::binary|ios::out|ios::app);
		m.writemeter(rnn,series,mtrno,'N');
		fp.write((char*)&m,sizeof(m));
		fp.close();
} }
	 gotoxy(10,20);
	 cout<<"***************METER'S RECORD SAVED******************* ";
	 cin.ignore();
	 getch();
	}
//********************get meter no*************************************
int getmeterno()
{
 ifstream objiff;
 meter m;
 int count=0,count2=0;
 objiff.open("meter.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		count=1;
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &m, sizeof(meter)))
	{
	  count2++;
	}

count=count2;
count++;
}
objiff.close();
return count;
}
//*****************Billing transcations informations*****************************
//*********************************************
 void transcations()
 {
	clrscr();
	char ch2='\0';
	char mnum[25];
  //************************************************************
	 clrscr();
	intromain();
	gotoxy(20,6);
	cout<<"=================BILLING/TRANSCATIONS====================";
	gotoxy(22,7);
	cout<<"1.ADD BILL READING";
	gotoxy(22,8);
	cout<<"2.MODIFY BILL READING";
	gotoxy(22,9);
	cout<<"3.TRANSCATIONS";
	gotoxy(22,10);
	cout<<"4.BACK TO MENU";
	gotoxy(22,12);
	cout<<"Please Enter Your Choice (1-4) ";
	gotoxy(23,16);
	ch2=getche();
  switch(ch2)
  {
		case '1':
					clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE METER NO:";
					gotoxy(55,9);
					cin>>mnum;
					write_bills(mnum);
					break;

		case '2':
				 clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE METER NO:";
					gotoxy(55,9);
					cin>>mnum;
					modify_bills(mnum);
					break;
		case '3':
					clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE METER NO:";
					gotoxy(55,9);
					cin>>mnum;
					paid_bills(mnum);
					break;
		case '4':
					break;
		default:
					cout<<"\a";
					admin_menu();
  }
 }
//***************************************************************
void paid_bills(char mnum[25])
{

	 fstream fp;
	 fstream objiffback;
	 billing bl;
	 char meternum[25];
	 fp.open("billing.dat",ios::binary|ios::out|ios::in);
	 ofstream trobj("trans.dat",ios::binary|ios::app);
	 trans tr;
	 clrscr();
	 intromain();
	 con_date d1;
               int bpos=-1,bflag=-1;
	billprevrecord  brprv;
	float amtadd=0.00;
               float amtded=0.00;
	 int kpos=0,amount=0;
	 float deduct=0.00;
	 float amountaddnxt=0.00,totalamount=0.00;
	 //********************meter details*****************************************************************
	ifstream objiff;
	meter mt;
	int flag=-1,flag2=-1;
	objiff.open("meter.dat",ios::binary);
	objiff.seekg(0,ios::beg);
	if(!objiff)
	{
	cout<<"File could not be open !! Press any Key...";
	}
	else{
		 while(objiff.read((char *) &mt, sizeof(meter)))
		{
	if((strcmp(mnum,mt.getmeterreg())==0)&& mt.getmeterstatus()=='Y')
	{
	flag=1;
	break;
	}} }
	//*************************meter details**************************************************
	if(flag==1)
	{
	if(checkbillpaid(mnum)!=1)
	{
	clrscr();
	intromain();
	strcpy(meternum,mt.getmeterreg());
	//*****************display customer information**********
	displaycust_meterno(mnum,5);
	//*****************bill info
	if(!objiff)
	{
	}else{
	 while(fp.read((char *) &bl, sizeof(billing)))
	{
	  if((strcmp(meternum,bl.getmtn())==0) && bl.getstatus()=='Y')
	  {
	  kpos=(int)fp.tellg();
	  flag2=1;
	  break;
	  }
	}
	if(flag2==1)
	{
	//***************get the previou left amount*********************
	objiffback.open("billsprevrecord.dat",ios::binary|ios::in|ios::out);
	objiffback.seekg(0,ios::beg);
	if(!objiffback)
	{
	cout<<"File could not be open !! Press any Key...";
	}else{
	 while(objiffback.read((char *) &brprv, sizeof(billprevrecord)))
	{
	if((strcmp(mnum,brprv.mtrno)==0)&& brprv.status=='Y')
	{
	bpos=(int)objiffback.tellg();
	bflag=1;
	break;
	}
	}
	if(bflag==1)
	{
	amtadd= brprv.amtadd;
	amtded=brprv.amtdud;
	brprv.status='N';
	objiffback.seekp(bpos-sizeof(billprevrecord),ios::beg);
	objiffback.write((char*)&brprv,sizeof(billprevrecord));
	} }
	//***************get the previou left amount*********************
	  gotoxy(5,10);
               cout<<"============================================================";
	  gotoxy(5,11);
	  totalamount=bl.getnetamt();
	  totalamount=totalamount+amtadd;
	  totalamount=totalamount-amtded;
cout<<"AMOUNT:"<<setw(8)<<bl.getnetamt()<<setw(10)<<"+ADD AMT:"<<setw(8)<<amtadd<<setw(10)<<"-DEDUCT AMT:"<<setw(8)<<amtded;
	  gotoxy(5,12);
	  cout<<"BILL AMOUNT"<<setw(15)<<totalamount;
	  gotoxy(5,13);
	  cout<<"Please deposite the amount:";
	  gotoxy(50,14);
	  cin>>amount;
	  gotoxy(5,15);
	 cout<<"date of deposit[dd-mm-yyyy]:";
	  gotoxy(5,16);
	  cin>>d1.dd>>d1.mm>>d1.yy;
	if(amount>totalamount)
	{
	deduct=(amount-totalamount);
	amountaddnxt=0;
	}else{
	amountaddnxt=(totalamount-amount);
	deduct=0;
	}
 tr.settrans(bl.getbno(),meternum,bl.getbno(),d1,totalamount,amount,amountaddnxt,deduct);
 trobj.write((char*)&tr,sizeof(trans));
	 gotoxy(10,20);
	 cout<<"***************bill Paid******************* ";
	 overwritebillrecord(meternum);
	 //*******set the amount for nxt bills
	 setoldleftamount(bl.getbno(),meternum,amountaddnxt,deduct);
	  //*******set the amount for nxt bills
	 fp.seekp(kpos-sizeof(billing),ios::beg);
	 bl.setstatus('N');
	 fp.write((char*)&bl,sizeof(billing));
  } }
 //*****************bill info
}else	{
	gotoxy(10,20);
	cout<<"***************BILL PAID!!!!!!!!******************* ";
	}}else
	 {
	 gotoxy(10,20);
	 cout<<"***************error!!!!!!!******************* ";
	 }
	 getch();
	 objiff.close();fp.close();trobj.close();
	 objiffback.close();
}
//*******************bill entry****************************
void write_bills(char mnum[25])
{

	 fstream fp;
	 billing bl;
	 char meternum[25];
	 fp.open("billing.dat",ios::binary|ios::out|ios::app);
	 clrscr();
	 intromain();
	 int rnn=getbillno();
	 if(rnn>100)
	 {
	 rnn=1;
	 }
	ifstream objiff;
	meter mt;
	int flag=-1;
	objiff.open("meter.dat",ios::binary);
	objiff.seekg(0,ios::beg);
	if(!objiff)
	{
	cout<<"File could not be open !! Press any Key...";
	}
else{
//**************temporary hiding these lines
 while(objiff.read((char *) &mt, sizeof(meter)))
{
if((strcmp(mnum,mt.getmeterreg())==0)&& mt.getmeterstatus()=='Y')
{
flag=1;
break;
}} }
	 //******************get the meter no    mt.getmeterreg()
if(flag==1)
{
if(checkbillpaid(mnum)==1)
	{
	 clrscr();
	 intromain();
	 strcpy(meternum,mt.getmeterreg());
	 //*****************display customer information**********
	 displaycust_meterno(mnum,5);
	 //*******************************************************
	 bl.addbill(rnn,meternum);
	 fp.write((char*)&bl,sizeof(billing));
	 gotoxy(10,20);
	 cout<<"***************bill created******************* ";
	 savebillrecord(rnn,mnum);
	 cin.ignore();
	 getch();
	}else{
	 gotoxy(10,20);
	 cout<<"***************PLEASE PAY PREVIOUS BILL FIRST!!!!!!!******************* ";
	}
}else {
	 gotoxy(10,20);
	 cout<<"***************error!!!!!!!******************* ";
        }
	 getch();
	 objiff.close();fp.close();
}
//*******************bill entry *************************************
void overwritebillrecord(char mn[25])
{
  fstream objiff;
  billrecord  br;
  int kpos=0,flag=-1;
  objiff.open("billsrecord.dat",ios::binary|ios::in|ios::out);
  if(!objiff)
  {
	cout<<"File could not be open !! Press any Key...";
  }else{
	while(objiff.read((char *) &br, sizeof(billrecord)))
	{
	if((strcmp(mn,br.mrtno)==0)&& br.billstatus =='Y')
	{
		flag=1;
		kpos=(int)objiff.tellg();
		break;
	}}
	if(flag==1)
	{
	objiff.seekp(kpos-sizeof(billrecord),ios::beg);
	  strcpy(br.mrtno,mn);
	  br.billstatus ='N';
	  objiff.write((char *) &br, sizeof(br));
	 }
  }
 objiff.close();
}
//******************save bill record********************
void savebillrecord(int r,char mn[25])
{
  ofstream objiff;
  billrecord  br;
  objiff.open("billsrecord.dat",ios::binary|ios::app);
  if(!objiff)
  {
		cout<<"File could not be open !! Press any Key...";
  }else{
	  br.billno=r;
	  strcpy(br.mrtno,mn);
	  br.billstatus ='Y';
	  objiff.write((char *) &br, sizeof(br));
  }
 objiff.close();
}
//**********************CHECK THE BILL PAID OR NOT*****************
int checkbillpaid(char mn[25])
{
  ifstream objiff;
  billrecord  br;
  int flag=0;
  objiff.open("billsrecord.dat",ios::binary);
  objiff.seekg(0,ios::beg);
  if(!objiff)
  {
	cout<<"File could not be open !! Press any Key...";
	return 1;
  }else{
//**************temporary hiding these lines
 while(objiff.read((char *) &br, sizeof(br)))
	{
	if((strcmp(mn,br.mrtno)==0)&& br.billstatus =='Y')
	{
	flag=0;
	break;
	}else
           {flag=1;}
}}
  objiff.close();
  return flag;
}
//********************get meter no*************************************
int getbillno()
{
 ifstream objiff;
 billing bl;
 int count=0,count2=0;
 objiff.open("billing.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		count=1;
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &bl, sizeof(billing)))
	{
	  count2++;
	}
count=count2;
count++;
}
objiff.close();
return count;
}
//*******************ALL Reports Display Menu************************
 void reports()
 {
	clrscr();
	char ch2='\0';
	char mnum[25];
	 clrscr();
		intromain();
		gotoxy(20,6);
		cout<<"=================REPORTS====================";
		gotoxy(22,7);
	cout<<"1.All Customer's Details With Meter No.";
	gotoxy(22,8);
	cout<<"2.All Meter's Details Working";
	gotoxy(22,9);
	cout<<"3.Display all bills ";
	gotoxy(22,10);
	cout<<"4.Display Customer details With Bills Details";
	gotoxy(22,11);
	cout<<"5.Display all bill records";
	gotoxy(22,12);
	cout<<"6.Display all transcations";
	gotoxy(22,13);
	cout<<"7.BACK TO MENU";
	gotoxy(22,14);
	cout<<"Please Enter Your Choice (1-7) ";
	gotoxy(23,16);
	ch2=getche();
  switch(ch2)
  {
		case '1':
					display_customer();
					getch();
					break;
		case '2':
				  display_meters();
				  getch();
					break;
		case '3':
				 display_bills();
				  getch();
					break;
		case '4':
              clrscr();
					intromain();
					gotoxy(10,8);
					cout<<"***ENTER THE CUSTOMER METER NO:";
					gotoxy(55,9);
					cin>>mnum;
					display_custwithbills(mnum);
               				getch();
		break;

		case '5':
				  display_billrecords();
				  getch();
		break;
		case '6':
					displaytrans();
					getch();
					break;
		case '7':
					break;
		default:
					cout<<"\a";
					admin_menu();
  }
 }
//***************************************************************
int checkmetergen()
{
 ifstream objiff;
 meter mt;
 int count=-1;
 objiff.open("meter.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
		count=-1;
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &mt, sizeof(meter)))
	{
		if(mt.getmeterstatus()=='N')
		{   count=1;
			 break;
		}
	}
 }
	objiff.close();
	return count;
}
//*****************************display all meters***********************
void display_meters()
{
 ifstream objiff;
 meter mt;int c=7;
 objiff.open("meter.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}else{
//**************temporary hiding these lines
clrscr();
	intromain();
	gotoxy(25,5);
	cout<<"METER NO"<<  setw(15)<<"STATUS";
	gotoxy(8,6);
	cout<<"=========================================================";
 while(objiff.read((char *) &mt, sizeof(meter)))
{
	mt.showallmeters(c);
	c++;
} }
	gotoxy(8,c);
	cout<<"=========================================================";
	objiff.close();
}
void  displaycust_meterno(char mnum2[25],int k)
{
 ifstream objiff;
 customer cust;
 int count=0;
 objiff.open("customer.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
	}else{
//**************temporary hiding these lines
 while(objiff.read((char *) &cust, sizeof(customer)))
	{
	  if(strcmp(mnum2,cust.getmetern())==0)
	  {
		  count=1;
		  break;
	  }
	}
  if(count==1)
  {	 cust.showallcustdetails(k);
  }}
objiff.close();
}
//**********************display customers***************************
void display_customer()
{
  ifstream objiff;
 customer cust;
  int c=7;
 objiff.open("customer.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
	}else{
//**************temporary hiding these lines
clrscr();
	intromain();
	gotoxy(1,5);
cout<<"NAME OF CUST."<<setw(12)<<"ADDRESS" <<setw(15)<<"MOB.NO" <<setw(12)<<"METERNO" <<setw(15) <<"DATEODCONN";
gotoxy(1,6);
cout<<"======================================================================";
 while(objiff.read((char *) &cust, sizeof(customer)))
	{
	cust.showallcust(c);
	c++;
	}
gotoxy(1,c);
cout<<"======================================================================";
}
objiff.close();
}
//************************************************************************
void display_bills()
{
 ifstream objiff;
 billing bl;
 int c=7;
 objiff.open("billing.dat",ios::binary);
 objiff.seekg(0,ios::beg);
	if(!objiff)
	{
		cout<<"File could not be open !! Press any Key...";
	}else{
//**************temporary hiding these lines
	clrscr();
	intromain();
	gotoxy(1,5);
cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8)<<"UNITS"<<setw(15)<<"AMT + TAX ="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";
gotoxy(1,6);
cout<<"===============================================================================";
 while(objiff.read((char *) &bl, sizeof(billing)))
	{
		bl.showallbill(c);
		c++;
	}
	 gotoxy(1,c);
	cout<<"===============================================================================";
}
objiff.close();
}
//******************************bill records******************************
void display_billrecords()
{
  ifstream objiff;
  billrecord  br;
  objiff.open("billsrecord.dat",ios::binary);
  int c=7;
  objiff.seekg(0,ios::beg);
  if(!objiff)
  {
	cout<<"File could not be open !! Press any Key...";
  }else{
//**************temporary hiding these lines
              clrscr();
	intromain();
	gotoxy(1,5);
	cout<<"BILL NO"<<setw(10)<<"METERNO"<<setw(15)<<"STATUS";
	gotoxy(1,6);
	cout<<"===============================================================================";
	 while(objiff.read((char *) &br, sizeof(br)))
		{
		 gotoxy(5,c);
		 cout<<br.billno<<setw(10)<<br.mrtno<<setw(15)<<br.billstatus;
		 c++;
		}
		 gotoxy(1,c);
	cout<<"===============================================================================";
	}
  objiff.close();
}
//**************************display bills of customer*****************************
void display_custwithbills(char mnum[25])
{
  fstream fp;
	 billing bl;
	 char meternum[25];
	 fp.open("billing.dat",ios::binary|ios::out|ios::in);
	 clrscr();
	 intromain();
	 //******************get the meter no
	ifstream objiff;
	meter mt;
	int flag=-1;
	objiff.open("meter.dat",ios::binary);
	objiff.seekg(0,ios::beg);
	if(!objiff)
	{
	cout<<"File could not be open !! Press any Key...";
	}
	else{
//**************temporary hiding these lines
 while(objiff.read((char *) &mt, sizeof(meter)))
{
if((strcmp(mnum,mt.getmeterreg())==0)&& mt.getmeterstatus()=='Y')
{
flag=1;
break;
}} }
 //******************get the meter no    mt.getmeterreg()
if(flag==1)
{
 clrscr();
 intromain();
 strcpy(meternum,mt.getmeterreg());
 //*****************display customer information**********
 displaycust_meterno(mnum,5);
 //*****************bill info
if(!fp)
{
}else{
gotoxy(1,8);
cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8)<<"UNITS"<<setw(15)<<"AMT + TAX ="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";
gotoxy(1,9);
cout<<"===============================================================================";
int c=10;
 while(fp.read((char *) &bl, sizeof(billing)))
	{
	  if(strcmp(meternum,bl.getmtn())==0)
	  {
		  bl.showallbill(c);
		  c++;
	  }
	}
	gotoxy(1,c);
	cout<<"===============================================================================";
	  }
	}else
	{
	 gotoxy(10,10);
	 cout<<"***********************no such customer record***************";
	 getch();
	 }
	 fp.close();
	 objiff.close();
}
//***********************modify th bill reading
void modify_bills(char mnum[25])
{
	 fstream fp;
	 billing bl;
	 char meternum[25];
	 fp.open("billing.dat",ios::binary|ios::out|ios::in);
	 clrscr();
	 intromain();
	 int pos=-1,creading=0;
	 //******************get the meter no
					ifstream objiff;
					meter mt;
					int flag=-1;
					objiff.open("meter.dat",ios::binary);
					objiff.seekg(0,ios::beg);
					if(!objiff)
					{
						cout<<"File could not be open !! Press any Key...";
					}
					else{
//**************temporary hiding these lines
	 while(objiff.read((char *) &mt, sizeof(meter)))
	{
	if((strcmp(mnum,mt.getmeterreg())==0)&& mt.getmeterstatus()=='Y')
	{
	flag=1;
	break;
	}} }
	 //******************get the meter no    mt.getmeterreg()
if(flag==1)
{
	 clrscr();
	 intromain();
	 strcpy(meternum,mt.getmeterreg());
	 //*****************display customer information**********
	 displaycust_meterno(mnum,5);
	while(fp.read((char *) &bl, sizeof(billing)))
	{
	if((strcmp(meternum,bl.getmtn())==0) && bl.getstatus()=='Y')
	  {
	 pos=(int)fp.tellg();
	 break;
	  }}
	 //***************************************
	 gotoxy(1,8);
cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8) <<"UNITS" <<setw(15) <<"AMT + TAX ="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";
	gotoxy(1,9);
	cout<<"===============================================================================";
	bl.showallbill(10);
	 gotoxy(10,11);
	 cout<<"Please enter the new current reading:";
	 gotoxy(10,12);
	 cin>>creading;
	 bl.setnewbillreading(creading);
	 fp.seekp(pos-sizeof(billing),ios::beg);
	 fp.write((char*)&bl,sizeof(billing));
	 gotoxy(10,20);
	 cout<<"***************bill re-created******************* ";
	 cin.ignore();
	 getch();
}else
	 {
	 gotoxy(10,20);
	 cout<<"***************error!!!!!!!******************* ";
	 }
	 getch();
	 objiff.close();fp.close();
}
//**********************set the bill record
void setoldleftamount(int r,char mn[25],float amtaddnxt,float amtdeduct)
{
  ofstream objiff;
  billprevrecord  brprv;
  objiff.open("billsprevrecord.dat",ios::binary|ios::app);
  if(!objiff)
  {
		cout<<"File could not be open !! Press any Key...";
  }else{
	  brprv.bno=r;
	  strcpy(brprv.mtrno,mn);
	  brprv.amtadd=amtaddnxt;
	  brprv.amtdud=amtdeduct;
	  brprv.status ='Y';
	  objiff.write((char *) &brprv, sizeof(billprevrecord));

  }
 objiff.close();
}
//***************************display transcation**************************
void displaytrans()
{
  ifstream objiff;
  trans  tr;
  objiff.open("trans.dat",ios::binary);
  int c=7;
  objiff.seekg(0,ios::beg);
  if(!objiff)
  {
   cout<<"File could not be open !! Press any Key...";

  }else{
//**************temporary hiding these lines
  clrscr();
intromain();
gotoxy(1,5);
cout<<"TRNO"<<setw(10)<<"METERNO"<<setw(5)<<"BNO"<<setw(5)<<"DATEOFDEPOSIT"<<setw(10)<<"AMOUNT"<<setw(10)<<"PAID"<<setw(10)<<"+ADDTONXT"<<setw(8)<<"-DEDUCT"<<setw(8)<<"STATUS";
gotoxy(1,6);
cout<<"===============================================================================";
 while(objiff.read((char *) &tr, sizeof(trans)))
{
 tr.showalltrans(c);
c++;
}
 gotoxy(1,c);
cout<<"===============================================================================";
}
  objiff.close();
}
//*****************************FUNCTIONS ENDS HERE*************************

