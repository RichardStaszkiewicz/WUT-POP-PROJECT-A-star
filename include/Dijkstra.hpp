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
        /// @brief Graph Dijkstra is searching
        Graph graph;
        
    public:
        /// @brief Constructor of Dijkstra class
        /// @param g The object describing the graph to be used by algorithm.
        Dijkstra(Graph g);

        /// @brief Setter for graph
        /// @param graph The object describing the graph to be used by algorithm.
        void set_Graph(Graph graph);

        /// @brief Getter for currently used graph
        /// @return Currently used graph
        Graph get_Graph();

        /// @brief Executes the Dijkstra search algorithm
        /// @param start The index of starting point of the algorithm
        /// @param destination The index of destination point of the graph
        /// @param verbose Flag of wether user wants algorithm to raport raute on terminal
        /// @return The value of the shortest raute between start & destination as percived by A*
        float exe(int start, int destination, bool verbose = false);

};

#endif