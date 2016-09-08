#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <set>

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

// 0 - A, 1 - B

class Strategy {
  private:
    int m_Val;
  public:
    Strategy(int val) : m_Val(val) {}
    void incr() { m_Val++; }
    int32_t countB() {
        int val = m_Val;
        int32_t i = 0;
        while (val != 0) {
            if (val % 2 != 0)
                i++;
            val /= 2;
        }
        return i;
    }
};

class Language {
  private:
    std::set<std::string> m_Words;
  public:
    void add(std::string word) {
        m_Words.insert(word);
    }
    bool has(std::string word) {
        auto search = m_Words.find(word);
        return search != m_Words.end();
    }
    friend std::ostream & operator << (std::ostream & out, Language & l) {
        out << "language:" << std::endl;
        for (std::string word : l.m_Words)
            out << word << std::endl;
        return out;
    }
};

class Mode {
  public:
    bool good_strategy(Strategy s, Language l) const {
        return true;
    }
};

Graph readgraph() {
    Graph graph(4);
    graph.addEdge(0, 1, '0');
    graph.addEdge(0, 1, '1');
    graph.addEdge(1, 2, '0');
    graph.addEdge(1, 3, '1');
    graph.addEdge(2, 3, '1');
    graph.addEdge(3, 0, '0');
    return graph;
}

void dive(Language & l, Node * node, int & count, int & lim, std::string & str) {
    if (count == lim) {
        l.add(str);
        return;
    }
    for (Edge * edge : node -> out()) {
        count += 1;
        str.push_back(edge -> m_Label);
        dive(l, edge -> m_Node, count, lim, str);
        count -= 1;
        str.pop_back();
    }
}

Language readlang(Graph & graph, int lim) {
    Language l;
    int count = 0;
    std::string buffer;
    for (Node * node : graph.nodes()) {
       dive(l, node, count, lim, buffer); 
    }
    return l;
}

class TNode {
  private:
    char m_Label;
    std::vector<TNode * > m_Children;
  public:
    TNode(char label) : m_Label(label) {}
    bool hasChild(char label) {
        for (TNode node : m_Children)
            if (node -> m_Label == label)
                return true;
        return false;
    }
    void addChild(char label) {
        m_Children.push_back(new TNode(label));
    }
    const TNode * getChild(char label) {
        for (TNode * node : m_Children) 
            if (node -> m_Label == label)
                return node;
        return NULL;
    }
};

class Tree {
  private:
    TNode m_Root;
    void propagate(TNode & root, std::string word) {
        if (!root.hasChild(word.at(0)))    
            root.addChild(word.at(0));
        propagate(*root.getChild(word.at(0)));
    }
  public:
    void addWord(std::string word) {
        propagate(root, word);
    }
    const TNode & root() const {
        return root;
    }
};

int main (void) {
    std::cout << "calculating... " << std::endl;
    Graph graph = readgraph();
    Language lang = readlang(graph, 5);
    Strategy strat(0);
    Mode mode;
    int slen = 3;
    int max = 0;
    int num = 1 << slen;
    for (int i = 0; i < num; i++) {
        if (mode.good_strategy(strat, lang)
                && max < strat.countB())
            max = strat.countB();
        strat.incr();
    }
    std::cout << max << std::endl;
    return 0;
}
