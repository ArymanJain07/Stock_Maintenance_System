#include<iostream>
#include<fstream>
#include<String>
using namespace std;

class shopping {
	
	private:
		int pcode;
		float price;
		float diss;
		string pname;
		
	public:
		void menu();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
		void administrator();
		void remove();
		
		
			
};

void shopping :: menu(){
	
	m:
	
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t\t_______________________________________________________\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t			 MAIN MENU      		\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t_______________________________________________________\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t| 			1) Administrator		|\n";
	cout<<"\t\t\t\t\t                                \n";
	cout<<"\t\t\t\t\t| 			2) Buyer 			|\n";
	cout<<"\t\t\t\t\t                                \n";
	cout<<"\t\t\t\t\t| 			3) Exit 			|\n";
	cout<<"\t\t\t\t\t_______________________________________________________\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t          Please Select            \n";
	
	cin>>choice;
	
	switch (choice){
		
		case 1:
			cout<<"\t\t\t\t\t   please login   \n  ";
			cout<<"\t\t\t\t\t   Enter Email:   \n  ";
			cin>>email;
			cout<<"\t\t\t\t\t   Password:      \n  ";
			cin>>password; 
			
			if (email=="arymanjain.03@gmail.com" && password == "aryman@123"){
				
				administrator();
				
			}
			else {
				
				cout<<"\t\t\t\t\t\t 	Invalid Email ID / password		\n";
				
			}
			break;
			
		
		case 2:
			{
				buyer();
			}
			
		case 3:
			{
				exit(0);
			}
			
		default :
			{
				cout<< "please select the given option";
				
			}
			
			
	}
		
	goto m;
	
}


void shopping :: administrator(){
	
	m: 
	
	int choice;
	
	cout<<"\t\t\t\t\t___________________________________\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t		 ADMINISTRATOR MENU    		\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t___________________________________\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t| 			1) Add the product		|\n";
	cout<<"\t\t\t\t\t                               	 \n";
	cout<<"\t\t\t\t\t| 			2) Modify the product	|\n";
	cout<<"\t\t\t\t\t                              	     \n";
	cout<<"\t\t\t\t\t| 			3) Delete the Product	|\n";
	cout<<"\t\t\t\t\t                                   \n";
	cout<<"\t\t\t\t\t| 			4) Back to main Menu	|\n";
	cout<<"\t\t\t\t\t___________________________________\n";
	cout<<"\t\t\t\t\t          Please Select            \n";
	
	cin>>choice; 
	
	switch(choice){
		
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			remove();
			break;
		case 4:
			menu();
			break;
		default :
			cout<<"Invalid choice!";
			
	}
	goto m;
}

void shopping :: buyer(){
	
	m:
		
	int choice;
	
	cout<<"\t\t\t\t\t	 Buyer				\n";
	cout<<"\t\t\t\t\t_______________		\n";
	cout<<"\t\t\t\t\t           			\n";
	cout<<"\t\t\t\t\t 	 1) Buy Product 	\n";
	cout<<"\t\t\t\t\t           			\n";
	cout<<"\t\t\t\t\t	 2) Go Back 		\n";
	cout<<"\t\t\t\t\t      			     	\n";
	cout<<"\t\t\t\t\t    Enter your choice  \n";

	cin>>choice;
	
	switch(choice){
		
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid Choice"	;
			
	
	}
	goto m;


}


void shopping :: add(){
	
	m:
		
	fstream data;
	
	int c;
	int token = 0 ;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\n\n\t\t 	Add new Product";
	cout<<"\n\n\n\t\t\t 	Product code of the product";
	cin>>pcode;
	cout<<"\n\n\n\t\t\t		Name of the Product ";
	cin>>pname;
	cout<<"\n\n\n\t\t\t		Price of the product ";
	cin>>price;
	cout<<"\n\n\n\t\t\t		Discount on product ";
	cin>>diss;
	
	data.open("database.txt",ios::in);
	
	if (!data){
		
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<diss<<"\n";
		data.close();
	}
	else {
		
		
		data>>c>>n>>p>>d;
		
		while(!data.eof()){
			
			if (c == pcode){
				
				token++;
				
			}
			
			data>>c>>n>>p>>d;
			
		}
		data.close();
		
		if (token==1){
			
			goto m;
		}
		else{
			
			data.open("database.txt", ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<diss<<"\n";
			data.close();
			
		}
		
	}
	
	cout<<"\n\n\t\t	Record inserted ";
	
}



void shopping :: edit(){
	
	fstream data, data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t Modify the record";
	cout<<"\n\n\t\t Product Code";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	
	if(!data){
		
		cout<<"\n\n\t\t	File doesn't exist! ";
	}
	else{
		
		data1.open("database1.txt", ios::app|ios::out);
		data>>pcode>>pname>>price>>diss;
		while(!data.eof()){
			
			if (pkey==pcode){
				cout<<"\n\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\n\t\t Name of the product:";
				cin>>n;
				cout<<"\n\n\t\t Price";
				cin>>p;
				cout<<"\n\n\t\t Disscount :";
				cin>>d;
				
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
				
			}
			else {
				
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<diss<<"\n";
				
			}
			data>>pcode>>pname>>price>>diss;
			
		}
		data.close();
		data1.close();
		
		//remove("database.txt");
		rename("database1.txt","database.txt");
		
		if (token==0){
			
			cout<<"\n\n record not found!";
			
			
		}
		
	}
	
}

void shopping::remove(){
	
	
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\n\n\t\t Delete product";
	cout<<"\n\n\n\n\t\t Product Code";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		
		cout<<"file dosent exist";
		
	}
	else{
		
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>diss;
		while (!data.eof()){
			if (pcode==pkey){
				cout<<"\n\n\n\t Product deleted succesfully ";
				token++;
				
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<diss<<"\n";
				
			}
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<diss<<"\n";
				
		}
		data.close();
		data1.close();
		//remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0){
			cout<<"\n\n\t record not found";
			
		}
		
	}
	
}


void shopping::list(){
	
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|____________________________________\n";
	cout<<"Pro NO \t\t Name \t price\n";
	cout<<"\n\n|_____________________________________\n";
	data>>pcode>>pname>>price>>diss;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>diss;
		
	}
	data.close();
	
}

void shopping::receipt(){
	
	fstream data ;
	
	int arrc[100];
	int arrq[100];
	string choice;
	int c=0;
	float amount=0 ;
	float diss=0;
	float total=0;
	
	cout<<"\n\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"\n\n Empty database ";
		
	}
	
	else {
		data.close();
		
		list();
		cout<<"\n\n_________________________________\n";
		cout<<"\n|                                   \n";
		cout<<"\n      please place the Order         \n";
		cout<<"\n|                                   \n";
		cout<<"\n\n_________________________________\n";
		
		do{
			
			m: 
			cout<<"\n\n Enter Product Code";
			cin>>arrc[c];
			cout<<"\n\n  Enetr the product quantity :";
			cin>>arrq[c];
			for(int i=0 ; i<c ; i++){
				if (arrc[c]==arrc[i]){
					cout<<"\n\n Duplicate product code, Please try again";
					goto m;
					
				}
				
			}
			c++;
			cout<<"\n\n do you want to buy another product ? if yes then press Y else N";
			cin>>choice;
			
		}while(choice== "y");
		
		cout<<"\n\n\n\t\t\t _____________________RECEIPT___________\n";
		cout<<"\nProduct No \t Product Name \t product quantity \t pricr\tAmount\tAmount with disscount";
		
		for (int i=0 ; i<c;i++){
			data.open("database.txt", ios::in);
			data>>pcode>>pname>>price>>diss;
			
			while(!data.eof()){
				if(pcode==arrc[i]){
					
					amount = price*arrq[i];
					diss=amount-(amount *diss/100);
					total= total+diss;
					cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<diss;
					
				}
				data>>pcode>>pname>>price>>diss;
				
			}
		}
		data.close();
		
	}
	
	cout<<"\n\n_______________________________________________________";
	cout<<"\n\nTotal Amount : "<<total;
	
	
}

int main(){

	shopping s;
	s.menu();
	

}
