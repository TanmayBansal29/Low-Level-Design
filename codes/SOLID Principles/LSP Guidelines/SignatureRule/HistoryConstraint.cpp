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

class FixedDepositAccount : public BankAccount {
    public:
        FixedDepositAccount(double b) : BankAccount(b) {}

        // LSP Breaks - History Constraint broke!!
        // Parent class Behaviour changed
        void withdraw(double amount) override {
            throw runtime_error("Withdrawal not allowed in Fixed Deposit");
        }
};

int main() {
    BankAccount* bankAccount = new BankAccount(1000);
    bankAccount->withdraw(1000);
}
