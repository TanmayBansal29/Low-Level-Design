#include<iostream>
using namespace std;

// Method Argument Rule:
// Subtype method arguments can be identical or wider than the supertype
// C++ imposed this by keepinh signature identical

class Parent {
    public:
        virtual void print(string msg) {
            cout << "Parent: " << msg << endl;
        }
};

class Child : public Parent {
    public:
        void print(string msg) override {
            cout << "Child: " << msg << endl; 
        }
};

// Client that pass string as msg as client expects
class Client {
    private:
        Parent* p;
    
    public: 
        Client(Parent* p) {
            this->p = p;
        }
        void printMsg() {
            p->print("Hello Ji");
        }
};

int main() {
    Parent* parent = new Parent();
    Parent* child = new Child();

    Client* client = new Client(child);
    client->printMsg();

    return 0;
}