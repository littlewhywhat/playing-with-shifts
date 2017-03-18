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
#include <fstream>

class GraphMatrix {
  private:
	typedef std::vector<std::vector<int>> matrix;
	matrix m_Values;
	int m_Size;
    std::string m_Filename;
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
			std::string isomorph = identity.multiply(*this).multiply(identity.inverse()).to_string();
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
    const matrix & v() const {
        return m_Values;
    }
    const int & size() const {
    	return m_Size;    }
    void push_row(std::vector<int> row) {
    	m_Values.push_back(row);
    }
    void pop_row() {
    	m_Values.pop_back();
    }

    void zeros() {
        if (!m_Values.size()) {
            for (int i = 0; i < m_Size; i++) {
                std::vector<int> row;
                for (int j = 0; j < m_Size; j++)
                    row.push_back(0);
                m_Values.push_back(row);
            }
        }
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

    GraphMatrix inverse() {
        GraphMatrix result(m_Size);
        for (int i = 0; i < m_Size; i++) {
            std::vector<int> row;
            for (int j = 0; j < m_Size; j++)
                row.push_back(m_Values[j][i]);
            result.push_row(row);
        }
        return result;
    }

    void set_filename(const std::string & filename) {
        m_Filename = filename;
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

    GraphMatrix multiply(const GraphMatrix & multiplicant) {
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

    void write_to_file() {
        std::fstream fs(m_Filename, std::ios_base::out);
        fs << m_Size << std::endl;
        for (int i = 0; i < m_Size; i++) {
            for (int j = 0; j < m_Size; j++) {
                int value = m_Values[i][j];
                int symbol = 0;
                while (value) {
                    if (value & 1)
                        fs << i << ',' << j << ',' << symbol << std::endl;
                    symbol++;
                    value >>= 1;
                }
            }
        }
        fs.close();
    }

    std::string & get_filename() {
        return m_Filename;
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

int countOnes(int num) {
    int cnt = 0;
    while (num) {
        if (num & 1)
            cnt++;
        num >>= 1;
    }
    return cnt;
}

std::set<std::string> nonisographs;

void generateGraphs(int i, int j, GraphMatrix & matrix, 
                    int maxEdges, int numECodes) {

    if (i == matrix.size() || !maxEdges) {
        //matrix.print();
        if (
       		   //!matrix.is_trivial() &&
				matrix.isSCGraph()
				&&
				!matrix.isomorphic_to(nonisographs)
				) {
            matrix.print();
            std::string basefilename = matrix.get_filename();
            std::string newfilename = basefilename;
            newfilename.append(std::to_string(nonisographs.size()));
        	matrix.set_filename(newfilename);
            nonisographs.insert(matrix.to_string());

        	matrix.write_to_file();
            matrix.set_filename(basefilename);
        }
        return;
    }
    int nexti;
    int nextj;
    if (j == matrix.size()) {
        nextj = 0;
        nexti = i + 1;
        generateGraphs(nexti, nextj, matrix, maxEdges, numECodes);
        return;
    } else {
        nextj = j + 1;
        nexti = i;

        for (int k = 0; k < numECodes; k++) {
            int cntEdges = countOnes(k);
            int nextMaxEdges = maxEdges - cntEdges;
            if (nextMaxEdges >= 0) {
                matrix.v()[i][j] = k;          
                generateGraphs(nexti, nextj, matrix, nextMaxEdges, numECodes);
            }
        }
        matrix.v()[i][j] = 0;
    }

}

void generateGraphs(int cntNodes, int maxEdges, int numSymbols, std::string & filename) {
    GraphMatrix matrix(cntNodes);
    matrix.set_filename(filename);
    for (int i = 0; i < cntNodes; i++) {
        std::vector<int> row;
        for (int j = 0; j < cntNodes; j++)
            row.push_back(0);
        matrix.push_row(row);
    }
    std::cout << (int) std::pow(2, numSymbols) << std::endl;
    generateGraphs(0, 0, matrix, maxEdges, std::pow(2,numSymbols));

}

void generateGraphsByTemplateR(GraphMatrix & matrix, int i, int j, int numECodes) {
    if (i == matrix.size()) {
        if (
            !matrix.is_trivial() 
            && 
            !matrix.isomorphic_to(nonisographs)
            ) {
            std::string basefilename = matrix.get_filename();
            std::string newfilename = basefilename;
            newfilename.append(std::to_string(nonisographs.size()));
            matrix.set_filename(newfilename);
            nonisographs.insert(matrix.to_string());

            matrix.write_to_file();
            matrix.set_filename(basefilename);
        }
        return;
    }
    if (j == matrix.size()) {
        generateGraphsByTemplateR(matrix, i + 1, 0, numECodes);
        return;
    }
    if (!matrix.v()[i][j]) {
        generateGraphsByTemplateR(matrix, i, j + 1, numECodes);
        return;
    }
    for (int code = 1; code < numECodes; code++) {
        matrix.v()[i][j] = code;
        generateGraphsByTemplateR(matrix, i, j + 1, numECodes);
    }
    matrix.v()[i][j] = 1;
}

GraphMatrix readOnesMatrix(const std::string & templatefile) {
    std::fstream fs(templatefile, std::ios::in);
    std::string buffer;
    std::getline(fs, buffer);
    GraphMatrix matrix(std::stoi(buffer));
    matrix.zeros();
    char DELIM = ',';
    int n1, n2, lbl = 1;
    while (std::getline(fs, buffer, DELIM)) {
        n1 = std::stoi(buffer);
        if (!std::getline(fs, buffer))
            throw "Error while reading n1 in file";
        n2 = std::stoi(buffer);
        std::cout << n1 << ' ' << n2 << std::endl;
        matrix.v()[n1][n2] = lbl;
    }
    fs.close();
    return matrix;
}

void generateGraphsByTemplate(const std::string & templatefile, int numECodes) {
    if (!numECodes)
        return;
    GraphMatrix sample = readOnesMatrix(templatefile);
    std::string filename(templatefile);
    filename.push_back('_');
    sample.set_filename(filename);
    generateGraphsByTemplateR(sample, 0, 0, numECodes);
}

// cntNodes, maxEdges
int main(int argc, char** argv) {

    if (argc < 3) {
        std::cout << "not enough arguments" << std::endl;
        return 0;
    }
    int cntNodes = std::stoi(argv[1]);
    int maxEdges = std::stoi(argv[2]);
    std::string filename(argv[3]);
    int numSymbols = 2;

    // int cntNodes = 4;
    // GraphMatrix matrix1(cntNodes);
    // std::vector<int> row10 = { 0, 0, 0, 1 };
    // std::vector<int> row11 = { 1, 0, 0, 0 };
    // std::vector<int> row12 = { 1, 0, 0, 0 };
    // std::vector<int> row13 = { 0, 1, 1, 0 };
    // matrix1.push_row(row10);
    // matrix1.push_row(row11);
    // matrix1.push_row(row12);
    // matrix1.push_row(row13);
    // matrix1.print();
    // GraphMatrix matrix2(cntNodes);
    // std::vector<int> row20 = { 0, 0, 0, 1 };
    // std::vector<int> row21 = { 0, 0, 0, 1 };
    // std::vector<int> row22 = { 1, 1, 0, 0 };
    // std::vector<int> row23 = { 0, 0, 1, 0 };
    // matrix2.push_row(row20);
    // matrix2.push_row(row21);
    // matrix2.push_row(row22);
    // matrix2.push_row(row23);
    // matrix2.print();
    // std::cout << std::endl;
    // //matrix2.multiply(matrix1).print().multiply(matrix2.inverse()).print();
    // nonisographs.insert(matrix1.to_string());
    // std::cout << std::boolalpha << matrix2.isomorphic_to(nonisographs) << std::endl;

    // try {
    //     GraphMatrix matrix = readOnesMatrix(filename);
    //     matrix.print();
    // } catch (const char * e) {
    //     std::cout << e << std::endl;
    //     return 0;
    // }

    //generateGraphs(cntNodes, maxEdges, numSymbols, filename);
	generateGraphsByTemplate(filename, std::pow(2, numSymbols));
    std::cout << nonisographs.size() << std::endl;
    return 0;
}
