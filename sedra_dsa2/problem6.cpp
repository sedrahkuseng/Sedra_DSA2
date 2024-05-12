#include <iostream>
#include <vector>
#include <string>

bool isSafe(int x, int y, int n, std::vector<std::vector<int>>& maze, std::vector<std::vector<bool>>& visited) {
    return (x >= 0 && x < n&& y >= 0 && y < n&& maze[x][y] == 1 && !visited[x][y]);
}

void solveMaze(std::vector<std::vector<int>>& maze, int x, int y, std::vector<std::string>& paths, std::string path, std::vector<std::vector<bool>>& visited) {
    int n = maze.size();
    // If the rat reaches the bottom-right corner, add the path to paths vector
    if (x == n - 1 && y == n - 1) {
        paths.push_back(path);
        return;
    }

    // Mark the cell as visited
    visited[x][y] = true;

    // Move right
    if (isSafe(x, y + 1, n, maze, visited)) {
        solveMaze(maze, x, y + 1, paths, path + 'R', visited);
    }

    // Move left
    if (isSafe(x, y - 1, n, maze, visited)) {
        solveMaze(maze, x, y - 1, paths, path + 'L', visited);
    }

    // Move down
    if (isSafe(x + 1, y, n, maze, visited)) {
        solveMaze(maze, x + 1, y, paths, path + 'D', visited);
    }

    // Move up
    if (isSafe(x - 1, y, n, maze, visited)) {
        solveMaze(maze, x - 1, y, paths, path + 'U', visited);
    }

    // Unmark the cell as visited for backtracking
    visited[x][y] = false;
}

std::vector<std::string> findPaths(std::vector<std::vector<int>>& maze) {
    std::vector<std::string> paths;
    int n = maze.size();
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) return paths; // If start or end is blocked

    std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
    solveMaze(maze, 0, 0, paths, "", visited);
    return paths;
}

int main() {
    std::vector<std::vector<int>> maze = { {1, 0, 0, 0},
                                          {1, 1, 0, 1},
                                          {0, 1, 0, 0},
                                          {1, 1, 1, 1} };
    std::vector<std::string> paths = findPaths(maze);
    for (const auto& path : paths) {
        std::cout << path << std::endl;
    }
    return 0;
}
