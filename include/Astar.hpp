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

    private:
        std::vector <float> prefix_sum;
        std::vector <int> vertex_dist;

    public: Astar(Graph graph);

    public:
        float exe(int start, int destination);
        void prep(int destination);
        float heuristic(int start, int destination);
        std::vector <int> get_vertex_dist();
};

#endif