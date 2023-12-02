#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t_____________________________________________________\n\n\n";
    cout << "\t\t\t             Hello And Welcome                        \n\n\n";
    cout << "\t\t\t__________Please Select from menu______________________\n\n";
    cout << "                                                             \n\n";
    cout << "\t | Press 1 to LOGIN                     |" << endl;
    cout << "\t | Press 2 to Register                  |" << endl;
    cout << "\t | Press 3 to if Forgot PASSWAORD       |" << endl;
    cout << "\t | Press 4 to Exit                      |" << endl;
    cout << "\n\t\t\t Please Enter Your Choice: ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t Thank You \n\n";

    default:
        system("cls");
        cout << "Enter a Valid Choice ! ";
        main();
    }
}

void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please Enter Your Details: " << endl;
    cout << "\t\t\t Username: " << endl;
    cin >> userId;
    cout << "\t\t\t Password: " << endl;
    cin >> password;

    ifstream input("records.txt");
    // data ko read karne ke liye ifstream

    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\n LoggedIn Successfully ! \n ";
        main();
    }
    else
    {
        cout << "\n Loggin Error ! Invalid Username or Password \n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword, rid, rpass;
    //    rid -> registration Id
    system("cls");
    cout << "\t\t\t Enter Your Username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter the Password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);

    // ofstream ko data manuputalion ke liye use karte h
    // ios -> input output stream
    // app -> data ko file me append karne ke liye hota h.
    // aur bhi hote h padh lena.
    // f1 naam ka ek object h

    f1 << ruserId << ' ' << rpassword << endl;
    system("cls");
    cout << "\n\t\t\t Registered Successfully! ";
    main();
}

void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t Forgot Password \n ";
    cout << "\t\t\t Press 1 to Search " << endl;
    cout << "\t\t\t Press 2 to Go To Main Menu " << endl;
    cout << "\t\t\t Enter Your Choice: ";
    cin >> option;
    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserId, sId, spass;
        cout << "\n\t\t Enter the last remembered Username: ";
        cin >> suserId;

        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n \t\t\t User Data Found! \n";
            cout << "\n\n \t\t\t Your Password is: " << spass << endl;
            main();
        }
        else
        {
            cout << "\n\t No User Found \n";
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
        cout << "\t\t\t Enter a valid choice! " << endl;
        forgot();
    }
} 