
#include "source/Compare.cpp"
#include "Graph.hpp"
#include "Dijkstra.hpp"

#include <iostream>
#include <filesystem>

int main()
{
    for (const auto& dirEntry : std::filesystem::__cxx11::recursive_directory_iterator("../test/test_data/")){
        std::filesystem::path p(dirEntry.path());
        Graph graph(std::string(dirEntry.path()), false);
        Compare(graph, true, "../test/test_timed/" + std::string(p.filename()) );
        std::cout << dirEntry.path() << std::endl;
    }

    return 0;
}