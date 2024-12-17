#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void dfs( int current, vector<int> &path, vector<vector<int>>&graph);
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs( 0, path, graph );
        return result;
    }

    void dfs( int current, vector<int> &path, vector<vector<int>>&graph) {
        path.push_back(current);
        if ( current == graph.size() - 1 ) {
            result.push_back(path);
            path.pop_back();
            return;
        }

        for( auto &neighbor : graph[current] ) {
            dfs( neighbor, path, graph );
        }

        path.pop_back();
    }
};