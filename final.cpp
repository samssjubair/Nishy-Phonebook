#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void MiddlePrint(string str)
{
    cout << "\t\t\t\t" << str << "\n\n";
}

class PerInf
{
    string Name, Mnumber, Address, Fname, Mname, Email,blood;

public:
    perInf() {}

    void GetInf()
    {
        cout << "Name: ";
        getline(cin, Name);

        while(true)
        {
            cout << "Number: ";
            getline(cin, Mnumber);
            bool right = true;

            for(int i = 0; i < Mnumber.size(); i++)
                if(!isdigit(Mnumber[i]))
                {
                    right = false;
                    break;
                }

            if(right && Mnumber.size())
                break;

            else
                cout << "The number is not valid!\n";
        }

        cout << "Address: ";
        getline(cin, Address);
        cout << "Father's name: ";
        getline(cin, Fname);
        cout << "Mother's name: ";
        getline(cin, Mname);
        cout<<("Blood Group: ");
        getline(cin,blood);

        while(true)
        {
            cout << "E-mail: ";
            getline(cin, Email);
            bool right = false;

            for(int i = 0; i < Email.size(); i++)
                if(Email[i] == '@')
                {
                    right = true;
                    break;
                }

            if(right && Email.size())
                break;

            else
                cout << "Not a valid Email!\n";
        }
    }

    void fGetInf(ifstream &fin)
    {
        getline(fin, Name);
        getline(fin, Mnumber);
        getline(fin, Address);
        getline(fin, Fname);
        getline(fin, Mname);
        getline(fin, Email);
        getline(fin,blood);
    }

    void ShowInf()
    {
        cout << "Name: " << Name << endl;
        cout << "Number: " << Mnumber << endl;
        cout << "Address: " << Address << endl;
        cout << "Father's name: " << Fname << endl;
        cout << "Mother's name: " << Mname << endl;
        cout << "E-mail: " << Email << endl;
        cout<< "Blood Group: "<<blood<<endl;
    }

    void fShowInf(ofstream &fout)
    {
        fout << Name << endl;
        fout << Mnumber << endl;
        fout << Address << endl;
        fout << Fname << endl;
        fout << Mname << endl;
        fout << Email << endl;
        fout<<blood<<endl;
    }

    bool SrchNamePat(string Sname)
    {
        size_t found = Name.find(Sname);
        return found != string :: npos ? true : false;
    }

    bool SrchBloodPat(string Sblood)
    {
        size_t found = blood.find(Sblood);
        return found != string :: npos ? true : false;
    }

    bool SrchNumPat(string Snum)
    {
        size_t found = Mnumber.find(Snum);
        return found != string :: npos ? true : false;
    }

    string GetName()
    {
        return Name;
    }

    bool operator < (PerInf tmp)
    {
        return Name < tmp.Name;
    }

};

class PhoneBook
{
    vector <PerInf> Memory;
    string Dfname;

    bool MemoryCheck()
    {
        if(Memory.size())
            return true;

        cout << "Phonebook is empty!\n\n";
        return false;
    }

public:
    PhoneBook() {}

    PhoneBook(string fname)
    {
        Dfname = fname;
        ifstream fin(Dfname.c_str());
        int N;
        fin >> N;
        fin.ignore();

        for(int i = 0; i < N; i++)
        {
            PerInf tmp;
            tmp.fGetInf(fin);
            Memory.push_back(tmp);
        }
    }

    ~PhoneBook()
    {
        ofstream fout(Dfname.c_str());
        fout << Memory.size() << endl;

        for(int i = 0; i < Memory.size(); i++)
            Memory[i].fShowInf(fout);
    }

    void Add()
    {
        PerInf tmp;
        system("cls");
        MiddlePrint("ENTER INFORMATION");
        tmp.GetInf();
        Memory.push_back(tmp);
        sort(Memory.begin(), Memory.end());
        cout << "\nAdded successfully\n";
    }

    void Modify()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("MODIFY");
        string Mname;
        cout << "Enter name: ";
        getline(cin, Mname);

        for(int i = 0; i < Memory.size(); i++)
        {
            if(Memory[i].GetName() == Mname)
            {
                Memory[i].GetInf();
                sort(Memory.begin(), Memory.end());
                cout << "\nModified successfully\n";
                return;
            }
        }

        cout << "\nContact not found\n";
    }

    void Delete()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("DELETE");
        string Dname;
        cout << "Enter Name: ";
        getline(cin, Dname);

        for(int i = 0; i < Memory.size(); i++)
        {
            if(Memory[i].GetName() == Dname)
            {
                Memory.erase(Memory.begin() + i);
                sort(Memory.begin(), Memory.end());
                cout << "\nDeleted successfully\n";
                return;
            }
        }

        cout << "\nContact not found\n";
    }

    void SearchByName()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("SEARCH BY NAME");
        string Sname;
        cout << "Enter Name: ";
        getline(cin, Sname);
        int Number = 0;

        for(int i = 0; i < Memory.size(); i++)
        {
            if(Memory[i].SrchNamePat(Sname))
            {
                cout << endl << ++Number << ".\n";
                Memory[i].ShowInf();
            }
        }

        if(!Number)
            cout << "No such contact exists\n";

        else
            cout << "\nSearch has been completed\n";
    }

    void SearchByBlood()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("SEARCH FOR BLOOD");
        string Sblood;
        cout << "Enter Blood Group: ";
        getline(cin, Sblood);
        int Number = 0;

        for(int i = 0; i < Memory.size(); i++)
        {
            if(Memory[i].SrchBloodPat(Sblood))
            {
                cout << endl << ++Number << ".\n";
                Memory[i].ShowInf();
            }
        }

        if(!Number)
            cout << "No contact with this blood group exists\n";

        else
            cout << "\nSearch has been completed\n";
    }

    void SearchByNumber()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("SEARCH BY NUMBER");
        string Snum;
        cout << "Enter Number: ";
        getline(cin, Snum);
        int Number = 0;

        for(int i = 0; i < Memory.size(); i++)
        {
            if(Memory[i].SrchNumPat(Snum))
            {
                cout << endl << ++Number << ".\n";
                Memory[i].ShowInf();
            }
        }

        if(!Number)
            cout << "No such contact exists\n";

        else
            cout << "\nSearch has been completed\n";
    }

    void ShowAll()
    {
        system("cls");

        if(!MemoryCheck())
            return;

        MiddlePrint("ALL CONTACTS");
        bool space = false;

        for(int i = 0; i < Memory.size(); i++)
        {
            if(space)
                cout << "\n";

            space = true;
            cout << i + 1 << ".\n";
            Memory[i].ShowInf();
        }

        cout << "\nAll contacts has been displayed\n";
    }
};

int Menu()
{
    system("cls");
    int choice;
    MiddlePrint("WELCOME TO DYNAMIC PHONEBOOK");
    cout << "1. Add a contact.\t2. Modify a contact.\t3. Delete a contact.\n";
    cout << "4. Search by name.\t5. Search by number.\t6. Show all contacts.\n";
    cout<<"7. Search for blood.\n\n\n";
    cout << "8. Exit.\n\n[Caution: For saving information \"Exit\" by exit option.]\n\n";
    cout << "Enter your choice: ";

    while(true)
    {
        cin >> choice;

        if(choice > 0 && choice < 9)
            return choice;

        else
        {
            cout << "Enter a valid key\n";
            continue;
        }
    }
}

void pause()
{
    cout << "Enter a key to continue...\n";
    cin.get();
}

int main()
{
    PhoneBook MyPhnBook("Data.txt");

    while(true)
    {
        int choice = Menu();
        cin.ignore();

        if(choice == 8){
            system("cls");
            cout<<"\nThanks for using Dynamic Phonebook."<<endl;
            cout<<"Donate Blood ,Save Life :)"<<endl;
            cout<<"\n\n[Developed by Samss Jubair,MBSTU]"<<endl;
            break;
        }

        switch(choice)
        {
        case 1:
            MyPhnBook.Add();
            break;

        case 2:
            MyPhnBook.Modify();
            break;

        case 3:
            MyPhnBook.Delete();
            break;

        case 4:
            MyPhnBook.SearchByName();
            break;

        case 5:
            MyPhnBook.SearchByNumber();
            break;


        case 6:
            MyPhnBook.ShowAll();
            break;

        case 7:
            MyPhnBook.SearchByBlood();
            break;

        default:
            break;
        }

        pause();
    }

    return 0;
}
