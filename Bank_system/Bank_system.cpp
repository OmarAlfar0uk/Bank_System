#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Validation Class for name, password, balance, and salary validations
class Validation {
public:
    // Validate name (alphabetic and between 5 and 20 characters)
    bool IsValidation(string name) {
        if (name.size() < 5 || name.size() > 20) {
            return false;
        }
        for (int i = 0; i < name.size(); i++) {
            if (!isalpha(name[i])) {
                return false;
            }
        }
        return true;
    }

    // Validate password (between 8 and 20 characters)
    bool IsValidationPassword(string password) {
        if (password.size() < 8 || password.size() > 20) {
            return false;
        }
        return true;
    }

    // Validate balance (must be >= 1500)
    bool IsValidationBalance(double balance) {
        if (balance < 1500) {
            return false;
        }
        return true;
    }

    // Validate salary (must be >= 5000)
    bool IsValidationSalary(double& s) {
        if (s < 5000) {
            return false;
        }
        return true;
    }
};

// Client Class inheriting from Validation
class Clint : public Validation {
private:
    int id;
    string name, password;
    double balance;
public:
    // Setters and Getters for Client details
    void SetId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    void SetName(string name) {
        if (Validation::IsValidation(name)) {
            this->name = name;
            cout << "Name set successfully." << " \n" << endl;
        }
        else {
            cout << "Invalid name. The name must be alphabetic and between 5 and 20 characters." << " \n" << endl;
        }
    }

    string getName() {
        return name;
    }

    void SetPassword(string password) {
        if (Validation::IsValidationPassword(password)) {
            this->password = password;
            cout << "Password set successfully." << " \n" << endl;
        }
        else {
            cout << "Invalid password. The password must be between 8 and 20 characters." << " \n" << endl;
        }
    }

    string getPassword() {
        return password;
    }

    void SetBalance(double balance) {
        if (Validation::IsValidationBalance(balance)) {
            this->balance = balance;
            cout << "Balance set successfully." << " \n" << endl;
        }
        else {
            cout << "Invalid balance. The balance must be at least 1500." << " \n" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    // Deposit function
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully. New balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount. Deposit amount must be positive." << endl;
        }
    }

    // Withdraw function
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully. New balance: " << balance << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
        else {
            cout << "Invalid amount. Withdrawal amount must be positive." << endl;
        }
    }

    // Transfer function
    void transferTo(double amount, Clint& recipient) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferred " << amount << " to recipient. New balance: " << balance << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance. Transfer failed." << endl;
        }
        else {
            cout << "Invalid amount. Transfer amount must be positive." << endl;
        }
    }

    // Check current balance
    void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }

    // Display client details
    void Display() {
        cout << "Client ID: " << id << endl;
        cout << "Client Name: " << name << endl;
        cout << "Client Balance: " << balance << endl;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Employee class inheriting from Validation
class Employee : public Validation {
private:
    int id;
    string name;
    string password;
    double salary;

public:
    // Employee Constructor
    Employee(int i = 0, string n = " not found ", string p = "0", double s = 0.0) {
        id = i;
        name = n;
        password = p;
        salary = s;
    }

    // Setters and Getters for Employee details
    void setid(int d) {
        id = d;
    }

    int getid() {
        return id;
    }

    void setname(string n) {
        if (Validation::IsValidation(n)) {
            name = n;
        }
        else {
            cout << "Enter name size between 5 and 20 characters and must be alphabetic." << endl;
        }
    }

    string getname() {
        return name;
    }

    void setpassword(string p) {
        if (Validation::IsValidationPassword(p)) {
            password = p;
        }
        else {
            cout << "Password must be between 8 and 20 characters." << endl;
        }
    }

    string getpassword() {
        return password;
    }

    void setsalary(double s) {
        if (Validation::IsValidationSalary(s)) {
            salary = s;
        }
        else {
            cout << "Salary must not be less than 5000." << endl;
        }
    }

    double getsalary() {
        return salary;
    }

    // Display employee details
    void display() {
        cout << "Employee Info: " << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Admin Class - amira
class Admin : public Validation {
private:
    int id;
    string name;
    string password;
    double salary;

public:
    // Admin Constructor
    Admin(int i = 0, string n = "not found", string p = "0", double s = 0.0) {
        id = i;
        name = n;
        password = p;
        salary = s;
    }

    // Setters and Getters for Admin details
    void setId(int d) {
        id = d;
    }

    int getId() {
        return id;
    }

    void setName(string n) {
        if (Validation::IsValidation(n)) {
            name = n;
        }
        else {
            cout << "Invalid name. Name must be between 5 and 20 characters." << endl;
        }
    }

    string getName() {
        return name;
    }

    void setPassword(string p) {
        if (Validation::IsValidationPassword(p)) {
            password = p;
        }
        else {
            cout << "Invalid password. Password must be between 8 and 20 characters." << endl;
        }
    }

    string getPassword() {
        return password;
    }

    void setSalary(double s) {
        if (Validation::IsValidationSalary(s)) {
            salary = s;
        }
        else {
            cout << "Invalid salary. Salary must be at least 5000." << endl;
        }
    }

    double getSalary() {
        return salary;
    }

    // Display admin details
    void display() {
        cout << "Admin Info: " << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Main function for testing
int main() {
    // Clint (Client) Testing
    string name, password;
    int Id;
    double balance, deposit, withdraw, transfer;

    Clint c, c1, c2;
    cout << "Client info: " << endl;

    cout << "Enter name: ";
    cin >> name;
    c.SetName(name);

    cout << "Enter ID: ";
    cin >> Id;
    c.SetId(Id);

    cout << "Enter password: ";
    cin >> password;
    c.SetPassword(password);

    cout << "Enter balance: ";
    cin >> balance;
    c.SetBalance(balance);

    cout << "Enter deposit amount: ";
    cin >> deposit;
    c.deposit(deposit);

    cout << "Enter withdrawal amount: ";
    cin >> withdraw;
    c.withdraw(withdraw);

    cout << "Enter transfer amount: ";
    cin >> transfer;
    c1.transferTo(transfer, c2);

    c.checkBalance();

    cout << "Client c1 details: " << endl;
    c1.Display();

    cout << "Client c2 details: " << endl;
    c2.Display();

    // Employee Testing
    cout << endl << "Employee info: " << endl;
    Employee E1;
    E1.display();

    // Admin Testing  - amira
    cout << endl << "Admin info: " << endl;
    Admin a1(3, "Amira", "password123", 6000);
    a1.display();

    return 0;
}