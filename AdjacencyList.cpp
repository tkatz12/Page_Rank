#include <iostream>
#include <iomanip>
#include "AdjacencyList.h"
using namespace std;

//prints the PageRank of all pages after p powerIterations in ascending
//alphabetical order of webpages and rounding rank to two decimal places
void AdjacencyList::PageRank(int p)
{
    //perform power iterations
    updateRank(p);

    //since using map, just have to print the respective page and rank
    for (auto node : graph)
    {
        cout << std::fixed << std::showpoint;
        cout << std::setprecision(2);
        cout << node.first << " " << node.second.second << endl;
    }
}

//insertEdge in the graph
void AdjacencyList::insertEdge(const string from, const string to, double rank)
{
    //add to graph
    graph[from].first.push_back(to);

    //check if to does not exist and initialize with empty list
    if (graph.find(to) == graph.end())
    {
        graph[to] = {vector<string>(), rank};
    }
}

//this was helpful for debugging
void AdjacencyList::printGraph()
{
    for (auto node : graph)
    {
        cout << std::fixed << std::showpoint;
        cout << std::setprecision(2);
        cout << node.first << ", Rank: " << node.second.second << ", To: ";

        for (auto outgoing : node.second.first)
        {
            cout << outgoing << " ";
        }

        cout << endl;
    }
}

//update ranks for each power iteration
void AdjacencyList::updateRank(int p)
{
    //initialize ranks to 1 / |V| when iterations = 1
    for (auto& node : graph)
    {
        node.second.second = 1.0 / graph.size();
    }

    //power iterations for p > 1
    for (int i = 1; i < p; i++)
    {
        //store new ranks for each node and reset for each iteration
        //to calculate current rank, r(t + 1), using r(t) in next loop
        map<string, double> new_ranks;
        for (auto& node : graph)
        {
            new_ranks[node.first] = 0.0;
        }

        //calculate the ranks for each node
        for (auto& node : graph)
        {
            //store the outgoing nodes for calculation
            vector<string> outgoing = node.second.first;

            //using the formula, calculate the appropriate ranks based on outdegrees
            if (!outgoing.empty())
            {
                for (string to : outgoing)
                {
                    new_ranks[to] += node.second.second / outgoing.size();
                }
            }
        }

        //update ranks in graph
        for (auto& node : graph)
        {
            node.second.second = new_ranks[node.first];
        }
    }
}
