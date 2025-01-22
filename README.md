### Emergency Travel Planner
This project provides a solution to help travelers plan their journey back to a specific destination in the minimum number of days, considering road and aerial route constraints. The tool utilizes a graph-based algorithm to determine the shortest travel time while adhering to specified travel rules.

### Features
## Graph Representation: 
    Cities are represented as nodes, and routes (road or aerial) are represented as edges.
## Road Travel Constraint: 
    A traveler can visit up to 6 cities via road in one day.
## Aerial Travel Constraint: 
    A traveler can instantly reach the connected city via an aerial route, provided the rules are met.
## BFS Algorithm: 
    Implements Breadth-First Search (BFS) to calculate the shortest path in terms of days to reach the destination.
## Customizable Input: 
    Supports multiple travel maps with user-defined cities and aerial routes.
#### How It Works
The traveler starts at an initial city and aims to reach the destination city in the least number of days.
The travel graph is constructed:
## Road Routes: 
    Automatically added for adjacent cities.
## Aerial Routes: 
    Defined by the user.
## BFS is performed to find the shortest path:
    Days are calculated considering road and aerial constraints.Stops are managed to avoid backtracking via aerial routes.