#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class representing a Product
class Product {
private:
    string name;
    float price;

public:
    // Constructor
    Product(string n, float p) : name(n), price(p) {}

    // Getters
    string getName() const { return name; }
    float getPrice() const { return price; }

    // Display product details
    void displayProduct() const {
        cout << "Product: " << name << " | Price: $" << price << endl;
    }
};

// Class representing a Shopping Cart
class Cart {
private:
    vector<Product> products;

public:
    // Add a product to the cart
    void addProduct(const Product& product) {
        products.push_back(product);
        cout << product.getName() << " has been added to the cart.\n";
    }

    // Remove a product from the cart by name
    void removeProduct(const string& productName) {
        for (auto it = products.begin(); it != products.end(); ++it) {
            if (it->getName() == productName) {
                cout << productName << " has been removed from the cart.\n";
                products.erase(it);
                return;
            }
        }
        cout << "Product not found in the cart.\n";
    }

    // View all products in the cart
    void viewCart() const {
        if (products.empty()) {
            cout << "Your cart is empty.\n";
            return;
        }

        cout << "Products in your cart:\n";
        for (const auto& product : products) {
            product.displayProduct();
        }
    }

    // Calculate the total price of the cart
    float calculateTotal() const {
        float total = 0;
        for (const auto& product : products) {
            total += product.getPrice();
        }
        return total;
    }
};

// Main Function
int main() {
    Cart cart;
    vector<Product> store = {
        Product("Laptop", 999.99),
        Product("Smartphone", 499.99),
        Product("Headphones", 149.99),
        Product("Keyboard", 89.99),
        Product("Mouse", 59.99)
    };

    int choice;
    while (true) {
        // Display menu
        cout << "\nE-commerce Cart System\n";
        cout << "1. View Store\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Remove Product from Cart\n";
        cout << "5. Checkout\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Available products:\n";
                for (size_t i = 0; i < store.size(); ++i) {
                    cout << i + 1 << ". ";
                    store[i].displayProduct();
                }
                break;
            }
            case 2: {
                int productNumber;
                cout << "Enter the product number to add to your cart: ";
                cin >> productNumber;

                if (productNumber > 0 && productNumber <= (int)store.size()) {
                    cart.addProduct(store[productNumber - 1]);
                } else {
                    cout << "Invalid product number.\n";
                }
                break;
            }
            case 3: {
                cart.viewCart();
                break;
            }
            case 4: {
                string productName;
                cout << "Enter the name of the product to remove: ";
                cin.ignore();
                getline(cin, productName);
                cart.removeProduct(productName);
                break;
            }
            case 5: {
                cout << "Total price of your cart: $" << cart.calculateTotal() << endl;
                cout << "Thank you for shopping!\n";
                return 0;
            }
            case 6: {
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
            }
        }
    }

    return 0;
}
