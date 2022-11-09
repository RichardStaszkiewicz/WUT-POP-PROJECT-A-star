#include "Astar.hpp"
#include "Graph.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

Astar::Astar(Graph graph) : g(graph)
{
    std::vector<float> temp = std::vector<float> {};
    for(auto i : g.connections)
    {
        for(auto j : i) temp.push_back(j.second);
    }
    std::sort(temp.begin(), temp.end());
    std::vector<float> temp2 = std::vector<float> {};
    for(int i = 0; i < int(temp.size()); i += 2) temp2.push_back(temp[i]);
    prefix_sum.push_back(temp2[0]);
    for(int i = 1; i < std::min(int(temp2.size()), g.no_vortex - 1); i++) prefix_sum.push_back(prefix_sum[i-1] + temp2[i]);
}

void Astar::prep(int destination)
{
    std::list <std::pair<int, int>> q;
    std::vector <bool> visited;
    visited.resize(g.no_vortex, false);
    vertex_dist.resize(g.no_vortex, 1000000);

    visited[destination] = true;
    vertex_dist[destination] = 0;

    q.push_back(std::pair<int, int>{destination, 0});

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
    if(vertex_dist[start] == 1000000) return 1000000;
    return prefix_sum[vertex_dist[start]];
}

float Astar::exe(int start, int destination)
{
    std::vector <bool> visited;
    visited.resize(g.no_vortex, false);
    std::priority_queue<std::pair <float, std::pair<float, int>>> q;
    // heuristic_cost, true_cost, vertex

    prep(destination);
    //always push the negative value -> the priority queue is outputing max
    q.push(std::make_pair(heuristic(start, destination), std::make_pair(0, start)));

    int current_pos = start;
    while(!q.empty())
    {
        auto x = q.top();
        q.pop();

        if(visited[x.second.second]) continue;
        else visited[x.second.second] = true;

        current_pos = x.second.second;
        if(x.second.second == destination) return -1 * x.second.first;


        for(auto neighbour : g.connections[current_pos])
        {
            if(!visited[neighbour.first])
            {
                q.push(std::make_pair(x.second.first - heuristic(neighbour.first, destination) - neighbour.second, std::make_pair(x.second.first - neighbour.second, neighbour.first)));
            }
        }
    }
    return -1;
}

std::vector <int> Astar::get_vertex_dist() {return vertex_dist;}