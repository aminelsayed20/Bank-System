#include <bits/stdc++.h>

/////
#define fast         ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define  ll          long long
#define  endl        '\n'
#define  loop(n)     for(int i=0; i<n; ++i)
#define  loop2(n)    for(int j=0; j<n; ++j)
#define  rloop(n)    for(int i=n ; i>0 ;--i)
#define  trav(a,b)   for(auto &a:b)
#define  brec(n)     fixed<<setprecision(n)
////
using namespace std;

/// struct

struct Name
{
    string FirstName;
    string SecondName;
    string LastName;

};
struct Address
{
   string City;
   int StreetNum;

};
struct Employees
{
    Name name;
    Address address;
    long long ID;
    float salary;

};
// database
const int N=1e5;
 Employees structure[N];
 int i=1; // index

 //// functions
void  TakeDatabase (int idx);

void menu ();

void OutputDatabase();

void FindEmployee (int idx);

void edit (int idx , int n);

int main()
{
    //fast
	//freopen("consistency_chapter_1_input.txt", "r", stdin);
    //freopen("database.txt", "w", stdout);

     int InitialValue = 1; ///You can change the initial value
    for  ( ; i<=InitialValue ; ++i)
    {
        TakeDatabase(i);
    }


    /// menu for user

    int num;

    do
    {
        menu();
        cin >> num;
       system("CLS");
        switch(num)
        {
        case 1:
            {
                TakeDatabase(i++);
                break;
            }
        case 2:
            {
               OutputDatabase();
               break;
            }
        case 3:
            {
                point:
                cout << "enter the number of employee : ";
                int idx;
                cin >>idx;
                FindEmployee(idx);
                cout << "\n\npress (1) if you want edit the name"<<endl;
                cout << "press (2) if you want edit the address"<<endl;
                cout << "press (3) if you want edit the ID"<<endl;
                cout << "press (4) if you want edit the salary"<<endl;
                int n;
                cin >> n;
                 edit(idx, n);
                 cout << "\nData has been updated successfully"<<endl;
                 cout << "if you want edit more data press (1)"<<endl;
                 cout << "for the main menu press (0)"<<endl;
                 cin >> n;
                 system("CLS");
                 if (n==1) goto point;
                  else
                        break;

            }
        case 4:
            {

            cout << "enter the first name : ";
                string name;
                cin >> name;
                bool fond = false;
                for (int j=1 ; j<i ;++j)
                {
                    if (name == structure[j].name.FirstName)
                         FindEmployee(j),fond = true;
                }
                 if (!fond)
                        cout <<"No data found\n";
                break;
            }
        case 5:
            {
                bool fond = false;
                    for (int j=1 ; j<i ;++j)
                {
                    if (structure[j].salary > 1000)
                            FindEmployee(j),fond = true;

                }
                 if (!fond)
                        cout <<"No data found\n";
                break;
            }
        case 6:
            {
                    bool fond = false;
                    for (int j=1 ; j<i ;++j)
                {
                    if (structure[j].salary == 500)
                            FindEmployee(j),fond = true;

                }
                 if (!fond)
                        cout <<"No data found\n";
                break;
            }
        case 7:
            {
                cout <<"enter Id : ";
                long long  id;
                cin >> id;
                            bool fond = false;
                    for (int j=1 ; j<i ;++j)
                {
                    if (structure[j].ID == id)
                            FindEmployee(j),fond = true;

                }
                 if (!fond)
                        cout <<"No data found\n";
                break;
            }
        case 8:
            {
                    cout << "enter the name of city : ";
                string city;
                cin >> city;
                bool fond = false;
                for (int j=1 ; j<i ;++j)
                {
                    if (city == structure[j].address.City)
                         FindEmployee(j),fond = true;
                }
                 if (!fond)
                        cout <<"No data found\n";
                break;
            }
        case 9:
            {
                cout << "Thank you for using the program\n";
                return 0;
            }
        default :
               cout <<"Please choose a correct choice"<<endl;

            }

        }
         while(1);


    return 0;
}



 //// functions
void  TakeDatabase (int idx)
{
    cout << "Enter the full name of employee " << idx <<endl;
        cout <<"enter the first name : ";
        cin >> structure[idx].name.FirstName;
        cout << "enter the second name : ";
         cin >> structure[idx].name.SecondName;
         cout << "enter the last name : ";
         cin >>structure[idx].name.LastName;
        cout << "\nEnter the address of employee " << idx <<endl;
        cout <<"enter the name of city : ";
        cin >> structure[idx].address.City;
        cout << "enter the number of street : ";
        cin >> structure[idx].address.StreetNum;
        cout << "\nEnter the ID of employee " << idx << " : ";
        cin >> structure[idx].ID;
         cout << "\nEnter the salary of employee " << idx <<" : ";
         cin >> structure[idx].salary;
         cout <<endl <<endl <<endl;

}
void menu ()
{
            cout <<"\t\t menu\n\n";
        cout << "press (1) to fill data of database"<<endl;
        cout << "press (2) to output data in the database"<<endl;
        cout << "press (3) to edit data for employees"<<endl;
        cout << "press (4) to search on employee by first name"<<endl;
        cout << "press (5) to search on employee with salary greater than 1000 L.E"<<endl;
        cout << "press (6) to search on employee that take 500 L.E"<<endl;
        cout << "press (7) to search on employee by ID"<<endl;
        cout << "press (8) to search on employee who lives in \"Maadi\" city"<<endl;
        cout << "press (9) to exit"<<endl;

}
void OutputDatabase()
{
    cout <<"\n the data for employees\n";
    cout << "you have ("<<i-1<<") employee\n\n\n";
    for (int j=1 ; j<i ; ++j)
    {
        cout << "the data for employee "<<j<<endl;
        cout << "Name : "<<structure[j].name.FirstName<<" "<<structure[j].name.SecondName <<" " <<structure[j].name.LastName<<endl;
        cout <<"Address : \n"<<"city : "<<structure[j].address.City<<"\nnumper of street : "<<structure[j].address.StreetNum<<endl;
        cout << "ID : "<<structure[j].ID<<endl;
        cout << "salary : "<< structure[j].salary;
        cout <<endl <<endl;

    }
}
void FindEmployee (int idx)
{
        cout << "the data for employee "<<idx<<endl;
        cout << "Name : "<<structure[idx].name.FirstName<<" "<<structure[idx].name.SecondName <<" " <<structure[idx].name.LastName<<endl;
        cout <<"Address : \n"<<"city : "<<structure[idx].address.City<<"\nnumper of street : "<<structure[idx].address.StreetNum<<endl;
        cout << "ID : "<<structure[idx].ID<<endl;
        cout << "salary : "<< structure[idx].salary;
        cout <<endl <<endl;
}
void edit (int idx , int n)
{
    switch(n)
{

  case 1:
    {
        cout << "enter the new name : ";
       cin >> structure[idx].name.FirstName >> structure[idx].name.SecondName >> structure[idx].name.LastName;
       break;
    }
  case 2:
    {
        cout << "enter the new city : ";
        cin >> structure[idx].address.City;
        cout << "\nenter new number for street : ";
        cin >> structure[idx].address.StreetNum;
        break;
    }
  case 3:
    {
        cout << "enter thee new ID : ";
        cin >> structure[idx].ID;
       break;
    }
  case 4:
    {
        cout << "enter the new salary : ";
        cin >> structure[idx].salary;
    }
}
}
