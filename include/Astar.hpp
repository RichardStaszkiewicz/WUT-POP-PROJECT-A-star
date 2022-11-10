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

/**
 * @class Astar Astar.hpp
 * @brief Class implementing environment of A* algorithm.
 *
 * Executes, handles and supervises operations needed to implement A* search on Graph.
 * */

class Astar
{
    public:
        /// @brief Graph the A* is searching
        Graph g;

    private:
        /// @brief Described destination of class current-state
        int D;

        /// @brief Vector of prefix sum of edges
        /// @paragraph Used to estimate the minimum potential raute to already set destination point
        std::vector <float> prefix_sum;

        /// @brief Vestor of edge distances from Astar::D
        /// @attention Set by Astar::prep function with BFS algorithm
        /// @paragraph Used to lookup the coefficiant to be taken from Astar::prefix_sum when counting heuristic value.
        std::vector <int> vertex_dist;

    /// @brief Constructor of Astar class
    /// @param graph The object describing the graph to be used by algorithm.
    public: Astar(Graph graph);

    public:
        /// @brief Prepares the graph for a new query of different destination
        /// @param destination The index of vertex to be searched in next query
        void prep(int destination);

        /// @brief Heuristic estimation of distance from start to current Astar::D
        /// @param start The point which heuristic distance from Astar::D we would like to know.
        /// @return Heuristic distance between start and Astar::D
        /// @paragraph Heuristic based on distance in edges from Astar::D assumes the route leads through the lowest-cost edges in graph.
        float heuristic(int start);

        /// @brief Executes the A* search algorithm
        /// @param start The index of starting point of the algorithm
        /// @param destination The index of destination point of the graph
        /// @param verbose Flag of wether user wants algorithm to raport raute on terminal
        /// @return The value of the shortest raute between start & destination as percived by A*
        float exe(int start, int destination, bool verbose = false);

        /// @brief Getter for Astar::vertex_dist attribute
        /// @return Astar::vertex_dist attribute
        std::vector <int> get_vertex_dist();
};

#endif