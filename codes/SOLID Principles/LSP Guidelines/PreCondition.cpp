#include<iostream>
using namespace std;

class User{
    public:
        virtual void setPassword(string password) {
            if(password.length() < 8) {
                throw invalid_argument("Password must be at least 8 Characters long");
            }
            cout << "Password Set Successfully"<< endl;
        }
};

class AdminUser : public User {
    public:
        void setPassword(string password) override{
            if(password.length() < 6) {
                throw invalid_argument("Password must be at least 6 Characters long");
            }
            cout << "Password Set Successfully" << endl;
        }
};

int main() {
    User* user = new User();
    User* admin = new AdminUser();

    user->setPassword("@Tanmay098");
    admin->setPassword("@Tanmay");

    return 0;
}