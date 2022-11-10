#include "Brut.hpp"
#include <queue>
#define INF 0x3f3f3f3f

Brut::Brut(Graph g)
{
    set_Graph(g);
}

float Brut::exe(int start, int destination)
{
    // brute force algorithm
    std::queue<std::pair <int, float>> q;
    //vector to store distances of all vertices from the source vertex.
    std::vector<int> dist(graph.no_vortex, INF);
    // Insert source itself in priority queue and initialize its distance as 0.

    dist[start] = 0;
    for (int i = 1; i <= graph.no_vortex-1; i++)
    {
        for (int start = 0; start < graph.no_vortex; start++)
        {
            for (auto econn : graph.connections[start])
            {
                auto s = start;
                auto end = econn.first;
                auto dista = econn.second;
                if(dist[s] != INF && dist[s] + dista < dist[end]) dist[end] = dist[s] + dista;
            }
        }
    }
    if (dist[destination] == INF) return -1;
    return dist[destination];


}
void Brut::set_Graph(Graph graph)
{
    this->graph = graph;
}

Graph Brut::get_Graph()
{
    return graph;
}