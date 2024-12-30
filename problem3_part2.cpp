#include <iostream>
#include <vector>
#include <set>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;
bool ValidPath(int n, vector<vector<int>>& edges, int source, int destination){
if (source == destination) {
        return true;
    }

    
    unordered_map<int, vector<int>> graph;
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    
    queue<int> q;
    unordered_set<int> visited;
    q.push(source);
    visited.insert(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        
        for (int neighbor : graph[node]) {
            if (neighbor == destination) {
                return true;
            }
            if (!visited.count(neighbor)) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return false;
}

int main(){
  int numVertices = 3;
    vector<vector< int>> edges = {{0, 1}, {0, 2}, {3, 5},{5,4},{4,3}};
    int source = 3, destination = 5;

    if (ValidPath(numVertices, edges, source, destination)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

return 0;
}
