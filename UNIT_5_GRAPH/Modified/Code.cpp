#include <iostream>
#include <string>
using namespace std;

int adj[20][20] = {0};
string rooms[20];
int n = 0;

// Display the adjacency matrix
void displayGraph()
{
    cout << "\nAdjacency Matrix:\n\t";

    for (int i = 0; i < n; i++)
        cout << rooms[i] << "\t";

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << rooms[i] << "\t";

        for (int j = 0; j < n; j++)
            cout << adj[i][j] << "\t";

        cout << endl;
    }
}

// Find a room by name
int findRoom(string name)
{
    for (int i = 0; i < n; i++)
    {
        if (rooms[i] == name)
            return i;
    }

    return -1;
}

// Insert a new room and its doorways
void insertRoom()
{
    if (n >= 20)
    {
        cout << "Maximum room limit reached!\n";
        return;
    }

    string name;

    cout << "Enter new room name: ";
    cin >> name;

    if (findRoom(name) != -1)
    {
        cout << "Room already exists!\n";
        return;
    }

    rooms[n] = name;
    n++;

    int count;

    cout << "Enter number of doorways for this room: ";
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string otherRoom;

        cout << "Enter connected room name: ";
        cin >> otherRoom;

        int j = findRoom(otherRoom);

        if (j == -1 || j == n - 1)
        {
            cout << "Invalid room name!\n";
            i--;
            continue;
        }

        adj[n - 1][j] = 1;
        adj[j][n - 1] = 1;
    }

    cout << "Room added successfully!\n";
    displayGraph();
}

// Remove a doorway between two rooms
void removeEdge()
{
    string r1, r2;

    cout << "Enter first room name: ";
    cin >> r1;

    cout << "Enter second room name: ";
    cin >> r2;

    int i = findRoom(r1);
    int j = findRoom(r2);

    if (i == -1 || j == -1)
    {
        cout << "Room not found!\n";
        return;
    }

    if (adj[i][j] == 0)
    {
        cout << "Doorway does not exist!\n";
        return;
    }

    adj[i][j] = 0;
    adj[j][i] = 0;

    cout << "Doorway removed successfully!\n";
    displayGraph();
}

// Display direct neighbours and degree
void displayNeighboursAndDegree()
{
    string name;

    cout << "Enter room name: ";
    cin >> name;

    int i = findRoom(name);

    if (i == -1)
    {
        cout << "Room not found!\n";
        return;
    }

    int degree = 0;

    cout << "Directly connected rooms:\n";

    for (int j = 0; j < n; j++)
    {
        if (adj[i][j] == 1)
        {
            cout << rooms[j] << endl;
            degree++;
        }
    }

    cout << "Degree of " << name << " = "
         << degree << endl;
}

int main()
{
    int edges, choice;

    cout << "Enter number of museum rooms: ";
    cin >> n;

    if (n < 1 || n > 20)
    {
        cout << "Invalid number of rooms!\n";
        return 0;
    }

    cout << "Enter room names:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> rooms[i];

        for (int j = 0; j < i; j++)
        {
            if (rooms[i] == rooms[j])
            {
                cout << "Duplicate room name!\n";
                return 0;
            }
        }
    }

    cout << "Enter number of doorways: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        string r1, r2;

        cout << "Enter two connected room names: ";
        cin >> r1 >> r2;

        int u = findRoom(r1);
        int v = findRoom(r2);

        if (u == -1 || v == -1 || u == v)
        {
            cout << "Invalid room names!\n";
            i--;
            continue;
        }

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    do
    {
        cout << "\n===== MUSEUM ROOM SYSTEM =====\n";
        cout << "1. Display Graph\n";
        cout << "2. Insert New Room and Doorways\n";
        cout << "3. Remove Doorway\n";
        cout << "4. Display Neighbours and Degree\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayGraph();
                break;

            case 2:
                insertRoom();
                break;

            case 3:
                removeEdge();
                break;

            case 4:
                displayNeighboursAndDegree();
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
