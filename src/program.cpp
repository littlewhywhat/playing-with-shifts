#include <iostream>
#include <vector>
#include <string>

class Node;
class DEdge;

class DEdge {
  public:
    DEdge(Node * to, char eVal) : m_Val(eVal), m_To(to) {}
    char m_Val;
    Node * m_To;
};

class Node {
  public:
    char m_Val;
    std::vector<DEdge*> edges;
    Node(char val) : m_Val(val) {}
    ~Node() {
        for (DEdge * edge : edges)
            delete edge;
    }
    Node * addEdge(Node * node, char eVal) {
        edges.push_back(new DEdge(node, eVal));
        return this;
    }
};
   
void read(std::vector<Node *> & graph) {
    Node * a = new Node('a');
    Node * b = new Node('b');
    Node * c = new Node('c');
    Node * d = new Node('d');
    a -> addEdge(c, '0');
    a -> addEdge(b, '1');
    b -> addEdge(d, '0');
    c -> addEdge(d, '0');
    c -> addEdge(b, '1');
    d -> addEdge(a, '0');
    
    graph.push_back(a);
    graph.push_back(b);
    graph.push_back(c);
    graph.push_back(d);
}

void recurse(Node * node, int & count, int & lim, std::string & str) {
    if (count == lim) {
        std::cout << str <<  std::endl;
        return;
    }
    for (DEdge * edge : node -> edges) {
        count += 1;
        str.push_back(edge -> m_Val);
        recurse(edge -> m_To, count, lim, str);
        count -= 1;
        str.pop_back();
    }
}

int main (void) {
    int lim = 3;
    std::cout << "calculating... " << std::endl;
    std::vector<Node *> graph;
    read(graph);
    int count = 0;
    std::string str;
    for (Node * node : graph) {
       std::cout << node -> m_Val << ":" << std::endl;
       recurse(node, count, lim, str); 
    }
    for (Node * node : graph) 
       delete node; 
    return 0;

}
