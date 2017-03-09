#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>

class GraphMatrix {
  private:
	typedef std::vector<std::vector<int>> matrix;
	matrix m_Values;
	int m_Size;
	char itoc(int i) {
		return i + 48;
	}
	int DFSCnt() {
	    int startNode = 0;
	    std::set<int> visited;
	    std::stack<int> stack;
	    stack.push(startNode);
	    visited.insert(startNode);
	    while (!stack.empty()) {
	        int node = stack.top();
	        stack.pop();
	        for (int i = 0; i < m_Size; i++) {
	            if (m_Values[node][i] && visited.find(i) == visited.end()) {
	                visited.insert(i);
	                stack.push(i);
	            }
	        }
	    }
	    return visited.size();
	}

  public:
	GraphMatrix(int size) : m_Size(size) {}
	std::string to_string() {
		std::string s;
		for (int i = 0; i < m_Size; i++)
			for (int j = 0; j < m_Size; j++)
				s.push_back(m_Values[i][j] + 48);
		return s;
	}
	void print() {
		for (int i = 0; i < m_Size; i++) {
			for (int j = 0; j < m_Size; j++)
				std::cout << m_Values[i][j] << ' ';
			std::cout << std::endl;
		}
	}
    matrix & v() {
    	return m_Values;
    }
    const int & size() const {
    	return m_Size;
    }
    void push_row(std::vector<int> row) {
    	m_Values.push_back(row);
    }

    bool isSCGraph() {
        if (DFSCnt() != m_Size)
            return false;

        reverse();
        //printMatrix(matrix, cntNodes);
        int cnt = DFSCnt();
        reverse();
        return cnt == m_Size;
    }

    void reverse() {
        for (int i = 1; i < m_Size; i++) {
            for (int j = 0; j < i; j++) {
                int tmp = m_Values[i][j];
                m_Values[i][j] = m_Values[j][i];
                m_Values[j][i] = tmp;
            }
        }
    }
};

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

//void printMatrix(std::vector<std::vector<int>> & matrix, int cnt) {
//    for (int i = 0; i < cnt; i++) {
//        for (int j = 0; j < cnt; j++)
//            std::cout << matrix[i][j] << ' ';
//        std::cout << std::endl;
//    }
//    std::cout << std::endl;
//}
//
//std::string convertToString(std::vector<std::vector<int>> matrix, int cntNodes) {
//	std::string s;
//	std::vector<std::string> subwords;
//	std::string buffer;
//	for (int node = 0; node < cntNodes; node++) {
//		for (int i = 0; i < cntNodes; i++)
//			buffer.push_back(matrix[i][node] + 48);
//		for (int j = 0; j < cntNodes; j++)
//			buffer.push_back(matrix[node][j] + 48);
//		subwords.push_back(buffer);
//		buffer.clear();
//	}
//	std::sort(subwords.begin(), subwords.end());
//	for (std::string & subword : subwords)
//		s.append(subword);
//	return s;
//}

std::set<std::string> nonisographs;
bool isomorphic(GraphMatrix & matrix) {
	std::string s = matrix.to_string();
	if (nonisographs.find(s) == nonisographs.end()) {
		nonisographs.insert(s);
		return true;
	}
	return false;
}

void generateGraphs(int i, int j, GraphMatrix & matrix, int numSymbols) {

    if (i == matrix.size()) {
        if (matrix.isSCGraph() && !isomorphic(matrix)) {
        	matrix.print();
        	std::cout << std::endl;
        }
        return;
    }
    int nexti;
    int nextj;
    if (j == matrix.size()) {
        nextj = 0;
        nexti = i + 1;
        generateGraphs(nexti, nextj, matrix, numSymbols);
        return;
    } else {
        nextj = j + 1;
        nexti = i;
        for (int k = 0; k < numSymbols; k++) {
            matrix.v()[i][j] = k;
            generateGraphs(nexti, nextj, matrix, numSymbols);
        }
    }
}

void generateGraphs(int cntNodes, int numSymbols) {
    GraphMatrix matrix(cntNodes);
    for (int i = 0; i < cntNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < cntNodes; j++)
            row.push_back(0);
        matrix.push_row(row);
    }
    generateGraphs(0, 0, matrix, std::pow(2,numSymbols));
}

int main(int argc, char** argv) {

    int cntNodes = 3;
//    GraphMatrix matrix1(cntNodes);
//    std::vector<int> row10 = { 1, 1, 1 };
//    std::vector<int> row11 = { 1, 1, 1 };
//    std::vector<int> row12 = { 1, 1, 1 };
//    matrix1.push_row(row10);
//    matrix1.push_row(row11);
//    matrix1.push_row(row12);
//    matrix1.print();
//    std::cout << std::boolalpha << matrix1.isSCGraph() << std::endl;
//    GraphMatrix matrix2(cntNodes);
//    std::vector<int> row20 = { 0, 1, 2 };
//    std::vector<int> row21 = { 1, 0, 2 };
//    std::vector<int> row22 = { 2, 2, 2 };
//    matrix2.push_row(row20);
//    matrix2.push_row(row21);
//    matrix2.push_row(row22);
//    matrix2.print();
//
//    std::cout << matrix1.to_string() << std::endl;
//    std::cout << matrix2.to_string() << std::endl;
    //std::cout << std::boolalpha << isSCGraph(matrix, cntNodes) << std::endl;



	generateGraphs(cntNodes, 2);
    std::cout << nonisographs.size() << std::endl;
    return 0;
}
