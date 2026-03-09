#include <iostream>
#include <string>
using namespace std;

class Expense {              
public:
    string name;
    string category;
    float amount;
};

class ExpenseTracker {     

private:
    Expense expenses[100];
    int count;                    // Keeps track of the number of expenses added
    float budget;

public:

    ExpenseTracker() 
    {
        count = 0;
        budget = 0;
    }

    void setBudget() 
    {
        cout << "\nEnter Monthly Budget: ";
        cin >> budget;
    }

    void addExpense() 
    {

        cout << "\nEnter Expense Name: ";
        cin >> expenses[count].name;              // here expenses is array of the object count is current position of the array and name is the member of the class expense

        cout << "Enter Category (Food/Travel/Shopping/Entertainment/etc): ";
        cin >> expenses[count].category;

        cout << "Enter Amount: ";
        cin >> expenses[count].amount;

        count++;

        cout << "Expense added successfully!\n";
    }

    void displayExpenses() 
    {

        if(count == 0) 
        {
            cout << "\nNo expenses recorded.\n";
            return;
        }

        cout << "\n------ Expense List ------\n";

        for(int i = 0; i < count; i++) 
        {

            cout << i + 1 << ". "
                 << expenses[i].name << " | "        // This is just for the text formating so the output will be something food | travel | 3000
                 << expenses[i].category << " | ₹"
                 << expenses[i].amount << endl;
        }
    }

    void showSummary() 
    {

        float total = 0;

        for(int i = 0; i < count; i++) 
        {
            total += expenses[i].amount;               // It keep adding the expenses amount
        }

        cout << "\n------ Budget Summary ------\n";
        cout << "Budget: ₹" << budget << endl;
        cout << "Total Expenses: ₹" << total << endl;
        cout << "Remaining Budget: ₹" << budget - total << endl;

        if(total > budget) 
        {
            cout << "⚠ Warning: Budget Exceeded!\n";
        }
    }
};

int main() {

    ExpenseTracker obj1;

    int choice;

    do {

        cout << "\n========= Expense Tracker =========\n";
        cout << "1. Set Budget\n";
        cout << "2. Add Expense\n";
        cout << "3. Show Expenses\n";
        cout << "4. Show Summary\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch(choice) 
        {

            case 1:
                obj1.setBudget();
                break;

            case 2:
                obj1.addExpense();
                break;

            case 3:
                obj1.displayExpenses();
                break;

            case 4:
                obj1.showSummary();
                break;

            case 5:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } 
    while(choice != 5);

    return 0;
}