
#include "source/Compare.cpp"
#include "Graph.hpp"



int main()
{
    Graph graph(std::string("../test/test_data/test1"), false);
    Compare(graph);
    return 0;
}