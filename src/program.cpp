#include <iostream>
#include <vector>
#include <string>
#include <cstdint>

class Node;

class Edge {
  public:
    Edge(Node * node, char label) : m_Label(label), m_Node(node) {}
    char m_Label;
    Node * m_Node;
};

class Node {
  private:
    uint32_t m_Val;
    std::vector<Edge*> m_Out;
  public:
    Node(uint32_t val) : m_Val(val) {}
    ~Node() {
        for (Edge * edge : m_Out)
            delete edge;
    }
    uint32_t val() {
        return m_Val;
    }
    void add_out(Node * node, char label) {
        m_Out.push_back(new Edge(node, label));
    }
    const std::vector<Edge*> & out() const {
        return m_Out;
    }
};

class Graph {
  private:
    std::vector<Node*> m_Nodes;
  public:
    Graph(uint32_t size) {
        std::cout << "graph" << std::endl;
        for (uint32_t i = 0; i < size; i++)
            m_Nodes.push_back(new Node(i));
    }
    ~Graph() {
        for (Node * node : m_Nodes)
            delete node;
    }
    void addEdge(uint32_t from, uint32_t to, char label) {
        m_Nodes.at(from) -> add_out(m_Nodes.at(to), label);
    }
    const std::vector<Node*> & nodes() const {
        return m_Nodes;
    }
};
 
Graph read() {
    Graph graph(4);
    graph.addEdge(0, 1, '0');
    graph.addEdge(0, 1, '1');
    graph.addEdge(1, 2, '0');
    graph.addEdge(1, 3, '1');
    graph.addEdge(2, 3, '1');
    graph.addEdge(3, 0, '0');
    return graph;
}

void recurse(Node * node, int & count, int & lim, std::string & str) {
    if (count == lim) {
        std::cout << str <<  std::endl;
        return;
    }
    for (Edge * edge : node -> out()) {
        count += 1;
        str.push_back(edge -> m_Label);
        recurse(edge -> m_Node, count, lim, str);
        count -= 1;
        str.pop_back();
    }
}

int main (void) {
    int lim = 3;
    std::cout << "calculating... " << std::endl;
    Graph graph = read();
    int count = 0;
    std::string buffer;
    for (Node * node : graph.nodes()) {
       std::cout << node -> val() << ":" << std::endl;
       recurse(node, count, lim, buffer); 
    }
    return 0;
}
