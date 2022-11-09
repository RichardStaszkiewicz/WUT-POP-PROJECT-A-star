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
        /// @brief Graph Brut is searching
        Graph graph;

    public:
        /// @brief Constructor of Brut class
        /// @param g The object describing the graph to be used by algorithm.
        Brut(Graph g);

        /// @brief Setter for graph
        /// @param graph The object describing the graph to be used by algorithm.
        void set_Graph(Graph graph);

        /// @brief Getter for currently used graph
        /// @return Currently used graph
        Graph get_Graph();

        /// @brief Executes the Brut search algorithm
        /// @param start The index of starting point of the algorithm
        /// @param destination The index of destination point of the graph
        /// @return The value of the shortest raute between start & destination as percived by Brut
        float exe(int start, int destination);
};

#endif