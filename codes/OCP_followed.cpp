#include<iostream>
#include<vector>

using namespace std;

class Product {
    public:
        string name;
        double price;

        Product(string name, double price) {
            this->name = name;
            this->price = price;
        }
};

// ShoppingCart : Only responsible for calculating total of products
class ShoppingCart {
    private:
        vector<Product*> products;
    
    public:
        void addProduct(Product *p) {
            products.push_back(p);
        }

        const vector<Product *>& getProducts() {
            return products;
        }

        // Calculate total price in cart
        double calculateTotal() {
            double total = 0;
            for(auto p: products) {
                total += p->price;
            }
            return total;
        }
};

// ShoppingCartPrinter: Only responsible for printing invoices
class ShoppingCartPrinter {
    private:
        ShoppingCart* cart;
    
    public:
        ShoppingCartPrinter(ShoppingCart* cart) {
            this->cart = cart;
        }

        void printInvoice() {
            cout << "Shopping Cart Invoice:\n";
            for(auto p : cart->getProducts()) {
                cout << p->name << " - $ " << p->price << endl;
            }
            cout << "Total: $" << cart->calculateTotal() << endl;
        }
};

// Abstract Class
class Persistence {
    private:
        ShoppingCart* cart;
    public:
        virtual void save(ShoppingCart* cart) = 0; // Pure Virtual Function
};

class SQLPersistence : public Persistence {
    public:
        void save(ShoppingCart* cart) {
            cout << "Saving shopping cart to SQL database..." << endl;
        }
};

class MongoPersistence : public Persistence {
    public:
        void save(ShoppingCart* cart) {
            cout << "Saving shopping cart to Mongo database..." << endl;
        }
};

class FilePersistence : public Persistence {
    public:
        void save(ShoppingCart* cart) {
            cout << "Saving shopping cart to File..." << endl;
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 1500));
    cart->addProduct(new Product("Mouse", 50));

    ShoppingCartPrinter* printer = new ShoppingCartPrinter(cart);
    printer->printInvoice();

    Persistence* db = new SQLPersistence();
    Persistence* mongo = new MongoPersistence();
    Persistence* file = new FilePersistence();

    db->save(cart);  // Save to SQL database
    mongo->save(cart); // Save to Mongo database
    file->save(cart); // Save to File

    return 0;
}