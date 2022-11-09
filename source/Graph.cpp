#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <string>

Graph::Graph(std::string dir)
{
    std::ifstream in(dir);
    in >> no_vortex >> no_edges >> no_questions;
    std::vector< std::pair <int, float> > connections[no_vortex];
    int a, b;
    float d;

    for(int i = 0; i < no_edges; i++)
    {
        in >> a >> b >> d;
        connections[a].push_back(std::pair<int, float>{b, d});
        connections[b].push_back(std::pair<int, float>{a, d});
    }
}
