#include<iostream>
using namespace std;

class Parent {
    public: 
        virtual void getValue() noexcept(false) {
            throw logic_error("Parent Error");
        }
};

class Child: public Parent {
    public: 
        virtual void getValue() noexcept(false) override{
            throw out_of_range("Child Error");
        }
};

class Client {
    private:
        Parent* p;
    public:
        Client(Parent* p){
            this->p = p;
        }
        void takeValue() {
            try {
                p->getValue();
            } catch (const logic_error& e) {
                cout << "Logic Error Excepton Occured: " << e.what() << endl;
            }
        }
};

int main() {
    Parent* parent = new Parent();
    Child* child = new Child();

    Client* client = new Client(parent);
    client->takeValue();

    return 0;
}