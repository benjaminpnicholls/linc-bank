#include <iostream>
#include "mainmethods.h"


// Shows all menu options to the user.
void MainMethods::printMenuOptions() {
    std::cout << "  OPTIONS" << std::endl;
    std::cout << "\topen type initial_deposit" << "\t" << "open a current(1), savings(2) or ISA(3) account" << std::endl;
    std::cout << "\tview[index]" << "\t\t\t" << "view balance and recent transactions" << std::endl;
    std::cout << "\twithdraw sum" << "\t\t\t" << "withdraw funds from most recently viewed account" << std::endl;
    std::cout << "\tdeposit sum" << "\t\t\t" << "deposit funds into most recently viewed account" << std::endl;
    std::cout << "\ttransfer src dest sum" << "\t\t" << "transfer funds between accounts" << std::endl;
    std::cout << "\tproject years" << "\t\t\t" << "project balance forward in time" << std::endl;
    std::cout << "\texit" << "\t\t\t\t" << "close this application" << std::endl;
    std::cout << "\toptions" << "\t\t\t\t" << "view these options again" << std::endl;
}


bool MainMethods::isCurrency(std::string Str) {
    for (auto a : Str) {
        if (!std::isdigit(a)) {
            if (a != '.') {
                return false;
            }
        }
    }
    return true;
}


bool MainMethods::isInt(std::string Str) {
    for (auto a : Str) {
        if (!std::isdigit(a)) {
            return false;
        }
    }
    return true;
}


std::string MainMethods::Truncate2dp(double Value) {
    std::string value = std::to_string(Value);
    value = value.substr(0, value.find('.')  + 3);
    return value;
}


std::string MainMethods::viewAllAccounts (std::vector<Account*> &Accounts) {
    std::string str = "";
    for (auto a : Accounts) {
        str += a->ToString();
    }
    return str;
}


std::string MainMethods::viewSingleAccount (std::vector<Account*> &Accounts, std::string &AccountNumber, int &NumberOfAccounts) {
    if (!MainMethods::isInt(AccountNumber)) { throw NotIntException(); }
    int index = std::stoi(AccountNumber);
    if (index > NumberOfAccounts) { throw AccountNumberOutOfRangeException(); }
    if (index == 0) { throw AccountNumberOutOfRangeException(); }
    Account* a = Accounts[index - 1];
    return a->ToString();		
}


bool MainMethods::withdraw(Account* A, std::string Value) {
    if (!MainMethods::isCurrency(Value)) { throw NotCurrencyException();	}
    double value = std::stod(Value);
    if (A->Withdraw(value)) { return true; }
    return false;
}


bool MainMethods::deposit(Account* A, std::string Value) {
    if (!MainMethods::isCurrency(Value)) { throw NotCurrencyException();	}
    double value = std::stod(Value);
    if (A->Deposit(value)) { return true; }
    return false;
}


std::string MainMethods::transfer(std::vector<Account*> &Accounts, std::string Source, std::string Destination, std::string Value, int &NumberOfAccounts) {
    if (!MainMethods::isInt(Source)) { throw NotIntException(); }
    if (!MainMethods::isInt(Destination)) { throw NotIntException(); }
    int source = std::stoi(Source);
    int destination = std::stoi(Destination);
    if (source == 0) { throw AccountNumberOutOfRangeException(); }
    if (source > NumberOfAccounts) { throw AccountNumberOutOfRangeException(); }
    if (destination == 0) { throw AccountNumberOutOfRangeException(); }
    if (destination > NumberOfAccounts) { throw AccountNumberOutOfRangeException(); }
    if (source == destination) { throw AccountNumberOutOfRangeException(); }
    if (!MainMethods::isCurrency(Value)) { throw NotCurrencyException();	}
    Account* a = Accounts[source - 1];
    Account* b = Accounts[destination - 1];
    double value = std::stod(Value);
    if (!a->Withdraw(value, destination)) { throw WithdrawFailException(); }
    b->Deposit(value, source);
    return a->ToString() + b->ToString();
}


double MainMethods::project(Account* a, std::string Years) {
    if (!MainMethods::isInt(Years)) { throw NotIntException(); }
    // If dynamic cast was unsuccessful, the account isn't a savings account.
    Savings* s = dynamic_cast<Savings*>(a);
    if (s == nullptr) { throw DynamicCastUnsuccessfulException(); }
    return s->ComputeInterest(std::stoi(Years));
}

