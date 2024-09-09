#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Validation {
public:
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

    bool IsValidationPassword(string password) {
        if (password.size() < 8 || password.size() > 20) {
            return false;
        }
        return true;
    }

    bool IsValidationBalance(double balance) {
        if (balance < 1500) {
            return false;
        }
        return true;
    }
    bool IsValidationSalary(double& s)
    {
        if (s < 5000) {

            return false;
        }

        return true;
    }

};

class Clint : public Validation {
private:
    int id;
    string name, password;
    double balance;
public:
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

    string grtPassword() {
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

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully. New balance: " << balance << endl;
        }
        else {
            cout << "Invalid amount. Deposit amount must be positive." << endl;
        }
    }

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


    void checkBalance() {
        cout << "Current balance: " << balance << endl;
    }

    void Display() {
        cout << "Client ID: " << id << endl;
        cout << "Client Name: " << name << endl;
        cout << "Client Balance: " << balance << endl;
    }
};

/////////////////////////////////////////////////////////////////////////////
//Employee class
class Employee : public Validation
{
private:
    int id;
    string name;
    string password;
    double salary;


public:
    Employee(int i = 0, string n = " not found ", string p = "0", double s = 0.0)
    {

        id = i;
        name = n;
        password = p;
        salary = s;

    }

    void setid(int d)
    {
        id = d;
    }

    int getid()
    {
        return id;
    }

    void setname(string n)
    {
        if (Validation::IsValidation(n))
        {

            name = n;
        }

        else
        {
            cout << "Enter name size between 5 and 20 characters and must be alphabetic " << endl;
        }



    }

    string getname()
    {
        return name;
    }

    void setpassword(string p)
    {

        if (Validation::IsValidationPassword(p))
        {

            password = p;
        }


        else
        {
            cout << "Password must be between 8 and 20 characters " << endl;
        }
    }

    string getpassword()
    {
        return password;
    }


    void setsalary(double s)
    {
        if (Validation::IsValidationSalary(s))
        {
            salary = s;
        }

        else
        {
            cout << "salary must not be less than 5000  " << endl;
        }
    }

    double getsalary()
    {
        return salary;
    }

    void display()
    {

        cout << "Employee Info :" << endl;
        cout << "Id : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Password : " << password << endl;
        cout << "Salary : " << salary << endl;
    }
};
int main()
{
    //clint 
    string name, password;
    int Id;
    double balance, deposit, withdraw, transfer;

    Clint c, c1, c2;
    cout << "clint info: " << endl;

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

    cout << "Enter deposit : ";
    cin >> deposit;
    c.deposit(deposit);

    cout << "Enter withdrawal : ";
    cin >> withdraw;
    c.withdraw(withdraw);

    cout << "Enter transfer : ";
    cin >> transfer;
    c1.transferTo(transfer, c2);

    c.checkBalance();

    cout << "Client c1 details: " << endl;
    c1.Display();

    cout << "Client c2 details: " << endl;
    c2.Display();


    cout << endl;
    //Employee

    cout << "Employee info: " << endl;
    Employee E1;
    double salary;


    cout << "Enter ID: ";
    cin >> Id;
    E1.setid(Id);

    cout << "Enter name: ";
    cin >> name;
    E1.setname(name);

    cout << "Enter password: ";
    cin >> password;
    E1.setpassword(password);

    cout << "Enter salary: ";
    cin >> salary;
    E1.setsalary(salary);

    cout << endl;
    E1.display();

    return 0;
}
