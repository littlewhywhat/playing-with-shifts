#include <iostream>
#include <vector>

class Node;
class DEdge;

class DEdge {
  private:
    char m_Val;
    Node * m_To;
  public:
    DEdge(Node * to, char eVal) : m_Val(eVal), m_To(to) {}
};

class Node {
  private:
    char m_Val;
    std::vector<DEdge*> edges;
  public:
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
    a -> addEdge(c, 0);
    a -> addEdge(b, 1);
    b -> addEdge(d, 0);
    c -> addEdge(d, 0);
    d -> addEdge(a, 0);
    
    graph.push_back(a);
    graph.push_back(b);
    graph.push_back(c);
    graph.push_back(d);
}

int main (void) {
    std::cout << "calculating... " << std::endl;
    std::vector<Node *> graph;
    read(graph);
    for (Node * node : graph) 
       delete node; 
    return 0;

}
