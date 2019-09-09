#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>

using namespace std;


 class hotel
{
			protected:
			int nk,ns,nv,total,paid;
			char name[25];
			char date[10];
      
			public:

			void getdata(char *d)
			{
				cout << "Please enter your name : ";
				cin >> name;
				cout << "\n\n";
				cout << "The items available are : \n";

				cout<< "KACHORI \t\t:\tRs.12\n";

				cout<< "SAMOSA  \t\t:\tRs.12\n";

				cout<< "VADAPAV \t\t:\tRs.15\n\n";

				cout << "Enter the number of items you like...\n";

				cout<< "KACHORI \t";
				cin >> nk;

				cout<< "SAMOSA  \t";
				cin >> ns;

				cout<< "VADAPAV \t";
				cin >> nv;

				total = nk * 12 + ns * 12 + nv * 15;
				paid = 0;
				strcpy(date,d);

				cout << endl;
			}




          
			void display()
			{
				cout << "The current order is of : " << name << "  on " << date<<"\n\n";

				cout << "KACHORI \t: " <<nk<<endl;

				cout << "SAMOSA  \t: " <<ns<<endl;

				cout << "VADAPAV \t: " <<nv<<"\n\n";
				
				cout << "The TOTAL is : " << total << "\n\n";
				
				
			}
       };
       
       class billing:public hotel
       {
       		public:
       	   void AddRecord(char * d)
          {

				fstream f;
				hotel h;

				f.open("Details.txt",ios::app|ios::binary);

				h.getdata(d);

				f.write( (char *) &h, sizeof(h) );

				f.close();
				h.display();

   	      }	
   	      
           void putdata()
          {

              cout<<"\n\t"<<date<<"\t\t"<<name<<"\t\t"<<nk<<"\t\t"<<ns<<"\t\t"<<nv<<"\t\t"<<total << "\t\t" << paid<<"\n";
          }
   	      
          void Display_complete()
          {

		          fstream f;
		          billing h;

		          f.open("Details.txt",ios::in|ios::binary);

		          cout<<"\n\tDATE\t\tNAME\t\tKACHORI\t\tSAMOSA\t\tVADAPAV\t\tTOTAL\t\tPAID\n";

		          while( (f.read((char*)&h,sizeof(h))) && f)
		          		h.putdata();

		          f.close();
         }
         
         void generate(char naam[],char datee[])
          {
				 
		          fstream f;
		          billing h;

		          f.open("Details.txt",ios::in|ios::binary);

		          

		          while( (f.read((char*)&h,sizeof(h))) && f)
		          {
		          		if(!strcmp(h.name,naam))
		          		{
		      
		          				h.display();
		          		}
		 	
	          	
		          }

		          f.close();
         }
         
         void payment(char naam[],char datee[])
         {
           		  fstream f;
		          billing h;
		          int amt = 0;
				  int nt = 0,np = 0;
		          f.open("Details.txt",ios::in|ios::binary);

		          

		          while( (f.read((char*)&h,sizeof(h))) && f)
		          {
		          		if(!strcmp(h.name,naam)) 
		          		{
							h.display();
							cout << "The amount paid is : " << h.paid << endl << endl;
		          		}	
		          		
		          		if(!strcmp(h.name,naam))
		          		{
		          			nt = nt + h.total;
		          			np = np + h.paid;
		          		}
	          			
	          	
		          }
		          cout << "\nThe total amount to be paid is : " << (nt-np) << endl;

		          f.close();
		          cout << "\nEnter the amount payed : ";
				  cin >> amt;
				  
				fstream f1;
				billing h1;
				strcpy(h1.name,naam);
				strcpy(h1.date,datee);
				h1.nk = 0;
				h1.ns = 0;
				h1.nv = 0;
				h1.total = 0;
				h1.paid = amt;
				f1.open("Details.txt",ios::app|ios::binary);

				f1.write( (char *) &h1, sizeof(h1) );

				f1.close();
				  
         }
       };
       
       

       int main()
       {
			char datee[25];
			int opt;
			billing h;
			
            cout << "Enter the date(dd/mm/yy) : \t";
			cin >> 	datee;
			cout << "\n";
	
	
	
		for(;;)
		{
	
	
			cout << "\n\nEnter \n1.TO ORDER\n2.TO GET BILL\n3.TO CHECK ALL RECORDS\n4.ACCEPT PAYMENT\n5.EXIT\n";
			cin >> opt;
	
	
			switch(opt)
			{
				case 1:	h.AddRecord(datee);
						break;
					
				case 2:	char n[25];
						cout << "\nEnter the name of the person whose bill to be generated  :   ";
						cin >> n;
						h.generate(n,datee);
						break;
			
			
				case 3:	h.Display_complete();
						break;
						
						
				case 4:	char n1[25];
						cout << "\nEnter the name of the person who is paying the bill :   ";
						cin >> n1;
						h.payment(n1,datee);
						
						
						break;
						
				case 5: exit(0);
						
					
			}
		}
		return 0;

                  
}


