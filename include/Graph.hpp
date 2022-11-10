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

/**
 * @class Graph Graph.hpp
 * @brief Class implementing the software representation of the search graph & query's.
 *
 * Loads data and provides constructed data storage for the graph-search algorithms. Compatible with
 * Astar, Brut & Dijkstra classes.
 * */
class Graph
{
    public:
        /// @brief Number of edges in the graph
        int no_edges = 0;
        /// @brief Number of vertexes in the graph
        int no_vortex = 0;
        /// @brief Number of declared query's in the input file
        int no_questions = 0;
        /// @brief The representation of connections between vertexes
        /// It can be represented as
        /// Vertex   Connections (Vertex, dist)
        ///  [0]     (7, 4.3), (1, 5.6)
        ///  [1]     (0, 5.6)
        ///  [2]     (7, 2.1)
        ///  ...
        ///  [7]     (0, 4.3), (2, 2.1)
        std::vector< std::vector< std::pair <int, float> > > connections;

        /// @brief The representation of defined query's
        /// The representation is in form of (start, destination) vector
        std::vector< std::pair <int, int> > questions;

        Graph();
        /// @brief Constructor with input file
        /// @param dir Path to file where graph data is provided
        /// @param verbose Flag wether to make data loading interactive. Default: False.
        Graph(std::string dir, bool verbose);
};

#endif