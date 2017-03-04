#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <stack>


void print(int word, int wordlen) {
    int buffer = word;
    for (int i = 0; i < wordlen; i++) {
        if (buffer & 1)
            std::cout << 1;
        else
            std::cout << 0;
        buffer >>= 1;
    }
    std::cout << std::endl;
}

void maximumstrategy(int wordlength, int maximalStrategy, int prefixSize) {
    std::queue<std::pair<int, int>> candidates;
    candidates.push(std::make_pair(maximalStrategy, prefixSize));
    while (!candidates.empty()) {
        int candidate = candidates.front().first;
        int candidatePrefixSize = candidates.front().second;
        candidates.pop();
        print(candidate, wordlength);
        if (candidatePrefixSize == wordlength)
            continue;
        int postfixSize = wordlength - candidatePrefixSize; 
        for (int i = 0; i < postfixSize; i++) {
           int newPrefixSize = candidatePrefixSize + postfixSize - i;
           candidates.push(std::make_pair(candidate - (1 << i), newPrefixSize ));
        }
    }
}

void printMatrix(std::vector<std::vector<int>> & matrix, int cnt) {
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int DFSCnt(std::vector<std::vector<int>> graph, int cntNodes) {
    int startNode = 0;
    std::set<int> visited;
    std::stack<int> stack;
    stack.push(startNode);
    visited.insert(startNode);
    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();
        for (int i = 0; i < cntNodes; i++) {
            if (graph[node][i] && visited.find(i) == visited.end()) {
                visited.insert(i);
                stack.push(i);
            }
        }
    }
    return visited.size();
}

void reverse(std::vector<std::vector<int>> & matrix, int cntNodes) {
    for (int i = 1; i < cntNodes; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}


bool isSCGraph(std::vector<std::vector<int>> matrix, int cntNodes) {
    if (DFSCnt(matrix, cntNodes) != cntNodes)
        return false;

    reverse(matrix, cntNodes);
    //printMatrix(matrix, cntNodes);
    if (DFSCnt(matrix, cntNodes) != cntNodes)
        return false;
    reverse(matrix, cntNodes);
    return true;
}

int cnt_graphs = 0;
void generateGraphs(int i, int j, std::vector<std::vector<int>> & matrix, int cntNodes, int numSymbols) {
    if (i == cntNodes) {
        if (isSCGraph(matrix, cntNodes)) {
            printMatrix(matrix, cntNodes);
            cnt_graphs++;
        }
        return;
    }
    int nexti;
    int nextj;
    if (j == cntNodes) {
        nextj = 0;
        nexti = i + 1;
        generateGraphs(nexti, nextj, matrix, cntNodes, numSymbols);
        return;
    } else {
        nextj = j + 1;
        nexti = i;
        for (int k = 0; k <= numSymbols; k++) {
            matrix[i][j] = k;
            generateGraphs(nexti, nextj, matrix, cntNodes, numSymbols);
        }
    }
}

void generateGraphs(int cntNodes) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < cntNodes; i++) {
        std::vector<int> line;
        for (int j = 0; j < cntNodes; j++)
            line.push_back(0);
        matrix.push_back(line);
    }
    generateGraphs(0, 0, matrix, cntNodes, 1);
}

int main(int argc, char** argv) {
    /*
    int cntNodes = 5;
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < cntNodes; i++) {
        std::vector<int> line;
        for (int j = 0; j < cntNodes; j++)
            line.push_back(0);
        matrix.push_back(line);
    }
    for (int j = 0; j < cntNodes; j++)
        matrix[0][j] = 1;
    printMatrix(matrix, cntNodes);
    std::cout << std::boolalpha << isSCGraph(matrix, cntNodes) << std::endl;
    */
    generateGraphs(3);
    std::cout << cnt_graphs << std::endl;
    return 0;
}
