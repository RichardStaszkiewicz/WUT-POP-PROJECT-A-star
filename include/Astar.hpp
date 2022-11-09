/**
 * @file Graph.hpp
 * @author Staszkiewicz Richard (corresponding author)
 * @author Bednarczyk Andrzej
 * @date 09.11.2022
 * @copyright GNU Public license
 * */
#ifndef ASTAR

#define ASTAR
#include "Graph.hpp"
#include <vector>
#include <string>
#include <iostream>

class Astar
{
    public:
        Graph g;

    Astar(Graph graph);

    public:
        void exe(int start, int destination);
        float heuristic(int start, int destination);
};

#endif