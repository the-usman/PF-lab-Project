#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

bool checkLogin(string acc)
{
    ifstream inFile;
    inFile.open("account.txt");
    string line;
    while (getline(inFile, line))
    {
        int index = line.find(' ');
        string cName = line.substr(0, index);
        string line1 = line.substr(index + 1);
        int index2 = line1.find(' ');
        string cAccount = line1.substr(0, index2);
        if (acc == cAccount)
        {
            return true;
        }
    }
    return false;
}

class Account
{
protected:
    string name;
    string AccountId;
    string password;
    int NoOfAccounts = 0;
    bool logined = false;

public:
    Account()
    {
        ifstream inFile;
        inFile.open("numberOfAccount.txt");
        string n1;
        inFile >> n1;
        // cout << n1 << endl;
        int num = atoi(n1.c_str());
        NoOfAccounts = num;
        NoOfAccounts++;
        ofstream outFile;
        outFile.open("numberOfAccount.txt");
        outFile << NoOfAccounts;
        outFile.close();
    }
    Account(string name, string AID, string password)
        : name(name), AccountId(AID), password(password)
    {
        NoOfAccounts++;
    }
    void login()
    {
        ifstream inFile;
        inFile.open("account.txt");
        string line;
        string data;
        while (getline(inFile, line))
        {
            int index = line.find(' ');
            string cName = line.substr(0, index);
            string line1 = line.substr(index + 1);
            int index2 = line1.find(' ');
            string cAccount = line1.substr(0, index2);
            string cPass = line1.substr(index2 + 1);
            if (cAccount == AccountId && password == cPass)
            {
                cout << "You have succesfully Loged in\n";
                logined = true;
            }
        }
        if (!logined)
        {
            cout << "Your Account number or Password is incorrect\n";
            this->getLoginInfo();
        }
        inFile.close();
    }
    void getLoginInfo();
    void getsignUpInfo();
    void Menu();
    void Deposite();
    void WidthDraw();
    void Loan();
};

void Account::getLoginInfo()
{
    cout << "Enter your Account Number \n";
    cin >> AccountId;
    cout << "Enter your Password \n";
    cin >> password;
    if (checkLogin(AccountId))
        this->login();
    else
    {
        char choice;
        bool b = false;
    start:
        system("cls");
        if (b)
            cout << "Invalid Input\n";
        cout << "This not exist. Create Your Account\n\n\n";
        cout << "Dou want to  \n a) \tCreate Your Account\t\t\t\t\t\tb) Do you want to login again (a/b) :    ";
        cin >> choice;
        if (choice == 'a' || choice == 'A')
            this->getsignUpInfo();
        else if (choice == 'b' || choice == 'B')
            this->getLoginInfo();
        else
        {
            goto start;
        }
    }
}

void Account::getsignUpInfo()
{
    ofstream outFile;
    outFile.open("account.txt", ios::app);
    cout << "Enter Your name :  \n";
    cin >> name;
    string str = "0000000";
    int num = NoOfAccounts;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (num == 0)
            break;
        else
        {
            int digit = num % 10;
            str[i] = char(digit + '0');
            num /= 10;
        }
    }

    string AccountId = "Current2023" + str;
    cout << AccountId << endl;

    cout << "Enter Your Password  :  \n";
    cin >> password;

    outFile << name << " " << AccountId << " " << password << endl;
}
void Account::Menu()
{
    int choice;
    cout << "\t\t\t\tHERE SOME STEPS YOU CAN TAKE\n";
    cout << "1) Take Loan\n";
    cout << "2) Deposite Money\n";
    cout << "3) Width Draw Money\n";
    cin >> choice;
}

int main()
{
    Account a;
    bool b = false;
start:
    system("cls");
    if (b)
        cout << "Invalid input\n";
    cout << "\t1) Login\t\t\t\t\t\t\t\t 2) Create Account\n";
    int number;
    cin >> number;

    if (number == 1)
    {
        a.getLoginInfo();
    }
    else if (number == 2)
    {
        a.getsignUpInfo();
    }
    else
    {
        cout << "Invalid number\n";
        b = true;
        goto start;
    }
    a.Menu();
    return 0;
}