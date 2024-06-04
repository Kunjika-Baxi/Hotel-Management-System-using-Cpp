#include<iostream>
#include<fstream>
using namespace std;
void charge();int cd=0,cs=0,ce=0,room;
class Hotel 
{
   public : 
   int tp,count=0,roomno;string name,cn,an;
   void get()
   {
      cout<<"\nEnter Guest Name : ";cin>>name;
      cout<<"\nEnter Contact Number : ";cin>>cn;
      cout<<"\nEnter Aadhar Card Number : ";cin>>an;
      cout<<"\nEnter Total Person to stay in the Hotel : ";cin>>tp;
      roomno=(rand()%50)+1;count++;
      charge();
   }
   void display()
   {
       cout<<"\n-------------------------------------\n";
       cout<<"\n\tDetails : ";
       cout<<"\nName : "<<name;
       cout<<"\nContact Number : "<<cn;
       cout<<"\nAadhar Card Number : "<<an;
       cout<<"\nRoom Number : "<<roomno;
       cout<<"\nTotal Person : "<<tp;
       cout<<"\n-------------------------------------\n";
   }
};
Hotel h;
void write()
{
    ofstream fout;
    fout.open("Hotel.dat",ios::app|ios::binary);
    h.get();
    fout.write((char*)&h,sizeof(h));
    fout.close();
    cout<<"\nData Added Successfully...";
}
void read()
{
    ifstream fin;
    fin.open("Hotel.dat",ios::in|ios::binary);
    while(fin.read((char*)&h,sizeof(h)))
    {
        h.display();
    }
    fin.close();
}
void charge()
{
    int night;float charge,total,amt;char ans;
    cout<<"\nEnter Type of Room : \n1.Deluxe Room\n2.Standard Room\n3.Executive Room";cout<<"\nEnter Choice : ";
    cin>>room;
    if(room==1)
    {
         charge = 2200;cd++;
         cout<<"\nEnter Total Nights of Stay : ";cin>>night;
         cout<<"\nIs Meal Included ? (y/n) : ";cin>>ans;
         if(ans=='y')
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nMeal : 700/-";
         amt=total+(700*night);
         cout<<"\nTotal : "<<amt;
         cout<<"\nThank You!!! Please Visit Again\n";
         }
         else 
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nTotal : "<<total;
         cout<<"\nThank You!!! Please Visit Again\n";
         }

    }
    else if(room==2)
    {
        charge = 3500;cs++;
         cout<<"\nEnter Total Nights of Stay : ";cin>>night;
         cout<<"\nIs Meal Included ? (y/n) : ";cin>>ans;
         if(ans=='y')
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nMeal : 100/-";
         amt=total+(100*night);
         cout<<"\nTotal : "<<amt;
         cout<<"\nThank You!!! Please Visit Again\n";
         }
         else 
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nTotal : "<<total;
         cout<<"\nThank You!!! Please Visit Again\n";
         }
    }
    else
    {
        charge = 5000;ce++;
         cout<<"\nEnter Total Nights of Stay : ";cin>>night;
         cout<<"\nIs Meal Included ? (y/n) : ";cin>>ans;
         if(ans=='y')
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nMeal : 700/-";
         amt=total+(1250*night);
         cout<<"\nTotal : "<<amt;
         cout<<"\nThank You!!! Please Visit Again\n";
         }
         else 
         {
         cout<<"\nTotal Charge : "<<(night*charge);
         cout<<"\nGST : 18 PERCENT ";
         total=(night*charge)+(0.18*night*charge);
         cout<<"\nTotal : "<<total;
         cout<<"\nThank You!!! Please Visit Again\n";
         }
    }
}
void search_specificname()
{
    fstream fin;
    int flag=0;string gname;
    fin.open("Hotel.dat",ios::in|ios::binary);
    cout<<"\nEnter the Name of the Guest whose Details you want to search : ";
    cin>>gname;
    while(fin.read((char*)&h,sizeof(h)))
    {
        if(h.name.compare(gname)==0)
        {
            flag=1;
            cout<<"\nRecord Found";
            h.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    fin.close();
}
void search_specificrn()
{
    fstream fin;
    int flag=0, rn;
    fin.open("Hotel.dat",ios::in|ios::binary);
    cout<<"\nEnter the Room Number for Details : ";
    cin>>rn;
    while(fin.read((char*)&h,sizeof(h)))
    {
        if(h.roomno==rn)
        {
            flag=1;
            cout<<"\nRecord Found";
            h.display();
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord Not Found !!!";
    }
    fin.close();
}
void delete_specific()
{
    int fl=0,rng;string gname;
    fstream f;
    f.open("Hotel.dat",ios::in|ios::binary);
    ofstream fout;
    fout.open("new.dat",ios::app|ios::binary);
    cout<<"\nEnter Name of Guest : ";
    cin>>gname;
    cout<<"\nEnter Type of Room in which Guest Stayed : (1-Deluxe , 2-Standard , 3-Executive): ";cin>>rng;
    while(f.read((char*)&h,sizeof(h)))
    {
        if(h.name.compare(gname)!=0)
        {
           if(rng==1)
           cd--;
           else if(rng==2)
           cs--;
           else
           ce--;

            fout.write((char*)&h,sizeof(h));
        }
        else{
            fl=1;
        }
    }
    f.close();
    fout.close();
    remove("Hotel.dat");
    rename("new.dat","hotel.dat");
    cout<<"\nSuccessful";

}
void count()
{
    cout<<"\nTotal Rooms in Hotel : 50";
    cout<<"\nTotal Available Rooms in Hotel : "<<(50-h.count);
    cout<<"\nAvailability of Deluxe Room : "<<(25-cd);
    cout<<"\nAvailability of Standard Room : "<<(15-cs);
    cout<<"\nAvailability of Executive Room : "<<(10-ce)<<"\n";
}
int main()
{
    int ch;
    remove("Hotel.dat");
    cout<<"\n\t----------Hotel Taj Palace----------";
    while(1)
    {
        cout<<"\nEnter : \n1.Enter Guest Details\n2.Display Details of All the Guests\n3.Search for Specific Guests using Name\n4.Search for Specific Guests using Room Number\n5.Delete the Details of Specific Guests\n6.Display Total Available Rooms in Hotel\n7.EXIT";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:write();break;
            case 2:read();break;
            case 3:search_specificname();break;
            case 4:search_specificrn();break;
            case 5:delete_specific();break;
            case 6:count();break; 
            case 7:exit(0);break;   
            default:cout<<"\nInvalid Choice";
        }
    }
}