#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <string>

GRAPH::Graph::Graph(){}

Graph::Graph(std::string dir, bool verbose)
{
    std::ifstream in(dir);
    in >> no_vortex >> no_edges >> no_questions;
    // first line of file is to be consisted of Vortexes, Edges and Questions count

    int a, b;
    float d;
    for(int i = 0; i < no_vortex; i++) connections.push_back(std::vector< std::pair <int, float> >{});
    // creation of dummy vector of connections as Vortex size.

    for(int i = 0; i < no_edges; i++)
    {
        in >> a >> b >> d; // points A, B and distance btw them
        connections[a].push_back(std::pair<int, float>{b, d});
        connections[b].push_back(std::pair<int, float>{a, d});
        if(verbose){
            std::cout << "start: " << connections[b].back().first;
            std::cout << " end: " << connections[a].back().first;
            std::cout << " distance: " << connections[b].back().second <<std::endl;
        }
    }

    // reading the questions provided at the end of the file
    for(int i = 0; i < no_questions; i++)
    {
        in >> a >> b;
        questions.push_back(std::pair<int, int>{a, b});
    }
}
