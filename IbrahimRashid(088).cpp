/*Muhammad Ibrahim Rashid (088)
  Hunain Hamid Khan (068)*/

                                                                         /*ATM Simulator Code*/

#include <iostream>
#include <fstream>
#include <process.h>

using namespace std;

// Structure to store user data
struct Account
{
    char username[30];
    char password[30];
    double balance;
};

void loadBalance(Account &acc);
void saveBalance(Account acc);
bool login(Account acc);
void checkBalance(Account acc);
void depositMoney(Account &acc);
void withdrawMoney(Account &acc);

int main()
{
    Account acc = {"muhammadibrahim704", "12345", 1000.00};

    loadBalance(acc);

    cout << "\n\n\t\t\t\t\t\tPlease Enter LOGIN Details\n";

    if (!login(acc)) {
        cout << "\nInvalid Login. Exiting...\n";
        exit (0);
    }

    int choice;

    do {
        cout << "\n\n\t\t\t\t\t\tWelcome to Chit Chat Luxmy Fund\n\n";
        cout << "\t1. Check Balance\n";
        cout << "\t2. Deposit Funds\n";
        cout << "\t3. Withdraw Funds\n";
        cout << "\t4. Exit\n";
        cout << "\t\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(acc);
                break;
            case 2:
                depositMoney(acc);
                break;
            case 3:
                withdrawMoney(acc);
                break;
            case 4:
                cout << "\n25 din may paisa double... Thank you! Please come again soon\n";
                break;
            default:
                cout << "\nInvalid option. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}

//Functions
void loadBalance(Account &acc) {
    ifstream file("balance.txt");

    if (!file) {
        acc.balance = 0;
        return;
    }

    file >> acc.username
         >> acc.balance;
    file.close();
}

void saveBalance(Account acc) {
    ofstream file("balance.txt");
    file << acc.username << "\n"; 
    file << acc.balance;
    file.close();
}

bool login(Account acc) {
    char u[30], p[30];

    cout << "\nEnter Username: ";
    cin >> u;

    cout << "Enter Password: ";
    cin >> p;

    int i = 0;
    bool userMatch = true;
    while (u[i] != '\0' || acc.username[i] != '\0') {
        if (u[i] != acc.username[i]) {
            userMatch = false;
            break;
        }
        i++;
    }

    i = 0;
    bool passMatch = true;
    while (p[i] != '\0' || acc.password[i] != '\0') {
        if (p[i] != acc.password[i]) {
            passMatch = false;
            break;
        }
        i++;
    }

    if (userMatch && passMatch) {
        cout << "\n\t\t\t\t\t\tLogin Successful!\n";
        return true;
    }

    cout << "\n\t\t\t\t\t\tAccount does not exist!\n";
    return false;
}


void checkBalance(Account acc) {
    cout << "\nYour Balance: $" << acc.balance << endl;
}

void depositMoney(Account &acc) {
    double amount;
    cout << "\nEnter amount to deposit: $";
    cin >> amount;

    if (amount <= 0) {
        cout << "\nInvalid amount!\n";
        return;
    }

    acc.balance += amount;
    saveBalance(acc);

    cout << "\nDeposit Successful!\n";
    
    checkBalance(acc);
}

void withdrawMoney(Account &acc) {
    double amount;
    cout << "\nEnter amount to withdraw: $";
    cin >> amount;

   // if (amount <= 0) {
       // cout << "\nInvalid amount!\n";
       // return;
    //}

   // if (amount > acc.balance) {
        //cout << "\nInsufficient Funds!\n";
       // return;
    //}

    acc.balance -= amount;
    saveBalance(acc);

    cout << "\nWithdrawal Successful!\n";
    
    checkBalance(acc);
}

