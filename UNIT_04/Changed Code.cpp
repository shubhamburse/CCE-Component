#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node* parent;
    vector<Node*> children;

    Node(string dirName, Node* p = NULL)
    {
        name = dirName;
        parent = p;
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

// Create a directory
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

    Node* newNode = new Node(newName, parent);
    parent->children.push_back(newNode);

    cout << "Directory created successfully!\n";
}

// Remove a directory and its descendants
void deleteSubtree(Node* node)
{
    for (Node* child : node->children)
        deleteSubtree(child);

    delete node;
}

void removeDirectory(Node* root)
{
    string name;

    cout << "Enter directory name to remove: ";
    cin >> name;

    Node* target = searchDirectory(root, name);

    if (target == NULL)
    {
        cout << "Directory not found!\n";
        return;
    }

    if (target == root)
    {
        cout << "Root directory cannot be removed!\n";
        return;
    }

    Node* parent = target->parent;

    for (int i = 0; i < (int)parent->children.size(); i++)
    {
        if (parent->children[i] == target)
        {
            parent->children.erase(parent->children.begin() + i);
            break;
        }
    }

    deleteSubtree(target);

    cout << "Directory removed successfully!\n";
}

// Display complete path
void displayPath(Node* directory)
{
    if (directory == NULL)
        return;

    if (directory->parent != NULL)
    {
        displayPath(directory->parent);
        cout << "/";
    }

    cout << directory->name;
}

void searchAndDisplayPath(Node* root)
{
    string name;

    cout << "Enter directory name to search: ";
    cin >> name;

    Node* result = searchDirectory(root, name);

    if (result == NULL)
    {
        cout << "Directory not found!\n";
        return;
    }

    cout << "Directory path: ";
    displayPath(result);
    cout << endl;
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

// Display immediate subdirectories
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

// Count immediate subdirectories
void countSubdirectories(Node* root)
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

    cout << "Number of immediate subdirectories: "
         << directory->children.size() << endl;
}

// Calculate maximum directory depth
int calculateDepth(Node* root)
{
    if (root == NULL)
        return 0;

    int maxDepth = 0;

    for (Node* child : root->children)
    {
        int depth = calculateDepth(child);

        if (depth > maxDepth)
            maxDepth = depth;
    }

    return maxDepth + 1;
}

int main()
{
    Node* root = new Node("Root");
    int choice;

    do
    {
        cout << "\n===== FILE DIRECTORY TREE =====\n";
        cout << "1. Create Directory\n";
        cout << "2. Remove Directory\n";
        cout << "3. Search Directory and Display Path\n";
        cout << "4. Display Directory Structure\n";
        cout << "5. Display Subdirectories\n";
        cout << "6. Count Subdirectories\n";
        cout << "7. Find Maximum Directory Depth\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                createDirectory(root);
                break;

            case 2:
                removeDirectory(root);
                break;

            case 3:
                searchAndDisplayPath(root);
                break;

            case 4:
                displayTree(root);
                break;

            case 5:
                displaySubdirectories(root);
                break;

            case 6:
                countSubdirectories(root);
                break;

            case 7:
                cout << "Maximum directory depth: "
                     << calculateDepth(root) - 1 << endl;
                break;

            case 8:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    deleteSubtree(root);

    return 0;
}
