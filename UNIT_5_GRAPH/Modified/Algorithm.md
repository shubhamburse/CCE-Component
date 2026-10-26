# Algorithm
   
Step 1: Start the program.
Step 2: Accept the number of museum rooms and enter the name of each room.
Step 3: Initialize the adjacency matrix with zeros.
Step 4: Accept the number of doorways and enter the pairs of rooms connected by each doorway.
Step 5: Update the adjacency matrix by setting the corresponding entries to 1 for each connected room pair. Since doorways are assumed to be bidirectional, update both matrix[i][j] and matrix[j][i].
Step 6: Display the adjacency matrix.
Step 7: Display a menu containing the following operations:
Display Graph
Insert New Room and Doorways
Remove Doorway
Display Direct Neighbours
Calculate Degree of a Room
Exit
Step 8: Insert New Room
Accept the new room name.
Add a new vertex to the graph.
Enter the rooms connected to the new room.
Update the adjacency matrix with the new edges.
Display the updated graph.
Step 9: Remove Doorway
Accept the names of the two rooms connected by the doorway.
Check whether the edge exists.
If it exists, remove the edge by setting the corresponding matrix entries to 0.
Display the updated graph.
Otherwise, display an appropriate error message.
Step 10: Display Direct Neighbours
Accept the name of a room.
Find its corresponding row in the adjacency matrix.
Display all rooms connected directly to it.
Step 11: Calculate Degree
Accept the name of a room.
Find its corresponding row in the adjacency matrix.
Count the number of entries equal to 1.
Display the degree of that room.
Step 12: Repeat the menu until the user selects Exit.
Step 13: Stop the program.
