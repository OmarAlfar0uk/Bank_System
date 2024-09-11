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

// Person Class for common attributes
class Person : public Validation {
protected:
    int id;
    string name;
    string password;
public:
    Person() {
        id = 0;
        name = "";
    }

    Person(int id, string name) {
        this->id = id;
        this->name = name;
    }

    Person(int id, string name ,string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }

    // Setters and Getters for common attributes
    void SetId(int id) {
        this->id = id;
    }

    int getId() {
        return id;
    }

    void SetName(string name) {
        while (!Validation::IsValidation(name)) {
            cout << "Invalid name. The name must be alphabetic and between 5 and 20 characters. Try again: ";
            cin >> name;
        }
        this->name = name;
        cout << "Name set successfully." << " \n" << endl;
    }

    string getName() {
        return name;
    }

    void SetPassword(string password) {
        while (!Validation::IsValidationPassword(password)) {
            cout << "Invalid password. The password must be between 8 and 20 characters. Try again: ";
            cin >> password;
        }
        this->password = password;
        cout << "Password set successfully." << " \n" << endl;
    }

    string getPassword() {
        return password;
    }
};

// Client Class inheriting from Person
class Clint : public Person {
private:
    double balance;
public:

    Clint() {
        balance = 1500; 
    }

    Clint(int id, string name, double bal) : Person(id, name) {
        if (Validation::IsValidationBalance(bal)) {
          this->  balance = balance;
        }
        else {
            this->balance = 1500; 
            cout << "Invalid balance provided. Balance initialized to 1500." << endl;
        }
        cout << "Parameterized constructor called. Client details initialized." << endl;
    }

    void SetBalance(double balance) {
        while (!Validation::IsValidationBalance(balance)) {
            cout << "Invalid balance. The balance must be at least 1500. Try again: ";
            cin >> balance;
        }
        this->balance = balance;
        cout << "Balance set successfully." << " \n" << endl;
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

// Employee class inheriting from Person
class Employee : public Person {
private:
    double salary;

public:
    // Employee Constructor
    Employee(int id = 0, string name = " omar ", string passeord = "0", double salary = 0.0) {
        this->id = id;
        this ->name = name;
        this->password = password;
        this->salary = salary;
    }

    // Setters and Getters for Employee details
    void setsalary(double s) {
        while (!Validation::IsValidationSalary(s)) {
            cout << "Salary must not be less than 5000. Try again: ";
            cin >> s;
        }
        salary = s;
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

// Admin Class
class Admin : public Person {
private:
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
    void setSalary(double s) {
        while (!Validation::IsValidationSalary(s)) {
            cout << "Invalid salary. Salary must be at least 5000. Try again: ";
            cin >> s;
        }
        salary = s;
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
    Clint c1(1, "Alice", 2000);  
    c1.deposit(500);             
    c1.withdraw(100);            
    Clint c2(2, "Bob", 1500);    
    c1.transferTo(200, c2);      

    // Display client details
    cout << "Client c1 details: " << endl;
    c1.Display();

    cout << "Client c2 details: " << endl;
    c2.Display();

    // Employee Testing
    Employee e1(3, "Charlie", "empPass", 6000);
    e1.display();                              

    // Admin Testing
    Admin a1(4, "Diana", "adminPass", 7000);   
    a1.display();
}