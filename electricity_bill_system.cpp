//***************************************************************//HEADERFILEUSEDINPROJECT//****************************************************************#include<stdio.h>#include<conio.h>#include<process.h>#include<fstream.h>#include<iomanip.h>#include<string.h>#include<ctype.h>#include<stdlib.h>//********************functionsnames*************************************voidintro();intcheckpass();voidadmin_menu();voidintromain();voidcustomer_info();voidmeter_info();voidtranscations();voidreports();voiddisplaytrans();//********************customerfunctions*********************************voidwrite_customer();voidmodify_customer_record(int);voiddelete_cust_record(int);intgetcustno();intcheckmetergentrans();//********************customerfunctions*********************************//******************meterinfo***********************voidwrite_meter();intgetmeterno();voiddelete_meter(charmn[25]);intcheckmetergen();//***************************************************voidwrite_bills(charmnum[25]);voiddisplaycust_meterno(charmnum2[25],intk);intcheckbillpaid(charmn[25]);voidsavebillrecord(intr,charmn[25]);//**********************reports********************voiddisplay_meters();intgetbillno();voidpaid_bills(charmnum[25]);voidoverwritebillrecord(charmn[25]);voiddisplay_customer();voiddisplay_bills();voiddisplay_billrecords();voiddisplay_custwithbills(charmnum[25]);voidmodify_bills(charmnum[25]);voidsetoldleftamount(intr,charmn[25],floatamtaddnxt,floatamtdeduct);//**************************************************structbillprevrecord{intbno;charmtrno[25];floatamtadd;floatamtdud;charstatus;};structbillrecord{intbillno;charmrtno[25];charbillstatus;};structcon_date{intdd;intmm;intyy;};structprevbillinfo{intmeterno;intbillno;charpstatus;};//*****************classesname*****************************************//*********************meterno*********************************8classmeter{intmeterno;charser[25];charmeterreg[25];charstatus;public:intgetmeterno(){returnmeterno;}char*getmeterreg(){returnmeterreg;}chargetmeterstatus(){returnstatus;}char*getseries(){returnser;}voidwritemeter(intmt,chars[25],charmtreg[25],charst){meterno=mt;strcpy(ser,s);strcpy(meterreg,mtreg);status=st;}voidsetmeterstatus(){status='Y';}voidshowallmeters(intc){gotoxy(25,c);cout<<meterreg<<setw(15)<<status;}voidshowmeters(){gotoxy(7,10);cout<<"METERNO:"<<setw(10)<<meterreg<<setw(10)<<"STATUS:"<<status;gotoxy(5,11);cout<<"===========================================================";}};//*********************meterno*********************************8classtrans{inttno;charmetrno[25];intbillno;con_dateddofpaid;floatbillamt,amtpaid;floataddtonextamtbill,deductamt;chartransstatus;public:intgettno(){returntno;}char*getmetno(){returnmetrno;}intgetbillno(){returnbillno;}floatgetprevamt(){returnaddtonextamtbill;}floatgetdeductamt(){returndeductamt;}chargetstatus(){returntransstatus;}voidsetstatus(chars1){transstatus=s1;}voidsettrans(intt1,charmt1[25],intbl1,con_dated1,floatbillamt1,floatamtpaid1,floatamtnxt,floatdduct){tno=t1;strcpy(metrno,mt1);billno=bl1;ddofpaid=d1;billamt=billamt1;amtpaid=amtpaid1;addtonextamtbill=amtnxt;deductamt=dduct;transstatus='Y';}voidshowalltrans(intc){gotoxy(3,c);cout<<tno<<setw(10)<<metrno<<setw(5)<<billno<<setw(5)<<ddofpaid.dd<<"-"<<ddofpaid.mm<<"-"<<ddofpaid.yy<<setw(10)<<billamt<<setw(10)<<amtpaid<<setw(10)<<addtonextamtbill<<setw(8)<<deductamt<<setw(10)<<transstatus;}};//************************billingclass******************************classbilling{intbno;charmno[25];intcurr_reading,prev_reading;intunit;floatamt,otheramt,netamt;charstatus;public:intgetbno(){returnbno;}char*getmtn(){returnmno;}intgetcurrread(){returncurr_reading;}intgetprvread(){returnprev_reading;}intgetunit(){returnunit;}chargetstatus(){returnstatus;}floatgetnetamt(){returnnetamt;}voidsetstatus(chars){status=s;}voidaddbill(intbid,charmtno[25]){gotoxy(5,7);cout<<"======================================================================";gotoxy(5,8);cout<<"BILLNO:";bno=bid;gotoxy(15,8);cout<<bno;gotoxy(35,8);cout<<"METERNO:";gotoxy(55,8);strcpy(mno,mtno);cout<<mno;gotoxy(5,9);cout<<"CURRENTREADING|-|PREVIOUSREADING";gotoxy(15,10);cin>>curr_reading;gotoxy(25,10);cin>>prev_reading;gotoxy(5,11);unit=(curr_reading-prev_reading);cout<<"UNITSCONSUMED:";gotoxy(35,11);cout<<unit;if(unit>=0&&unit<=100)amt=unit*2.5;elseif(unit>100&&unit<=200)amt=unit*3.0;elseif(unit>200&&unit<=350)amt=unit*3.5;elseif(unit>350&&unit<=450)amt=unit*4.2;elseif(unit>450)amt=unit*5.5;gotoxy(55,11);cout<<"AMOUNT";gotoxy(65,11);cout<<amt;gotoxy(5,12);cout<<"OTHERCHARGES+tax";cin>>otheramt;netamt=amt+otheramt+250;gotoxy(35,12);cout<<"TOTALAMOUNT:";gotoxy(55,12);cout<<netamt;status='Y';gotoxy(5,13);cout<<"=====================================================================";}voidshowallbill(intc){gotoxy(1,c);cout<<bno<<setw(12)<<mno<<setw(12)<<curr_reading<<"-"<<prev_reading<<setw(10)<<unit<<setw(10)<<amt<<"+"<<otheramt<<"="<<setw(12)<<netamt<<setw(10)<<status;}voidshowbill(intbid){gotoxy(5,7);cout<<"======================================================================";gotoxy(5,8);cout<<"BILLNO:";bno=bid;gotoxy(15,8);cout<<"BOO"<<bno;gotoxy(35,8);cout<<"METERNO:";gotoxy(55,8);cout<<mno;gotoxy(5,9);cout<<"CURRENTREADING-PREVIOUSREADING";gotoxy(5,10);cout<<curr_reading<<"-----"<<prev_reading;gotoxy(45,10);cout<<"UNITSCONSUMED:";gotoxy(55,10);cout<<unit;gotoxy(15,11);cout<<"AMOUNT";gotoxy(35,11);cout<<amt;gotoxy(5,12);cout<<"OTHERCHARGES";gotoxy(25,12);cout<<otheramt;gotoxy(5,12);cout<<"TOTALAMOUNT:";gotoxy(15,12);cout<<netamt;gotoxy(35,12);cout<<"STATUS:"<<status;gotoxy(5,13);cout<<"=====================================================================";}voidmodifybill(intbid,charmtno[25],intcr,intpr){gotoxy(5,7);cout<<"======================================================================";gotoxy(5,8);cout<<"BILLNO:";bno=bid;gotoxy(15,8);cout<<"BOO"<<bno;gotoxy(35,8);cout<<"METERNO:";gotoxy(55,8);strcpy(mno,mtno);cout<<mno;gotoxy(5,9);cout<<"CURRENTREADING-PREVIOUSREADING";gotoxy(15,9);if(cr!=0){curr_reading=cr;}cout<<curr_reading;gotoxy(25,9);if(pr!=0){prev_reading=pr;}cout<<prev_reading;gotoxy(5,10);unit=(curr_reading-prev_reading);cout<<"UNITSCONSUMED:";gotoxy(25,10);cout<<unit;gotoxy(5,11);if(unit>=0&&unit<=100)amt=unit*2.5;elseif(unit>100&&unit<=200)amt=unit*3.0;elseif(unit>200&&unit<=350)amt=unit*3.5;elseif(unit>350&&unit<=450)amt=unit*4.2;elseif(unit>450)amt=unit*5.5;gotoxy(15,11);cout<<"AMOUNT";gotoxy(35,11);cout<<amt;gotoxy(5,12);cout<<"OTHERCHARGES";gotoxy(35,12);cout<<otheramt;netamt=amt+otheramt;gotoxy(5,12);cout<<"TOTALAMOUNT:";gotoxy(15,12);cout<<netamt;status='Y';gotoxy(5,13);cout<<"=====================================================================";}voidsetnewbillreading(intcurrnt){curr_reading=currnt;unit=(curr_reading-prev_reading);if(unit>=0&&unit<=100)amt=unit*2.5;elseif(unit>100&&unit<=200)amt=unit*3.0;elseif(unit>200&&unit<=350)amt=unit*3.5;elseif(unit>350&&unit<=450)amt=unit*4.2;elseif(unit>450)amt=unit*5.5;netamt=amt+otheramt;}};//*******************************customerdetailsclasscustomer{intcust_id;charfname[15],lname[15];charhn[10],add1[20],add2[20];charphno[15];charmeterno[25];con_datedtconn;public:char*getmetern(){returnmeterno;}intgetcustid(){returncust_id;}char*getfname(){returnfname;}char*getlname(){returnlname;}con_dategetdate(){returndtconn;}voidsetdate(con_dated1){dtconn.dd=d1.dd;dtconn.mm=d1.mm;dtconn.yy=d1.yy;}//**************************addthecustomerdetails**********************voidaddcustomer(intcid,charm[25]){gotoxy(5,7);cout<<"======================================================================";gotoxy(5,8);cout<<"CUSTNO:";cust_id=cid;gotoxy(15,8);cout<<cust_id;gotoxy(25,8);cout<<"FIRSTNAME:";gotoxy(40,8);cin>>fname;gotoxy(50,8);cout<<"LASTNAME:";gotoxy(65,8);cin>>lname;gotoxy(5,9);cout<<"ADDRESS[HNO-ADDRESS1-ADDRESS2]";gotoxy(15,10);cin>>hn;gotoxy(25,10);cin>>add1;gotoxy(45,10);cin>>add2;gotoxy(5,11);cout<<"PHONENUMBER";gotoxy(25,11);cin>>phno;gotoxy(5,12);cout<<"METERNO";strcpy(meterno,m);gotoxy(35,12);cout<<meterno;gotoxy(5,13);cout<<"DATEOFCONNECTION:[DD-MM-YY]";gotoxy(5,14);cin>>dtconn.dd;gotoxy(25,14);cin>>dtconn.mm;gotoxy(35,14);cin>>dtconn.yy;gotoxy(5,15);cout<<"=====================================================================";}voidmodifydatacust();//********************modifythecustomerdetails****************************voidshowdatamulti_cust(){gotoxy(5,7);cout<<"======================================================================";gotoxy(8,8);cout<<"CUSTNO:";gotoxy(25,8);cout<<cust_id;gotoxy(35,8);cout<<"NAMEOFCUSTOMER:";gotoxy(55,8);cout<<fname<<"-"<<lname;gotoxy(8,9);cout<<"ADDRESS";gotoxy(25,9);cout<<hn<<"-"<<add1<<","<<add2;gotoxy(40,9);cout<<"PHONENO.:";gotoxy(55,9);cout<<phno;gotoxy(8,10);cout<<"METERNO:";gotoxy(25,10);cout<<meterno;gotoxy(35,10);cout<<"DATEOFCONNECTION:";gotoxy(53,10);cout<<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;gotoxy(5,11);cout<<"=====================================================================";}voidshowallcust(intc){gotoxy(1,c);cout<<fname<<"-"<<lname<<setw(8)<<hn<<"-"<<add1<<","<<add2<<setw(15)<<phno<<setw(10)<<meterno<<setw(10)<<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;}voidshowallcustdetails(intc){gotoxy(1,c);cout<<"FIRSTNAME:"<<setw(8)<<fname<<setw(15)<<"LASTNAME:"<<setw(8)<<lname<<setw(15)<<"ADDRESS:"<<setw(8)<<hn<<"-"<<add1<<","<<add2;gotoxy(1,c+1);cout<<"PHONENO:"<<setw(10)<<phno<<setw(10)<<"METERNO:"<<setw(10)<<meterno<<setw(15)<<"DATEOFCONN."<<setw(10)<<dtconn.dd<<"-"<<dtconn.mm<<"-"<<dtconn.yy;}};voidcustomer::modifydatacust(){chartmpnm[25],tmpnm2[25],tmpphno[15],tmpmtno[15],choice='n';gotoxy(5,14);cout<<"===================WANTTOMODIFY===============================";gotoxy(10,15);cout<<"CUSTNO:";gotoxy(25,15);cout<<cust_id;gotoxy(40,15);cout<<"FIRSTNAME:";gotoxy(60,15);cout<<fname;gotoxy(10,17);cout<<"WanttochangetheFirstName";gotoxy(50,17);intflag=0;while(1){gets(tmpnm);if(strlen(tmpnm)!=0){flag=1;break;}if(strlen(tmpnm)==0){flag=0;break;}}if(flag==1){strcpy(fname,tmpnm);}gotoxy(5,18);//****************COMPANYNAMETOBEMODIFYcout<<"LASTNAME:";gotoxy(20,18);cout<<lname;gotoxy(35,18);cout<<"WanttochangetheLastName";gotoxy(65,18);flag=0;while(1){gets(tmpnm2);if(strlen(tmpnm2)!=0){flag=1;break;}if(strlen(tmpnm2)==0){flag=0;break;}}if(flag==1){strcpy(lname,tmpnm2);}//*****************classtobemodifygotoxy(5,19);//****************CLASSNAMETOBEMODIFYcout<<"PHONENO.:";gotoxy(20,19);cout<<phno;gotoxy(35,19);cout<<"WanttochangethePhoneNo.";gotoxy(65,19);flag=0;while(1){gets(tmpphno);if(strlen(tmpphno)!=0){flag=1;break;}if(strlen(tmpphno)==0){flag=0;break;}}if(flag==1){strcpy(phno,tmpphno);}//****************************************************charmch;gotoxy(5,20);cout<<"METERNO.:";//****************CLASSSECTOBEMODIFYgotoxy(20,20);cout<<meterno;gotoxy(35,20);cout<<"WanttochangetheMeter:[yorn]";gotoxy(70,20);cin>>mch;if(mch=='y'){//******************getthemeternofstreamobjiff;metermt;charmeternum[25];objiff.open("meter.dat",ios::binary|ios::in|ios::out);objiff.seekg(0,ios::beg);intpos=0;if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if(mt.getmeterstatus()=='N'){pos=(int)objiff.tellg();flag=1;break;}}strcpy(meternum,mt.getmeterreg());mt.setmeterstatus();objiff.seekp(pos-sizeof(meter),ios::beg);objiff.write((char*)&mt,sizeof(meter));}objiff.close();//************************************************************strcpy(meterno,tmpmtno);}gotoxy(5,21);cout<<"ADDRESS:";gotoxy(20,21);cout<<hn<<"-"<<add1<<","<<add2;gotoxy(35,21);cout<<"Wanttochangetheaddress[yyesornno]";gotoxy(65,21);cin>>choice;if(choice=='y'){gotoxy(20,22);cout<<"hno,address1,address2";gotoxy(35,22);cin>>hn>>add1>>add2;}//***************************************************gotoxy(5,23);cout<<"=====================================================================";}//*****************classesnameends**************************************//*********************welcomepage*************************************voidintro(){clrscr();gotoxy(4,2);cout<<"***************************ELECTRICITYBILLING**************************";gotoxy(12,4);cout<<"==============================MANAGEMENT================================";gotoxy(5,5);cout<<"******************************S=Y=S=T=E=M*******************************";gotoxy(50,10);cout<<"PROJECT:";gotoxy(50,12);cout<<"MADEBY:STUDENTNAME";gotoxy(8,14);cout<<"--------------------DOONPUBLICSCHOOL,HALDWANI------------------------";gotoxy(8,15);cout<<"------------------CLASS:XIIB(COMPUTERSCIENCE)-------------------";getch();}//*********************welcomepage*************************************//************************MAINSTARTS***************************************voidmain(){charch;intro();if(checkpass()==0){do{//****************TEMPORARY***********************clrscr();intromain();gotoxy(20,6);cout<<"=================MAINMENU====================";gotoxy(28,7);cout<<"01.REPORTGENERATOR";gotoxy(28,8);cout<<"02.ADMINISTRATOR";gotoxy(28,9);cout<<"03.EXIT";gotoxy(20,10);cout<<"==============================================";gotoxy(25,12);cout<<"PleaseSelectYourOption(1-3)";gotoxy(30,14);ch=getche();switch(ch){case'1':reports();break;case'2':admin_menu();break;case'3':exit(0);}}while(ch!='3');}else{exit(0);}}//****************************FUNCTIONSSTARTSHERE************************//******************************loginnameandpassword****************intcheckpass(){charnm[20];charpass[10];clrscr();intromain();gotoxy(20,20);cout<<"PLEASEENTERTHEUSERNAME:";gotoxy(20,21);cin>>nm;clrscr();gotoxy(20,20);cout<<"PLEASEENTERTHEPASSWORD:";gotoxy(20,21);cin>>pass;if(strcmp(nm,"admin")==0&&strcmp(pass,"1234")==0){return0;}else{return1;}}//*******************introductionvoidintromain(){clrscr();gotoxy(1,2);cout<<"*************************ELECTRICITY****BILLING*****SYSTEM**********************";gotoxy(1,3);cout<<"*************************************PROJECT***********************************";}//**************************adminstarts**********************************voidadmin_menu(){clrscr();charch2='\0';//************************************************************clrscr();intromain();gotoxy(20,6);cout<<"=================ADMINMENU====================";gotoxy(22,7);cout<<"1.CUSTOMER'SINFORMATION";gotoxy(22,8);cout<<"2.METER'SINFORMATION";gotoxy(22,9);cout<<"3.BILLING/TRANSCATIONS";gotoxy(22,10);cout<<"4.BACKTOMAINMENU";gotoxy(22,12);cout<<"PleaseEnterYourChoice(1-4)";gotoxy(23,16);//**********************************************************ch2=getche();switch(ch2){case'1':if(checkmetergen()==1){customer_info();}else{clrscr();intromain();gotoxy(20,6);cout<<"Pleaseenterthemeterinformationfirst";getch();}break;case'2':meter_info();break;case'3':if(checkmetergentrans()==1){transcations();}else{clrscr();intromain();gotoxy(20,6);cout<<"Pleaseenterthemeterinformationfirst";}getch();break;case'4':break;default:cout<<"\a";admin_menu();}}//************************checkmetergeneratedfortransintcheckmetergentrans(){ifstreamobjiff;metermt;intcount=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";count=-1;}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if(mt.getmeterstatus()=='Y'){count=1;break;}}}objiff.close();returncount;}//**************************customerinformationsystem*******************voidcustomer_info(){clrscr();charch2='\0';intnum=0;//************************************************************clrscr();intromain();gotoxy(20,6);cout<<"=================CUSTOMER'SINFORMATION====================";gotoxy(22,7);cout<<"1.ADDCUSTOMER'SINFORMATIONS";gotoxy(22,8);cout<<"2.MODIFYCUSTOMER'SINFORMATIONS";gotoxy(22,9);cout<<"3.DELETECUSTOMER'SINFORMTIONS";gotoxy(22,10);cout<<"4.BACKTOMENU";gotoxy(22,12);cout<<"PleaseEnterYourChoice(1-4)";gotoxy(23,16);ch2=getche();switch(ch2){case'1':write_customer();break;case'2':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHECUSTIDTOBESEARCHEDANDMODIFY:";gotoxy(55,9);cin>>num;modify_customer_record(num);break;case'3':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHECUSTIDTOBESEARCHEDANDDELETE:";gotoxy(55,9);cin>>num;delete_cust_record(num);break;case'4':break;default:cout<<"\a";admin_menu();}}//************************customerfunctions*******************************//*****************deletethecustomerrecords****************************voiddelete_cust_record(intn){customercust;ifstreaminFile;inFile.open("customer.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}intflag=0;while(inFile.read((char*)&cust,sizeof(customer))){if(cust.getcustid()==n){clrscr();intromain();cust.showdatamulti_cust();flag=1;}}inFile.close();charch;if(flag==0)cout<<"\n\nrecordnotexist";else{//*******deletionoftherecordsstartsfromheregotoxy(1,15);cout<<"*****************************************************************************";gotoxy(5,16);cout<<"======DOYOUWANTTODELETETHERECORDSGIVENABOVE[YES(Y)ORNO(N)========";gotoxy(2,17);cin>>ch;if(toupper(ch)=='Y'){ofstreamoutFile;outFile.open("Temp1.dat",ios::binary);ifstreamobjiff("customer.dat",ios::binary);objiff.seekg(0,ios::beg);while(objiff.read((char*)&cust,sizeof(customer))){if(cust.getcustid()!=n){outFile.write((char*)&cust,sizeof(customer));}}outFile.close();objiff.close();remove("customer.dat");rename("Temp2.dat","customer.dat");gotoxy(30,20);cout<<"----------------------------RecordDeleted----------------------------------";}}getch();}//*****************deletethecustomerrecords****************************//*****************modifythecustomerrecords****************************voidmodify_customer_record(intn){customercust;ifstreaminFile;intfpos=-1;inFile.open("customer.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();}intflag=0;while(inFile.read((char*)&cust,sizeof(customer))){if(cust.getcustid()==n){clrscr();intromain();cust.showdatamulti_cust();flag=1;}}inFile.close();if(flag==0)cout<<"\n\nrecordnotexist";else{//*******modifyingtherecordsstartsherefstreamFile;File.open("customer.dat",ios::binary|ios::in|ios::out);if(!File){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}while(File.read((char*)&cust,sizeof(customer))){if(cust.getcustid()==n){fpos=(int)File.tellg();break;}}File.seekp(fpos-sizeof(customer),ios::beg);gotoxy(1,12);cout<<"*****************************************************************************";gotoxy(1,13);cout<<"======ENTERNEWVALUESFORTHERECORDSGIVENABOVE=================";cust.modifydatacust();File.write((char*)&cust,sizeof(customer));File.close();}}//*****************modifythecustomerrecords****************************//functiontowriteinfile//****************************************************************voidwrite_customer(){intflag=-1,pos=0;fstreamfp;customercust;charmeternum[25];fp.open("customer.dat",ios::out|ios::app);clrscr();intromain();intrnn=getcustno();if(rnn>10000){rnn=1;}//******************getthemeternofstreamobjiff;metermt;objiff.open("meter.dat",ios::binary|ios::in|ios::out);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if(mt.getmeterstatus()=='N'){pos=(int)objiff.tellg();flag=1;break;}}}//******************getthemeternomt.getmeterreg()if(flag==1){strcpy(meternum,mt.getmeterreg());cust.addcustomer(rnn,meternum);mt.setmeterstatus();objiff.seekp(pos-sizeof(meter),ios::beg);objiff.write((char*)&mt,sizeof(meter));objiff.close();fp.write((char*)&cust,sizeof(customer));fp.close();gotoxy(10,20);cout<<"***************CUSTOMER'SRECORDSAVED*******************";cin.ignore();getch();}else{fp.close();gotoxy(10,20);cout<<"****PLEASEADDMETERINFORMATIONBEFORECUSTOMER'SRECORDSAVED****";cin.ignore();getch();}}//********************checktheStudentrollnumberalreadygivenornot******intgetcustno(){ifstreamobjiff;customercust;intcount=0,count2=0;objiff.open("customer.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";count=1;getch();}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&cust,sizeof(customer))){count2++;}count=count2;count++;}objiff.close();returncount;}//************************customerfunctions*******************************//*****************meter_infoinformations*****************************voidmeter_info(){clrscr();charch2='\0';charmnum[25];//************************************************************clrscr();intromain();gotoxy(20,6);cout<<"=================METER'SINFORMATION====================";gotoxy(22,7);cout<<"1.ADDMETER'SINFORMATIONS";gotoxy(22,8);cout<<"2.DELETEMETER'SINFORMTIONS";gotoxy(22,9);cout<<"3.BACKTOMENU";gotoxy(22,11);cout<<"PleaseEnterYourChoice(1-3)";gotoxy(23,13);ch2=getche();switch(ch2){case'1':write_meter();break;case'2':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHEMETERNOTOBESEARCHEDANDDELETE:";gotoxy(55,9);cin>>mnum;delete_meter(mnum);break;case'3':break;default:cout<<"\a";admin_menu();}}//***************************************************************//functiontodeletethemeternumbervoiddelete_meter(charmn[25]){metermt;ifstreaminFile;inFile.open("meter.dat",ios::binary);if(!inFile){cout<<"Filecouldnotbeopen!!PressanyKey...";getch();return;}intflag=0;while(inFile.read((char*)&mt,sizeof(meter))){if((strcmp(mt.getmeterreg(),mn)==0)&&mt.getmeterstatus()=='N'){clrscr();intromain();mt.showmeters();flag=1;}}inFile.close();charch;if(flag==0)cout<<"\n\nrecordnotexist";else{//*******deletionoftherecordsstartsfromheregotoxy(1,15);cout<<"*****************************************************************************";gotoxy(5,16);cout<<"==DOYOUWANTTODELETETHERECORDSGIVENABOVE[YES(Y)ORNO(N)========";gotoxy(2,17);cin>>ch;if(toupper(ch)=='Y'){ofstreamoutFile;outFile.open("Temp2.dat",ios::binary);ifstreamobjiff("meter.dat",ios::binary);objiff.seekg(0,ios::beg);while(objiff.read((char*)&mt,sizeof(meter))){if(strcmp(mt.getmeterreg(),mn)!=0){outFile.write((char*)&mt,sizeof(meter));}}outFile.close();objiff.close();remove("meter.dat");rename("Temp2.dat","meter.dat");gotoxy(30,20);cout<<"----------------------------RecordDeleted----------------------------------";}}getch();}//functiontowriteinfile//****************************************************************voidwrite_meter(){charseries[25],mtrno[25],ch,temp[15];fstreamfp;meterm;clrscr();intromain();intN,x;gotoxy(10,10);cout<<"newseriesoroldone[yorn]";gotoxy(10,11);cin>>ch;if(ch=='y'){clrscr();intromain();gotoxy(10,10);cout<<"Entertheseriesstarting4number:";gotoxy(10,11);cin>>series;clrscr();intromain();gotoxy(10,10);cout<<"Enternumberofmeternumbertobegenerated:";gotoxy(10,11);cin>>N;for(x=1;x<=N;x++){intrnn=getmeterno();if(rnn>10000){rnn=1;}strcpy(mtrno,series);itoa(rnn,temp,10);strcat(mtrno,temp);cout<<"\nrnn="<<rnn<<"series="<<series<<"mtrno="<<mtrno;getch();fp.open("meter.dat",ios::binary|ios::out|ios::app);m.writemeter(rnn,series,mtrno,'N');fp.write((char*)&m,sizeof(m));fp.close();}}else{strcpy(series,m.getseries());clrscr();intromain();gotoxy(10,10);cout<<"Enternumberofmeternumbertobegenerated:";gotoxy(10,11);cin>>N;for(x=1;x<=N;x++){intrnn=getmeterno();if(rnn>10000){rnn=1;}strcpy(mtrno,series);itoa(rnn,temp,1);strcat(mtrno,temp);fp.open("meter.dat",ios::binary|ios::out|ios::app);m.writemeter(rnn,series,mtrno,'N');fp.write((char*)&m,sizeof(m));fp.close();}}gotoxy(10,20);cout<<"***************METER'SRECORDSAVED*******************";cin.ignore();getch();}//********************getmeterno*************************************intgetmeterno(){ifstreamobjiff;meterm;intcount=0,count2=0;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){count=1;}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&m,sizeof(meter))){count2++;}count=count2;count++;}objiff.close();returncount;}//*****************Billingtranscationsinformations*****************************//*********************************************voidtranscations(){clrscr();charch2='\0';charmnum[25];//************************************************************clrscr();intromain();gotoxy(20,6);cout<<"=================BILLING/TRANSCATIONS====================";gotoxy(22,7);cout<<"1.ADDBILLREADING";gotoxy(22,8);cout<<"2.MODIFYBILLREADING";gotoxy(22,9);cout<<"3.TRANSCATIONS";gotoxy(22,10);cout<<"4.BACKTOMENU";gotoxy(22,12);cout<<"PleaseEnterYourChoice(1-4)";gotoxy(23,16);ch2=getche();switch(ch2){case'1':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHEMETERNO:";gotoxy(55,9);cin>>mnum;write_bills(mnum);break;case'2':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHEMETERNO:";gotoxy(55,9);cin>>mnum;modify_bills(mnum);break;case'3':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHEMETERNO:";gotoxy(55,9);cin>>mnum;paid_bills(mnum);break;case'4':break;default:cout<<"\a";admin_menu();}}//***************************************************************voidpaid_bills(charmnum[25]){fstreamfp;fstreamobjiffback;billingbl;charmeternum[25];fp.open("billing.dat",ios::binary|ios::out|ios::in);ofstreamtrobj("trans.dat",ios::binary|ios::app);transtr;clrscr();intromain();con_dated1;intbpos=-1,bflag=-1;billprevrecordbrprv;floatamtadd=0.00;floatamtded=0.00;intkpos=0,amount=0;floatdeduct=0.00;floatamountaddnxt=0.00,totalamount=0.00;//********************meterdetails*****************************************************************ifstreamobjiff;metermt;intflag=-1,flag2=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{while(objiff.read((char*)&mt,sizeof(meter))){if((strcmp(mnum,mt.getmeterreg())==0)&&mt.getmeterstatus()=='Y'){flag=1;break;}}}//*************************meterdetails**************************************************if(flag==1){if(checkbillpaid(mnum)!=1){clrscr();intromain();strcpy(meternum,mt.getmeterreg());//*****************displaycustomerinformation**********displaycust_meterno(mnum,5);//*****************billinfoif(!objiff){}else{while(fp.read((char*)&bl,sizeof(billing))){if((strcmp(meternum,bl.getmtn())==0)&&bl.getstatus()=='Y'){kpos=(int)fp.tellg();flag2=1;break;}}if(flag2==1){//***************getthepreviouleftamount*********************objiffback.open("billsprevrecord.dat",ios::binary|ios::in|ios::out);objiffback.seekg(0,ios::beg);if(!objiffback){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{while(objiffback.read((char*)&brprv,sizeof(billprevrecord))){if((strcmp(mnum,brprv.mtrno)==0)&&brprv.status=='Y'){bpos=(int)objiffback.tellg();bflag=1;break;}}if(bflag==1){amtadd=brprv.amtadd;amtded=brprv.amtdud;brprv.status='N';objiffback.seekp(bpos-sizeof(billprevrecord),ios::beg);objiffback.write((char*)&brprv,sizeof(billprevrecord));}}//***************getthepreviouleftamount*********************gotoxy(5,10);cout<<"============================================================";gotoxy(5,11);totalamount=bl.getnetamt();totalamount=totalamount+amtadd;totalamount=totalamount-amtded;cout<<"AMOUNT:"<<setw(8)<<bl.getnetamt()<<setw(10)<<"+ADDAMT:"<<setw(8)<<amtadd<<setw(10)<<"-DEDUCTAMT:"<<setw(8)<<amtded;gotoxy(5,12);cout<<"BILLAMOUNT"<<setw(15)<<totalamount;gotoxy(5,13);cout<<"Pleasedepositetheamount:";gotoxy(50,14);cin>>amount;gotoxy(5,15);cout<<"dateofdeposit[dd-mm-yyyy]:";gotoxy(5,16);cin>>d1.dd>>d1.mm>>d1.yy;if(amount>totalamount){deduct=(amount-totalamount);amountaddnxt=0;}else{amountaddnxt=(totalamount-amount);deduct=0;}tr.settrans(bl.getbno(),meternum,bl.getbno(),d1,totalamount,amount,amountaddnxt,deduct);trobj.write((char*)&tr,sizeof(trans));gotoxy(10,20);cout<<"***************billPaid*******************";overwritebillrecord(meternum);//*******settheamountfornxtbillssetoldleftamount(bl.getbno(),meternum,amountaddnxt,deduct);//*******settheamountfornxtbillsfp.seekp(kpos-sizeof(billing),ios::beg);bl.setstatus('N');fp.write((char*)&bl,sizeof(billing));}}//*****************billinfo}else{gotoxy(10,20);cout<<"***************BILLPAID!!!!!!!!*******************";}}else{gotoxy(10,20);cout<<"***************error!!!!!!!*******************";}getch();objiff.close();fp.close();trobj.close();objiffback.close();}//*******************billentry****************************voidwrite_bills(charmnum[25]){fstreamfp;billingbl;charmeternum[25];fp.open("billing.dat",ios::binary|ios::out|ios::app);clrscr();intromain();intrnn=getbillno();if(rnn>100){rnn=1;}ifstreamobjiff;metermt;intflag=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if((strcmp(mnum,mt.getmeterreg())==0)&&mt.getmeterstatus()=='Y'){flag=1;break;}}}//******************getthemeternomt.getmeterreg()if(flag==1){if(checkbillpaid(mnum)==1){clrscr();intromain();strcpy(meternum,mt.getmeterreg());//*****************displaycustomerinformation**********displaycust_meterno(mnum,5);//*******************************************************bl.addbill(rnn,meternum);fp.write((char*)&bl,sizeof(billing));gotoxy(10,20);cout<<"***************billcreated*******************";savebillrecord(rnn,mnum);cin.ignore();getch();}else{gotoxy(10,20);cout<<"***************PLEASEPAYPREVIOUSBILLFIRST!!!!!!!*******************";}}else{gotoxy(10,20);cout<<"***************error!!!!!!!*******************";}getch();objiff.close();fp.close();}//*******************billentry*************************************voidoverwritebillrecord(charmn[25]){fstreamobjiff;billrecordbr;intkpos=0,flag=-1;objiff.open("billsrecord.dat",ios::binary|ios::in|ios::out);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{while(objiff.read((char*)&br,sizeof(billrecord))){if((strcmp(mn,br.mrtno)==0)&&br.billstatus=='Y'){flag=1;kpos=(int)objiff.tellg();break;}}if(flag==1){objiff.seekp(kpos-sizeof(billrecord),ios::beg);strcpy(br.mrtno,mn);br.billstatus='N';objiff.write((char*)&br,sizeof(br));}}objiff.close();}//******************savebillrecord********************voidsavebillrecord(intr,charmn[25]){ofstreamobjiff;billrecordbr;objiff.open("billsrecord.dat",ios::binary|ios::app);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{br.billno=r;strcpy(br.mrtno,mn);br.billstatus='Y';objiff.write((char*)&br,sizeof(br));}objiff.close();}//**********************CHECKTHEBILLPAIDORNOT*****************intcheckbillpaid(charmn[25]){ifstreamobjiff;billrecordbr;intflag=0;objiff.open("billsrecord.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";return1;}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&br,sizeof(br))){if((strcmp(mn,br.mrtno)==0)&&br.billstatus=='Y'){flag=0;break;}else{flag=1;}}}objiff.close();returnflag;}//********************getmeterno*************************************intgetbillno(){ifstreamobjiff;billingbl;intcount=0,count2=0;objiff.open("billing.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){count=1;}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&bl,sizeof(billing))){count2++;}count=count2;count++;}objiff.close();returncount;}//*******************ALLReportsDisplayMenu************************voidreports(){clrscr();charch2='\0';charmnum[25];clrscr();intromain();gotoxy(20,6);cout<<"=================REPORTS====================";gotoxy(22,7);cout<<"1.AllCustomer'sDetailsWithMeterNo.";gotoxy(22,8);cout<<"2.AllMeter'sDetailsWorking";gotoxy(22,9);cout<<"3.Displayallbills";gotoxy(22,10);cout<<"4.DisplayCustomerdetailsWithBillsDetails";gotoxy(22,11);cout<<"5.Displayallbillrecords";gotoxy(22,12);cout<<"6.Displayalltranscations";gotoxy(22,13);cout<<"7.BACKTOMENU";gotoxy(22,14);cout<<"PleaseEnterYourChoice(1-7)";gotoxy(23,16);ch2=getche();switch(ch2){case'1':display_customer();getch();break;case'2':display_meters();getch();break;case'3':display_bills();getch();break;case'4':clrscr();intromain();gotoxy(10,8);cout<<"***ENTERTHECUSTOMERMETERNO:";gotoxy(55,9);cin>>mnum;display_custwithbills(mnum);getch();break;case'5':display_billrecords();getch();break;case'6':displaytrans();getch();break;case'7':break;default:cout<<"\a";admin_menu();}}//***************************************************************intcheckmetergen(){ifstreamobjiff;metermt;intcount=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";count=-1;}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if(mt.getmeterstatus()=='N'){count=1;break;}}}objiff.close();returncount;}//*****************************displayallmeters***********************voiddisplay_meters(){ifstreamobjiff;metermt;intc=7;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";return;}else{//**************temporaryhidingtheselinesclrscr();intromain();gotoxy(25,5);cout<<"METERNO"<<setw(15)<<"STATUS";gotoxy(8,6);cout<<"=========================================================";while(objiff.read((char*)&mt,sizeof(meter))){mt.showallmeters(c);c++;}}gotoxy(8,c);cout<<"=========================================================";objiff.close();}voiddisplaycust_meterno(charmnum2[25],intk){ifstreamobjiff;customercust;intcount=0;objiff.open("customer.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&cust,sizeof(customer))){if(strcmp(mnum2,cust.getmetern())==0){count=1;break;}}if(count==1){cust.showallcustdetails(k);}}objiff.close();}//**********************displaycustomers***************************voiddisplay_customer(){ifstreamobjiff;customercust;intc=7;objiff.open("customer.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselinesclrscr();intromain();gotoxy(1,5);cout<<"NAMEOFCUST."<<setw(12)<<"ADDRESS"<<setw(15)<<"MOB.NO"<<setw(12)<<"METERNO"<<setw(15)<<"DATEODCONN";gotoxy(1,6);cout<<"======================================================================";while(objiff.read((char*)&cust,sizeof(customer))){cust.showallcust(c);c++;}gotoxy(1,c);cout<<"======================================================================";}objiff.close();}//************************************************************************voiddisplay_bills(){ifstreamobjiff;billingbl;intc=7;objiff.open("billing.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselinesclrscr();intromain();gotoxy(1,5);cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8)<<"UNITS"<<setw(15)<<"AMT+TAX="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";gotoxy(1,6);cout<<"===============================================================================";while(objiff.read((char*)&bl,sizeof(billing))){bl.showallbill(c);c++;}gotoxy(1,c);cout<<"===============================================================================";}objiff.close();}//******************************billrecords******************************voiddisplay_billrecords(){ifstreamobjiff;billrecordbr;objiff.open("billsrecord.dat",ios::binary);intc=7;objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselinesclrscr();intromain();gotoxy(1,5);cout<<"BILLNO"<<setw(10)<<"METERNO"<<setw(15)<<"STATUS";gotoxy(1,6);cout<<"===============================================================================";while(objiff.read((char*)&br,sizeof(br))){gotoxy(5,c);cout<<br.billno<<setw(10)<<br.mrtno<<setw(15)<<br.billstatus;c++;}gotoxy(1,c);cout<<"===============================================================================";}objiff.close();}//**************************displaybillsofcustomer*****************************voiddisplay_custwithbills(charmnum[25]){fstreamfp;billingbl;charmeternum[25];fp.open("billing.dat",ios::binary|ios::out|ios::in);clrscr();intromain();//******************getthemeternoifstreamobjiff;metermt;intflag=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if((strcmp(mnum,mt.getmeterreg())==0)&&mt.getmeterstatus()=='Y'){flag=1;break;}}}//******************getthemeternomt.getmeterreg()if(flag==1){clrscr();intromain();strcpy(meternum,mt.getmeterreg());//*****************displaycustomerinformation**********displaycust_meterno(mnum,5);//*****************billinfoif(!fp){}else{gotoxy(1,8);cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8)<<"UNITS"<<setw(15)<<"AMT+TAX="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";gotoxy(1,9);cout<<"===============================================================================";intc=10;while(fp.read((char*)&bl,sizeof(billing))){if(strcmp(meternum,bl.getmtn())==0){bl.showallbill(c);c++;}}gotoxy(1,c);cout<<"===============================================================================";}}else{gotoxy(10,10);cout<<"***********************nosuchcustomerrecord***************";getch();}fp.close();objiff.close();}//***********************modifythbillreadingvoidmodify_bills(charmnum[25]){fstreamfp;billingbl;charmeternum[25];fp.open("billing.dat",ios::binary|ios::out|ios::in);clrscr();intromain();intpos=-1,creading=0;//******************getthemeternoifstreamobjiff;metermt;intflag=-1;objiff.open("meter.dat",ios::binary);objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselineswhile(objiff.read((char*)&mt,sizeof(meter))){if((strcmp(mnum,mt.getmeterreg())==0)&&mt.getmeterstatus()=='Y'){flag=1;break;}}}//******************getthemeternomt.getmeterreg()if(flag==1){clrscr();intromain();strcpy(meternum,mt.getmeterreg());//*****************displaycustomerinformation**********displaycust_meterno(mnum,5);while(fp.read((char*)&bl,sizeof(billing))){if((strcmp(meternum,bl.getmtn())==0)&&bl.getstatus()=='Y'){pos=(int)fp.tellg();break;}}//***************************************gotoxy(1,8);cout<<"BILLNO"<<setw(8)<<"METERNO"<<setw(20)<<"CUR.-PREV.READING"<<setw(8)<<"UNITS"<<setw(15)<<"AMT+TAX="<<setw(10)<<"NETAMT"<<setw(10)<<"STATUS";gotoxy(1,9);cout<<"===============================================================================";bl.showallbill(10);gotoxy(10,11);cout<<"Pleaseenterthenewcurrentreading:";gotoxy(10,12);cin>>creading;bl.setnewbillreading(creading);fp.seekp(pos-sizeof(billing),ios::beg);fp.write((char*)&bl,sizeof(billing));gotoxy(10,20);cout<<"***************billre-created*******************";cin.ignore();getch();}else{gotoxy(10,20);cout<<"***************error!!!!!!!*******************";}getch();objiff.close();fp.close();}//**********************setthebillrecordvoidsetoldleftamount(intr,charmn[25],floatamtaddnxt,floatamtdeduct){ofstreamobjiff;billprevrecordbrprv;objiff.open("billsprevrecord.dat",ios::binary|ios::app);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{brprv.bno=r;strcpy(brprv.mtrno,mn);brprv.amtadd=amtaddnxt;brprv.amtdud=amtdeduct;brprv.status='Y';objiff.write((char*)&brprv,sizeof(billprevrecord));}objiff.close();}//***************************displaytranscation**************************voiddisplaytrans(){ifstreamobjiff;transtr;objiff.open("trans.dat",ios::binary);intc=7;objiff.seekg(0,ios::beg);if(!objiff){cout<<"Filecouldnotbeopen!!PressanyKey...";}else{//**************temporaryhidingtheselinesclrscr();intromain();gotoxy(1,5);cout<<"TRNO"<<setw(10)<<"METERNO"<<setw(5)<<"BNO"<<setw(5)<<"DATEOFDEPOSIT"<<setw(10)<<"AMOUNT"<<setw(10)<<"PAID"<<setw(10)<<"+ADDTONXT"<<setw(8)<<"-DEDUCT"<<setw(8)<<"STATUS";gotoxy(1,6);cout<<"===============================================================================";while(objiff.read((char*)&tr,sizeof(trans))){tr.showalltrans(c);c++;}gotoxy(1,c);cout<<"===============================================================================";}objiff.close();}//*****************************FUNCTIONSENDSHERE*************************
