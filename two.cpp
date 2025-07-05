#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class temp {
    string item_name, item_ID;
    int item_quantity, item_price;
    fstream file, file1;
    int total = 0, quantity, rate;
    string search;
    char _choice;
    int n;

public:
    void addProduct(void);   // Admin function
    void viewProduct(void);  // Customer function
    void buyProduct(void);   // Customer function
};

int main() {
    temp obj;
    char choice;
    // int n;

    cout << "TO START PRESS-->1" << endl;
    cout << "TO STOP PRESS-->0" << endl;
    cout << "TO ACCESS ADMIN MODE PRESS-->A" << endl;


    cin >> choice;


    switch (choice) {
    case 'A':
    
        obj.addProduct();
        break;

    case '1':
        obj.viewProduct();
        obj.buyProduct();
        break;

    case '0':
        cout << "Program Terminated" << endl;
        break;

    default:
        cout << "Invalid selection" << endl;
        break;
    }

    return 0;
}

void temp::addProduct()
 {
    cout<<"The number of products you want to add"<<endl;
    cin>>n;
    for(int i = 0; i<=n;i++ ){
cout << "Enter the product ID: ";
    cin >> item_ID;
    cout << "Enter the product name: ";
    cin >> item_name;
    cout << "Enter the product quantity: ";
    cin >> item_quantity;
    cout<<"gm"<<endl;
    cout<<item_quantity<<"gm"<<endl;
    cout << "Enter the product price: ";
    cin >> item_price;

    file.open("data.txt", ios::out | ios::app); //here my terminal data goes to data.txt file
    file << item_ID << "\t" << item_name << "\t" << item_quantity << "\t" << item_price << "\n";
    file.close();
    }
    
}

void temp::viewProduct() {
    file.open("data.txt", ios::in);// here I read the file in the terminal
    cout << "________________________________________________" << endl;
    cout << "Product ID\tProduct Name\tProduct Quantity\tProduct Price" << endl;

    while (file >> item_ID >> item_name >> item_quantity >> item_price) {
        cout << item_ID << "\t\t" << item_name << "\t\t\t" << item_quantity << "\t\t\t" << item_price << endl;
    }

    cout << "________________________________________________" << endl;
    file.close();
}

void temp::buyProduct() {
    _choice = 'y';
    while (_choice == 'y') {
        file.open("data.txt", ios::in);
        file1.open("temp.txt", ios::out| ios::app);
        cout << "Enter the product ID: ";
        cin >> search;
        cout << "Enter the quantity: ";
        cin >> quantity;

        while (file >> item_ID >> item_name >> item_quantity >> item_price) {
            if (item_ID == search) {
                item_quantity -= quantity;
                file1 << item_ID << "\t" << item_name << "\t" << item_quantity << "\t" << item_price << "\n";

                rate = quantity * item_price;
                total += rate;

                cout << "------------------Payable Amount-------------------" << endl;
                cout << "Total Purchase Amount: " << total << endl;
                cout << "---------------------------------------------------" << endl;
            } else {
                file1 << item_ID << "\t" << item_name << "\t" << item_quantity << "\t" << item_price << "\n";
            }
        }

        file.close();
        file1.close();
        remove("data.txt");
        rename("temp.txt", "data.txt");

        cout << "Continue shopping? (y/n): ";
        cin >> _choice;
    }
}
/*
1] ios::out --> This helps to write data into file. means my data going from terminal to my txt file
2]ios::in --> This helps to read data into terminal which ispresent in file

file >> item_ID >> item_name >> item_quantity >> item_price;

file: This is the file stream from which data is being read.
'>>' Operator:
Reads data from the file stream (file).
Extracts the next value from the file and assigns it to the variable immediately to its right.
Variables:
item_ID: Receives the first value from the file.
item_name: Receives the second value from the file.
item_quantity: Receives the third value from the file.
item_price: Receives the fourth value from the file.

*/