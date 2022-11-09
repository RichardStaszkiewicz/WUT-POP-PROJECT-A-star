#include "Dijkstra.hpp"
#include <queue>
#define INF 0x3f3f3f3f
#include <iostream>

Dijkstra::Dijkstra(Graph g)
{
    set_Graph(g);
}

float Dijkstra::exe(int start, int destination)
{
    // Priority queue to store vertices that are being processed.
    std::priority_queue<std::pair <float, int>, std::vector<std::pair <float, int>>, std::greater<std::pair <float, int>> > pq;
    //vector to store distances of all vertices from the source vertex.
    std::vector<int> dist(graph.no_vortex, INF);
    // Insert source itself in priority queue and initialize its distance as 0. 
    pq.push(std::make_pair(0, start));
    // Looping until end reach
    while (dist[destination] == INF)
    {
        // get the vertex with minimum distance value
        int current = pq.top().second;
        if(dist[current] != INF){
        pq.pop();
        continue;
        }
        dist[current] = pq.top().first;
        pq.pop();

        // get all adjecent of current
        for (auto i : graph.connections[current]) {
            // Get vertex label and weight of current adjacent of u. 
            int ver = i.first;
            int weight = i.second;
            // If there is shorter path
            if (dist[ver] > dist[current] + weight)
            {
                // Add new ver to queue
                pq.push(std::make_pair(dist[current] + weight, ver));
            }
        }
    }
    return dist[destination];
}
void Dijkstra::set_Graph(Graph graph)
{
    this->graph = graph;
}

Graph Dijkstra::get_Graph()
{
    return graph;
}