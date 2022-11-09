#include "Astar.hpp"
#include "Graph.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>

Astar::Astar(Graph graph) : g(graph)
{
    std::vector<float> temp = std::vector<float> {};
    for(auto i : g.connections)
    {
        for(auto j : i) temp.push_back(j.second);
    }
    std::sort(temp.begin(), temp.end());
    for(int i = 0; i < int(temp.size()); i += 2) sorted.push_back(temp[i]);
}

void Astar::prep(int start)
{

    std::list <std::pair<int, int>> q;
    std::vector <bool> visited;
    visited.resize(g.no_vortex, false);
    vertex_dist.resize(g.no_vortex, 1000000);

    visited[start] = true;
    vertex_dist[start] = 0;

    q.push_back(std::pair<int, int>{start, 0});

    while(!q.empty())
    {
        std::pair<int, int> s = q.front();
        q.pop_front();

        for(auto neighbour : g.connections[s.first])
        {
            if(!visited[neighbour.first])
            {
                visited[neighbour.first] = true;
                vertex_dist[neighbour.first] = s.second+1;
                q.push_back(std::pair<int, int>{neighbour.first, s.second+1});
            }
        }
    }
}
float Astar::heuristic(int start, int destination)
{
    return 0;
}

std::vector <int> Astar::get_vertex_dist() {return vertex_dist;}