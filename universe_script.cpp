#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>

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

std::string convertToString(std::vector<std::vector<int>> matrix, int cntNodes) {
	std::string s;
	std::vector<std::string> subwords;
	std::string buffer;
	for (int node = 0; node < cntNodes; node++) {
		for (int i = 0; i < cntNodes; i++)
			buffer.push_back(matrix[i][node] + 48);
		for (int j = 0; j < cntNodes; j++)
			buffer.push_back(matrix[node][j] + 48);
		subwords.push_back(buffer);
		buffer.clear();
	}
	std::sort(subwords.begin(), subwords.end());
	for (std::string & subword : subwords)
		s.append(subword);
	return s;
}

std::set<std::string> nonisographs;
bool isomorphic(std::vector<std::vector<int>> matrix, int cntNodes) {
	std::string s = convertToString(matrix, cntNodes);
	if (nonisographs.find(s) == nonisographs.end()) {
		nonisographs.insert(s);
		return true;
	}
	return false;
}

void generateGraphs(int i, int j, std::vector<std::vector<int>> & matrix, int cntNodes, int numSymbols) {
    if (i == cntNodes) {
        if (isSCGraph(matrix, cntNodes) && !isomorphic(matrix, cntNodes))
        	printMatrix(matrix, cntNodes);
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
        for (int k = 0; k < numSymbols; k++) {
            matrix[i][j] = k;
            generateGraphs(nexti, nextj, matrix, cntNodes, numSymbols);
        }
    }
}

void generateGraphs(int cntNodes, int numSymbols) {
    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < cntNodes; i++) {
        std::vector<int> line;
        for (int j = 0; j < cntNodes; j++)
            line.push_back(0);
        matrix.push_back(line);
    }
    generateGraphs(0, 0, matrix, cntNodes, std::pow(2,numSymbols));
}

int main(int argc, char** argv) {

    int cntNodes = 3;
    std::vector<std::vector<int>> matrix1;
    std::vector<int> row10 = { 2, 2, 2 };
    std::vector<int> row11 = { 2, 0, 1 };
    std::vector<int> row12 = { 2, 1, 0 };
    matrix1.push_back(row10);
    matrix1.push_back(row11);
    matrix1.push_back(row12);
    printMatrix(matrix1, cntNodes);
    std::vector<std::vector<int>> matrix2;
    std::vector<int> row20 = { 0, 1, 2 };
    std::vector<int> row21 = { 1, 0, 2 };
    std::vector<int> row22 = { 2, 2, 2 };
    matrix2.push_back(row20);
    matrix2.push_back(row21);
    matrix2.push_back(row22);
    printMatrix(matrix2, cntNodes);

    std::cout << convertToString(matrix1, cntNodes) << std::endl;
    std::cout << convertToString(matrix2, cntNodes) << std::endl;
    //std::cout << std::boolalpha << isSCGraph(matrix, cntNodes) << std::endl;



	//generateGraphs(3, 2);
    //std::cout << noisographs.size() << std::endl;
    return 0;
}
