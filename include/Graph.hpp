/**
 * @file Graph.hpp
 * @author Staszkiewicz Richard (corresponding author)
 * @author Bednarczyk Andrzej
 * @date 09.11.2022
 * @copyright GNU Public license
 * */
#ifndef GRAPH

#define GRAPH
#include <vector>
#include <string>
#include <iostream>

class Graph
{
    public:
        int no_edges = 0;
        int no_vortex = 0;
        int no_questions = 0;
        std::vector< std::vector< std::pair <int, float> > > connections;
        std::vector< std::pair <int, int> > questions;

        Graph();
        Graph(std::string dir);
};

#endif