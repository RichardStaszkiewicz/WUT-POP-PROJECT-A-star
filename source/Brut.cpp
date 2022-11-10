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
    //vector to store visited vertexes
    std::vector<int> visited(graph.no_vortex, 0);
    // Insert source itself in priority queue and initialize its distance as 0. 
    q.push(std::make_pair(0, start));
    dist[start] = 0;
    // Looping until end reach
    while (!q.empty())
    {
        // get the vertex with minimum distance value
        int current = q.front().second;
        if(visited[current] == 1){
        q.pop();
        continue;
        }
        visited[current] = 1;
        q.pop();
        // get all adjecent of current 
        for (auto i : graph.connections[current]) {
            // Get vertex label and weight of current adjacent of u. 
            int ver = i.first;
            int weight = i.second;
            // Add new ver to queue
            q.push(std::make_pair(dist[ver], ver));
            // If there is shorter path
            if (dist[ver] > dist[current] + weight)
            {
                // Update distance of ver
                dist[ver] = dist[current] + weight;
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