#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void headerLines()
{
    cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void smallHeaderLines(){
    // cout
}

void welcome()
{
    cout << endl
         << endl;
    headerLines();
    cout << "\n\033[1m                                                                                           QuickPicks\033[0m" << endl
         << endl;
    headerLines();
    cout << endl
         << endl;
    cout << "Welcome to QuickPicks !" << endl
         << endl;
}

class Product
{
public:
    string pName, pCategory;
    int pPrice;

    Product(string name, string category, int price)
        : pName(name), pCategory(category), pPrice(price) {}

    string getName() const { return pName; }
    string getCategory() const { return pCategory; }
    int getPrice() const { return pPrice; }
};

class userProfile
{
    string name, contact, email, address;
    string debitAccNo = "Not Available", creditAccNo = "Not Available";
    bool isProfileCreated = false; 

public:
    void createProfile()
    {
        cout << "\n\033[1mCreate User Profile\033[0m -" << endl;
        headerLines();

        cout << "\n\033[4mName\033[0m: ";
        getline(cin, name);

        cout << "\033[4mContact\033[0m: ";
        getline(cin, contact);

        cout << "\033[4mAddress\033[0m: ";
        getline(cin, address);

        cout << "\033[4mEmail\033[0m: ";
        getline(cin, email);

        paymentOpt();

        isProfileCreated = true; 

        cout << "\nProfile Created Successfully!" << endl;
        headerLines();
    }

    void paymentOpt()
    {
        int paymentOptions;

        while (true)
        {
            cout << "\nPayment Options (1 or 2 or 3):\n1. Add Debit Card.\n2. Add Credit Card.\n3. Add Both.\n--> ";
            cin >> paymentOptions;
            cin.ignore();

            switch (paymentOptions)
            {
            case 1:
                cout << "\033[4mDebit Card no\033[0m: ";
                getline(cin, debitAccNo);
                return;
            case 2:
                cout << "\033[4mCredit Card no\033[0m: ";
                getline(cin, creditAccNo);
                return;
            case 3:
                cout << "\033[4mDebit Card no\033[0m: ";
                getline(cin, debitAccNo);
                cout << "\033[4mCredit Card no\033[0m: ";
                getline(cin, creditAccNo);
                return;

            default:
                cout << "Invalid Option Entered! Please try again.\n";
                break;
            }
        }
    }

    void showProfile()
    {
        if (!isProfileCreated)
        {
            cout << "\n\033[1mNo profile exists. Please create a profile first.\033[0m\n";
            headerLines();
            return;
        }

        cout << "\n\033[1mProfile Information:\033[0m\n";
        headerLines();

        cout << "\n\033[4mName\033[0m: " << name << "\n";
        cout << "\033[4mContact\033[0m: " << contact << "\n";
        cout << "\033[4mAddress\033[0m: " << address << "\n";
        cout << "\033[4mEmail\033[0m: " << email << "\n";
        cout << "\033[4mDebit Card\033[0m: " << debitAccNo << "\n";
        cout << "\033[4mCredit Card\033[0m: " << creditAccNo << "\n";

        headerLines();
    }

    void modifyProfile()
    {
        if (!isProfileCreated)
        {
            cout << "\n\033[1mNo profile exists. Please create a profile first.\033[0m\n";
            return;
        }

        int choice;
        while (true)
        {
            cout << "\n\033[1mModify Profile:\033[0m\n";
            headerLines();

            cout << "\n1. Name\n2. Contact\n3. Address\n4. Email\n5. Debit Card Info\n6. Credit Card Info\n7. Exit\n";
            cout << "Choose an option to modify: ";
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case 1:
                cout << "\033[4mEnter new Name\033[0m: ";
                getline(cin, name);
                break;
            case 2:
                cout << "\033[4mEnter new Contact\033[0m: ";
                getline(cin, contact);
                break;
            case 3:
                cout << "\033[4mEnter new Address\033[0m: ";
                getline(cin, address);
                break;
            case 4:
                cout << "\033[4mEnter new Email\033[0m: ";
                getline(cin, email);
                break;
            case 5:
                cout << "\033[4mEnter new Debit Card No\033[0m: ";
                getline(cin, debitAccNo);
                break;
            case 6:
                cout << "\033[4mEnter new Credit Card No\033[0m: ";
                getline(cin, creditAccNo);
                break;
            case 7:
                cout << "Exiting Modify Menu.\n";
                return;
            default:
                cout << "Invalid Option! Please choose again.\n";
                continue;
            }

            cout << "\n\033[1mUpdated Profile Information:\033[0m\n";
            showProfile();
        }
    }

    void manageProfile()
    {
        int pChoice;
        cout << "\n1. Create Profile." << endl
             << "2. Modify Profile." << endl
             << "3. Show Profile." << endl;

        cout << "What would you like to do? ";
        cin >> pChoice;
        cin.ignore();

        switch (pChoice)
        {
        case 1:
            createProfile();
            break;
        case 2:
            modifyProfile();
            break;
        case 3:
            showProfile();
            break;
        default:
            cout << "Invalid Option Chosen!" << endl;
            manageProfile();
            break;
        }
    }
};


class Cart
{
public:
    map<string, int> cartItems; // Store product name and quantity

    void addToCart(const string &productName)
    {
        cartItems[productName]++;
    }

    void showCart(const vector<Product> &products)
    {
        cout << "\nItems in your Cart:\n";
        float totalPrice = 0;

        for (const auto &item : cartItems)
        {
            for (const auto &product : products)
            {
                if (product.getName() == item.first)
                {
                    cout << product.getName() << " (x" << item.second << ") - Rs. "
                         << product.getPrice() * item.second << endl;
                    totalPrice += product.getPrice() * item.second;
                }
            }
        }
        cout << "\nTotal Price: Rs. " << totalPrice << endl;

    }

    bool isEmpty()
    {
        return cartItems.empty();
    }
};

class OnlineShoppingSystem
{
public:
    vector<Product> products;
    userProfile user;
    Cart userCart;

    void loadProducts()
    {   
        // 1. Electronics.
        products.push_back(Product("Smartphone", "Electronics", 15000));
        products.push_back(Product("Laptop", "Electronics", 50000));
        products.push_back(Product("Smartwatch", "Electronics", 5000));
        products.push_back(Product("Headphones", "Electronics", 2000));
        products.push_back(Product("TV", "Electronics", 35000));
        products.push_back(Product("Refrigerator", "Electronics", 25000));
        products.push_back(Product("Washing Machine", "Electronics", 20000));
        products.push_back(Product("Microwave Oven", "Electronics", 8000));
        products.push_back(Product("Air Conditioner", "Electronics", 40000));
        products.push_back(Product("Blender", "Electronics", 3000));

        // 2. Fashion.
        products.push_back(Product("T-Shirt", "Fashion", 800));
        products.push_back(Product("Jeans", "Fashion", 1200));
        products.push_back(Product("Sneakers", "Fashion", 2500));
        products.push_back(Product("Jacket", "Fashion", 3000));
        products.push_back(Product("Sunglasses", "Fashion", 1500));
        products.push_back(Product("Cap", "Fashion", 600));
        products.push_back(Product("Watch", "Fashion", 3500));
        products.push_back(Product("Scarf", "Fashion", 1000));
        products.push_back(Product("Belt", "Fashion", 800));
        products.push_back(Product("Sweater", "Fashion", 1800));

        // 3. Home and Kitchen.
        products.push_back(Product("Blender", "Home and Kitchen", 3000));
        products.push_back(Product("Toaster", "Home and Kitchen", 1200));
        products.push_back(Product("Coffee Maker", "Home and Kitchen", 2500));
        products.push_back(Product("Rice Cooker", "Home and Kitchen", 2200));
        products.push_back(Product("Microwave Oven", "Home and Kitchen", 8000));
        products.push_back(Product("Dishwasher", "Home and Kitchen", 18000));
        products.push_back(Product("Electric Kettle", "Home and Kitchen", 1500));
        products.push_back(Product("Induction Cooktop", "Home and Kitchen", 3500));
        products.push_back(Product("Refrigerator", "Home and Kitchen", 25000));
        products.push_back(Product("Air Purifier", "Home and Kitchen", 12000));

        // 4. Health and Beauty.
        products.push_back(Product("Shampoo", "Health and Beauty", 300));
        products.push_back(Product("Conditioner", "Health and Beauty", 350));
        products.push_back(Product("Face Cream", "Health and Beauty", 500));
        products.push_back(Product("Toothbrush", "Health and Beauty", 150));
        products.push_back(Product("Toothpaste", "Health and Beauty", 100));
        products.push_back(Product("Hair Oil", "Health and Beauty", 400));
        products.push_back(Product("Lip Balm", "Health and Beauty", 150));
        products.push_back(Product("Makeup Kit", "Health and Beauty", 1500));
        products.push_back(Product("Deodorant", "Health and Beauty", 250));
        products.push_back(Product("Sunscreen", "Health and Beauty", 800));

        // 5. Sports and Outdoors.
        products.push_back(Product("Tennis Racket", "Sports and Outdoors", 2500));
        products.push_back(Product("Football", "Sports and Outdoors", 1200));
        products.push_back(Product("Yoga Mat", "Sports and Outdoors", 800));
        products.push_back(Product("Camping Tent", "Sports and Outdoors", 5000));
        products.push_back(Product("Hiking Backpack", "Sports and Outdoors", 3500));
        products.push_back(Product("Cycling Helmet", "Sports and Outdoors", 1500));
        products.push_back(Product("Fishing Rod", "Sports and Outdoors", 2000));
        products.push_back(Product("Baseball Glove", "Sports and Outdoors", 1000));
        products.push_back(Product("Water Bottle", "Sports and Outdoors", 300));
        products.push_back(Product("Ski Jacket", "Sports and Outdoors", 3500));

        // 6. Toys and Baby Products.
        products.push_back(Product("Teddy Bear", "Toys and Baby Products", 600));
        products.push_back(Product("Building Blocks", "Toys and Baby Products", 1200));
        products.push_back(Product("Baby Stroller", "Toys and Baby Products", 5000));
        products.push_back(Product("Toy Train Set", "Toys and Baby Products", 1500));
        products.push_back(Product("Baby Monitor", "Toys and Baby Products", 3000));
        products.push_back(Product("Stuffed Animal", "Toys and Baby Products", 800));
        products.push_back(Product("Playmat", "Toys and Baby Products", 1200));
        products.push_back(Product("Board Game", "Toys and Baby Products", 1000));
        products.push_back(Product("Doll", "Toys and Baby Products", 500));
        products.push_back(Product("Baby Feeding Bottle", "Toys and Baby Products", 300));

        // 7. Books and Stationary.
        products.push_back(Product("Notebook", "Books and Stationery", 150));
        products.push_back(Product("Pen Set", "Books and Stationery", 200));
        products.push_back(Product("Pencil Box", "Books and Stationery", 250));
        products.push_back(Product("Diary", "Books and Stationery", 400));
        products.push_back(Product("Textbook", "Books and Stationery", 800));
        products.push_back(Product("Colored Pencils", "Books and Stationery", 500));
        products.push_back(Product("Eraser", "Books and Stationery", 50));
        products.push_back(Product("Glue Stick", "Books and Stationery", 100));
        products.push_back(Product("Art Paper", "Books and Stationery", 250));
        products.push_back(Product("Planner", "Books and Stationery", 350));

        // 8. Groceries and Essentials.
        products.push_back(Product("Rice", "Groceries and Essentials", 200));
        products.push_back(Product("Sugar", "Groceries and Essentials", 150));
        products.push_back(Product("Flour", "Groceries and Essentials", 100));
        products.push_back(Product("Salt", "Groceries and Essentials", 50));
        products.push_back(Product("Cooking Oil", "Groceries and Essentials", 400));
        products.push_back(Product("Tea", "Groceries and Essentials", 250));
        products.push_back(Product("Coffee Powder", "Groceries and Essentials", 300));
        products.push_back(Product("Pasta", "Groceries and Essentials", 150));
        products.push_back(Product("Cereal", "Groceries and Essentials", 500));
        products.push_back(Product("Milk", "Groceries and Essentials", 50));

        // 9. Automotive and Accessories.
        products.push_back(Product("Car Phone Mount", "Automotive and Accessories", 800));
        products.push_back(Product("Car Charger", "Automotive and Accessories", 600));
        products.push_back(Product("Seat Covers", "Automotive and Accessories", 2000));
        products.push_back(Product("Steering Wheel Cover", "Automotive and Accessories", 500));
        products.push_back(Product("Car Vacuum Cleaner", "Automotive and Accessories", 2500));
        products.push_back(Product("Dashboard Camera", "Automotive and Accessories", 4500));
        products.push_back(Product("Car Air Freshener", "Automotive and Accessories", 200));
        products.push_back(Product("Jumper Cables", "Automotive and Accessories", 800));
        products.push_back(Product("Tire Inflator", "Automotive and Accessories", 1500));
        products.push_back(Product("Car Battery", "Automotive and Accessories", 7000));

        // 10. Gadgets and Tech Accessories.
        products.push_back(Product("Bluetooth Earphones", "Gadgets and Tech Accessories", 1500));
        products.push_back(Product("Wireless Mouse", "Gadgets and Tech Accessories", 700));
        products.push_back(Product("Laptop Stand", "Gadgets and Tech Accessories", 1200));
        products.push_back(Product("Power Bank", "Gadgets and Tech Accessories", 1500));
        products.push_back(Product("Phone Case", "Gadgets and Tech Accessories", 600));
        products.push_back(Product("Screen Protector", "Gadgets and Tech Accessories", 300));
        products.push_back(Product("Keyboard", "Gadgets and Tech Accessories", 1500));
        products.push_back(Product("Smartwatch Strap", "Gadgets and Tech Accessories", 800));
        products.push_back(Product("Portable Speaker", "Gadgets and Tech Accessories", 2500));
        products.push_back(Product("External Hard Drive", "Gadgets and Tech Accessories", 4000));
    }

    void showCategories()
    {
        cout << "\nCategories Available:\n";
        cout << "1. Electronics\n2. Fashion\n3. Home and Kitchen\n4. Health and Beauty\n5. Sports and Outdoors\n";
        cout << "6. Toys and Baby Products\n7. Books and Stationery\n8. Groceries and Essentials\n9. Automotive and Accessories\n";
        cout << "10. Gadgets and Tech Accessories\n";
    }

    void viewProductsByCategory(const string &category)
    {
        cout << "\nProducts in " << category << ":\n";
        bool addMore = true;

        while (addMore)
        {
            int count = 0;
            for (const auto &product : products)
            {
                if (product.pCategory == category)
                {
                    cout << ++count << ". " << product.pName << " - Rs. " << product.pPrice << endl;
                }
            }

            cout << "\nDo you want to add any product to your cart? (y/n): ";
            char addChoice;
            cin >> addChoice;

            if (addChoice == 'y' || addChoice == 'Y')
            {
                cout << "Enter the product name to add to cart: ";
                string productName;
                cin.ignore();
                getline(cin, productName);

                bool found = false;
                for (const auto &product : products)
                {
                    if (product.pName == productName && product.pCategory == category)
                    {
                        userCart.addToCart(product.pName);
                        cout << "Product '" << product.pName << "' added to your cart!" << endl;
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "Product not found in this category!" << endl;
            }
            else
            {
                addMore = false;
            }

            cout << "\nDo you want to continue viewing products in this category? (y/n): ";
            char continueChoice;
            cin >> continueChoice;

            if (continueChoice != 'y' && continueChoice != 'Y')
                addMore = false;
        }
    }

    void searchProduct()
    {
        cout << "\nDo you want to search by name or category? (Enter 'name' or 'category'): ";
        string choice;
        cin >> choice;

        if (choice == "name")
        {
            cout << "\nEnter product name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            bool found = false;
            for (const auto &product : products)
            {
                if (product.getName() == name)
                {
                    cout << product.getName() << " - Rs. " << product.getPrice() << endl;
                    cout << "Would you like to add this product to the cart? (y/n): ";
                    char addChoice;
                    cin >> addChoice;
                    if (addChoice == 'y' || addChoice == 'Y')
                    {
                        userCart.addToCart(product.getName());
                        cout << product.getName() << " added to cart.\n";
                    }
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Product not found!" << endl;
        }
        else if (choice == "category")
        {
            showCategories();
            cout << "Enter category number: ";
            int categoryChoice;
            cin >> categoryChoice;
            string categories[] = {"Electronics", "Fashion", "Home and Kitchen", "Health and Beauty", "Sports and Outdoors",
                                   "Toys and Baby Products", "Books and Stationery", "Groceries and Essentials", "Automotive and Accessories",
                                   "Gadgets and Tech Accessories"};
            if (categoryChoice >= 1 && categoryChoice <= 10)
            {
                viewProductsByCategory(categories[categoryChoice - 1]);
                cout << "Would you like to add any product to your cart? (y/n): ";
                char addChoice;
                cin >> addChoice;
                if (addChoice == 'y' || addChoice == 'Y')
                {
                    cout << "Enter product name to add to cart: ";
                    cin.ignore();
                    string name;
                    getline(cin, name);
                    userCart.addToCart(name);
                    cout << name << " added to cart.\n";
                }
            }
            else
            {
                cout << "Invalid category!" << endl;
            }
        }
    }

    void checkout()
    {
        if (userCart.isEmpty())
        {
            cout << "\nYour cart is empty. Add items to your cart before checkout.\n";
            return;
        }

        userCart.showCart(products);
        cout << "\nDo you want to proceed to checkout? (y/n): ";
        char proceed;
        cin >> proceed;
        if (proceed == 'y' || proceed == 'Y')
        {
            cout << "\nThank you for shopping with us! Your order will be processed shortly.\n";
        }
        else
        {
            cout << "\nCheckout canceled.\n";
        }
    }

    void displayMenu()
    {
        int choice;
        while (true)
        {

            cout << "\n--> What would you like to do?\n";
            cout << "1. Profile\n2. Cart\n3. Orders\n4. View Products\n5. Checkout\n6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            cout << endl;

            switch (choice)
            {
            case 1:
                user.manageProfile();
                break;
            case 2:
                userCart.showCart(products);
                break;
            case 3:
                cout << "Orders functionality coming soon!" << endl;
                break;
            case 4:
                // Keep viewing products until the user wants to exit
                while (true)
                {
                    cout << "\nDo you want to search by name or category? (Enter 'name' or 'category'), or 'exit' to go back: ";
                    string searchChoice;
                    cin >> searchChoice;

                    if (searchChoice == "name")
                    {
                        cout << "\nEnter product name: ";
                        string name;
                        cin.ignore();
                        getline(cin, name);
                        bool found = false;
                        for (const auto &product : products)
                        {
                            if (product.pName == name)
                            {
                                cout << product.pName << " - Rs. " << product.pPrice << endl;
                                // Add to cart option
                                cout << "Do you want to add this product to your cart? (y/n): ";
                                char addChoice;
                                cin >> addChoice;
                                if (addChoice == 'y' || addChoice == 'Y')
                                {
                                    userCart.addToCart(product.pName);
                                    cout << "Product added to your cart!" << endl;
                                }
                                found = true;
                                break;
                            }
                        }
                        if (!found)
                            cout << "Product not found!" << endl;
                    }
                    else if (searchChoice == "category")
                    {
                        showCategories();
                        cout << "Enter category number: ";
                        int categoryChoice;
                        cin >> categoryChoice;
                        string categories[] = {"Electronics", "Fashion", "Home and Kitchen", "Health and Beauty", "Sports and Outdoors",
                                               "Toys and Baby Products", "Books and Stationery", "Groceries and Essentials", "Automotive and Accessories",
                                               "Gadgets and Tech Accessories"};
                        if (categoryChoice >= 1 && categoryChoice <= 10)
                        {
                            viewProductsByCategory(categories[categoryChoice - 1]);

                            // After viewing the category, prompt for adding to cart
                            cout << "\nDo you want to add a product to your cart? (y/n): ";
                            char addChoice;
                            cin >> addChoice;
                            if (addChoice == 'y' || addChoice == 'Y')
                            {
                                string productName;
                                cout << "Enter the product name to add to cart: ";
                                cin.ignore();
                                getline(cin, productName);
                                bool added = false;
                                for (const auto &product : products)
                                {
                                    if (product.pName == productName && product.pCategory == categories[categoryChoice - 1])
                                    {
                                        userCart.addToCart(product.pName);
                                        cout << "Product added to your cart!" << endl;
                                        added = true;
                                        break;
                                    }
                                }
                                if (!added)
                                    cout << "Product not found in the selected category!" << endl;
                            }
                        }
                        else
                        {
                            cout << "Invalid category!" << endl;
                        }
                    }
                    else if (searchChoice == "exit") // Option to exit the search
                    {
                        break; // Exit product viewing loop and return to the main menu
                    }
                    else
                    {
                        cout << "Invalid choice! Please try again." << endl;
                    }
                }
                break;
            case 5:
                checkout();
                break;
            case 6:
                cout << "Exiting. Thank you!" << endl;
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }
};

int main()
{
    welcome();
    OnlineShoppingSystem system;
    system.loadProducts();
    system.displayMenu();
    return 0;
}
