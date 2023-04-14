/**********|**********|**********|
Program: TC02.1181203267.LIM.JIA.MIN.cpp | TC02.1181203295.LEE.XIN.CHEN.cppw
Course: Object Oriented Programming
Year: 2020/21 Trimester 1
Name: Lim Jia Min | Lee Xin Chen
ID: 1181203267 | 1181203295
Lecture Section: TC02
Tutorial Section: TT04
Email: 1181203267@student.mmu.edu.my | 1181203295@student.mmu.edu.my
Phone: 016-3738920 | 010-4238038
**********|**********|**********/

#include <iostream>
#include "TC02.1181203267.LIM.JIA.MIN.cpp"
#include "TC02.1181203295.LEE.XIN.CHEN.cpp"

using namespace std;

class KIOSK
{
	public:
		KIOSK()
		{	
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl;
			cout<<"+             WELCOME TO MMU SHOPPING KIOSK             +" <<endl;
			cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++" <<endl<<endl;
		}
};

int main()
{
	int a;
	int mp;
	
	do
	{
		KIOSK K;
		
		cout<<"[1] Shopper" <<endl;
		cout<<"[2] Shop Owner"<<endl;
		cout<<"[3] Exit Program"<<endl<<endl;
		cout<<"Enter your choice : ";
		cin>>a;
		cout<<endl;
		
		while(a!=1 && a!=2 && a!=3)
		{
			cout<<">>INVALID CHOICE. PLEASE ENTER AGAIN.<<"<<endl<<endl;
			
			KIOSK K;
		
			cout<<endl;
			cout<<"[1] Shopper" <<endl;
			cout<<"[2] Shop Owner"<<endl;
			cout<<"[3] Exit Program"<<endl<<endl;
			cout<<"Enter your choice : ";
			cin>>a;
			cout<<endl;
		}
	
		if(a==1) //SHOPPER
		{
			mp=shopper(); //mp=1
			cout<<endl; 
		}
		if(a==2) //Shop_Owner
		{
			cin.ignore();
			mp=owner();//mp=1
		}
		if(a==3) //exit
		{
			cout<<"Thank you for using this program."<<endl;
			return 0;
		}
	}
	while(mp==1);
} 
