/**********|**********|**********|
Program: TC02.1181203295.LEE.XIN.CHEN.cpp
Course: Object Oriented Programming
Year: 2020/21 Trimester 1
Name: Lee Xin Chen
ID: 1181203295
Lecture Section: TC02
Tutorial Section: TT04
Email: 1181203295@student.mmu.edu.my
Phone: 010-4238038
**********|**********|**********/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <sstream>
using namespace std;

class ShopItem
{
	protected:
		string name, company;
		double price;
		int id, unit, menu_choose, owner_choose;
		
		//for update
		string nname, ncompany;
		double nprice;
		int nunit;
		
	public:
		ShopItem()
		{
			id=0;
		}
		
		void menuShopOwner()
		{
			cout<<"--------------------------------"<<endl;
			cout<<"           SHOP OWNER           "<<endl;
			cout<<"--------------------------------"<<endl;
			cout<<"[1] Login"<<endl;
			cout<<"or"<<endl;
			cout<<"[2] Back to main page"<<endl<<endl;
		}
		
		int insertLogin()
		{
			char id[20], id1[20];
			char pw[20], pw1[20];
					
			fstream login;
			login.open("Owner Profile.txt", ios::in);
			if(!login.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
					
			cout<<"Enter ID	: ";
			cin.getline(id1, 20);
					        
			cout<<"Enter Password	: ";
			cin.getline(pw1, 20);
			cout<<endl;
					
			int check;
				
			while(!login.eof())
			{
				login.getline(id, 20, ' ');
				login.getline(pw, 20);
		
				if(strcmp(pw, pw1)==0 && strcmp(id, id1)==0)//success
				{
					check=1;
				}
				else if(strcmp(id, id1)==0)
				{
					check=2;
				}
				else if(strcmp(pw, pw1)==0)
				{
					check=3;
				}
				else if(strcmp(pw, pw1)!=0 && strcmp(id, id1)!=0)
				{
					check=4;
				}
			}
							
			login.close();
					
			return check;
		}
		
		void mainmenu()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"                      MENU                      "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] Edit Profile"<<endl;
			cout<<"[2] Manage Shop Item"<<endl;
			cout<<"[3] Sales Data Analysis"<<endl;
			cout<<"[4] Logout"<<endl<<endl;
		}
		
		int chooseMainmenu()
		{
			mainmenu();
			
			int menu_choose;
			
			cout<<"Enter your choice : ";
			cin>>menu_choose;
			cout<<endl;
			
			while(menu_choose!=1 && menu_choose!=2 && menu_choose!=3 && menu_choose!=4)
			{
				cout<<"***YOU HAVE ENTERED AN INVALID CHOICE***"<<endl<<endl;
				
				mainmenu();
				
				cout<<"Enter your choice : ";
				cin>>menu_choose;
				cout<<endl;
			}
			
			return menu_choose;
		}
		
		int editProfile()
		{
			string newusername, newpw;
			int checkname, checkpw, con;
					
			cout<<"-EDIT USERNAME & PASSWORD-"<<endl;
			do
			{
				cin.ignore();
				do
				{
					cout<<"Enter new username [max 20 characters] : ";
					getline(cin, newusername);
							
					if(newusername.size()>20)
					{
						cout<<"***USERNAME CANNOT BE OVER THAN 20 CHARACTERS***"<<endl<<endl;
						checkname=1;
					}
					else if(newusername.size()==0)
					{
						cout<<"***USERNAME CANNOT BE BLANK***"<<endl<<endl;
						checkname=2;
					}
					else if(newusername.find (' ') != string::npos) 
					{
					    cout<<"***USERNAME CANNOT CONTAIN SPACE***" <<endl<<endl; 
					    checkname=3;
					}
					else
					{
						checkname=4; //success
					}
				}while(checkname!=4);
						
				do
				{
					cout<<"Enter new password [max 20 characters] : ";
					getline(cin, newpw);
							
					if(newpw.size()>20)
					{
						cout<<"***PASSWORD CANNOT BE OVER THAN 20 CHARACTERS***"<<endl<<endl;
						checkpw=1;
					}
					else if(newpw.size()==0)
					{
						cout<<"***PASSWORD CANNOT BE BLANK***"<<endl<<endl;
						checkpw=2;
					}
					else if(newpw.find (' ') != string::npos) 
					{
					    cout<<"***PASSWORD CANNOT CONTAIN SPACE***" <<endl<<endl; 
					    checkpw=3;
					}
					else
					{
						checkpw=4; //success
					}
				}while(checkpw!=4);
		
				while(checkname==4 && checkpw==4)
				{
					cout<<endl;
					cout<<"Below is your latest username & password: "<<endl;
					cout<<"Username : "<<newusername<<endl;
					cout<<"Password : "<<newpw<<endl<<endl;
					
					cout<<"--DONE EDITING--"<<endl<<endl;
					break;
				}
						
				ofstream login;
				login.open("Owner Profile.txt");
				if(!login.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
				login<<newusername<<' '<<newpw;
				login.close();
						
				cout<<"Do you want to"<<endl;
				cout<<"[1] continue to previous action - edit profile"<<endl;
				cout<<"[2] back to menu"<<endl;
				cout<<">> ";
				cin>>con;
				cout<<endl;
				
				while(con!=1 && con!=2)
				{
					cout<<"***YOU HAVE ENTERED AN INVALID CHOICE***"<<endl<<endl;
					
					cout<<"Do you want to"<<endl;
					cout<<"[1] continue to previous action - edit profile"<<endl;
					cout<<"[2] back to menu"<<endl;
					cout<<">> ";
					cin>>con;
					cout<<endl;
				}
			}while(con==1);
					
			return con;
		}

		void menuViewSalesReport()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"              SALES DATA ANALYSIS               "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"View by"<<endl;
			cout<<"[1] Product Name"<<endl;
			cout<<"[2] Company Name"<<endl;
			cout<<"[3] Item Type"<<endl;
			cout<<"or"<<endl;
			cout<<"[4] Back to menu"<<endl<<endl;
		}
		
		int chooseViewSalesReport()
		{
			menuViewSalesReport();
			
			int sales_view_choose;
			
			cout<<"Enter your choice : ";
			cin>>sales_view_choose;
			cout<<endl;
			
			while(sales_view_choose!=1 && sales_view_choose!=2 && sales_view_choose!=3 && sales_view_choose!=4)
			{
				cout<<"***YOU HAVE ENTERED AN INVALID ITEM***"<<endl<<endl;
				
				menuViewSalesReport();
				
				cout<<"Enter your choice : ";
				cin>>sales_view_choose;
				cout<<endl;
			}
			
			return sales_view_choose;
		}
		
		void trim(string& s)//to trim char array with whitespace
		{
	    	size_t p=s.find_first_not_of(" \t");
	    	s.erase(0, p);
	   
	    	p=s.find_last_not_of(" \t");
	    	if (string::npos != p)
	    	s.erase(p+1);
		}
		
		int checkLine()//check lines in file
		{
			int count=0;
			string data;
			ifstream checkline;
			checkline.open("Sales Record.txt");
			if(!checkline.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			while (getline(checkline, data))
			{
				count++;
			}
			checkline.close();
			
			return count;
		}
		
		void prodNameSales_store(int count, string NAME[], int UNIT[], double PRICE[])
		{
			int num;
			string name[count*100];
			double price[count*100];
			int unit[count*100];
			
			num=count;
			for(int i=0; i<count; i++)
			{
				name[i]=NAME[i];
				price[i]=PRICE[i];
				unit[i]=UNIT[i];
			}
			
			int i, j, k;
			for(i=0; i<num; i++)
		    {
		        for(j=i+1; j<num; j++)
		        {
		            //If any duplicate found
		            if(name[i]==name[j])
		            {
		            	//add all duplicated name's price and unit together
						price[i]+=price[j];
						unit[i]+=unit[j];
		            	
		                // Delete the current duplicate element
		                for(k=j; k<num; k++)
		                {
		                    name[k]=name[k+1];
		                    price[k]=price[k+1];
		                    unit[k]=unit[k+1];
		                }
		 
		                //Decrement size after removing duplicate element
		                num--;
		 
		                // If shifting of elements occur then don't increment j
		                j--;
		            }
		            
		        }
		    }
		    
		    //store to file
		    if(num!=0)
		    {
		    	ofstream prodsales;
			    prodsales.open("Sales-Product Name.txt");
			    if(!prodsales.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
			    prodsales<<left<<setw(25)<<"Product NAME"<<setw(25)<<"TOTAL SALES UNITS"<<setw(25)<<"TOTAL SALES AMOUNT(RM)"<<endl;
			    for(int i=1; i<num; i++)
			    {
			    	prodsales<<fixed<<setprecision(2);
			        prodsales<<left<<setw(25)<<name[i]<<setw(25)<<unit[i]<<setw(25)<<price[i]<<endl;
			    }
			    prodsales.close();
			}
		}
		
		void prodNameSales_disp()
		{
			//read num of lines in file
			int count2=0;
			string data2;
			ifstream checkline2;
			checkline2.open("Sales-Product Name.txt");
			if(!checkline2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			while (getline(checkline2, data2))
			{
				count2++;
			}
			checkline2.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count2!=0) //to check is there any data in file
			{
				do
				{
					string pns, prodname_sales[count2];
					ifstream sales_prod;
					sales_prod.open("Sales-Product Name.txt");
					if(!sales_prod.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					for(int i=0; i<count2; i++)
					{
						getline(sales_prod, pns);
						prodname_sales[i]=pns;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<prodname_sales[j]<<endl;
					}
					//output data
					if(end<count2)
					{
						for(int j=start; j<end; j++)
						{
							cout<<prodname_sales[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count2)
					{
						for(int j=start; j<count2; j++)
						{
							cout<<prodname_sales[j]<<endl;
						}

						cout<<"--NO MORE SALES ANALYSIS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					sales_prod.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO SALES ANALYSIS FOUND--"<<endl<<endl;
			}
		}
		
		void prodNameSales()
		{
			cout<<"PRODUCT NAME"<<endl;
			
			int count;
			count=checkLine();
			
			string data, data_array[count];
			int purchase_id[count], cust_id[count], item_id[count], unit[count];
			char i_type[12], p_name[24], comp[24];
			string item_type[count], prod_name[count], company[count];
			double price[count];
			string blank, blank1, blank2, blank3, blank4;
			
			//get data from file
			ifstream getdata;
			getdata.open("Sales Record.txt");
			if(!getdata.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			for(int i=0; i<count; i++)
			{
				getline(getdata, data);
				data_array[i]=data;
			}
			
			for(int i=1; i<count; i++)
			{
				istringstream data(data_array[i]);
				
				data>>purchase_id[i];
				data>>cust_id[i];
					for(int j=0; j<9; j++)
					{
						getline(data, blank, ' ');
					}
				data.get(i_type, 12);
				item_type[i]=i_type;
				trim(item_type[i]);
					getline(data, blank1, ' ');
				data>>item_id[i];
					for(int j=0; j<8; j++)
					{
						getline(data, blank2, ' ');
					}
				data.get(p_name, 24);
				prod_name[i]=p_name;
				trim(prod_name[i]);
					getline(data, blank3, ' ');
				data.get(comp, 24);
				company[i]=comp;
				trim(company[i]);
					getline(data, blank4, ' ');
				data>>unit[i];
				data>>price[i];
			}
			
			//sort alphabetically
			double p;
		    int u, pid, cid, iid;
		    string c, it, pn;
		    for(int i=1; i<count; i++)
		    {
		        for(int j=i+1; j<count; j++)
		        {
		            if (prod_name[i]>prod_name[j]) //to sort by prod name
		            {
		            	pid=purchase_id[i];
		                purchase_id[i]=purchase_id[j];
		                purchase_id[j]=pid;
		                
		                cid=cust_id[i];
		                cust_id[i]=cust_id[j];
		                cust_id[j]=cid;
		            	
		            	it= item_type[i];
		                item_type[i]= item_type[j];
		                item_type[j]= it;
		            	
		            	iid= item_id[i];
		                item_id[i]= item_id[j];
		                item_id[j]= iid;
		            	
		                c=company[i];
		                company[i]=company[j];
		                company[j]=c;
		                     
		                p= price[i];
		                price[i]= price[j];
		                price[j]= p;
		                     
		                u= unit[i];
		                unit[i]= unit[j];
		                unit[j]= u;
		                
		                pn= prod_name[i];
		                prod_name[i]= prod_name[j];
		                prod_name[j]= pn;
		            }
		        }
		    }
			getdata.close();
			
			prodNameSales_store(count, prod_name, unit, price);
			
			//display sales report
			prodNameSales_disp();
		}
		
		void compNameSales_store(int count, string NAME[], int UNIT[], double PRICE[])
		{
			int num;
			string name[count*100];
			double price[count*100];
			int unit[count*100];
			
			num=count;
			for(int i=0; i<count; i++)
			{
				name[i]=NAME[i];
				price[i]=PRICE[i];
				unit[i]=UNIT[i];
			}
			
			int i, j, k;
			for(i=0; i<num; i++)
		    {
		        for(j=i+1; j<num; j++)
		        {
		            //If any duplicate found
		            if(name[i] == name[j])
		            {
		            	//add all duplicated name's price and unit together
						price[i]+=price[j];
						unit[i]+=unit[j];
		            	
		                // Delete the current duplicate element
		                for(k=j; k<num; k++)
		                {
		                    name[k]=name[k+1];
		                    price[k]=price[k+1];
		                    unit[k]=unit[k+1];
		                }
		 
		                //Decrement size after removing duplicate element
		                num--;
		 
		                // If shifting of elements occur then don't increment j
		                j--;
		            }
		            
		        }
		    }
		    
		    //store to file
		    if(num!=0)
		    {
		    	ofstream compsales;
			    compsales.open("Sales-Company Name.txt");
			    if(!compsales.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
			    compsales<<left<<setw(25)<<"COMPANY NAME"<<setw(25)<<"TOTAL SALES UNITS"<<setw(25)<<"TOTAL SALES AMOUNT(RM)"<<endl;
			    for(int i=1; i<num; i++)
			    {
			    	compsales<<fixed<<setprecision(2);
			        compsales<<left<<setw(25)<<name[i]<<setw(25)<<unit[i]<<setw(25)<<price[i]<<endl;
			    }
			    compsales.close();
			}
		}
		
		void compNameSales_disp()
		{
			//read num of lines in file
			int count2=0;
			string data2;
			ifstream checkline2;
			checkline2.open("Sales-Company Name.txt");
			if(!checkline2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			while (getline(checkline2, data2))
			{
				count2++;
			}
			checkline2.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count2!=0) //to check is there any data in file
			{
				do
				{
					string cns, compname_sales[count2];
					ifstream sales_comp;
					sales_comp.open("Sales-Company Name.txt");
					if(!sales_comp.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					for(int i=0; i<count2; i++)
					{
						getline(sales_comp, cns);
						compname_sales[i]=cns;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<compname_sales[j]<<endl;
					}
					//output data
					if(end<count2)
					{
						for(int j=start; j<end; j++)
						{
							cout<<compname_sales[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count2)
					{
						for(int j=start; j<count2; j++)
						{
							cout<<compname_sales[j]<<endl;
						}

						cout<<"--NO MORE SALES ANALYSIS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					sales_comp.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO SALES ANALYSIS FOUND--"<<endl<<endl;
			}
		}
		
		void compNameSales()
		{
			cout<<"COMPANY NAME"<<endl;
			
			int count;
			count=checkLine();
			
			string data, data_array[count];
			int purchase_id[count], cust_id[count], item_id[count], unit[count];
			char i_type[12], p_name[24], comp[24];
			string item_type[count], prod_name[count], company[count];
			double price[count];
			string blank, blank1, blank2, blank3, blank4;
			
			//get data from file
			ifstream getdata;
			getdata.open("Sales Record.txt");
			if(!getdata.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			for(int i=0; i<count; i++)
			{
				getline(getdata, data);
				data_array[i]=data;
			}
			
			for(int i=1; i<count; i++)
			{
				istringstream data(data_array[i]);
				
				data>>purchase_id[i];
				data>>cust_id[i];
					for(int j=0; j<9; j++)
					{
						getline(data, blank, ' ');
					}
				data.get(i_type, 12);
				item_type[i]=i_type;
				trim(item_type[i]);
					getline(data, blank1, ' ');
				data>>item_id[i];
					for(int j=0; j<8; j++)
					{
						getline(data, blank2, ' ');
					}
				data.get(p_name, 24);
				prod_name[i]=p_name;
				trim(prod_name[i]);
					getline(data, blank3, ' ');
				data.get(comp, 24);
				company[i]=comp;
				trim(company[i]);
					getline(data, blank4, ' ');
				data>>unit[i];
				data>>price[i];
			}
			
			//sort alphabetically
			double p;
		    int u, pid, cid, iid;
		    string c, it, pn;
		    for(int i=1; i<count; i++)
		    {
		        for(int j=i+1; j<count; j++)
		        {
		            if (company[i]>company[j]) //to sort by comp name
		            {
		            	pid=purchase_id[i];
		                purchase_id[i]=purchase_id[j];
		                purchase_id[j]=pid;
		                
		                cid=cust_id[i];
		                cust_id[i]=cust_id[j];
		                cust_id[j]=cid;
		            	
		            	it= item_type[i];
		                item_type[i]= item_type[j];
		                item_type[j]= it;
		            	
		            	iid= item_id[i];
		                item_id[i]= item_id[j];
		                item_id[j]= iid;
		            	
		                c=company[i];
		                company[i]=company[j];
		                company[j]=c;
		                     
		                p= price[i];
		                price[i]= price[j];
		                price[j]= p;
		                     
		                u= unit[i];
		                unit[i]= unit[j];
		                unit[j]= u;
		                
		                pn= prod_name[i];
		                prod_name[i]= prod_name[j];
		                prod_name[j]= pn;
		            }
		        }
		    }
			getdata.close();
			
			compNameSales_store(count, company, unit, price);
			
			//display sales report
			compNameSales_disp();
		}
		
		void itemTypeSales_store(int count, string NAME[], int UNIT[], double PRICE[])
		{
			int num;
			string name[count*100];
			double price[count*100];
			int unit[count*100];
			
			num=count;
			for(int i=0; i<count; i++)
			{
				name[i]=NAME[i];
				price[i]=PRICE[i];
				unit[i]=UNIT[i];
			}
			
			int i, j, k;
			for(i=0; i<num; i++)
		    {
		        for(j=i+1; j<num; j++)
		        {
		            //If any duplicate found
		            if(name[i] == name[j])
		            {
		            	//add all duplicated name's price and unit together
						price[i]+=price[j];
						unit[i]+=unit[j];
		            	
		                // Delete the current duplicate element
		                for(k=j; k<num; k++)
		                {
		                    name[k]=name[k+1];
		                    price[k]=price[k+1];
		                    unit[k]=unit[k+1];
		                }
		 
		                //Decrement size after removing duplicate element
		                num--;
		 
		                // If shifting of elements occur then don't increment j
		                j--;
		            }
		            
		        }
		    }
		    
		    //store to file
		    if(num!=0)
		    {
		    	ofstream itypesales;
			    itypesales.open("Sales-Item Type.txt");
			    if(!itypesales.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
			    itypesales<<left<<setw(25)<<"ITEM TYPE"<<setw(25)<<"TOTAL SALES UNITS"<<setw(25)<<"TOTAL SALES AMOUNT(RM)"<<endl;
			    for(int i=1; i<num; i++)
			    {
			    	itypesales<<fixed<<setprecision(2);
			        itypesales<<left<<setw(25)<<name[i]<<setw(25)<<unit[i]<<setw(25)<<price[i]<<endl;
			    }
			    itypesales.close();
			}
		}
		
		void itemTypeSales_disp()
		{
			//read num of lines in file
			int count2=0;
			string data2;
			ifstream checkline2;
			checkline2.open("Sales-Item Type.txt");
			if(!checkline2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			while (getline(checkline2, data2))
			{
				count2++;
			}
			checkline2.close();
			
			//view
			int start=1;
			int end=11;
			int add=1;
			char cont;
			
			if(count2!=0) //to check is there any data in file
			{
				do
				{
					string its, itemtype_sales[count2];
					ifstream sales_itemtype;
					sales_itemtype.open("Sales-Item Type.txt");
					if(!sales_itemtype.is_open())
					{
						cout<<"Could Not Open File" <<endl;
						exit(0);
					}
					for(int i=0; i<count2; i++)
					{
						getline(sales_itemtype, its);
						itemtype_sales[i]=its;
					}
					//output heading
					for(int j=0; j<1; j++)
					{
						cout<<itemtype_sales[j]<<endl;
					}
					//output data
					if(end<count2)
					{
						for(int j=start; j<end; j++)
						{
							cout<<itemtype_sales[j]<<endl;
						}
						
						cout<<endl;
						cout<<"Do you want to keep viewing [Y/N] : ";
						cin>>cont;
						cout<<endl;
					}
					//stop output data when it is the end of the file
					else if(end>=count2)
					{
						for(int j=start; j<count2; j++)
						{
							cout<<itemtype_sales[j]<<endl;
						}

						cout<<"--NO MORE SALES ANALYSIS FOUND--"<<endl<<endl;
						break;
					}
					
					add++;
					end=(10*add)+1;
					start=end-10;
					
					sales_itemtype.close();
				}
				while(cont=='Y' || cont=='y');
			}
			else
			{
				cout<<endl;
				cout<<"--NO SALES ANALYSIS FOUND--"<<endl<<endl;
			}
		}
		
		void itemTypeSales()
		{
			cout<<"ITEM TYPE"<<endl;
			
			int count;
			count=checkLine();
			
			string data, data_array[count];
			int purchase_id[count], cust_id[count], item_id[count], unit[count];
			char i_type[12], p_name[24], comp[24];
			string item_type[count], prod_name[count], company[count];
			double price[count];
			string blank, blank1, blank2, blank3, blank4;
			
			//get data from file
			ifstream getdata;
			getdata.open("Sales Record.txt");
			if(!getdata.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			for(int i=0; i<count; i++)
			{
				getline(getdata, data);
				data_array[i]=data;
			}
			
			for(int i=1; i<count; i++)
			{
				istringstream data(data_array[i]);
				
				data>>purchase_id[i];
				data>>cust_id[i];
					for(int j=0; j<9; j++)
					{
						getline(data, blank, ' ');
					}
				data.get(i_type, 12);
				item_type[i]=i_type;
				trim(item_type[i]);
					getline(data, blank1, ' ');
				data>>item_id[i];
					for(int j=0; j<8; j++)
					{
						getline(data, blank2, ' ');
					}
				data.get(p_name, 24);
				prod_name[i]=p_name;
				trim(prod_name[i]);
					getline(data, blank3, ' ');
				data.get(comp, 24);
				company[i]=comp;
				trim(company[i]);
					getline(data, blank4, ' ');
				data>>unit[i];
				data>>price[i];
			}
			
			//sort alphabetically
			double p;
		    int u, pid, cid, iid;
		    string c, it, pn;
		    for(int i=1; i<count; i++)
		    {
		        for(int j=i+1; j<count; j++)
		        {
		            if (item_type[i]>item_type[j]) //to sort by item type
		            {
		            	pid=purchase_id[i];
		                purchase_id[i]=purchase_id[j];
		                purchase_id[j]=pid;
		                
		                cid=cust_id[i];
		                cust_id[i]=cust_id[j];
		                cust_id[j]=cid;
		            	
		            	it= item_type[i];
		                item_type[i]= item_type[j];
		                item_type[j]= it;
		            	
		            	iid= item_id[i];
		                item_id[i]= item_id[j];
		                item_id[j]= iid;
		            	
		                c=company[i];
		                company[i]=company[j];
		                company[j]=c;
		                     
		                p= price[i];
		                price[i]= price[j];
		                price[j]= p;
		                     
		                u= unit[i];
		                unit[i]= unit[j];
		                unit[j]= u;
		                
		                pn= prod_name[i];
		                prod_name[i]= prod_name[j];
		                prod_name[j]= pn;
		            }
		        }
		    }
			getdata.close();
			
			itemTypeSales_store(count, item_type, unit, price);
			
			//display sales report
			itemTypeSales_disp();
		}
		
		void menuItem()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"                 TYPES OF ITEMS                 "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] Book"<<endl;
			cout<<"[2] Magazine"<<endl;
			cout<<"[3] Movie"<<endl;
			cout<<"or"<<endl;
			cout<<"[4] Back to menu"<<endl<<endl;
		}
		
		int chooseItem()
		{
			menuItem();
			
			int item_choose;
			
			cout<<"Enter your choice : ";
			cin>>item_choose;
			cout<<endl;
			
			while(item_choose!=1 && item_choose!=2 && item_choose!=3 && item_choose!=4)
			{
				cout<<"***YOU HAVE ENTERED AN INVALID ITEM***"<<endl<<endl;
				
				menuItem();
				
				cout<<"Enter your choice : ";
				cin>>item_choose;
				cout<<endl;
			}
			
			return item_choose;
		}
		
		void menuAction()
		{
			cout<<"------------------------------------------------"<<endl;
			cout<<"                ACTIONS TO ITEMS                "<<endl;
			cout<<"------------------------------------------------"<<endl;
			cout<<"[1] View Items"<<endl;
			cout<<"[2] Insert New Items"<<endl;
			cout<<"[3] Update Information of Items"<<endl;
			cout<<"[4] Delete Item"<<endl;
			cout<<"or"<<endl;
			cout<<"[5] Back to choose items"<<endl;
			cout<<"[6] Back to menu"<<endl<<endl;
		}
		
		int chooseAction()
		{
			menuAction();
			
			int action_choose;
			
			cout<<"Enter your choice : ";
			cin>>action_choose;
			cout<<endl;
			
			while(action_choose!=1 && action_choose!=2 && action_choose!=3 && action_choose!=4 && action_choose!=5 && action_choose!=6)
			{
				cout<<"***YOU HAVE ENTERED AN INVALID TYPE OF ACTION***"<<endl<<endl;
				
				menuAction();
				
				cout<<"Enter your choice : ";
				cin>>action_choose;
				cout<<endl;
			}
			
			return action_choose;
		}
		
		virtual void view()=0;
		
		void insert()
		{
			cin.ignore();
		
			cout<<"Name                          : ";
			getline(cin, name);
			
			int check;
			do
			{			
				cout<<"Price                         : RM ";
				cin>>price;
				if(price<0)
				{
					cout<<"***PRICE CANNOT BE A NEGATIVE NUMBER***"<<endl;
					check=1;
				}
				else
				{
					check=0;
				}
			}while(check==1);
			
			do
			{			
				cout<<"Number of Units Available     : ";
				cin>>unit;
				if(unit<0)
				{
					cout<<"***UNIT CANNOT BE A NEGATIVE NUMBER***"<<endl;
					check=1;
				}
				else
				{
					check=0;
				}
			}while(check==1);
				
			cin.ignore();
				
			cout<<"Company                       : ";
			getline(cin, company);
		}
		
		int randID()//auto generate id
		{
		    int i=0;
		    int id=0;
		    
		    while(i<5) 
			{
		        id=(id*10)+rand()%9+1;
		        i++;
		    }
		    
		    return id;
		}
		
		void dispIns()
		{	
			cout<<"ID                            : "<<id<<endl;
			cout<<"Name                          : "<<name<<endl;
			cout<<"Price                         : RM "<<price<<endl;
			cout<<"Number of Units Available     : "<<unit<<endl;
			cout<<"Company                       : "<<company<<endl;
		}
		
		void update()
		{
			cin.ignore();
					
			cout<<"Name                          : ";
			getline(cin, nname);
			
			int check;				
			do
			{			
				cout<<"Price                         : RM ";
				cin>>nprice;
				if(nprice<0)
				{
					cout<<"***PRICE CANNOT BE A NEGATIVE NUMBER***"<<endl;
					check=1;
				}
				else
				{
					check=0;
				}
			}while(check==1);
			
			do
			{			
				cout<<"Number of Units Available     : ";
				cin>>nunit;
				if(nunit<0)
				{
					cout<<"***UNIT CANNOT BE A NEGATIVE NUMBER***"<<endl;
					check=1;
				}
				else
				{
					check=0;
				}
			}while(check==1);
							
			cin.ignore();
							
			cout<<"Company                       : ";
			getline(cin, ncompany);			
		}
};

class Book:public ShopItem
{
	private:
		string author;
	
	public:
		Book()
		{
			cout<<"BOOK - ";
		}
		
		//ins
		void insertBook()
		{
			cout<<"INSERT NEW ITEM"<<endl;
			
			//heading
			fstream b_heading;
			b_heading.open("Book.txt");
			if(!b_heading.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			b_heading<<left<<setw(8)<<"ID"<<setw(25)<<"NAME"<<setw(14)<<"PRICE(RM)"<<setw(10)<<"UNIT"<<setw(25)<<"COMPANY"<<setw(25)<<"AUTHOR"<<endl;
			b_heading.close();
			
			//data
			fstream b_data;
			b_data.open("Book.txt", ios::app);
			if(!b_data.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			//insert
			insert();
			
			cout<<"Name of Author                : ";
			getline(cin, author);
			cout<<endl;
			
			//display
			cout<<"ITEM DETAILS"<<endl;
			
			srand(time(0));
			id=randID();
			
			dispInsBook();
			
			//store file
			b_data<<left<<setw(8)<<id<<setw(25)<<name<<setw(14)<<price<<setw(10)<<unit<<setw(25)<<company<<setw(25)<<author<<endl;
			b_data.close();
			
			cout<<"--DONE INSERT--"<<endl<<endl;
		}
		
		void dispInsBook()
		{
			dispIns();
			cout<<"Name of Author                : "<<author<<endl<<endl;
		}

		void view()
		{
			cout<<"VIEW ITEM"<<endl;
			
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

		void updateBook()
		{
			cout<<"UPDATE INFORMATION OF ITEM"<<endl;
			
			int idupd, num;
			string data, nauthor;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream upd_book_check;
	            upd_book_check.open("Book.txt", ios::in);
	            if(!upd_book_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
	            cout<<"Enter ID of Item to update : ";
				cin>>idupd;
				
				while(upd_book_check.good())
				{
					getline(upd_book_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>author;
					
					if(id==idupd && idupd!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				upd_book_check.close();
			
			}while(!found);
			
			//after found
			ifstream upd_book;
			upd_book.open("Book.txt");
			if(!upd_book.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			ofstream upd_book2;
			upd_book2.open("newBook.txt");
			if(!upd_book2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			cout<<"Enter information below"<<endl;
			update();
			cout<<"Name of Author                : ";
			getline(cin, nauthor);
			cout<<endl;
			
			while(upd_book.good())
			{
				getline(upd_book, data);
				
				if(upd_book)
				{
					int num;
					istringstream(data)>>num;
	    			
		            if(num!=idupd)
		            {
		            	upd_book2<<data<<endl;
		            }
		            else
		            {	
					    upd_book2<<left<<setw(8)<<idupd<<setw(25)<<nname<<setw(14)<<nprice<<setw(10)<<nunit<<setw(25)<<ncompany<<setw(25)<<nauthor<<endl;
					}
				}
			}
			
			upd_book2.close();
			upd_book.close();
			
			remove("Book.txt");
			rename("newBook.txt", "Book.txt");
			
			cout<<"--DONE UPDATE--"<<endl<<endl;
		}

		void deleteBook()
		{
			cout<<"DELETE ITEM"<<endl;
			
			int iddlt;
			string data;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream del_book_check;
	            del_book_check.open("Book.txt", ios::in);
	            if(!del_book_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
				cout<<"Enter ID of Item to delete :";
				cin>>iddlt;
				cout<<endl;
				
				while(del_book_check.good())
				{
					getline(del_book_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>author;
					
					if(id==iddlt && iddlt!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				del_book_check.close();
			
			}while(!found);
			
			//after found
			fstream del_book;
			del_book.open("Book.txt");
			if(!del_book.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			del_book.clear();
			
			fstream del_book2;
			del_book2.open("newBook.txt", ios::out | ios::trunc);
			if(!del_book2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			while(del_book.good())
			{
				getline(del_book, data);
				if(del_book)
				{
					int num;
					istringstream(data)>>num;
					if(num!=iddlt)
					{
						del_book2<<data<<endl;
					}
				}
			}
			
			del_book.close();
			del_book2.close();
			remove("Book.txt");
			rename("newBook.txt", "Book.txt");

			cout<<"--DONE DELETE--"<<endl<<endl;
		}
};

class Magazine:public ShopItem
{
	private:
		string dates;
		
	public:
		Magazine()
		{
			cout<<"MAGAZINE - ";
		}
		
		////////////////////ins
		void insertMag()
		{
			cout<<"INSERT NEW ITEM"<<endl;
			
			//heading
			fstream mag_heading;
			mag_heading.open("Magazine.txt");
			if(!mag_heading.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			mag_heading<<left<<setw(8)<<"ID"<<setw(25)<<"NAME"<<setw(14)<<"PRICE(RM)"<<setw(10)<<"UNIT"<<setw(25)<<"COMPANY"<<setw(30)<<"PUBLISHED TIME[YYYY/MM]"<<endl;
			mag_heading.close();
			
			//data
			fstream mag_data;
			mag_data.open("Magazine.txt", ios::app);
			if(!mag_data.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			//insert
			insert();

			cout<<"Time of Publication [yyyy/mm] : ";
			getline(cin, dates);
			cout<<endl;
			
			//display
			cout<<"ITEM DETAILS"<<endl;
			
			srand(time(0));
			id=randID();
			
			dispInsMag();
			
			//store file
			mag_data<<left<<setw(8)<<id<<setw(25)<<name<<setw(14)<<price<<setw(10)<<unit<<setw(25)<<company<<setw(25)<<dates<<endl;
			mag_data.close();
			
			cout<<"--DONE INSERT--"<<endl<<endl;
		}
		
		void dispInsMag()
		{
			dispIns();
			
			cout<<"Time of Publication [yyyy/mm] : "<<dates<<endl<<endl;
		}

		void view()
		{
			cout<<"VIEW ITEM"<<endl;
			
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

		void updateMag()
		{
			cout<<"UPDATE INFORMATION OF ITEM"<<endl;
			
			int idupd, num;
			string data, ndates;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream upd_mag_check;
	            upd_mag_check.open("Magazine.txt", ios::in);
	            if(!upd_mag_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
	            cout<<"Enter ID of Item to update : ";
				cin>>idupd;
				cout<<endl;
				
				while(upd_mag_check.good())
				{
					getline(upd_mag_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>dates;
					
					if(id==idupd && idupd!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				upd_mag_check.close();
			
			}while(!found);
			
			//after check
			ifstream upd_mag;
			upd_mag.open("Magazine.txt");
			if(!upd_mag.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			ofstream upd_mag2;
			upd_mag2.open("newMagazine.txt");
			if(!upd_mag2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			cout<<"Enter information below"<<endl;
			update();
			cout<<"Time of Publication [yyyy/mm] : ";
			getline(cin, ndates);
			cout<<endl;
			
			while(upd_mag.good())
			{
				getline(upd_mag, data);
				
				if(upd_mag)
				{
					int num;
					istringstream(data)>>num;
	    			
		            if(num!=idupd)
		            {
		            	upd_mag2<<data<<endl;
		            }
		            else
		            {	
					    upd_mag2<<left<<setw(8)<<idupd<<setw(25)<<nname<<setw(14)<<nprice<<setw(10)<<nunit<<setw(25)<<ncompany<<setw(25)<<ndates<<endl;
					}
				}
			}
			
			upd_mag2.close();
			upd_mag.close();
			
			remove("Magazine.txt");
			rename("newMagazine.txt", "Magazine.txt");
			
			cout<<"--DONE UPDATE--"<<endl<<endl;
		}

		void deleteMag()
		{
			cout<<"DELETE ITEM"<<endl;
			
			string data;
			int iddlt;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream del_mag_check;
	            del_mag_check.open("Magazine.txt", ios::in);
	            if(!del_mag_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
				cout<<"Enter ID of Item to delete :";
				cin>>iddlt;
				cout<<endl;
				
				while(del_mag_check.good())
				{
					getline(del_mag_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>dates;
					
					if(id==iddlt && iddlt!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				del_mag_check.close();
			
			}while(!found);
			
			//after found
			fstream del_mag;
			del_mag.open("Magazine.txt");
			if(!del_mag.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			del_mag.clear();
			
			fstream del_mag2;
			del_mag2.open("newMagazine.txt", ios::out | ios::trunc);
			if(!del_mag2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			while(del_mag.good())
			{
				getline(del_mag, data);
				if(del_mag)
				{
					int num;
					istringstream(data)>>num;
					if(num!=iddlt)
					{
						del_mag2<<data<<endl;
					}
				}
			}
			
			del_mag.close();
			del_mag2.close();
			remove("Magazine.txt");
			rename("newMagazine.txt", "Magazine.txt");
			
			cout<<"--DONE DELETE--"<<endl<<endl;
		}
};

class Movie:public ShopItem
{
	private:
		string actor;
		
	public:
		Movie()
		{
			cout<<"MOVIE - ";
		}
		
		void insertMov()
		{
			cout<<"INSERT NEW ITEM"<<endl;
			
			//heading
			fstream mov_heading;
			mov_heading.open("Movie.txt");
			if(!mov_heading.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			mov_heading<<left<<setw(8)<<"ID"<<setw(25)<<"NAME"<<setw(14)<<"PRICE(RM)"<<setw(10)<<"UNIT"<<setw(25)<<"COMPANY"<<setw(25)<<"ACTOR"<<endl;
			mov_heading.close();
			
			//data
			fstream mov_data;
			mov_data.open("Movie.txt", ios::app);
			if(!mov_data.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			//insert
			insert();
			
			cout<<"Name of Main Actor            : ";
			getline(cin, actor);
			cout<<endl;
			
			//display
			cout<<"ITEM DETAILS"<<endl;
			
			srand(time(0));
			id=randID();
			
			dispInsMov();
			
			//store file
			mov_data<<left<<setw(8)<<id<<setw(25)<<name<<setw(14)<<price<<setw(10)<<unit<<setw(25)<<company<<setw(25)<<actor<<endl;
			mov_data.close();
			
			cout<<"--DONE INSERT--"<<endl<<endl;
		}
		
		void dispInsMov()
		{
			dispIns();
			
			cout<<"Name of Main Actor            : "<<actor<<endl<<endl;
		}
		
		void view()
		{
			cout<<"VIEW ITEM"<<endl;
			
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

		void updateMov()
		{
			cout<<"UPDATE INFORMATION OF ITEM"<<endl;
			
			int idupd, num;
			string data, nactor;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream upd_mov_check;
	            upd_mov_check.open("Movie.txt", ios::in);
	            if(!upd_mov_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
	            cout<<"Enter ID of Item to update : ";
				cin>>idupd;
				cout<<endl;
				
				while(upd_mov_check.good())
				{
					getline(upd_mov_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>actor;
					
					if(id==idupd && idupd!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				upd_mov_check.close();
			
			}while(!found);
			
			//after check
			ifstream upd_mov;
			upd_mov.open("Movie.txt");
			if(!upd_mov.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			
			ofstream upd_mov2;
			upd_mov2.open("newMovie.txt");
			if(!upd_mov2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			cout<<"Enter information below"<<endl;
			update();
			cout<<"Name of Main Actor            : ";
			getline(cin, nactor);
			cout<<endl;
			
			while(upd_mov.good())
			{
				getline(upd_mov, data);
				
				if(upd_mov)
				{
					int num;
					istringstream(data)>>num;
	    			
		            if(num!=idupd)
		            {
		            	upd_mov2<<data<<endl;
		            }
		            else
		            {	
					    upd_mov2<<left<<setw(8)<<idupd<<setw(25)<<nname<<setw(14)<<nprice<<setw(10)<<nunit<<setw(25)<<ncompany<<setw(25)<<nactor<<endl;
					}
				}
			}
			
			upd_mov2.close();
			upd_mov.close();
			
			remove("Movie.txt");
			rename("newMovie.txt", "Movie.txt");
			
			cout<<"--DONE UPDATE--"<<endl<<endl;
		}

		void deleteMov()
		{
			cout<<"DELETE ITEM"<<endl;
			
			string data;
			int iddlt;
			
			bool found = false;
			
			do //to check validation of id
			{
	            ifstream del_mov_check;
	            del_mov_check.open("Movie.txt", ios::in);
	            if(!del_mov_check.is_open())
				{
					cout<<"Could Not Open File" <<endl;
					exit(0);
				}
	            string data_check=" ";
	            
				cout<<"Enter ID of Item to delete :";
				cin>>iddlt;
				cout<<endl;
				
				while(del_mov_check.good())
				{
					getline(del_mov_check, data_check);
					istringstream in(data_check);
					in>>id;
					in>>name;
					in>>price;
					in>>unit;
					in>>company;
					in>>actor;
					
					if(id==iddlt && iddlt!=0)
					{
						found=true;
						continue;
					}
				}
				
				if(!found)
				{
					cout<<"***INVALID ID***"<<endl<<endl;
				}
				del_mov_check.close();
			
			}while(!found);
			
			//after found
			fstream del_mov;
			del_mov.open("Movie.txt");
			if(!del_mov.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}
			del_mov.clear();
			
			fstream del_mov2;
			del_mov2.open("newMovie.txt", ios::out | ios::trunc);
			if(!del_mov2.is_open())
			{
				cout<<"Could Not Open File" <<endl;
				exit(0);
			}

			while(del_mov.good())
			{
				getline(del_mov, data);
				if(del_mov)
				{
					int num;
					istringstream(data)>>num;
					if(num!=iddlt)
					{
						del_mov2<<data<<endl;
					}
				}
			}
			
			del_mov.close();
			del_mov2.close();
			remove("Movie.txt");
			rename("newMovie.txt", "Movie.txt");
			
			cout<<"--DONE DELETE--"<<endl<<endl;
		}
};



int select()
{
	int chooseitem=0, chooseaction=0, cont;
	string item, action;
	
	cout<<"-MANAGE SHOP ITEM-"<<endl;
	
	ShopItem *SI;
	
	do
	{
		chooseitem=SI->chooseItem();
		do
		{
			if(chooseitem==4)//back to menu
			{
				cont=4;
			}
			else
			{
				chooseaction=SI->chooseAction();
				if(chooseaction==5)//back to choose item
				{
					cont=3;
				}
				else if(chooseaction==6)//back to menu
				{
					cont=4;
				}
				else
				{
					do
					{
						if(chooseitem==1) //book
						{
							item="book";
							Book B;
							SI=&B;
							if(chooseaction==1) //view
							{
								action="view";
								B.view();
							}
							
							else if(chooseaction==2) //insert
							{
								action="insert";
								B.insertBook();
							}
							
							else if(chooseaction==3) //update
							{
								action="update";
								B.updateBook();
							}
							
							else if(chooseaction==4) //delete
							{
								action="delete";
								B.deleteBook();
							}
						}
					
						else if(chooseitem==2) //magazine
						{
							item="magazine";
							
							Magazine Mag;
							SI=&Mag;
							if(chooseaction==1) //view
							{
								action="view";
								Mag.view();
							}
							
							else if(chooseaction==2) //insert
							{
								action="insert";
								Mag.insertMag();
							}
							
							else if(chooseaction==3) //update
							{
								action="update";
								Mag.updateMag();
							}
							
							else if(chooseaction==4) //delete
							{
								action="delete";
								Mag.deleteMag();
							}
						}
					
						else if(chooseitem==3) //movie
						{
							item="movie";
							
							Movie Mov;
							SI=&Mov;
							if(chooseaction==1) //view
							{
								action="view";
								Mov.view();
							}
							
							else if(chooseaction==2) //insert
							{
								action="insert";
								Mov.insertMov();
							}
							
							else if(chooseaction==3) //update
							{
								action="update";
								Mov.updateMov();
							}
							
							else if(chooseaction==4) //delete
							{
								action="delete";
								Mov.deleteMov();
							}
						}
						cout<<"Do you want to"<<endl;
						cout<<"[1] continue manage previous action  - "<<item<<":"<<action<<endl;
						cout<<"[2] continue manage previous item    - "<<item<<endl;
						cout<<"[3] continue manage shop item"<<endl;
						cout<<"[4] back to menu"<<endl;
						cout<<">> ";
						cin>>cont;
						cout<<endl;
						
						while(cont!=1 && cont!=2 && cont!=3 && cont!=4)
						{
							cout<<"***YOU HAVE ENTERED AN INVALID CHOICE***"<<endl<<endl;
							
							cout<<"Do you want to"<<endl;
							cout<<"[1] continue manage previous action  - "<<item<<":"<<action<<endl;
							cout<<"[2] continue manage previous item    - "<<item<<endl;
							cout<<"[3] continue manage shop item"<<endl;
							cout<<"[4] back to menu"<<endl;
							cout<<">> ";
							cin>>cont;
							cout<<endl;
						}
					}while(cont==1);//cont	
				}	
			}
		}while(cont==2);//cont item
	}while(cont==3);//cont edit shop item
	
	return cont;
}

int report()
{
	cout<<"-SALES DATA ANALYSIS-"<<endl;
	
	ShopItem *SI;
	
	int view_sales;
	int cont;
	string s_view;
	
	do
	{
		view_sales=SI->chooseViewSalesReport();
		if(view_sales==4)
		{
			cont==3;
		}
		else
		{
			do
			{
				cout<<"VIEW BY - ";
				if(view_sales==1)//prod name
				{
					s_view="product name";
					SI->prodNameSales();
				}
				else if(view_sales==2)//comp name
				{
					s_view="company name";
					SI->compNameSales();
				}
				else if(view_sales==3)//item type
				{
					s_view="item type";
					SI->itemTypeSales();
				}
				
				cout<<"Do you want to"<<endl;
				cout<<"[1] continue view report by previous viewing choice - "<<s_view<<endl;
				cout<<"[2] continue view report"<<endl;
				cout<<"[3] back to menu"<<endl;
				cout<<">> ";
				cin>>cont;
				cout<<endl;
								
				while(cont!=1 && cont!=2 && cont!=3)
				{
					cout<<"***YOU HAVE ENTERED AN INVALID CHOICE***"<<endl<<endl;
									
					cout<<"Do you want to"<<endl;
					cout<<"[1] continue view report by previous viewing choice - "<<s_view<<endl;
					cout<<"[2] continue view report"<<endl;
					cout<<"[3] back to menu"<<endl;
					cout<<">> ";
					cin>>cont;
					cout<<endl;
				}
			}while(cont==1);//cont previous
		}
	}while(cont==2);//cont view report
	
	return cont;
}

int menu()
{
	ShopItem *SI;
	char choosemenu=0;
	int logout=0, cont1=0, cont2=0, cont3=0, cont4=0;
	
	do
	{
		choosemenu=SI->chooseMainmenu();
		
		if(choosemenu==1) //edit profile
		{
			cont1=SI->editProfile();
			logout=0;
		}
		else if(choosemenu==2)//view,insert,edit,dlt
		{
			cont2=select();
			logout=0;
		}
		else if(choosemenu==3)//sales analysis
		{
			cont3=report();
			logout=0;
		}
		else if(choosemenu==4)//logout
		{
			cont4=1;
			cout<<"Logged out."<<endl;
			cout<<"--THANK YOU--"<<endl<<endl;
			logout=1;
			break;
		}
	}
	while(cont1==2 || cont2==4 || cont3==3 || cont4!=1);
	
	return logout;
}



int login()
{
	ShopItem *SI;
	
	int check;
	
	cout<<"-LOGIN-"<<endl;
	cin.ignore();
	
	do
	{
		check=SI->insertLogin();
	
		if(check==1)
		{
			cout<<"-------LOGIN SUCCESSFUL-------"<<endl<<endl;
		}
		else if(check==2)
		{
			cout<<"***WRONG PASSWORD***"<<endl<<endl;
		}
		else if(check==3)
		{
			cout<<"***WRONG ID***"<<endl<<endl;
		}
		else if(check==4)
		{
			cout<<"***WRONG ID & PASSWORD***"<<endl<<endl;
		}
	}
	while(check!=1);
	
	return check;
}

int owner()
{
	ShopItem *SI;
	
	int chooseShopOwner, logout=0, mainpage, check=0;
	
	do
	{
		SI->menuShopOwner();
			
		cout<<"Enter your choice : ";
		cin>>chooseShopOwner;
		cout<<endl;
			
		while(chooseShopOwner!=1 && chooseShopOwner!=2)
		{
			cout<<"***YOU HAVE ENTERED AN INVALID CHOICE***"<<endl<<endl;
			
			SI->menuShopOwner();
				
			cout<<"Enter your choice : ";
			cin>>chooseShopOwner;
			cout<<endl;
		}
		
		if(chooseShopOwner==1)//login
		{
			check=login();
			logout=menu();
		}
		else if(chooseShopOwner==2)
		{
			mainpage=1;
			logout=0;
		}
	}
	while(logout==1);
	
	return mainpage;
}
