/**
 * @file Dijkstra.hpp
 * @author Staszkiewicz Richard (corresponding author)
 * @author Bednarczyk Andrzej
 * @date 09.11.2022
 * @copyright GNU Public license
 * */
#ifndef BRUT

#define BRUT
#include <vector>
#include <string>
#include <iostream>
#include "Graph.hpp"


class Brut
{
    private:
        Graph graph;
    public:
        Brut(Graph g);
        void set_Graph(Graph graph);
        Graph get_Graph();
        float exe(int start, int destination);
};

#endif