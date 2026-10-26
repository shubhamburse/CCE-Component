#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, edges;
    string rooms[20];
    int adj[20][20] = {0};

    cout << "Enter number of museum rooms: ";
    cin >> n;

    cout << "Enter room names:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Room " << i + 1 << ": ";
        cin >> rooms[i];
    }

    cout << "Enter number of doorways: ";
    cin >> edges;

    cout << "Enter connected room numbers:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Doorway " << i + 1 << " (room numbers): ";
        cin >> u >> v;

        if (u >= 1 && u <= n && v >= 1 && v <= n && u != v)
        {
            adj[u - 1][v - 1] = 1;
            adj[v - 1][u - 1] = 1;
        }
        else
        {
            cout << "Invalid room numbers!\n";
            i--;
        }
    }

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

    string searchRoom;
    int index = -1;

    cout << "\nEnter room name to find direct connections: ";
    cin >> searchRoom;

    for (int i = 0; i < n; i++)
    {
        if (rooms[i] == searchRoom)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Room not found!\n";
    }
    else
    {
        cout << "Rooms directly connected to "
             << searchRoom << ":\n";

        bool found = false;

        for (int j = 0; j < n; j++)
        {
            if (adj[index][j] == 1)
            {
                cout << rooms[j] << endl;
                found = true;
            }
        }

        if (!found)
            cout << "No directly connected rooms found.\n";
    }

    return 0;
}
