# Bank System

This is a simple banking system implemented in C++. It allows users to create and manage bank accounts, including depositing, withdrawing, and transferring funds. The system also includes basic validation for user input.

## Features

- **Create and Manage Clients:** Add new clients with their name, ID, password, and initial balance.
- **Deposit Funds:** Add money to a client's account.
- **Withdraw Funds:** Withdraw money from a client's account, with checks for sufficient balance.
- **Transfer Funds:** Transfer money between two clients.
- **Check Balance:** View the current balance of a client's account.
- **Input Validation:** Ensures that user inputs like name, password, balance, and salary meet predefined criteria.

## Getting Started

To get a local copy up and running, follow these simple steps.

### Prerequisites

You need a C++ compiler to build the project. If you are on Windows, you can use Visual Studio. If you are on a different operating system, you can use a compiler like g++.

### Installation & Running

1. **Clone the repo**
   ```sh
   git clone https://github.com/your_username/your_project_name.git
   ```
2. **Navigate to the project directory**
   ```sh
   cd your_project_name/Bank_system
   ```
3. **Compile the code**
   - **Using g++:**
     ```sh
     g++ Bank_system.cpp -o Bank_system
     ```
   - **Using Visual Studio:**
     Open the `Bank_system.sln` file in Visual Studio and build the project.
4. **Run the executable**
   - **If you used g++:**
     ```sh
     ./Bank_system
     ```
   - **If you used Visual Studio:**
     Run the project from within the IDE.

## Classes

The project is structured into several classes to manage different aspects of the banking system:

- **`Validation`:** A utility class that provides methods for validating user inputs such as name, password, balance, and salary.
- **`Person`:** A base class that contains common attributes for all individuals in the system, such as `id`, `name`, and `password`. It also inherits from the `Validation` class.
- **`Client`:** Represents a bank client and inherits from the `Person` class. It includes functionalities specific to clients, such as depositing, withdrawing, transferring funds, and checking the balance.
- **`Employee`:** Represents a bank employee and inherits from the `Person` class. It includes employee-specific attributes like `salary`.
- **`Admin`:** Represents a bank administrator and also inherits from the `Person` class, with attributes similar to an employee.
