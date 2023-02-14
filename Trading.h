//
// Created by Omar Hegazy on 2/13/23.
//

#ifndef C_PROJECTS_TRADING_H
#define C_PROJECTS_TRADING_H

/* Psuedocode:
 *
 * For this project, basic knowledge of trading operations must be accounted for. This includes:
 *
 * 1.) Get Account Information
 * 2.) Deposit Money
 * 3.) Withdraw Money
 * 4.) Buy Cryptocoins
 * 5.) Sell Cryptocoins
 * 6.) Check Transactions
 *
 * Hence, the following variables must exist:
 *
 * 1.) Balance
 * 2.) Profit/Loss Checker
 * 3.) Choice
 * 4.) Amount to deposit/ Amount to withdraw
 *
 */

#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;

class Account
{
    int ethereum, bitcoin;
    int balance;
    int deposit, withdraw;
    int ethereum_value, bitcoin_value;
    int invest;
    int sell;

    vector<pair<string, int> > transactions;

public:

    // Deposits money into account
    bool Deposit(int money)
    {
        deposit += money; // Deposit = deposit + money
        balance += money; // Balance = balance + money
        transactions.push_back({"Deposit: ", money});

        cout << "Your updated balance is now " << balance << " dollars." << endl;
    }

    // Gets account info
    void get_account_info()
    {
        cout << "Money Details: " << endl;
        cout << "Account Balance: " << balance << endl;
        cout << "Ethereum owned: " << ethereum << endl;
        cout << "Bitcoin owned: " << bitcoin << endl;
    }

    // Withdraws money from account
    bool Withdraw(int money)
    {
        if (money > balance)
        {
            cerr << "Insufficient funds." << endl;
            return false;
        }

        withdraw += money;
        balance -= money;
        transactions.push_back({"Withdraw: ", money});

        cout << "Your updated balance is now " << balance << " dollars." << endl;

        return true;
    }

    // Buy Crypto
    bool buyCrypto()
    {
        int option;
        cout << "Would you like to purchase Bitcoin or Ethereum? Put 1 for Bitcoin, 2 for Ethereum." << endl;
        cin >> option;

        if (option == 1)
        {
            int amount;
            cout << "Enter how much you would like to buy: " << endl;
            cin >> amount;
            bitcoin += amount;

            if(amount > balance)
            {
                return false;
            }

            cout << "You now have " << bitcoin << " bitcoin." << endl;

            balance -= bitcoin_value;
            invest += (bitcoin) * bitcoin_value;
            return true;
        }

        else if(option == 2)
        {
            int amount;
            cout << "Enter how much you would like to buy: " << endl;
            cin >> amount;
            ethereum += amount;

            if(amount > balance)
            {
                return false;
            }

            cout << "You now have " << ethereum << " ethereum." << endl;

            balance -= ethereum_value;
            invest += (ethereum) * ethereum_value;
            return true;
        }
    }

    // Sell Crypto
    bool sellCrypto()
    {
        int option;
        cout << "Would you like to sell Bitcoin or Ethereum? Enter 1 for Bitcoin and 2 for Ethereum." << endl;
        cin >> option;

        if (option == 1)
        {
            if(bitcoin == 0)
            {
                return false;
            }

            sell += bitcoin_value;
            balance += bitcoin_value;
            transactions.push_back({"Bitcoin sold: ", bitcoin_value});
            bitcoin -= 1;
        }

        else if(option == 2)
        {
            if(ethereum == 0)
            {
                return false;
            }

            sell += ethereum_value;
            balance+= bitcoin_value;
            transactions.push_back({"Ethereum sold: ", ethereum_value});
            ethereum -= 1;
        }

        return true;
    }

    // Checks all transactions
    void accountHistory()
    {
        cout << "Displaying all transactions.... " << endl;
        for(auto it : transactions)
        {
            cout << it.first << it.second << endl;
        }

        char clear;
        cout << "Do you wish to clear all transactions made on this account?" << endl;
        cin >> clear;

        int number_of_transactions = transactions.size();

        // Clears all transactions
        if(clear == 'Y' || clear == 'y')
        {
            transactions.clear();
            cout << "Total Transactions Cleared: " << number_of_transactions << endl;
        }
        else
            cout << "Total Transactions: " << number_of_transactions << endl;

    }

    // Account info that user starts with as well as value for Bitcoin and Ethereum.
    Account()
    {
        invest = 0;
        sell = 0;

        balance = 100000;
        ethereum = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        bitcoin_value = 1500;
        ethereum_value = 1300;
    }

};

#endif //C_PROJECTS_TRADING_H
