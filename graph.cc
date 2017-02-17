#include "graph.hh"

typedef unordered_map<string, unordered_set<string>> Graph_t;  

Graph_t buildGraph( const vector<Edge>& edges )
{
Graph_t graph;
for ( auto& e : edges ) graph[e.start].emplace( e.end );
return graph;
}
