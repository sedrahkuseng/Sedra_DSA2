#include <iostream>
#include <vector>

bool isSafe(int v, std::vector<std::vector<int>>& graph, std::vector<int>& colors, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && c == colors[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(std::vector<std::vector<int>>& graph, int m, std::vector<int>& colors, int v) {
    int n = graph.size();
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, colors, c)) {
            colors[v] = c;
            if (graphColoringUtil(graph, m, colors, v + 1)) {
                return true;
            }
            colors[v] = 0; // Backtrack
        }
    }
    return false;
}

bool graphColoring(std::vector<std::vector<int>>& graph, int m) {
    std::vector<int> colors(graph.size(), 0);
    return graphColoringUtil(graph, m, colors, 0);
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors
    std::cout << "The graph " << (graphColoring(graph, m) ? "can" : "cannot") << " be colored with " << m << " colors." << std::endl;
    return 0;
}
