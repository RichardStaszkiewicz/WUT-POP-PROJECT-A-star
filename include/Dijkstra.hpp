/**
 * @file Dijkstra.hpp
 * @author Staszkiewicz Richard (corresponding author)
 * @author Bednarczyk Andrzej
 * @date 09.11.2022
 * @copyright GNU Public license
 * */
#ifndef DIJKSTRA

#define DIJKSTRA
#include <vector>
#include <string>
#include <iostream>
#include "Graph.hpp"


class Dijkstra
{
    private:
        Graph graph;
    public:
        Dijkstra(Graph g);
        void set_Graph(Graph graph);
        Graph get_Graph();
        float exe(int start, int destination);

};

#endif