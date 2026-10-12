#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int orderID;
    string foodItem;
    int quantity;
    Node* next;
};

Node* head = NULL;

// Add a new order
void addOrder()
{
    Node* newNode = new Node;

    cout << "Enter Order ID: ";
    cin >> newNode->orderID;

    cout << "Enter Food Item: ";
    cin >> newNode->foodItem;

    cout << "Enter Quantity: ";
    cin >> newNode->quantity;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Order added successfully!\n";
}

// Delete an order
void deleteOrder()
{
    int id;
    cout << "Enter Order ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->orderID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Order not found!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Order deleted successfully!\n";
}

// Search for an order
void searchOrder()
{
    int id;
    cout << "Enter Order ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->orderID == id)
        {
            cout << "\nOrder Found!\n";
            cout << "Order ID: " << temp->orderID << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            cout << "Quantity: " << temp->quantity << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found!\n";
}

// Display all orders
void displayOrders()
{
    if (head == NULL)
    {
        cout << "No pending orders.\n";
        return;
    }

    Node* temp = head;

    cout << "\n----- Pending Orders -----\n";

    while (temp != NULL)
    {
        cout << "Order ID: " << temp->orderID << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "--------------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Food Order Management System =====\n";
        cout << "1. Add Order\n";
        cout << "2. Delete Order\n";
        cout << "3. Search Order\n";
        cout << "4. Display Orders\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addOrder();
                break;

            case 2:
                deleteOrder();
                break;

            case 3:
                searchOrder();
                break;

            case 4:
                displayOrders();
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
