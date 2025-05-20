#include<iostream>
using namespace std;

class BankAccount {
    protected:
        double balance;
    public:
        BankAccount(double b) {
            if(b < 0) throw invalid_argument("Balance cannot be negative");
            balance = b;
        }

        virtual void withdraw(double amount) {
            if(balance - amount < 0) throw runtime_error("Insufficient funds");
            balance -= amount;
            cout << "Amount Withdrawn. Remaining balance is " << balance << endl;
        }
};

class CheatAccount : public BankAccount {
    public:
        CheatAccount(double b) : BankAccount(b) {}
        void withdraw(double amount) override {
            balance -= amount;
            cout << "Amount Withdrawn. Remaining balance is " << balance << endl;
        }
};

int main() {
    BankAccount* bankAccount = new BankAccount(1000);
    bankAccount->withdraw(1000);
}