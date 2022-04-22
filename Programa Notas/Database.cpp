
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//Insert Function
void Insert(ofstream & write){
	
	int id;
	string name;
	float grade1;

	write.open("Database.txt",ios::out|ios::app);
	if(write.is_open()){
	cout<<"Enter the ID: ";
	cin>>id;
	cout<<"Enter the first name: ";
	cin>>name;
	cout<<"Enter grade: ";
	cin>>grade1;
	write<<id<<" "<<name<<" "<<grade1<<"\n";
	write.close();
	}else{
		cout<<"Error while opening the file."<<endl;
	}
}

//General Consult Function
void general_consult(ifstream & read){
	
	string id, name,grade1;
	
	read.open("Database.txt", ios::in);
	if(read.is_open()){
	cout<<"\n--------------General Consult--------------"<<endl;
	read>>id;
	while (!read.eof()){
		read>>name;
		read>>grade1;
		cout<<"ID --------> "<<id<<endl;
		cout<<"Name ------> "<<name<<endl;
		cout<<"Grade 1 ---> "<<grade1<<endl;
		cout<<"-----------------------------------"<<endl;
		read>>id;
	}
	read.close();
	}else{
		cout<<"Error while opening the file."<<endl;
	}
}

//Consult by ID Function
void consult_by_id(ifstream & read){
	
	string id, aux_id, name, grade1;
	bool find = false;
	
	read.open("Database.txt", ios::in);
	if(read.is_open()){
			cout<<"\nEnter the ID for search: ";
	cin>>aux_id;
	
	read>>id;
	while(!read.eof() && !find){
		read>>name;
		read>>grade1;
		
		if(id == aux_id){
	    cout<<"\n-----------------------------------"<<endl;	
		cout<<"ID --------> "<<id<<endl;
		cout<<"Name ------> "<<name<<endl;
		cout<<"Grade 1 ---> "<<grade1<<endl;
		cout<<"-----------------------------------"<<endl;
		find = true;
		}
		read>>id;
	}
	read.close();
	if(!find){
		cout<<"ID not found"<<endl;
	}
	}else{
		cout<<"\nError while opening the file."<<endl;
	}
}

//Modify Function
void modify(ifstream & read){
	
	string id, aux_id, name, grade1, aux_grade1;
	int op = 0;

	read.open("Database.txt", ios::in);
	ofstream override ("Database2.txt", ios::out);
	
	cout<<"\nType 1 to modify Grade.";
	cout<<"\n\nEnter your choice here: ";
	cin>>op;
	
			if (read.is_open()){

				cout<<"\nEnter a valid ID: ";
		    	cin>>aux_id;
		    	
		        read>>id;
		        while(!read.eof()){
	                read>>name;
		            read>>grade1;
		    	        if(id == aux_id){
		    		        cout<<"\nType a new Grade 1: ";
		    		        cin>>aux_grade1;
		    	        	override<<aux_id<<" "<<name<<" "<<aux_grade1<<" "<<endl;
				    	}else{
					        override<<id<<" "<<name<<" "<<grade1<<" "<<endl;
				    	}   
		    		read>>id;
			    }
				read.close();	
				override.close();
				remove("Database.txt");
				rename("Database2","Database.txt");

			}else{
				cout<<"\nError while opening the file."<<endl;
			}
	
	}

//Delete Function
void delete_row(ifstream & read){
	
	string id, aux_id, name, grade1, aux_grade1;
	int op = 0;
	
	read.open("Database.txt", ios::in);
	ofstream override ("Database2.txt", ios::out);
	
	cout<<"\nType 1 to modify Grade.";
	cout<<"\nType 2 to cancel.";
	cout<<"\n\nEnter your choice here: ";
	cin>>op;
	
	do{

			if (read.is_open()){

				cout<<"\nEnter a valid ID: ";
		    	cin>>aux_id;
		    	
		        read>>id;
		        while(!read.eof()){
	                read>>name;
		            read>>grade1;
		    	        if(id == aux_id){
		    		        cout<<"\nDeleted.";
				    	}else{
					        override<<id<<" "<<name<<" "<<grade1<<" "<<endl;
				    	}   
		    		read>>id;
			    }
				read.close();	
				override.close();
				remove("Database.txt");
				rename("Database2","Database.txt");

			}else{
				cout<<"\nError while opening the file."<<endl;
			}

        }while(op != 2);

}

//Main function
int main(){
	
	ofstream write;
	ifstream read;
	int op = 0;
	
	do{
		cout<<"\n\n------Database------";
		cout<<"\n\n1: Insert."<<endl<<"2: Modify."<<endl<<"3: Delete."<<endl<<"4: Consult by ID."<<endl<<"5: General Consult."<<endl<<"6: Exit.";
		cout<<"\n\n------Database------";
		cout<<"\n\nEnter your choice here: ";
		cin>>op;
		
		switch(op){
			
			case 1:
				Insert(write);
			break;
			
			case 2:
				modify(read);
			break;
			
			case 3:
				delete_row(read);
			break;
			
			case 4:
				consult_by_id(read);
			break;
			
			case 5:
				general_consult(read);
			break;
			
			default: cout<<"\nPlease enter a valid option.";	
		}
		
	}while(op != 6);
	
	return 0;
}
