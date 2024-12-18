#include <iostream>
#include "AdjacencyList.h"
using namespace std;

int main()
{
    //initialize graph and use main template
    AdjacencyList graph;
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;

    for (int i = 0; i < no_of_lines; i++)
    {
        cin >> from;
        cin >> to;
        graph.insertEdge(from, to, 1);
    }

    graph.PageRank(power_iterations);
}
