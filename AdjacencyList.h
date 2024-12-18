#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class AdjacencyList {
    private:
    //initialize adjacency list using a map where the key is the from URL
    //and the values are the to URLS and rank
    map<string, pair<vector<string>, double>> graph;

    public:
    AdjacencyList() = default;
    void insertEdge(const string from, const string to, double rank);
    void printGraph();
    void updateRank(int p);
    void PageRank(int p);
};