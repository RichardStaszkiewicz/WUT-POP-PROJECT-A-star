/**
 * @file Astar.cpp
 * @author Staszkiewicz Richard (corresponding author)
 * @author Bednarczyk Andrzej
 * @date 09.11.2022
 * @copyright GNU Public license
 * */

#include "Astar.hpp"
#include "Graph.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <queue>

Astar::Astar(Graph graph) : g(graph)
{
    std::vector<float> temp = std::vector<float> {}; // to hold all found edges distances
    for(auto i : g.connections)
    {
        for(auto j : i) temp.push_back(j.second);
    }
    std::sort(temp.begin(), temp.end()); // sorting those lengths
    std::vector<float> temp2 = std::vector<float> {};
    for(int i = 0; i < int(temp.size()); i += 2) temp2.push_back(temp[i]); //each length in temp1 was doubled - we remove those doubles
    prefix_sum = std::vector<float>{0};  // we initiate prefix sum with 0, as the distance of 0 edges from end is
    for(int i = 0; i < std::min(int(temp2.size()), g.no_vortex - 1); i++) prefix_sum.push_back(prefix_sum[i] + temp2[i]);
}

void Astar::prep(int destination)
{
    std::list <std::pair<int, int>> q;
    std::vector <bool> visited;
    visited.resize(g.no_vortex, false);
    vertex_dist.resize(g.no_vortex, 1000000);
    D = destination;

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

float Astar::heuristic(int start)
{
    if(vertex_dist[start] == 1000000) return 1000000;
    return prefix_sum[vertex_dist[start]];
}

float Astar::exe(int start, int destination, bool verbose = false)
{
    std::vector <bool> visited;
    visited.resize(g.no_vortex, false);
    std::priority_queue<std::pair <float, std::pair<float, int>>> q;
    // heuristic_cost, true_cost, vertex

    prep(destination);
    //always push the negative value -> the priority queue is outputing max
    q.push(std::make_pair(heuristic(start), std::make_pair(0, start)));

    int current_pos = start;
    if(verbose) std::cout << "pos\tcost\theura" <<std::endl;
    while(!q.empty())
    {
        auto x = q.top();
        q.pop();

        if(visited[x.second.second]) continue;
        else visited[x.second.second] = true;

        current_pos = x.second.second;
        if(verbose) std::cout << current_pos << "\t" << x.second.first << "\t" << heuristic(current_pos) << std::endl;
        if(x.second.second == destination) return -1 * x.second.first;


        for(auto neighbour : g.connections[current_pos])
        {
            if(!visited[neighbour.first])
            {
                q.push(std::make_pair(x.second.first - heuristic(neighbour.first) - neighbour.second, std::make_pair(x.second.first - neighbour.second, neighbour.first)));
            }
        }
    }
    return -1;
}

std::vector <int> Astar::get_vertex_dist() {return vertex_dist;}