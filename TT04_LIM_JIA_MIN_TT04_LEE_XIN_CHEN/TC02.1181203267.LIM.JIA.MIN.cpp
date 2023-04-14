/**********|**********|**********|
Program: TC02.1181203267.LIM.JIA.MIN.cpp 
Course: Object Oriented Programming
Year: 2020/21 Trimester 1
Name: Lim Jia Min
ID: 1181203267
Lecture Section: TC02
Tutorial Section: TT04
Email: 1181203267@student.mmu.edu.my
Phone: 016-3738920
**********|**********|**********/

#include <iostream>
#include <fstream>	//for file
#include <iomanip>	//for setw() 
#include <ctime>	//for time 
#include <cstdlib>	//for srand & rand (random number)
#include <string.h> //for strcmp(x,y) ->compare x and y
#include <sstream>	//for istringstream

using namespace std;

class SHOPPER
{
	protected:
		string name, username, address, password, password2, type, major, state;
		int id;
		
	public:
		SHOPPER()
		{
			id=0;
		}
		
		///////////////////////////////////REGISTER//////////////////////////////////////
		
		//check whether user enter number or character
		bool check_number(string name) 
		{
		   	for (int i = 0; i < name.length(); i++)
		   	{
			   	if (isdigit(name[i]) == false)
			      return false;
				else
			      return true;
			}
		}

		void register_acc()
		{
			int checkname, checkuname, checkaddress, checkpw, checkpw2;
			
			//create and write to file
			fstream f;
			f.open("User Profile.txt");	
			
			if(!f.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			f<<left <<setw(10) <<"ID" <<setw(25) <<"USERNAME" <<setw(25) <<"PASSWORD" <<setw(40) <<"NAME" <<setw(50) <<"ADDRESS" <<setw(30) <<"Customer Type" <<setw(50) <<"MAJOR STUDY" <<setw(40) <<"WORK DEPARTMENT" <<endl;
			f.close();
			
			//open file again and store profile into file without delete previous record	
			fstream f1;		
			f1.open("User Profile.txt", ios::app);	
			
			if(!f1.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			//get auto generate id
			id=getid();
			
			//name
			do
			{
				cout<<"Name					: ";		
				getline(cin,name);
				
				if(name.size()==0)
				{
					cout<<"***NAME CANNOT BE BLANK***" <<endl <<endl;
					checkname=1;
				}
				else if(check_number(name))
				{
					cout<<"***NAME CANNOT BE A NUMERIC***" <<endl <<endl;
					checkname=2;
				}
				else
				{
					checkname=3;
				}
			}
			while(checkname!=3);
			
			//username
			do
			{
				cout<<"Username [max 20 characters]		: ";
				getline(cin,username);
				
				if(username.size()>20)
				{
					cout<<"***USERNAME CANNOT BE OVER THAN 20 CHARACTERS***" <<endl <<endl;
					checkuname=1;
				}
				else if(username.size()==0)
				{
					cout<<"***USERNAME CANNOT BE BLANK***" <<endl <<endl;
					checkuname=2;
				}
				else if(username.find (' ') != string::npos) 
				{
				    cout<<"***USERNAME CANNOT HAVE A SPACE***" <<endl <<endl; 
				    checkuname=3;
				}
				else
				{
					checkuname=4;
				}
			}
			while(checkuname!=4);
			
			//address
			do
			{
				cout<<"Full Address				: ";
				getline(cin,address);
				
				if(address.size()==0)
				{
					cout<<"***ADDRESS CANNOT BE BLANK***" <<endl <<endl;
					checkaddress=1;
				}
				else
				{
					checkaddress=2;
				}
			}
			while(checkaddress!=2);
			
			//password
			do
			{
				do
				{
					cout<<"Password [max 20 characters]		: ";
					getline(cin,password);
					
					if(password.size()>20)
					{
						cout<<"***PASSWORD CANNOT BE OVER THAN 20 CHARACTERS***" <<endl <<endl;
						checkpw=1;
					}
					else if(password.size()==0)
					{
						cout<<"***PASSWORD CANNOT BE BLANK***"<<endl <<endl;
						checkpw=2;
					}
					else if(password.find (' ') != string::npos) 
					{
					    cout<<"***PASSWORD CANNOT HAVE A SPACE***" <<endl <<endl; 
					    checkpw=3;
					}
					else
					{
						checkpw=4;
					}
				}
				while(checkpw!=4);
			
				//re-enter password
				cout<<"Re-enter Password 			: ";
				getline(cin,password2);
			
				if(password!=password2)
				{
					cout<<"***WRONG PASSWORD***" <<endl <<endl;
					checkpw2=1;
				}
				else
				{
					checkpw2=2;
				}
			}
			while(checkpw2!=2);
			
           	if(password==password2)
			{
				cout<<endl <<"-------DONE REGISTER-------" <<endl <<endl;
			}
			
			f1<<left <<setw(10) <<id <<setw(25) <<username <<setw(25) <<password2 <<setw(40) <<name <<setw(50) <<address <<setw(30) <<type <<setw(50) <<major <<setw(40) <<state <<endl;
           	f1.close();
		}
		
		//////////////////////////////////////LOGIN///////////////////////////////////////////////
		
		void login_acc()
		{
			//register
			string name, username, address, password, password2, type, major, state;
				
			//login
			string uname, un, p, pw;
			
			bool found = false;
			
			cin.ignore();		
			do
			{
				//read from file
				ifstream f2("User Profile.txt", ios::in);
				
				if(!f2.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
		    	
				// user login with username and password	
		       	cout<<endl;
				cout<<"Enter Username	: ";    
		        getline(cin,uname);
		    
				cout<<"Enter Password	: ";
		        getline(cin,p);
		
				string line=" ";
					
		   	   	//read word with space
				while(getline(f2,line))	
			    {
					istringstream data(line);
					data >> id;	
					data >> un;
					data >> pw;
					data >> name;
					data >> address;
					data >> type;
					data >> major;
					data >> state;
					
		            if(pw==p && un==uname)
		            {
		            	cout<<endl <<"-------LOGIN SUCCESSFULL-------" <<endl <<endl;
		    			found=true;
						break;        	
		            }
			    }
			    
			    //when not found the specific username and password
			    if(!found)
			    {
			    	cout<<"***INVALID ID OR PASSWORD***" <<endl <<endl;
				}
				
				f2.close();
			}
			while(!found);
		}
		
		//////////////////////////////////////UPDATE ACC////////////////////////////////////////////////
		
		//check whether user enter number or character
		bool check_newnumber(string newname) 
		{
		   for (int i = 0; i < newname.length(); i++)
		   {
			   	if (isdigit(newname[i]) == false)
			      return false;
				else
			      return true;
			}
		}
		
		void update_acc()
		{
			//register
			string name, username, address, password, password2, type, major, state;
			int id;
			
			//login
			string uname, un, p, pw;
		
			//update
			string newname, newusername, newaddress, newpassword, newpassword2, newtype, newmajor, newstate;
			
			int checktype, checkname, checkuname, checkaddress, checkpw, checkpw2;
			int idupt, num, choice;
			string data;
			
			cout<<"-------UPDATE PROFILE-------" <<endl <<endl;
			
			//viewuser();
			
			bool found = false;
			
			do
			{	
				//open file to check id user to be update	
				ifstream a;
		    	a.open("User Profile.txt", ios::in);
		    	
		    	if(!a.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
		        cout<<"Enter Your ID : ";
				cin>>idupt;
				
				cout<<endl;
				
			    string line;
			    
				//read word with space
				while(getline(a,line))	
			    {
					istringstream data(line);
					data >> id;	
					data >> un;
					data >> pw;
					data >> name;
					data >> address;
					data >> type;
					data >> major;
					data >> state;
					
		            if(id==idupt && idupt!=0)
		            {
		            	found=true;
		            	continue;       	
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ID***" <<endl <<endl;
				}
				a.close();
			}
			while(!found);
			
			//open file again to update profile
			ifstream user;
		    user.open("User Profile.txt");
		    
		    if(!user.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
		    
			ofstream temp;
		    temp.open("temp.txt");
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			//change new profile//
		
			//change new customer type
			do
			{
				cout<<"=== CUSTOMER TYPE ===" <<endl;
				cout<<"[1] Normal Customer " <<endl;
				cout<<"[2] MMU Student " <<endl;
				cout<<"[3] MMU Staff " <<endl;
				
				cout<<endl;
				cout<<"Choice of New Customer Type : ";
				cin>>choice;
				
				cout<<endl;
				cin.ignore();
				
				if(choice==1)
				{
					newmajor="-";
					newstate="-";
					newtype="Normal Customer";
					
					checktype=1;
				}
				else if(choice==2)
				{
					cout<<"Major Study				: ";
					getline(cin,newmajor);
					
					newstate="-";
					newtype="MMU Student";
					
					checktype=2;
				}
				else if(choice==3)
				{
					newmajor="-";
					
					cout<<"Name of Work Department : ";
					getline(cin,newstate);
					
					newtype="MMU Staff";
					
					checktype=3;
				}
				else
				{
					cout<<"***INVALID INPUT***" <<endl <<endl;
					checktype=4;
				}
			}
			while(checktype==4);
			
			//change new name
			do
			{
				cout<<"New Name				: ";		
				getline(cin,newname);
				
				if(newname.size()==0)
				{
					cout<<"***NAME CANNOT BE BLANK***" <<endl <<endl;
					checkname=1;
				}
				else if(check_newnumber(newname))
				{
					cout<<"***NAME CANNOT BE A NUMERIC***" <<endl <<endl;
					checkname=2;
				}
				else
				{
					checkname=3;
				}
			}
			while(checkname!=3);
			
			//change new username
			do
			{
				cout<<"New Username [max 20 characters]	: ";
				getline(cin,newusername);
				
				if(newusername.size()>20)
				{
					cout<<"***USERNAME CANNOT BE OVER THAN 20 CHARACTERS***" <<endl <<endl;
					checkuname=1;
				}
				else if(newusername.size()==0)
				{
					cout<<"***USERNAME CANNOT BE BLANK***" <<endl <<endl;
					checkuname=2;
				}
				else if(newusername.find (' ') != string::npos) 
				{
				    cout<<"***USERNAME CANNOT HAVE SPACE***" <<endl; 
				    checkuname=3;
				}
				else
				{
					checkuname=4;
				}
			}
			while(checkuname!=4);
			
			//change new address
			do
			{
				cout<<"New Address				: ";
				getline(cin,newaddress);
				
				if(newaddress.size()==0)
				{
					cout<<"***ADDRESS CANNOT BE BLANK***" <<endl <<endl;
					checkaddress=1;
				}
				else
				{
					checkaddress=2;
				}
			}
			while(checkaddress!=2);
			
			//change new password
			do
			{
				do
				{
					cout<<"New Password [max 20 characters]	: ";
					getline(cin,newpassword);
					
					if(newpassword.size()>20)
					{
						cout<<"***PASSWORD CANNOT BE OVER THAN 20 CHARACTERS***" <<endl <<endl;
						checkpw=1;
					}
					else if(newpassword.size()==0)
					{
						cout<<"***PASSWORD CANNOT BE BLANK***" <<endl <<endl;
						checkpw=2;
					}
					else
					{
						checkpw=3;
					}
				}
				while(checkpw!=3);
			
				//re-enter new password
				cout<<"Re-enter New Password 			: ";
				getline(cin,newpassword2);
			
				if(newpassword!=newpassword2)
				{
					cout<<"***WRONG PASSWORD***" <<endl <<endl;
					checkpw2=1;
				}	
				else
				{
					checkpw2=2;
				}
			}
			while(checkpw2!=2);
			
			while(user.good())	
		    {
		    	getline(user,data);
		    	if(user)
		    	{
		    		int num;
					istringstream(data)>>num;
					
		            if(num!=idupt)
		            {
		            	temp<<data<<endl; 	
		            }
		            else
		            {
		            	//store updated profile into new file 
		            	temp<<left <<setw(10) <<idupt <<setw(25) <<newusername <<setw(25) <<newpassword2 <<setw(40) <<newname <<setw(50) <<newaddress <<setw(30) <<newtype <<setw(50) <<newmajor <<setw(40) <<newstate <<endl;
					}
		        }
		    }
		    
		    temp.close();
		    user.close();		
			remove("User Profile.txt"); //remove old file
			rename("temp.txt","User Profile.txt"); //rename new file 
			
			//display latest profile
			if(choice==1) //normal cust
			{
				cout<<endl;
				cout<<"-------YOUR LATEST PROFILE-------" <<endl<<endl;
				cout<<"ID		: " <<idupt <<endl;
				cout<<"Customer Type	: " <<newtype <<endl;
				cout<<"Name		: " <<newname <<endl;
				cout<<"Username	: " <<newusername <<endl;
				cout<<"Address		: " <<newaddress <<endl;
				cout<<"Password	: " <<newpassword2 <<endl <<endl;
			
			}
			else if(choice==2) //MMU Stud
			{
				cout<<endl;
				cout<<"-------YOUT LATEST PROFILE-------" <<endl<<endl;
				cout<<"ID		: " <<idupt <<endl;
				cout<<"Customer Type	: " <<newtype <<endl;
				cout<<"Major Study	: " <<newmajor  <<endl;
				cout<<"Name		: " <<newname <<endl;
				cout<<"Username	: " <<newusername <<endl;
				cout<<"Address		: " <<newaddress <<endl;
				cout<<"Password	: " <<newpassword2 <<endl <<endl;
			}
			else if(choice==3) //MMU Staff
			{
				cout<<endl;
				cout<<"-------YOUR LATEST PROFILE-------" <<endl<<endl;
				cout<<"ID		: " <<idupt <<endl;
				cout<<"Customer Type	: " <<newtype <<endl;
				cout<<"Department	: " <<newstate  <<endl;
				cout<<"Name		: " <<newname <<endl;
				cout<<"Username	: " <<newusername <<endl;
				cout<<"Address		: " <<newaddress <<endl;
				cout<<"Password	: " <<newpassword2 <<endl <<endl;
			}
			
			cout<<"--DONE UPDATE--" <<endl <<endl;
		}
		
		//////////////////////////////////////DEREGISTER//////////////////////////////////////////////
				
		void deregister_acc()	
		{
			//register
			string name, username, address, password, password2, type, major, state;
			int id;
			
			//login
			string uname, un, p, pw;
		
			//update
			string newname, newusername, newaddress, newpassword, newpassword2, newtype, newmajor, newstate;
		
			string data;
			int iddlt, num;
			
			cout<<"-------Delete Account-------" <<endl <<endl;
			
			bool found = false;
			
			do
			{		
				//open file to check id user to be delete
				ifstream a;
		    	a.open("User Profile.txt", ios::in);
				
				if(!a.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
		        cout<<"Enter Your ID : ";
				cin>>iddlt;
			    cout<<endl;
			    
			    string line;
			    
			    //read word by word with space
				while(getline(a,line))	
			    {
					istringstream data(line);
					data >> id;	
					data >> un;
					data >> pw;
					data >> name;
					data >> address;
					data >> type;
					data >> major;
					data >> state;
					
		            if(id==iddlt && iddlt!=0)
		            {
		            	found=true;
		            	continue;       	
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ID***" <<endl <<endl;
				}
				a.close();
			}
			while(!found);
			
			fstream user ;
		    user.open("User Profile.txt");
		    
		    if(!user.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
		    
			fstream temp;
		    temp.open("temp.txt", ios::out | ios::trunc);
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
				
		    while(user.good())	
		    {
		    	getline(user,data);
		    	if(user)
		    	{
					istringstream(data)>>num;
		            if(num!=iddlt)
		            {
		            	temp<<data<<endl; 	
		            }
		        }
		    }
		    
		    user.close();
		    temp.close();
		    remove("User Profile.txt");
			rename("temp.txt","User Profile.txt");
			
			cout<<endl <<"--DONE DELETE--" <<endl <<endl <<endl;
		}
		
		////////////////////////////////////AUTO GENERATE ID///////////////////////////////////////////
		
		//to get customer id
		//4 digit auto generate number
		int getid()
		{
			//program for auto generated numbers
			//this  function must write before the 'rand' function
			unsigned seed = time(0);
			srand(seed);
			
       		id = rand()%9000+1000; 
			//random number between 1000 to 9999
			
			return id;
		}
		
		//to get order id and purchase id
		//5 digit auto generate number
		int get_randid()
		{
			int id;
			//program for auto generated numbers
			//this  function must write before the 'rand' function
			unsigned seed = time(0);
			srand(seed);
			
			id = rand()%90000+10000; 
			//random number between 10000 to 99999
			
			return id;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////
		
		//view all registered user profile
		void viewuser()
		{
			string data;
			
			fstream document;
			document.open("User Profile.txt");
			
			while(!document.eof())
			{
				getline(document,data);
				cout<<data<<endl;
			}
		}
		
		virtual void display() = 0; //PURE VIRTUAL FUNCTION
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Customer : public SHOPPER
{
	char yn;
	
	public:
		Customer()
		{
			cout<<"--Normal Customer--" <<endl<<endl;
		}
		
		string set_type()
		{ 
			type="Normal Customer";
			cin.ignore();
			
			return type;
		}
	
		string set_state()
		{
			state="-";
			return state;
		}
		
		string set_major()
		{
			major="-";
			return major;
		}
		
		void display()
		{
			cout<<endl;
			cout<<"-------YOUR PROFILE-------" <<endl <<endl;
			cout<<"ID		: " <<id <<" (auto generate)" <<endl;
			cout<<"Customer Type	: " <<type <<endl;
			cout<<"Name		: " <<name <<endl;
			cout<<"Username	: " <<username <<endl;
			cout<<"Address		: " <<address <<endl;
			cout<<"Password	: " <<password2 <<endl <<endl;
		}
};

class MMUStudent : public SHOPPER
{
	public:
		MMUStudent()
		{
			cout<<"--MMU Student--" <<endl<<endl;
		}
		
		string set_type()
		{ 
			type="MMU Student";
			return type;
		}
		
		string set_state()
		{
			state="-";
			return state;
		}
		
		void set_major()
		{
			cout<<"Major Study				: ";
			cin.ignore();
			getline(cin,major);
		}
		
		void display()
		{
			cout<<endl;
			cout<<"-------YOUR PROFILE-------" <<endl <<endl;
			cout<<"ID		: " <<id <<" (auto generate)" <<endl;
			cout<<"Customer Type	: " <<type <<endl;
			cout<<"Major Study	: " <<major  <<endl;
			cout<<"Name		: " <<name <<endl;
			cout<<"Username	: " <<username <<endl;
			cout<<"Address		: " <<address <<endl;
			cout<<"Password	: " <<password2 <<endl <<endl;
		}
};

class MMUStaff : public SHOPPER
{
	public:
		MMUStaff()
		{
			cout<<"--MMU Staff--" <<endl<<endl;
		}
		
		string set_type()
		{ 
			type="MMU Staff";
			return type;
		}
		
		void set_state()
		{
			cout<<"Name of Work Department 		: ";
			cin.ignore();
			getline(cin,state);
		}
		
		string set_major()
		{
			major="-";
			return major;
		}
		
		void display()
		{
			cout<<endl;
			cout<<"-------YOUR PROFILE-------" <<endl <<endl;
			cout<<"ID		: " <<id <<" (auto generate)" <<endl;
			cout<<"Customer Type	: " <<type <<endl;
			cout<<"Department	: " <<state  <<endl;
			cout<<"Name		: " <<name <<endl;
			cout<<"Username	: " <<username <<endl;
			cout<<"Address		: " <<address <<endl;
			cout<<"Password	: " <<password <<endl <<endl;
		}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Shop_Cart
{
	private:
		int action1, action2, action3, action4;
		
		SHOPPER *s;
	public:
		Shop_Cart()
		{
			cout<<endl;
			cout<<"================================================"<<endl;
			cout<<"           SHOPPER MANAGEMENT CENTER            "<<endl;
			cout<<"================================================"<<endl<<endl;
		}
		
		////////////////////////////////////////////MAIN MENU////////////////////////////////////////////////////////////
		
		int mainmenu()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"                    ACTIONS                     "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] Manage Profile"<<endl;
			cout<<"[2] Manage Shopping Cart"<<endl;
			cout<<"[3] Manage Past Shopping Record"<<endl;
			cout<<"[4] Logout"<<endl<<endl;
			
			action_menu();
		}
		
		void action_menu()
		{
			cout<<"Enter your choice : ";
			cin>>action1;
			cout<<endl;
			
			while(action1!=1 && action1!=2 && action1!=3 && action1!=4)
			{
				cout<<">>YOU HAVE ENTERED AN INVALID ACTION<<"<<endl<<endl;
				
				mainmenu();
				
				cout<<"Enter your choice : ";
				cin>>action1;
				cout<<endl;
			}
			
			manage_action();
		}
		
		void manage_action()
		{	
			if(action1==1) //manage profile
			{
				manage_profile();
			}
			else if(action1==2) //manage shopping cart
			{
				manage_shopcart();
			}
			else if(action1==3) //manage past shopping cart record
			{
				manage_pastrecord();
			}
			else if(action1==4) //logout
			{
				cout<<"Logged out."<<endl;
				cout<<"--THANK YOU--"<<endl <<endl;
				exit(0);
			}
		}
		
		////////////////////////////////////////////////////MANAGE ROFILE////////////////////////////////////////////////////////////
		
		void manage_profile()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"               ACTIONS TO PROFILE               "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] Update Profile"<<endl;
			cout<<"[2] Deregister"<<endl;
			cout<<"or"<<endl;
			cout<<"[3] Back to menu"<<endl<<endl;
			
			action_profile();
		}
		
		void action_profile()
		{
			cout<<"Enter your choice : ";
			cin>>action2;
			cout<<endl;
			
			while(action2!=1 && action2!=2 && action2!=3)
			{
				cout<<">>YOU HAVE ENTERED AN INVALID ACTION<<"<<endl<<endl;
				
				manage_profile();
				
				cout<<"Enter your choice : ";
				cin>>action2;
				cout<<endl;
			}
			
			profile();
		}
		
		void profile()
		{
			if(action2==1) //update profile
			{
				s->update_acc();
				manage_profile(); //back to menu of ACTION TO PROFILE
			}
			else if(action2==2) //deregister
			{
				s->deregister_acc();
				manage_profile(); //back to menu of ACTION TO PROFILE
			}
			else if(action2==3) //back to mainmenu
			{
				mainmenu();
			}
			
			manage_profile();
		}
		
		/////////////////////////////////////////////////////////MANAGE SHOP CART////////////////////////////////////////////////
		
		void manage_shopcart()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"            ACTIONS TO SHOPPING CART            "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] View Items"<<endl;
			cout<<"[2] Add Items To Shopping Cart"<<endl;
			cout<<"[3] Modify Items In Shopping Cart"<<endl;
			cout<<"[4] Delete Items From Shopping Cart"<<endl;
			cout<<"[5] Check Out Items"<<endl;
			cout<<"or"<<endl;
			cout<<"[6] Back to menu"<<endl<<endl;
			
			action_shopcart();
		}
		
		void action_shopcart()
		{
			cout<<"Enter your choice : ";
			cin>>action3;
			cout<<endl;
			
			while(action3!=1 && action3!=2 && action3!=3 && action3!=4 && action3!=5 && action3!=6)
			{
				cout<<">>YOU HAVE ENTERED AN INVALID ACTION<<"<<endl<<endl;
				
				manage_shopcart();
				
				cout<<"Enter your choice : ";
				cin>>action3;
				cout<<endl;
			}
			
			shopcart();
		}
		
		void shopcart()
		{
			if(action3==1) //view item
			{
				view_item();
				manage_shopcart(); // back to menu of ACTIONS TO SHOPPING CART
			}
			else if(action3==2) //add item
			{
				add_item();
				manage_shopcart(); // back to menu of ACTIONS TO SHOPPING CART
			}
			else if(action3==3) //modify item
			{
				modify_item();
				manage_shopcart(); // back to menu of ACTIONS TO SHOPPING CART
			}
			else if(action3==4) //delete item
			{
				delete_item();
				manage_shopcart(); // back to menu of ACTIONS TO SHOPPING CART
			}
			else if(action3==5) //checkout
			{
				check_out();
				manage_shopcart(); // back to menu of ACTIONS TO SHOPPING CART
			}
			else if(action3==6) //back to mainmenu
			{
				mainmenu();
			}
		}
		
		////////////////////////////////////////////////MANAGE PAST RECORD/////////////////////////////////////////////////
		
		void manage_pastrecord()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"         ACTIONS TO PAST SHOPPING RECORD        "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] View Past Shopping Records"<<endl;
			cout<<"[2] Delete Past Shopping Records"<<endl;
			cout<<"or"<<endl;
			cout<<"[3] Back to menu"<<endl<<endl;
			
			action_pastrecord();
		}
		
		void action_pastrecord()
		{
			cout<<"Enter your choice : ";
			cin>>action4;
			cout<<endl;
			
			while(action4!=1 && action4!=2 && action4!=3)
			{
				cout<<">>YOU HAVE ENTERED AN INVALID ACTION<<"<<endl<<endl;
				
				manage_pastrecord();
				
				cout<<"Enter your choice : ";
				cin>>action4;
				cout<<endl;
			}
			
			pastrecord();
		}
		
		void pastrecord()
		{
			if(action4==1) //view record
			{
				view_record();
				manage_pastrecord(); //back to menu of ACTIONS TO PAST SHOPPING RECORD
			}
			else if(action4==2) //delete record
			{
				delete_record();
				manage_pastrecord(); //back to menu of ACTIONS TO PAST SHOPPING RECORD
			}
			else if(action4==3) //back to mainmenu
			{
				mainmenu(); 
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		///////////////////////VIEW ITEM//////////////////////////////////////////////////////////////////////////////
		
		void view_item() // 1
		{
			int num, check;
			
			do
			{
				cout<<"[1] Book" <<endl;
				cout<<"[2] Magazine" <<endl;
				cout<<"[3] Movie" <<endl <<endl;
				
				cout<<"Which item do you wishes to view ?" <<endl <<"=> ";
				cin>>num;
			
				if(num==1)	//book
				{	
					cout<<endl <<"-------VIEW ITEM BOOK-------"<<endl <<endl;
					view_book();
					check=1;
				}
				else if(num==2)	//magazine
				{
					cout<<endl <<"-------VIEW ITEM MAGAZINE-------" <<endl <<endl;
					view_magazine();
					check=2;
				}
				else if(num==3)	//movie
				{
					cout<<endl <<"-------VIEW ITEM MOVIE-------" <<endl <<endl;
					view_movie();
					check=3;
				}
				else
				{
					check=4;
					cout<<"***INVALID INPUT***"<<endl<<endl;
				}
			}
			while(check==4);
		}
		
		void view_book()
		{
			//read num of lines in file
			ifstream b_readline;
			b_readline.open("Book.txt");
			
			if(!b_readline.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int count=0;
			string line;
			
			while (getline(b_readline, line))
			{
				count++;
			}
			b_readline.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count!=0) //to check is there any data in file
			{
				do
				{
					ifstream b_view;
					b_view.open("Book.txt");
					if(!b_view.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
					string data;
					string data_array[end];
					int counter=0;
					
					//get data from file
					for(int i=0; i<end; i++)
					{
						getline(b_view, data);
						data_array[counter]=data;
						counter++;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<data_array[j]<<endl;
					}
					//output data
					//to output maximum 10 item on screen
					//if user wish to continue view then output continue's 10 item
					if(end<count)
					{
						for(int j=start; j<end; j++)
						{
							cout<<data_array[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count)
					{
						for(int j=start; j<count; j++)
						{
							cout<<data_array[j]<<endl;
						}

						cout<<"--NO MORE ITEMS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					b_view.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO ITEMS FOUND--"<<endl<<endl;
			}
		}
		
		void view_magazine()
		{
			//read num of lines in file
			ifstream mag_readline;
			mag_readline.open("Magazine.txt");
			
			if(!mag_readline.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int count=0;
			string line;
			
			while (getline(mag_readline, line))
			{
				count++;
			}
			mag_readline.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count!=0) //to check is there any data in file
			{
				do
				{
					ifstream mag_view;
					mag_view.open("Magazine.txt");
					if(!mag_view.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
					string data;
					string data_array[end];
					int counter=0;
					
					//get data from file
					for(int i=0; i<end; i++)
					{
						getline(mag_view, data);
						data_array[counter]=data;
						counter++;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<data_array[j]<<endl;
					}
					//output data
					//to output maximum 10 item on screen
					//if user wish to continue view then output continue's 10 item
					if(end<count)
					{
						for(int j=start; j<end; j++)
						{
							cout<<data_array[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count)
					{
						for(int j=start; j<count; j++)
						{
							cout<<data_array[j]<<endl;
						}

						cout<<"--NO MORE ITEMS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					mag_view.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO ITEMS FOUND--"<<endl<<endl;
			}
		}
		
		void view_movie()
		{
			//read num of lines in file
			ifstream mov_readline;
			mov_readline.open("Movie.txt");
			
			if(!mov_readline.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int count=0;
			string line;
			
			while (getline(mov_readline, line))
			{
				count++;
			}
			mov_readline.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count!=0) //to check is there any data in file
			{
				do
				{
					ifstream mov_view;
					mov_view.open("Movie.txt");
					if(!mov_view.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
					string data;
					string data_array[end];
					int counter=0;
					
					//get data from file
					for(int i=0; i<end; i++)
					{
						getline(mov_view, data);
						data_array[counter]=data;
						counter++;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<data_array[j]<<endl;
					}
					//output data
					//to output maximum 10 item on screen
					//if user wish to continue view then output continue's 10 item
					if(end<count)
					{
						for(int j=start; j<end; j++)
						{
							cout<<data_array[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count)
					{
						for(int j=start; j<count; j++)
						{
							cout<<data_array[j]<<endl;
						}

						cout<<"--NO MORE ITEMS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					mov_view.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO ITEMS FOUND--"<<endl<<endl;
			}
		}
		
		///////////////////////ADD ITEM////////////////////////////////////////////////////////////////////////////////
		
		void add_item()
		{
			//create and write to file
			fstream cart_head;	
			cart_head.open("Shopping Cart.txt");
			
			if(!cart_head.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			cart_head<<left<<setw(13) <<"ORDER ID" <<setw(13) <<"USER ID" <<setw(13) <<"ITEM TYPE" <<setw(13) <<"ITEM ID" <<setw(25) <<"PRODUCT NAME" <<setw(25) <<"COMPANY" <<setw(10) <<"UNIT" <<setw(10) <<"TOTAL COST (RM)" <<endl;
			cart_head.close();
			
			int num, check, checkunit;
			char yn;
			
			string blank, blank2, blank3, blank4;
			int unit, unit2, size;
			float price;
			char bookname[23], maganame[23], moviename[23]; 
			char company[25];
			string author, time, actor;
			
			//check ID (User Profile)
			int id;
			string un, pw, name, address, type, major, state; 
			
			int orderid, userid, idbook, idmaga, idmovie, qty;
			string itemtype;
			float total;
			
			do
			{
				//open file again and store added item into file without delete previous record
				fstream cart;	
				cart.open("Shopping Cart.txt" , ios::app);
				
				if(!cart.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
				orderid=s->get_randid();
				
				bool found = false;
			
				do
				{		
					ifstream a;
	            	a.open("User Profile.txt", ios::in);
					
					if(!a.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
		            //check id
		            cout<<"Enter Your ID : ";
					cin>>userid;
					cout<<endl;
				    
				    string line;
				    
					while(getline(a,line))	
				    {
						istringstream data(line);
						data >> id;	
						data >> un;
						data >> pw;
						data >> name;
						data >> address;
						data >> type;
						data >> major;
						data >> state;
		    			
			            if(id==userid && userid!=0)
			            {
			            	found=true;
			            	continue;       	
			            }
				    }
				    
				    if(!found)
				    {
				    	cout<<"***INVALID ID***" <<endl <<endl;
					}
					a.close();
				}
				while(!found); 
				
				do
				{
					cout<<"------------------------------------------------"<<endl;
					cout<<"                 TYPES OF ITEMS                 "<<endl;
					cout<<"------------------------------------------------"<<endl;
					
			   		cout<<"[1] Book" <<endl; 		
					cout<<"[2] Magazine" <<endl; 	
					cout<<"[3] Movie" <<endl <<endl; 		
					
					cout<<"Which item do you wishes to add to your shopping cart ?" <<endl <<"=> ";
					cin>>num;
					
					if(num==1)
					{
						itemtype="Book";
						check=1;
					}
					else if(num==2)
					{
						itemtype="Magazine";
						check=2;
					}
					else if(num==3)
					{
						itemtype="Movie"; 
						check=3; 
					}
					else
					{
						cout<<"***WRONG INPUT***" <<endl <<endl; 
						check=4;
					}
				}
				while(check==4);
					
				if(check==1) //book
				{
					bool found = false;
		
					do
					{
						cout<<endl <<"--BOOK DETAILS--" <<endl<<endl;
						view_book();
						
						//read file
						ifstream book;
						book.open("Book.txt");
						
						if(!book.is_open())
						{
							cout<<"Could Not Open File" <<endl;
							exit(0);
						}
			        		
						cout<<"Enter the "<<itemtype <<" ID	: ";
						cin>>idbook;
				    	
				    	string line;
			       	   	//read line by line
						while(getline(book,line))	
					    {
							istringstream data(line);
							data >> id;	
							for(int i=0; i<3; i++)
							{
								getline(data,blank,' ');
							}
							data.get(bookname,23);
							getline(data,blank2,' ');
							data >> price;
							data >> unit;
							unit2=unit;
							if(unit2>=1000)
							{
								size=4;
							}
							else if(unit2>=100)
							{
								size=3;
							}
							else if(unit>=10)
							{
								size=2;
							}
							else if(unit>=0)
							{
								size=1;
							}
							for(int i=0; i<(10-size); i++)
							{
								getline(data,blank3,' ');
							}
							data.get(company,25);
							getline(data,blank4,' ');
							getline(data,author);;
							
				            if(id==idbook && idbook!=0)
				            {
				            	found=true;
				            	
					            do
				            	{
					            	cout<<"Enter the quantity	: ";
									cin>>qty;
									
									if(cin.fail())
									{
										cin.clear();
										cin.ignore();
										cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
										checkunit=1;
									}
									else if(qty<=0)
									{
										cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
										checkunit=2;
									}
									else if(qty>unit)
									{
										cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
										checkunit=3;
									}
									else
									{
										checkunit=4;
									}
								}
								while(checkunit!=4);
								
								total=price*qty;
								
								cout<<setprecision(2) <<fixed;
								 
								cout<<endl;
								cout<<"-------SUMMARY OF ADDED ITEM-------" <<endl;
								cout<<"Order ID	: " <<orderid <<endl;
								cout<<"Item		: " <<itemtype <<endl;
								cout<<"Item ID		: " <<idbook <<endl;
								cout<<"Item Name	: " <<bookname <<endl;
								cout<<"Company		: " <<company <<endl;
								cout<<"Quantity	: " <<qty <<endl;
								cout<<"Total Cost	: RM " <<total <<endl <<endl; 
								
								cart<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<itemtype <<setw(13) <<idbook <<setw(25) <<bookname <<setw(25) <<company <<setw(10) <<qty <<setw(10) <<total <<endl;     	
				            }
					    }
					    
					    if(!found)
					    {
					    	cout<<"***INVALID ID***" <<endl <<endl;
						}
						
						book.close();
					}
					while(!found);
				}
				else if(check==2) //magazine
				{
					bool found = false;
					
					cin.ignore();
					
					do
					{
						cout<<endl <<"--MAGAZINE DETAILS--" <<endl<<endl;
						view_magazine();
						
						//read file
						ifstream magazine;
						magazine.open("Magazine.txt");
						
						if(!magazine.is_open())
						{
							cout<<"Could Not Open File" <<endl;
							exit(0);
						}
			        		
						cout<<"\nEnter the "<<itemtype <<" ID	: ";
						cin>>idmaga;
				    	
				    	string line;
			       	   	//read line by line
						while(getline(magazine,line))	
					    {
							istringstream data(line);
							data >> id;	
							for(int i=0; i<3; i++)
							{
								getline(data,blank,' ');
							}
							data.get(maganame,23);
							getline(data,blank2,' ');
							data >> price;
							data >> unit;
							unit2=unit;
							if(unit2>=1000)
							{
								size=4;
							}
							else if(unit2>=100)
							{
								size=3;
							}
							else if(unit>=10)
							{
								size=2;
							}
							else if(unit>=0)
							{
								size=1;
							}
							for(int i=0; i<(10-size); i++)
							{
								getline(data,blank3,' ');
							}
							data.get(company,25);
							getline(data,blank4,' ');
							getline(data,time);
							
				            if(id==idmaga && idmaga!=0)
				            {
				            	found=true;
				            	
				            	do
				            	{
					            	cout<<"Enter the quantity	: ";
									cin>>qty;
									
									if(cin.fail())
									{
										cin.clear();
										cin.ignore();
										cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
										checkunit=1;
									}
									else if(qty<=0)
									{
										cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
										checkunit=2;
									}
									else if(qty>unit)
									{
										cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
										checkunit=3;
									}
									else
									{
										checkunit=4;
									}
								}
								while(checkunit!=4);
								
								total=price*qty;
								
								cout<<setprecision(2) <<fixed;
								
								cout<<endl;
								cout<<"-------SUMMARY OF ADDED ITEM-------" <<endl;
								cout<<"Order ID	: " <<orderid <<endl;
								cout<<"Item		: " <<itemtype <<endl;
								cout<<"Item ID		: " <<idmaga <<endl;
								cout<<"Item Name	: " <<maganame <<endl;
								cout<<"Company		: " <<company <<endl;
								cout<<"Quantity	: " <<qty <<endl;
								cout<<"Total Cost	: RM " <<total <<endl <<endl;       
								
								cart<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<itemtype <<setw(13) <<idmaga <<setw(25) <<maganame <<setw(25) <<company <<setw(10) <<qty <<setw(10) <<total <<endl;   	
				            }
					    }
					    
					    if(!found)
					    {
					    	cout<<"***INVALID ID***" <<endl <<endl;
						}
						
						magazine.close();
					}
					while(!found);	
				}
				else if(check==3) //movie
				{
					bool found = false;
					
					cin.ignore();
					
					do
					{
						cout<<endl <<"--MOVIE DETAILS--" <<endl<<endl;
						view_movie();
						
						//read file
						ifstream movie;
						movie.open("Movie.txt");
						
						if(!movie.is_open())
						{
							cout<<"Could Not Open File" <<endl;
							exit(0);
						}
			        	
						cout<<"\nEnter the "<<itemtype <<" ID	: ";
						cin>>idmovie;
				    	
				    	string line;
			       	   	//read line by line
						while(getline(movie,line))	
					    {
							istringstream data(line);
							data >> id;	
							for(int i=0; i<3; i++)
							{
								getline(data,blank,' ');
							}
							data.get(moviename,23);
							getline(data,blank2,' ');
							data >> price;
							data >> unit;
							unit2=unit;
							if(unit2>=1000)
							{
								size=4;
							}
							else if(unit2>=100)
							{
								size=3;
							}
							else if(unit>=10)
							{
								size=2;
							}
							else if(unit>=0)
							{
								size=1;
							}
							for(int i=0; i<(10-size); i++)
							{
								getline(data,blank3,' ');
							}
							data.get(company,25);
							getline(data,blank4,' ');
							getline(data,actor);
							
				            if(id==idmovie && idmovie!=0)
				            {
				            	found=true;
				            	
				            	do
				            	{
					            	cout<<"Enter the quantity	: ";
									cin>>qty;
									
									if(cin.fail())
									{
										cin.clear();
										cin.ignore();
										cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
										checkunit=1;
									}
									else if(qty<=0)
									{
										cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
										checkunit=2;
									}
									else if(qty>unit)
									{
										cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
										checkunit=3;
									}
									else
									{
										checkunit=4;
									}
								}
								while(checkunit!=4);
								
								total=price*qty;
								
								cout<<setprecision(2) <<fixed;
								
								cout<<endl;
								cout<<"-------SUMMARY OF ADDED ITEM-------" <<endl <<endl;
								cout<<"Order ID	: " <<orderid <<endl;
								cout<<"Item		: " <<itemtype <<endl;
								cout<<"Item ID		: " <<idmovie <<endl;
								cout<<"Item Name	: " <<moviename <<endl;
								cout<<"Company		: " <<company <<endl;
								cout<<"Quantity	: " <<qty <<endl;
								cout<<"Total Cost	: RM " <<total <<endl <<endl;  
								
								cart<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<itemtype <<setw(13) <<idmovie <<setw(25) <<moviename <<setw(25) <<company <<setw(10) <<qty <<setw(10) <<total <<endl;    
				            }
					    }
					    
					    if(!found)
					    {
					    	cout<<"***INVALID ID***" <<endl <<endl;
						}
						
						movie.close();
					}
					while(!found);
				}
				
				cart.close();
				
				cout<<"Do you want to continue add item [y-yes or n-no] : ";
				cin>>yn;
								
				cout<<endl<<endl;
			}
			while(yn=='y' || yn=='Y');
		}
		
		///////////////////////MODIFY ITEM////////////////////////////////////////////////////////////////////////////
		
		void modify_item() // 4
		{
			cout<<"-------MODIFY ITEM-------" <<endl<<endl;
			
			view_shopcart();
			
			//old item
			int idupt, orderid, userid, itemid, qty;
			string itemtype;
			char itemname[25], company[25];
			float total;
			
			//check
			int num, check, checkunit;
			string data;
			
			//book, magazine, movie detail
			string blank, blank2, blank3, blank4;
			int unit, unit2, size, id;
			float price;
			char bookname[23], maganame[23], moviename[23]; 
			string author, time, actor;
			
			//update new item
			int newitemid, newqty, newidbook, newidmaga, newidmovie;
			string newitemtype;
			float newtotal;
			
			bool found = false;
			
			do
			{		
				ifstream a;
            	a.open("Shopping Cart.txt", ios::in);
				
				if(!a.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
	            //check id
	            cout<<"Enter Your Order ID : ";
				cin>>idupt;
				cout<<endl;
			    	
				string line;
				while(getline(a,line))	
			    {
			    	istringstream data(line);
					data >> orderid;	
					data >> userid;
					data >> itemtype;
					data >> itemid;
					for(int i=0; i<8; i++) //13-8
					{
						getline(data,blank,' ');
					}
					data.get(itemname,25);
					getline(data,blank2,' ');
					data.get(company, 25);
					getline(data, blank4, ' ');
					data >> qty;
					data >> total;
	
					if(orderid==idupt && idupt!=0)
		            {
		            	found=true;
		            	continue;       	
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ID***" <<endl <<endl;
				}
				a.close();
			}
			while(!found);
			
			
			ifstream upt_cart;
            upt_cart.open("Shopping Cart.txt");
            
            if(!upt_cart.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			ofstream temp;
            temp.open("temp.txt");
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			while(upt_cart.good())	
		    {
		    	getline(upt_cart,data);
		    	if(upt_cart)
		    	{
					istringstream(data)>>num;
					
		            if(num!=idupt)
		            {
		            	temp<<data<<endl; 	
		            }
		            else
		            {    	
						//Modify Item//
		            	do
						{
							//change new item type
							cout<<"------------------------------------------------"<<endl;
							cout<<"                 TYPES OF ITEMS                 "<<endl;
							cout<<"------------------------------------------------"<<endl;
							
					   		cout<<"[1] Book" <<endl; 		
							cout<<"[2] Magazine" <<endl; 	
							cout<<"[3] Movie" <<endl <<endl; 		
							
							cout<<"Which item do you wishes to add to your shopping cart ?" <<endl <<"=> ";
							cin>>num;
							
							if(num==1)
							{
								newitemtype="Book";
								check=1;
							}
							else if(num==2)
							{
								newitemtype="Magazine";
								check=2;
							}
							else if(num==3)
							{
								newitemtype="Movie"; 
								check=3; 
							}
							else
							{
								cout<<"***WRONG INPUT***" <<endl <<endl; 
								check=4;
							}
						}
						while(check==4);
							
						if(check==1) //book
						{
							bool found = false;
				
							do
							{
								cout<<endl <<"--BOOK DETAILS--" <<endl<<endl;
								view_book();
								
								//read file
								ifstream book;
								book.open("Book.txt");
								
								if(!book.is_open())
								{
									cout<<"Could Not Open File" <<endl;
									exit(0);
								}
					        		
								cout<<"Enter the "<<newitemtype <<" ID	: ";
								cin>>newidbook;
						    	
						    	string line;
					       	   	//read line by line
								while(getline(book,line))	
							    {
									istringstream data(line);
									data >> id;	
									for(int i=0; i<3; i++)
									{
										getline(data,blank,' ');
									}
									data.get(bookname,23);
									getline(data,blank2,' ');
									data >> price;
									data >> unit;
									unit2=unit;
									if(unit2>=1000)
									{
										size=4;
									}
									else if(unit2>=100)
									{
										size=3;
									}
									else if(unit2>=10)
									{
										size=2;
									}
									else if(unit2>=0)
									{
										size=1;
									}
									for(int i=0; i<(10-size); i++)
									{
										getline(data,blank3,' ');
									}
									data.get(company,25);
									getline(data,blank4,' ');
									getline(data,author);;
									
						            if(id==newidbook && newidbook!=0)
						            {
						            	found=true;
						            	
							            do
						            	{
							            	cout<<"Enter the quantity	: ";
											cin>>newqty;
											
											if(cin.fail())
											{
												cin.clear();
												cin.ignore();
												cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
												checkunit=1;
											}
											else if(newqty<=0)
											{
												cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
												checkunit=2;
											}
											else if(newqty>unit)
											{
												cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
												checkunit=3;
											}
											else
											{
												checkunit=4;
											}
										}
										while(checkunit!=4);
										
										newtotal=price*newqty;
										
										cout<<setprecision(2) <<fixed;
										 
										cout<<endl;
										cout<<"-------SUMMARY OF UPDATED ADDED ITEM-------" <<endl;
										cout<<"Order ID	: " <<orderid <<endl;
										cout<<"Item		: " <<newitemtype <<endl;
										cout<<"Item ID		: " <<newidbook <<endl;
										cout<<"Item Name	: " <<bookname <<endl;
										cout<<"Company		: " <<company <<endl;
										cout<<"Quantity	: " <<newqty <<endl;
										cout<<"Total Cost	: RM " <<newtotal <<endl <<endl; 
										
										temp<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<newitemtype <<setw(13) <<newidbook <<setw(25) <<bookname <<setw(25) <<company <<setw(10) <<newqty <<setw(10) <<newtotal <<endl;     	
						            }
							    }
							    
							    if(!found)
							    {
							    	cout<<"***INVALID ID***" <<endl <<endl;
								}
								
								book.close();
							}
							while(!found);
						}
						else if(check==2) //magazine
						{
							bool found = false;
							
							cin.ignore();
							
							do
							{
								cout<<endl <<"--MAGAZINE DETAILS--" <<endl<<endl;
								view_magazine();
								
								//read file
								ifstream magazine;
								magazine.open("Magazine.txt");
								
								if(!magazine.is_open())
								{
									cout<<"Could Not Open File" <<endl;
									exit(0);
								}
					        		
								cout<<"\nEnter the "<<newitemtype <<" ID	: ";
								cin>>newidmaga;
						    	
								string line;
					       	   	//read line by line
								while(getline(magazine,line))	
							    {
									istringstream data(line);
									data >> id;	
									for(int i=0; i<3; i++)
									{
										getline(data,blank,' ');
									}
									data.get(maganame,23);
									getline(data,blank2,' ');
									data >> price;
									data >> unit;
									unit2=unit;
									if(unit2>=1000)
									{
										size=4;
									}
									else if(unit2>=100)
									{
										size=3;
									}
									else if(unit2>=10)
									{
										size=2;
									}
									else if(unit2>=0)
									{
										size=1;
									}
									for(int i=0; i<(10-size); i++)
									{
										getline(data,blank3,' ');
									}
									data.get(company,25);
									getline(data,blank4,' ');
									getline(data,time);
									
						            if(id==newidmaga && newidmaga!=0)
						            {
						            	found=true;
						            	
						            	do
						            	{
							            	cout<<"Enter the quantity	: ";
											cin>>newqty;
											
											if(cin.fail())
											{
												cin.clear();
												cin.ignore();
												cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
												checkunit=1;
											}
											else if(newqty<=0)
											{
												cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
												checkunit=2;
											}
											else if(newqty>unit)
											{
												cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
												checkunit=3;
											}
											else
											{
												checkunit=4;
											}
										}
										while(checkunit!=4);
										
										newtotal=price*newqty;
										
										cout<<setprecision(2) <<fixed;
										
										cout<<endl;
										cout<<"-------SUMMARY OF UPDATED ADDED ITEM-------" <<endl;
										cout<<"Order ID	: " <<orderid <<endl;
										cout<<"Item		: " <<newitemtype <<endl;
										cout<<"Item ID		: " <<newidmaga <<endl;
										cout<<"Item Name	: " <<maganame <<endl;
										cout<<"Company		: " <<company <<endl;
										cout<<"Quantity	: " <<newqty <<endl;
										cout<<"Total Cost	: RM " <<newtotal <<endl <<endl;       
										
										temp<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<newitemtype <<setw(13) <<newidmaga <<setw(25) <<maganame <<setw(25) <<company <<setw(10) <<newqty <<setw(10) <<newtotal <<endl;   	
						            }
							    }
							    
							    if(!found)
							    {
							    	cout<<"***INVALID ID***" <<endl <<endl;
								}
								
								magazine.close();
							}
							while(!found);	
						}
						else if(check==3) //movie
						{
							bool found = false;
							
							cin.ignore();
							
							do
							{
								cout<<endl <<"--MOVIE DETAILS--" <<endl<<endl;
								view_movie();
								
								//read file
								ifstream movie;
								movie.open("Movie.txt");
								
								if(!movie.is_open())
								{
									cout<<"Could Not Open File" <<endl;
									exit(0);
								}
					        	
								cout<<"\nEnter the "<<newitemtype <<" ID	: ";
								cin>>newidmovie;
						    	
								string line;
					       	   	//read line by line
								while(getline(movie,line))	
							    {
									istringstream data(line);
									data >> id;	
									for(int i=0; i<3; i++)
									{
										getline(data,blank,' ');
									}
									data.get(moviename,23);
									getline(data,blank2,' ');
									data >> price;
									data >> unit;
									unit2=unit;
									if(unit2>=1000)
									{
										size=4;
									}
									else if(unit2>=100)
									{
										size=3;
									}
									else if(unit2>=10)
									{
										size=2;
									}
									else if(unit2>=0)
									{
										size=1;
									}
									for(int i=0; i<(10-size); i++)
									{
										getline(data,blank3,' ');
									}
									data.get(company,25);
									getline(data,blank4,' ');
									getline(data,actor);
									
						            if(id==newidmovie && newidmovie!=0)
						            {
						            	found=true;
						            	
						            	do
						            	{
							            	cout<<"Enter the quantity	: ";
											cin>>newqty;
											
											if(cin.fail())
											{
												cin.clear();
												cin.ignore();
												cout<<"***QUANTITY CANNOT BE A CHARACTER***" <<endl<<endl;
												checkunit=1;
											}
											else if(newqty<=0)
											{
												cout<<"***QUANTITY CANNOT BE A ZERO OR NEGATIVE NUMBER***" <<endl<<endl;
												checkunit=2;
											}
											else if(newqty>unit)
											{
												cout<<"***ONLY " <<unit <<" LEFT. PLASE ENTER AGAIN***" <<endl<<endl;
												checkunit=3;
											}
											else
											{
												checkunit=4;
											}
										}
										while(checkunit!=4);
										
										newtotal=price*newqty;
										
										cout<<setprecision(2) <<fixed;
										
										cout<<endl;
										cout<<"-------SUMMARY OF UPDATED ADDED ITEM-------" <<endl <<endl;
										cout<<"Order ID	: " <<orderid <<endl;
										cout<<"Item		: " <<newitemtype <<endl;
										cout<<"Item ID		: " <<newidmovie <<endl;
										cout<<"Item Name	: " <<moviename <<endl;
										cout<<"Company		: " <<company <<endl;
										cout<<"Quantity	: " <<newqty <<endl;
										cout<<"Total Cost	: RM " <<newtotal <<endl <<endl;  
										
										temp<<left<<setw(13) <<orderid <<setw(13) <<userid <<setw(13) <<newitemtype <<setw(13) <<newidmovie <<setw(25) <<moviename <<setw(25) <<company <<setw(10) <<newqty <<setw(10) <<newtotal <<endl;    
						            }
							    }
							    
							    if(!found)
							    {
							    	cout<<"***INVALID ID***" <<endl <<endl;
								}
								
								movie.close();
							}
							while(!found);
						}
		            }
		        }
		    }
		    
            temp.close();
            upt_cart.close();
			remove("Shopping Cart.txt");
			rename("temp.txt","Shopping Cart.txt");
			
			cout<<endl <<"--DONE UPDATE--" <<endl <<endl;
		}
		
		///////////////////////DELETE ITEM////////////////////////////////////////////////////////////////////////////
		
		void delete_item() // 3
		{
			cout<<"-------DELETE ITEM-------" <<endl<<endl;
			
			view_shopcart();
	
			int iddlt, orderid, userid, itemid, qty;
			string itemtype, data;
			char itemname[25], company[25];
			float total;
			string blank, blank2, blank3, blank4;
			
			bool found = false;
			
			do
			{		
				ifstream a;
            	a.open("Shopping Cart.txt", ios::in);
            	
            	if(!a.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
	            //check order id
	            cout<<"Enter Your Order ID To Delete: ";
				cin>>iddlt;
			    cout<<endl;
			    
				string line;
				while(getline(a,line))	
			    {
					istringstream data(line);
					data >> orderid;	
					data >> userid;
					data >> itemtype;
					data >> itemid;
					for(int i=0; i<8; i++) //13-8
					{
						getline(data,blank,' ');
					}
					data.get(itemname,25);
					getline(data,blank2,' ');
					data.get(company, 25);
					getline(data, blank4, ' ');
					data >> qty;
					data >> total;
	    			
		            if(orderid==iddlt && iddlt!=0)
		            {
		            	found=true;
		            	continue;       	
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ID***" <<endl <<endl;
				}
				a.close();
			}
			while(!found);
			
			fstream dlt_cart;
            dlt_cart.open("Shopping Cart.txt");
            
            if(!dlt_cart.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
            
			fstream temp;
            temp.open("temp.txt", ios::out | ios::trunc);
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int num;
            while(dlt_cart.good())	
		    {
		    	getline(dlt_cart,data);
		    	if(dlt_cart)
		    	{
					istringstream(data)>>num;
		            if(num!=iddlt)
		            {
		            	temp<<data<<endl; 	
		            }
		        }
		    }
		    
		    dlt_cart.close();
		    temp.close();
		    remove("Shopping Cart.txt"); //remove old file
			rename("temp.txt","Shopping Cart.txt"); //rename new file
			
			cout<<endl <<"--DONE DELETE--" <<endl <<endl <<endl;
		}
		
		////////////////////////CHECK OUT///////////////////////////////////////////////////////////////////////////////
		
		bool check_pin(string pin) //check whether shopper insert character or digit
		{
		   for (int i = 0; i < pin.length(); i++)
		   {
			   	if (isdigit(pin[i]) != false)
			      return false;
				else
			      return true;
			}
		}

		void check_out() // 7
		{	
			cout<<endl <<"-------CHECK OUT ITEM------- " <<endl <<endl;
			
			//shop_cart detail
			int p_id, o_id, orderid, userid, itemid, qty;
			string itemtype;
			char itemname[25], company[25];
			float total;
			string blank, blank2, blank3, blank4;
			int checkitemid;
			
			//check
			string pin, data;
			int checkpin, num;
			
			//update unit in book/magazine/movie
			int idbook,idmaga, idmovie;
			int unitbook, unitmaga, unitmovie, unit2, size, checkid;
			float price;
			char bookname[23], maganame[23], moviename[23]; 
			string author, time, actor;
			int newunitbook, newunitmaga, newunitmovie;
					
			
			fstream precord_head;
			precord_head.open("Purchase Record.txt");
			
			if(!precord_head.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			fstream srecord_head;
			srecord_head.open("Sales Record.txt");
			
			if(!srecord_head.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			precord_head<<left <<setw(17) <<"PURCHASED ID" <<setw(13) <<"USER ID" <<setw(13) <<"ITEM TYPE" <<setw(13) <<"ITEM ID" <<setw(25) <<"PRODUCT NAME" <<setw(25) <<"COMPANY" <<setw(10) <<"UNIT" <<setw(10) <<"TOTAL COST (RM)" <<endl;
			precord_head.close();
			
			srecord_head<<left <<setw(17) <<"PURCHASED ID" <<setw(13) <<"USER ID" <<setw(13) <<"ITEM TYPE" <<setw(13) <<"ITEM ID" <<setw(25) <<"PRODUCT NAME" <<setw(25) <<"COMPANY" <<setw(10) <<"UNIT" <<setw(10) <<"TOTAL COST (RM)" <<endl;
			srecord_head.close();
			
			fstream purchase;
			purchase.open("Purchase Record.txt", ios::app);
			
			if(!purchase.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			fstream sales;
			sales.open("Sales Record.txt", ios::app);
			
			if(!sales.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			bool found = false;
			cin.ignore();
			
			p_id=s->get_randid();
			
			do
			{
				cout<<"-------ORDER ITEM------- " <<endl <<endl;
				view_shopcart();
				
				//read file
				ifstream shop;
				shop.open("Shopping Cart.txt" , ios::in);
			
				if(!shop.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
				cout<<"Enter Your Order ID To Check Out : ";
				cin>>o_id;
				
				string line;
	       	   	//read line by line
				while(getline(shop,line))	
			    {
					istringstream data(line);
					data >> orderid;	
					data >> userid;
					data >> itemtype;
					data >> itemid;
					for(int i=0; i<8; i++) //13-8
					{
						getline(data,blank,' ');
					}
					data.get(itemname,25);
					getline(data,blank2,' ');
					data.get(company, 25);
					getline(data, blank4, ' ');
					data >> qty;
					data >> total;
					
		            if(orderid==o_id && orderid!=0)
		            {
		            	found=true;    
		            	
						cout<<"Your Total Payment is RM " <<total<<endl<<endl;   
					
						cin.ignore();
						do
						{
							cout<<"Enter Your Payment Card Number [10 digit number] : ";
							getline(cin,pin);
							
							if(pin.size()==0)
							{
								cout<<"***CARD NUMBER CANNOT BE BLANK***" <<endl <<endl;
								checkpin=1;
							}
							else if(check_pin(pin))
							{
								cout<<"***CARD NUMBER CANNOT BE A CHARACTER***" <<endl <<endl;
								checkpin=2;
							}
							else if(pin.size()!=10)
							{
								cout<<"***CARD NUMBER MUST BE 10 DIGIT***" <<endl <<endl;
								checkpin=3;
							}
							else if(pin.find (' ') != string::npos) 
							{
							    cout<<"***CARD NUMBER CANNOT HAVE A SPACE***" <<endl <<endl; 
							    checkpin=4;
							}
							else
							{
								checkpin=5; //success
							}
						}
						while(checkpin!=5);
						
						cout<<endl<<endl;
						cout<<"~~~~~~~~~~~~ PAYMENT ON PROCESSING ~~~~~~~~~~~~" <<endl <<endl;
						cout<<"~~~~~~~~~~ YOUR PAYMENT IS SUCCESSFUL ~~~~~~~~~~" <<endl <<endl;
						cout<<"~~~~~~~~~~ THANK YOU FOR YOUR PAYMENT ~~~~~~~~~~" <<endl <<endl;
						
						//after payment put that order in purchase record
						purchase<<left <<setw(17) <<p_id <<setw(13) <<userid <<setw(13) <<itemtype <<setw(13) <<itemid <<setw(25) <<itemname <<setw(25) <<company <<setw(10) <<qty <<setw(10) <<total <<endl;
						sales<<left <<setw(17) <<p_id <<setw(13) <<userid <<setw(13) <<itemtype <<setw(13) <<itemid <<setw(25) <<itemname <<setw(25) <<company <<setw(10) <<qty <<setw(10) <<total <<endl;
						///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						
						//decrease unit available in book/magazine/movie
			
						//check book//
						ifstream book;
						book.open("Book.txt");
						
						if(!book.is_open())
						{
							cout<<"Could Not Open File" <<endl;
							exit(0);
						}
						
						ofstream book2;
			            book2.open("Book2.txt");
						
						if(!book2.is_open())
						{
							cout<<"Could Not Open File" <<endl;
							exit(0);
						}
						
						string line;
						while(getline(book,line))	
					    {
							istringstream data(line);
							data >> idbook;
							for(int i=0; i<3; i++)
							{
								getline(data, blank, ' ');
							}
							data.get(bookname, 23);
							getline(data, blank2, ' ');
							data >> price;
							data >> unitbook;
							unit2=unitbook;
							//size=sizeof(unit2);
							if(unit2>=1000)
							{
								size=4;
							}
							else if(unit2>=100)
							{
								size=3;
							}
							else if(unit2>=10)
							{
								size=2;
							}
							else if(unit2>=0)
							{
								size=1;
							}
							for(int i=0; i<(10-size); i++)
							{
								getline(data, blank3, ' ');
							}
							data.get(company, 25);
							getline(data, blank4, ' ');
							getline(data, author);
							
				            if(idbook==itemid)
				            {
				            	found=true;
				            	checkid=1;
				            	
				            	newunitbook=unitbook-qty;
				            	//update unit available of book
				            	book2<<left<<setw(8)<<idbook<<setw(25)<<bookname<<setw(14)<<price<<setw(10)<<newunitbook<<setw(25)<<company<<setw(25)<<author<<endl;
						    }
						    else
						    {
						    	book2<<line<<endl;
							}
				        }
				        book.close();
				        
				        book2.close();
			            book.close();		
						remove("Book.txt"); //remove old file
						rename("Book2.txt","Book.txt"); //rename new file
						
						//check magazine//
				        if(checkid!=1) //check itemid in magazine if itemid not found in book
				        {
					        ifstream maga;
							maga.open("Magazine.txt");
							
							if(!maga.is_open())
							{
								cout<<"Could Not Open File" <<endl;
								exit(0);
							}
							
							ofstream maga2;
				            maga2.open("Magazine2.txt");
							
							if(!maga2.is_open())
							{
								cout<<"Could Not Open File" <<endl;
								exit(0);
							}
							
							string line;
							while(getline(maga,line))	
						    {
								istringstream data(line);
								data >> idmaga;	
								for(int i=0; i<3; i++)
								{
									getline(data,blank,' ');
								}
								data.get(maganame,23);
								getline(data,blank2,' ');
								data >> price;
								data >> unitmaga;
								unit2=unitmaga;
								if(unit2>=1000)
								{
									size=4;
								}
								else if(unit2>=100)
								{
									size=3;
								}
								else if(unit2>=10)
								{
									size=2;
								}
								else if(unit2>=0)
								{
									size=1;
								}
								for(int i=0; i<(10-size); i++)
								{
									getline(data,blank3,' ');
								}
								data.get(company,25);
								getline(data,blank4,' ');
								getline(data,time);
								
					            if(idmaga==itemid)
					            {
					            	found=true;
					            	checkid=2;
					            	
					        		newunitmaga=unitmaga-qty;
					        		//update unit available of magazine
					        		maga2<<left<<setw(8)<<idmaga<<setw(25)<<maganame<<setw(14)<<price<<setw(10)<<newunitmaga<<setw(25)<<company<<setw(25)<<time<<endl;
					            }
					            else
							    {
							    	maga2<<line<<endl;
								}
					        }
					        maga2.close();
				            maga.close();		
							remove("Magazine.txt"); //remove old file
							rename("Magazine2.txt","Magazine.txt"); //rename new file
						}
						
						//check movie//
						if(checkid!=1 && checkid!=2 ) //check itemid in movie if itemid not found in book and magazine
						{
							ifstream movie;
							movie.open("Movie.txt");
							
							if(!movie.is_open())
							{
								cout<<"Could Not Open File" <<endl;
								exit(0);
							}
							
							ofstream movie2;
				            movie2.open("Movie2.txt");
							
							if(!movie2.is_open())
							{
								cout<<"Could Not Open File" <<endl;
								exit(0);
							}
							
							string line;
							while(getline(movie,line))	
						    {
								istringstream data(line);
								data >> idmovie;	
								for(int i=0; i<3; i++)
								{
									getline(data,blank,' ');
								}
								data.get(moviename,23);
								getline(data,blank2,' ');
								data >> price;
								data >> unitmovie;
								unit2=unitmovie;
								if(unit2>=1000)
								{
									size=4;
								}
								else if(unit2>=100)
								{
									size=3;
								}
								else if(unit2>=10)
								{
									size=2;
								}
								else if(unit2>=0)
								{
									size=1;
								}
								for(int i=0; i<(10-size); i++)
								{
									getline(data,blank3,' ');
								}
								data.get(company,25);
								getline(data,blank4,' ');
								getline(data,actor);
								
					            if(idmovie==itemid)
					            {
					            	found=true;
					            	checkid=3;
					            	
					            	newunitmovie=unitmovie-qty;
					            	//update unit available of movie
									movie2<<left<<setw(8)<<idmovie<<setw(25)<<moviename<<setw(14)<<price<<setw(10)<<newunitmovie<<setw(25)<<company<<setw(25)<<actor<<endl;		            	
					            }
					            else
							    {
							    	movie2<<line<<endl;
								}
							}
							movie2.close();
				            movie.close();		
							remove("Movie.txt"); //remove old file
							rename("Movie2.txt","Movie.txt"); //rename new file
						}
					
						continue;
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ORDER ID***" <<endl <<endl;
				}
				
				shop.close();
			}
			while(!found);
			
			purchase.close();
			sales.close();
			
			//after checkout the order and put into purchased record file, 
			//delete the order from cart.
			//(switch that order from shopping cart into purchae record)
			
			ifstream dlt_order;
			dlt_order.open("Shopping Cart.txt");
			
			if(!dlt_order.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			dlt_order.clear();
			
			ofstream temp;
			temp.open("temp.txt", ios::out | ios::trunc);
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			while(dlt_order.good())
			{
				getline(dlt_order, data);
				if(dlt_order)
				{
					istringstream(data)>>num;
					if(num!=o_id)
					{
						temp<<data<<endl;
					}
				}
			}
			
			dlt_order.close();
			temp.close();
			remove("Shopping Cart.txt"); //remove old file
			rename("temp.txt", "Shopping Cart.txt"); //rename new file
		}
	
		void view_shopcart()
		{
			ifstream cart;
			cart.open("Shopping Cart.txt" , ios::in);
			
			if(!cart.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int count=0;
			string line;
			
			while (getline(cart, line))
			{
				count++;
			}
			cart.close();
			
			//view
			int start=3;
			int end=13;
			int add=1;
			char cont;
			
			if(count!=0) //check is there any data in file
			{
				do
				{
					ifstream shop;
					shop.open("Shopping Cart.txt" , ios::in);
					
					if(!shop.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
					string data;
					string data_array[end];
					int counter = 0;
			        
			        //get data from file
					for(int x=0; x<end; x++)
					{
						getline(shop,data);
						data_array[counter] = data;
						
						counter++;
					}
					
					//output heading
					for(int j=0; j<3; j++)
					{
						cout<<data_array[j]<<endl;
					}
					
					//output data
					if(end<=count)
					{
						for(int j=start; j<end; j++)
						{
							cout<<data_array[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>count)
					{
						for(int j=start; j<count; j++)
						{
							cout<<data_array[j]<<endl;
						}

						cout<<"--NO MORE ORDERS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+3;
					start=end-10;
					
					shop.close();
				}
				while(cont=='Y' || cont=='y');
			}
		}
		
		///////////////////////VIEW RECORD///////////////////////////////////////////////////////
		
		void view_record()
		{
			ifstream record;
			record.open("Purchase Record.txt" , ios::in);
			
			if(!record.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			int count=0;
			string line;
			
			while (getline(record, line))
			{
				count++;
			}
			record.close();
			
			//view
			int start=3;
			int end=13;
			int add=1;
			char cont;
			
			if(count!=0) //check is there any data in file
			{
				do
				{
					ifstream record2;
					record2.open("Purchase Record.txt" , ios::in);
					
					if(!record2.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					
					string data;
					string data_array[end];
					int counter = 0;
			        
			        //get data from file
					for(int x=0; x<end; x++)
					{
						getline(record2,data);
						data_array[counter] = data;
						
						counter++;
					}
					
					//output heading
					for(int j=0; j<3; j++)
					{
						cout<<data_array[j]<<endl;
					}
					
					//output data
					if(end<=count)
					{
						for(int j=start; j<end; j++)
						{
							cout<<data_array[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>count)
					{
						for(int j=start; j<count; j++)
						{
							cout<<data_array[j]<<endl;
						}

						cout<<"--NO MORE RECORDS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+3;
					start=end-10;
					
					record2.close();
				}
				while(cont=='Y' || cont=='y');
			}
		}
		
		///////////////////////DELETE RECORD///////////////////////////////////////////////////////
		
		void delete_record()
		{
			cout<<"-------DELETE RECORD-------" <<endl<<endl;
			
			view_record();
			
			//purchased record
			int iddlt, p_id, userid, itemid, qty;
			string itemname, itemtype, company;
			float total;
			
			int num;
			string data;
			
			bool found = false;
			
			do
			{		
				ifstream record;
            	record.open("Purchase Record.txt", ios::in);
				
				if(!record.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				
	            //check id
	            cout<<"Enter Purchased ID To Delete : ";
				cin>>iddlt;
			    cout<<endl;
			    
				string line;
				while(getline(record,line))	
			    {
					istringstream data(line);
					data >> p_id;	
					data >> userid;
					data >> itemtype;
					data >> itemid;
					data >> itemname;
					data >> company;
					data >> qty;
					data >> total;
	    			
		            if(p_id==iddlt && iddlt!=0)
		            {
		            	found=true;
		            	continue;       	
		            }
			    }
			    
			    if(!found)
			    {
			    	cout<<"***INVALID ID***" <<endl <<endl;
				}
				record.close();
			}
			while(!found);
			
			fstream dlt_record;
            dlt_record.open("Purchase Record.txt");
            
            if(!dlt_record.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
            
			fstream temp;
            temp.open("temp.txt", ios::out | ios::trunc);
			
			if(!temp.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
            while(dlt_record.good())	
		    {
		    	getline(dlt_record,data);
		    	if(dlt_record)
		    	{
					istringstream(data)>>num;
		            if(num!=iddlt)
		            {
		            	temp<<data<<endl; 	
		            }
		        }
		    }
		    
		    dlt_record.close();
		    temp.close();
		    remove("Purchase Record.txt");
			rename("temp.txt","Purchase Record.txt");
			
			cout<<endl <<"--DONE DELETE--" <<endl <<endl <<endl;
		}
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int shopper()
{
	int b, type, choice;
	int checktype, check, logout;
	
	do
	{
		cout<<"--------------------------------"<<endl;
		cout<<"             SHOPPER            "<<endl;
		cout<<"--------------------------------"<<endl;
		
		cout<<"[1] Register" <<endl;
		cout<<"[2] Login" <<endl;
		cout<<"[3] Back to Main Page" <<endl<<endl;
		cout<<"Enter your choice : ";
		cin>>b;
			
		SHOPPER *S; 
		
		if(b==1) //Register
		{		
			cout<<endl <<"-------WELCOME TO REGISTER CENTER------- " <<endl <<endl;
		
			cout<<"=== CUSTOMER TYPE ===" <<endl;
			cout<<"[1] Normal Customer " <<endl;
			cout<<"[2] MMU Student " <<endl;
			cout<<"[3] MMU Staff " <<endl;
		
			do
			{				
				cout<<endl;
				cout<<"Choice of Customer Type : ";
				cin>>type;
				
				cout<<endl;
				
				if(type==1)	//Normal Customer
				{	
					Customer C;
					S=&C;
					
					C.set_type(); 
					C.set_major(); 
					C.set_state(); 
					S->register_acc(); //Early binding because register_acc is non-virtual in base 
					S->display(); //Late binding
					
					checktype=1;
				}
				else if(type==2) //MMU Student
				{
					MMUStudent Stu;
					S=&Stu;
					
					Stu.set_type();
					Stu.set_major();
					Stu.set_state();
					S->register_acc(); //Early binding because register_acc is non-virtual in base
					S->display(); //late binding
					
					checktype=2;
				}
				else if(type==3) //MMU Staff
				{
					MMUStaff Sta;
					S=&Sta;
					
					Sta.set_type();
					Sta.set_major();
					Sta.set_state();
					S->register_acc(); //Early binding because register_acc is non-virtual in base
					S->display(); //late biding
					
					checktype=3;
				}
				else
				{
					cout<<"***INVALID INPUT***" <<endl <<endl;
					checktype=4;
				}
			}
			while(checktype==4);
			
			logout=1;
		}
		else if(b==2) //Login
		{	
			cout<<endl <<"-------WELCOME TO LOGIN CENTER------- " <<endl;
			
			S->login_acc();	
		
			Shop_Cart sc;
			logout=sc.mainmenu();
		}
		else if(b==3) //back main page
		{
			logout=0;
			check=1;
		}
		else
		{
			cout<<"***INVALID INPUT***" <<endl;
			logout=1;
		}
		cout<<endl;
	}
	while(logout==1);
	
	return check;
}

