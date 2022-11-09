#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <string>

GRAPH::Graph::Graph(){}

Graph::Graph(std::string dir, bool verbose=false)
{
    std::ifstream in(dir);
    in >> no_vortex >> no_edges >> no_questions;
    //std::vector< std::vector< std::pair <int, float> > > connections;
    int a, b;
    float d;
    for(int i = 0; i < no_vortex; i++) connections.push_back(std::vector< std::pair <int, float> >{});

    for(int i = 0; i < no_edges; i++)
    {
        in >> a >> b >> d;
        connections[a].push_back(std::pair<int, float>{b, d});
        connections[b].push_back(std::pair<int, float>{a, d});
        if(verbose){
            std::cout << "start: " << connections[b].back().first;
            std::cout << " end: " << connections[a].back().first;
            std::cout << " distance: " << connections[b].back().second <<std::endl;
        }
    }

    for(int i = 0; i < no_questions; i++)
    {
        in >> a >> b;
        questions.push_back(std::pair<int, int>{a, b});
    }
}
