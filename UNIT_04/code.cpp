#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    string name;
    vector<Node*> children;

    Node(string dirName)
    {
        name = dirName;
    }
};

// Search for a directory
Node* searchDirectory(Node* root, string name)
{
    if (root == NULL)
        return NULL;

    if (root->name == name)
        return root;

    for (Node* child : root->children)
    {
        Node* result = searchDirectory(child, name);

        if (result != NULL)
            return result;
    }

    return NULL;
}

// Create a subdirectory
void createDirectory(Node* root)
{
    string parentName, newName;

    cout << "Enter parent directory name: ";
    cin >> parentName;

    Node* parent = searchDirectory(root, parentName);

    if (parent == NULL)
    {
        cout << "Parent directory not found!\n";
        return;
    }

    cout << "Enter new directory name: ";
    cin >> newName;

    if (searchDirectory(root, newName) != NULL)
    {
        cout << "Directory name already exists!\n";
        return;
    }

    Node* newNode = new Node(newName);
    parent->children.push_back(newNode);

    cout << "Directory created successfully!\n";
}

// Display the complete directory tree
void displayTree(Node* root, int level = 0)
{
    if (root == NULL)
        return;

    for (int i = 0; i < level; i++)
        cout << "  ";

    cout << "|-- " << root->name << endl;

    for (Node* child : root->children)
        displayTree(child, level + 1);
}

// Display subdirectories
void displaySubdirectories(Node* root)
{
    string name;

    cout << "Enter directory name: ";
    cin >> name;

    Node* directory = searchDirectory(root, name);

    if (directory == NULL)
    {
        cout << "Directory not found!\n";
        return;
    }

    if (directory->children.empty())
    {
        cout << "No subdirectories found.\n";
        return;
    }

    cout << "Subdirectories of " << name << ":\n";

    for (Node* child : directory->children)
        cout << child->name << endl;
}

int main()
{
    Node* root = new Node("Root");

    int choice;

    do
    {
        cout << "\n--- File Directory Tree ---\n";
        cout << "1. Create Directory\n";
        cout << "2. Display Directory Structure\n";
        cout << "3. Display Subdirectories\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createDirectory(root);
                break;

            case 2:
                displayTree(root);
                break;

            case 3:
                displaySubdirectories(root);
                break;

            case 4:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
