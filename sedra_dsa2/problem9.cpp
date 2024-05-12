#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <array>

struct TrieNode {
    TrieNode* children[26] = {};
    bool isEndOfWord = false;

    ~TrieNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

void insertWord(TrieNode* root, const std::string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children[c - 'A']) {
            node->children[c - 'A'] = new TrieNode();
        }
        node = node->children[c - 'A'];
    }
    node->isEndOfWord = true;
}

void searchWord(TrieNode* node, std::vector<std::vector<char>>& board, int x, int y, std::unordered_set<std::string>& foundWords, std::string currentWord) {
    if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '*' || !node->children[board[x][y] - 'A']) {
        return;
    }

    currentWord += board[x][y];
    node = node->children[board[x][y] - 'A'];

    if (node->isEndOfWord) {
        foundWords.insert(currentWord);
    }

    char temp = board[x][y];
    board[x][y] = '*'; // Mark the cell as visited

    std::array<std::pair<int, int>, 8> directions = { {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}} };
    for (auto [dx, dy] : directions) {
        searchWord(node, board, x + dx, y + dy, foundWords, currentWord);
    }

    board[x][y] = temp; // Unmark the cell, backtrack
}

std::unordered_set<std::string> findWords(std::vector<std::string>& dictionary, std::vector<std::vector<char>>& board) {
    TrieNode root;
    for (const std::string& word : dictionary) {
        insertWord(&root, word);
    }

    std::unordered_set<std::string> foundWords;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            searchWord(&root, board, i, j, foundWords, "");
        }
    }

    return foundWords;
}

int main() {
    std::vector<std::string> dictionary = { "CAT", "CAN", "CANT", "DOG", "DOGS", "ANT" };
    std::vector<std::vector<char>> board = {
        {'C', 'A', 'N'},
        {'D', 'O', 'G'},
        {'T', 'S', 'N'}
    };

    auto words = findWords(dictionary, board);
    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
