#include "Brut.hpp"
#include "Dijkstra.hpp"
#include "Astar.hpp"

#include <chrono>
#include <iostream>

void Compare(Graph graph)
{
    auto begin = std::chrono::high_resolution_clock::now();
    Brut brut(graph);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Elapsed brut time in nanoseconds : " << elapsed.count() << " ns" << std::endl;
    begin = std::chrono::high_resolution_clock::now();
    Dijkstra dijkstra(graph);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Elapsed dijkstra time in nanoseconds : " << elapsed.count() << " ns" << std::endl;
    // begin = std::chrono::high_resolution_clock::now();
    // Astar astar(graph);
    // end = std::chrono::high_resolution_clock::now();
    // elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // std::cout << "Elapsed astar time in nanoseconds : " << elapsed.count() << " ns" << std::endl;
}