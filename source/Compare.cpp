#include "Brut.hpp"
#include "Dijkstra.hpp"
#include "Astar.hpp"

#include <chrono>
#include <iostream>
#include <fstream>

void Compare(Graph graph, bool toFile = false, std::string FileName = "", bool verbose = false)
{
    float time = 0;

    std::ofstream myfile (FileName);

    float weight = 0;
    for(auto query : graph.questions)
    {
        Brut brut(graph);
        auto begin = std::chrono::high_resolution_clock::now();
        weight = brut.exe(query.first, query.second);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time += elapsed.count();
    }
    if(verbose)
        std::cout << "Elapsed brut time in nanoseconds : " << time << " ns" << std::endl;
    if (toFile)
        myfile << "Brut: " << time << ", " <<  weight << "\n";

    time = 0;
    for(auto query : graph.questions)
    {
        Dijkstra dijkstra(graph);
        auto begin = std::chrono::high_resolution_clock::now();
        dijkstra.exe(query.first, query.second);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time += elapsed.count();
    }
    if(verbose)
        std::cout << "Elapsed Dijkstra time in nanoseconds : " << time << " ns" << std::endl;
    if (toFile)
        myfile << "Dijkstra: " << time << ", " <<  weight << "\n";

    time = 0;
    Astar astar(graph);
    for(auto query : graph.questions)
    {
        astar.prep(query.second);
        auto begin = std::chrono::high_resolution_clock::now();
        astar.exe(query.first, query.second);
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        time += elapsed.count();
    }
    if(verbose)
        std::cout << "Elapsed A* time in nanoseconds : " << time << " ns" << std::endl;

    if (toFile)
        myfile << "A*: " << time << ", " <<  weight;

    myfile.close();
}