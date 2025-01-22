#include"Graph.h"
#include"Queue.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include <cmath>
#include <thread>
using namespace std;
int main()
{
    int cases, city, aerial_route;

    cout << "Welcome to Emergency Travel Planner" << endl;
    cout << "Please enter the number of travel maps: ";
    cin >> cases;

    while (cases < 0 || cases > 11)
    {
        cout << "Invalid number of cases! Please enter a valid number: ";
        cin >> cases;
    }

    int cases_count = 0;

    while (cases_count != cases)
    {
        cout << "Please enter the number of cities for Travel Map " << cases_count + 1 << ": ";
        cin >> city;

        while (city < 0 || city > 200)
        {
            cout << "Invalid number of cities! Please enter a valid number: ";
            cin >> city;
        }

        Graph graph(city);

        cout << "Please enter the number of aerial routes for Travel Map " << cases_count + 1 << ": ";
        cin >> aerial_route;

        while (aerial_route < 0 || aerial_route >(city * (city - 1)))
        {
            cout << "Invalid number of aerial routes! Please enter a valid number: ";
            cin >> aerial_route;
        }

        system("cls");
        cin.ignore();

        for (int i = 1; i <= aerial_route; ++i)
        {
            string routes_input;
            cout << "Enter two integers separated by a space of Travel Map " << cases_count + 1 <<": ";

            getline(cin, routes_input);

            // Check if there is a space between num1 and num2
            size_t spacePos = routes_input.find(' ');
            if (spacePos == string::npos)
            {
                cout << "Invalid input. Please enter again with a space between the two integers: ";
                i--; // Decrement i to repeat the current iteration
                continue;
            }

            istringstream stream(routes_input);
            int num1, num2;
            const int routeType = 1;

            while ((stream >> num1 >> num2) && ((num1 >= city) || (num2 >= city)))
            {
                cout << "Invalid input. Please enter again: ";
                getline(cin, routes_input);
                stream.clear(); // Clear any error flags
                stream.str(routes_input); // Set a new string for input
            }

            graph.addEdge(num1, num2, routeType);
        }

        system("cls");

        graph.printAdjacencyList();
        std::this_thread::sleep_for(std::chrono::seconds(5));
        system("cls");
        graph.BFS();
        std::this_thread::sleep_for(std::chrono::seconds(5));

        cases_count++;

        system("cls");
        cin.ignore();
    }

    return 0;
}