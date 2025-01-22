#pragma once
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
#include <thread>
using namespace std;

class GraphNode
{
public:
    int data;
    int routeType;
    GraphNode* next;

    GraphNode(int x, int type)
    {
        data = x;
        routeType = type;
        next = nullptr;
    }
};

class Graph
{
private:
    int numCities;
    GraphNode** adjacencyList;

public:
    Graph(int num)
    {
        numCities = num;
        adjacencyList = new GraphNode * [numCities];
        for (int i = 0; i < numCities; ++i)
        {
            adjacencyList[i] = nullptr;
        }

        createRoadConnections(); // When Graph is created Node connection is Created
    }

    void addEdge(int source, int destination, int routeType)
    {
        // If the cities are adjacent, set route type to road (0)
        if (abs(source - destination) == 1)
        {
            routeType = 0;
        }

        GraphNode* newNode = new GraphNode(destination, routeType);
        newNode->next = adjacencyList[source];
        adjacencyList[source] = newNode;
    }

    void createRoadConnections()
    {
        for (int i = 0; i < numCities - 1; ++i)
        {
            addEdge(i, i + 1, 0);
        }
    }

    void BFS()
    {
        bool* visited = new bool[numCities];
        double* distance = new double[numCities];

        for (int i = 0; i < numCities; ++i)
        {
            visited[i] = false;
            distance[i] = -1.0;
        }

        Queue q;

        q.enqueue(0);
        visited[0] = true;
        distance[0] = 0.0;

        while (!q.isEmpty())
        {
            int currentCity = q.Front();
            q.dequeue();

            GraphNode* current = adjacencyList[currentCity];
            while (current != nullptr)
            {
                int neighbor = current->data;

                if (!visited[neighbor])
                {
                    q.enqueue(neighbor);
                    visited[neighbor] = true;

                    double value = 0.16;  // Set the initial value for the edge distance

                    if (current->routeType == 1) // If the route type is aerial, update the value accordingly
                    {
                        if (neighbor < currentCity)
                        {
                            distance[neighbor] = ceil(distance[currentCity]);// Stay at the current city, round up to a positive integer
                        }
                        else
                        {
                            distance[neighbor] = ceil(distance[currentCity] + value); // Move to the next city, round up to a positive integer
                        }
                    }
                    else
                    {
                        distance[neighbor] = distance[currentCity] + value; // Update distance for the neighbor for road route
                    }

                    
                    if (fmod(distance[neighbor], 1.0) == 0.96) // If the sum of distance modulo 1 is 0.96, round up the distance
                    {
                        distance[neighbor] = ceil(distance[neighbor]);
                    }

                    
                    if (neighbor == numCities - 1) // If the neighbor is the last city (city 30), print the result
                    {
                        cout << "Shortest distance from 0 to " << numCities << ": " << ceil(distance[neighbor]) << " days" << endl;
                        return;  // Stop the BFS since you only need the distance to the last node
                    }
                }

                current = current->next;
            }
        }

        delete[] visited;
        delete[] distance;
    }



    // ya dono print function bs asa h hai  sb kch check krna k lia ha bss
    void printAdjacencyList()
    {
        for (int i = 0; i < numCities; ++i)
        {
            cout << "Cities Connection " << i << ": ";

            GraphNode* current = adjacencyList[i];
            while (current != nullptr)
            {
                cout << current->data << "(" << (current->routeType == 0 ? "Road" : "Aerial") << ") ";
                current = current->next;
            }

            cout << endl;
        }
    }

    ~Graph()
    {
        for (int i = 0; i < numCities; ++i)
        {
            GraphNode* current = adjacencyList[i];
            while (current != nullptr)
            {
                GraphNode* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] adjacencyList;
    }
};