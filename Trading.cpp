//
// Created by Omar Hegazy on 2/13/23.
//

#include "Trading.h"

int main()
{
    Account person;
    int amount;
    int choice;

    while (1)
    {
        std::cout << endl;
        cout << "Welcome to the Main Menu!" << endl;
        cout << "Press 1 if you would like to access your Account Info" << endl;
        cout << "Press 2 if you would like to make a deposit." << endl;
        cout << "Press 3 if you would like to make a withdrawal." << endl;
        cout << "Press 4 if you would like to access your account history." << endl;
        cout << "Press 5 if you would like to buy crypto." << endl;
        cout << "Press 6 if you would like to sell crypto." << endl;
        cout << "Else press any invalid key to exit the menu." << endl;

        cin >> choice;
        std::cout << endl;

        int ans;

        switch (choice)
        {
            case 1:
                person.get_account_info();
                break;
            case 2:
                cout << "Enter amount you would like to deposit: " << endl;
                cin >> amount;
                ans = person.Deposit(amount);
                if (ans)
                {
                    cout << "Successful Deposit!" << endl;
                }
                break;
            case 3:
                cout << "Enter amount you would like to withdraw: " << endl;
                cin >> amount;
                ans = person.Withdraw(amount);
                if (ans)
                {
                    cout << "Successful Withdrawal!" << endl;
                }
                break;
            case 4:
                person.accountHistory();
                break;
            case 5:
                ans = person.buyCrypto();
                if (ans)
                {
                    cout << "Successful Purchase!" << endl;
                }
                break;
            case 6:
                ans = person.sellCrypto();
                if (ans)
                {
                    cout << "Successful Sell!" << endl;
                }
                break;
            default:
                exit(0);
                break;

        }
    }

}