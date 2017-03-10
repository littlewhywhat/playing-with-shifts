#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

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

	bool isomorphic(GraphMatrix & identity, int i, std::set<std::string> & graph_strs) {
		if (i == m_Size) {
			std::string isomorph = identity.multiply(*this).multiply(identity).print().to_string();
			return graph_strs.find(isomorph) != graph_strs.end();
		}
		for (int j = 0; j < m_Size; j++) {
			bool is_occupied = false;
			for (int k = 0; k < i; k++)
				if (identity.v()[k][j]) {
					is_occupied = true;
					break;
				}
			if (!is_occupied) {
				identity.v()[i][j] = 1;
				if (isomorphic(identity, i + 1, graph_strs))
					return true;
				identity.v()[i][j] = 0;
			}
		}
		return false;
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
	GraphMatrix & print() {
		for (int i = 0; i < m_Size; i++) {
			for (int j = 0; j < m_Size; j++)
				std::cout << m_Values[i][j] << ' ';
			std::cout << std::endl;
		}
		std::cout << std::endl;
		return *this;
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
    void pop_row() {
    	m_Values.pop_back();
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

    bool isomorphic_to(std::set<std::string> & graph_strs)  {
    	GraphMatrix identity(m_Size);
    	for (int i = 0; i < m_Size; i++) {
    		std::vector<int> row;
    		for (int j = 0; j < m_Size; j++)
    			row.push_back(0);
    		identity.push_row(row);
    	}
    	return isomorphic(identity, 0, graph_strs);
    }

    GraphMatrix multiply(GraphMatrix & multiplicant) {
    	GraphMatrix result(m_Size);
    	for (int i = 0; i < m_Size; i++) {
    		std::vector<int> row;
    		result.push_row(row);
    	}
    	for (int i = 0; i < m_Size; i++)
    		for (int j = 0; j < m_Size; j++) {
    			int sum = 0;
    			for (int k = 0; k < m_Size; k++)
    				sum += m_Values[i][k] * multiplicant.v()[k][j];
    			result.v()[i].push_back(sum);
    		}
    	return result;
    }

    bool is_trivial() {
    	std::set<int> set;
    	for (int i = 0; i < m_Size; i++)
    		for (int j = 0; j < m_Size; j++)
    			if (m_Values[i][j] && set.find(m_Values[i][j]) == set.end())
    				set.insert(m_Values[i][j]);
    	return set.size() < 2;
    }
};

GraphMatrix & print(int word, int wordlen) {
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

std::set<std::string> nonisographs;

void generateGraphs(int i, int j, GraphMatrix & matrix, int numSymbols) {

    if (i == matrix.size()) {
//        if (
//        		//!matrix.is_trivial() &&
//				matrix.isSCGraph()
//				//&&
//				//!matrix.isomorphic_to(nonisographs)
//				) {
        	nonisographs.insert(matrix.to_string());

        	//matrix.print();
//        }
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
    GraphMatrix matrix1(cntNodes);
    std::vector<int> row10 = { 2, 2, 2 };
    std::vector<int> row11 = { 2, 0, 1 };
    std::vector<int> row12 = { 2, 1, 0 };
    matrix1.push_row(row10);
    matrix1.push_row(row11);
    matrix1.push_row(row12);
    matrix1.print();
    std::cout << std::endl;
    GraphMatrix matrix2(cntNodes);
    std::vector<int> row20 = { 0, 1, 2 };
    std::vector<int> row21 = { 1, 0, 2 };
    std::vector<int> row22 = { 2, 2, 2 };
    matrix2.push_row(row20);
    matrix2.push_row(row21);
    matrix2.push_row(row22);
    matrix2.print();
    std::cout << std::endl;
    nonisographs.insert(matrix1.to_string());
    std::cout << std::boolalpha << matrix2.isomorphic_to(nonisographs) << std::endl;


	//generateGraphs(cntNodes, 2);
    //std::cout << nonisographs.size() << std::endl;
    return 0;
}
