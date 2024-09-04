#include<bits/stdc++.h>
using namespace std;

class BankAccount
{
    private:
        string f_name,l_name;
        long int accno;
        long long int balance;
    
    public:
        BankAccount(string f,string l,double b)
        {
            static int x=0;
            accno = 400000+x;
            f_name = f;
            l_name = l;
            balance = b;
            x++;
            cout<<"Account number is: "<<accno<<endl;
        }
        string getname()
        {
            return f_name+l_name;
        }
        int getaccno()
        {
            return accno;
        }
        double getbalance()
        {
            return balance;
        }
        void setbalance(int x)
        {
			balance=x;
        }
};
class Bankmanagement
{
    private:
        vector<BankAccount> accounts;
    public:
        void addaccount()
        {
        	string f_name,l_name;
            double bal;
            cout<<"enter first name: ";
            cin>>f_name;
            cout<<"enter last name: ";
            cin>>l_name;
            cout<<"enter initial balance: ";
            cin>>bal;
            accounts.push_back(BankAccount(f_name,l_name,bal));
            cout<<"Congratulations Account is Created"<<endl;
        } 
        void balanceenquiry()
        {
        	long int x;
        	string y;
        	int z=0;
        	cout<<"Enter the Account Number: ";
        	cin>>x;
        	cout<<"Enter the Account Holder Name: ";
        	cin>>y;
        	for(int i=0;i<accounts.size();i++)
            {
                if((accounts[i].getaccno()==x)&&(accounts[i].getname()==y))
                {
                	cout<<"Balance: "<<accounts[i].getbalance()<<endl;
                	z++;
				}
            }
            if(z==0)
			{
				cout<<"Invalid Details, Try Again!"<<endl;
			}
		}
		void deposit()
		{
			long int x,b;
        	string y;
        	int a,z=0;
        	cout<<"Enter the Account Number: ";
        	cin>>x;
        	cout<<"Enter the Account Holder Name: ";
        	cin>>y;
        	cout<<"Enter Amount to be Deposited: ";
        	cin>>a;
        	for(int i=0;i<accounts.size();i++)
            {
                if((accounts[i].getaccno()==x)&&(accounts[i].getname()==y))
                {
                	b=accounts[i].getbalance()+a;
                	accounts[i].setbalance(b);
                	cout<<"Amount Deposited Successfully"<<endl;
                	z++;
				}
            }
            if(z==0)
			{
				cout<<"Invalid Details, Try Again!"<<endl;
			}
		}
		void withdraw()
		{
			long int x,b;
        	string y;
        	int a,z=0;
        	cout<<"Enter the Account Number: ";
        	cin>>x;
        	cout<<"Enter the Account Holder Name: ";
        	cin>>y;
        	cout<<"Enter Amount to be Credited: ";
        	cin>>a;
        	for(int i=0;i<accounts.size();i++)
            {
                if((accounts[i].getaccno()==x)&&(accounts[i].getname()==y))
                {
                	if(accounts[i].getbalance()>=a)
                	{
                		b=accounts[i].getbalance()-a;
                		accounts[i].setbalance(b);
					}
                	z++;
				}
            }
            if(z==0)
			{
				cout<<"Invalid Details, Try Again!"<<endl;
			}
		}
		void close()
		{
			long int x;
        	string y;
        	int z=0;
        	cout<<"Enter the Account Number: ";
        	cin>>x;
        	cout<<"Enter the Account Holder Name: ";
        	cin>>y;
        	for(int i=0;i<accounts.size();i++)
            {
                if((accounts[i].getaccno()==x)&&(accounts[i].getname()==y))
                {
                	accounts.erase(accounts.begin() + i);
           			cout << "Account deleted successfully" << endl;
					z++;
				}
            }
            if(z==0)
			{
				cout<<"Invalid Details, Try Again!"<<endl;
			}
		}
		void showall()
        {
            cout<<"All Account Details "<<endl;
            for(int i=0;i<accounts.size();i++)
            {
                cout<<"Account no.:"<<accounts[i].getaccno()<<" Name: "<<accounts[i].getname()<<" Balance: "<<accounts[i].getbalance()<<endl;
            }
        }
};

int main()
{
    Bankmanagement bank;
    int x;
    while(1){
        
        cout<<"Bank Management System"<<endl;
        cout<<"\tSelect an Option"<<endl;
        cout<<"\t 1. Open an Account"<<endl;
        cout<<"\t 2. Balance Enquiry"<<endl;
        cout<<"\t 3. Deposit"<<endl;
        cout<<"\t 4. Withdrawal"<<endl;
        cout<<"\t 5. Close an Account"<<endl;
        cout<<"\t 6. Show all Accounts"<<endl;
        cout<<"\t 7. Quit"<<endl;
        cout<<"Enter your Choice"<<endl;
        cin>>x;
        switch(x)
        {
            case 1:
            {
                bank.addaccount();
                break;
            }
            case 2:
            {
                bank.balanceenquiry();
                break;
            }
            case 3:
            {
            	bank.deposit();	
            	break;
			}
			case 4:
            {
            	bank.withdraw();	
            	break;
			}
			case 5:
            {
            	bank.close();	
            	break;
			}
            case 6:
            {
                bank.showall();
                break;
            }
            case 7:
            {
            	return 0;
			}
        }
    }
};
