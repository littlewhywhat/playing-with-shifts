#ifndef MODE2_H
#define MODE2_H

#include <cstdint>
#include <map>
#include <utility>

#include "strategy.h"
#include "wordtree.h"
#include "tnode.h"
#include "mode.h"
#include "alphabet.h"


class Restricts {
  private:
    std::map<uint32_t, std::set<char> *> m_Letters;
    std::map<uint32_t, bool> m_IsInit;
    std::set<char> * getSet(uint32_t pos) {
        auto set = m_Letters.find(pos);
        if (set == m_Letters.end())
            throw "No such pos to init"; 
        return set -> second;
    }
  public:
    Restricts(const Strategy & s) {
        for (uint32_t i = 0; i < s.lim(); i++)
            if (!s.at(i)) {
                m_IsInit.insert(std::make_pair(i, false));
                m_Letters.insert(std::make_pair(i, new std::set<char> ()));
            }
    }
    ~Restricts() {
        for (auto pair : m_Letters) 
            delete pair.second;
    }
    bool isInit(uint32_t pos) const {
        auto search = m_IsInit.find(pos);
        if (search != m_IsInit.end())
            return search -> second;
        throw "No such pos in rest";
    } 
    void init(const std::vector<TNode *> & children, uint32_t pos) {
        m_IsInit.erase(pos);
        m_IsInit.insert(std::make_pair(pos, true));
        auto set = getSet(pos);
        for (TNode * node : children) {
            set -> insert(node -> getLbl());
        }
    }
    void remove(char lbl, uint32_t pos) {
        auto set = getSet(pos);
        set -> erase(lbl);
    }
    bool empty(uint32_t pos) {
        return getSet(pos) -> empty();
    }
    const std::set<char> elems(uint32_t pos) {
        auto set = m_Letters.find(pos);
        if (set == m_Letters.end())
            throw "No such pos to init"; 
        return *set -> second;
    }
};

class Mode2 : public Mode {
  private:
    Restricts * m_Rest;
    bool good_turn(Strategy & s, const TNode * node, uint32_t turn, Alphabet & alpha) {
        if (turn == s.lim())
            return true;
        if (s.at(turn)) {
            for (char letter : alpha.letters()) {
                bool has = false;
                for (TNode * child : node -> getChildren(letter))
                    if (good_turn(s, child, turn + 1, alpha)) {
                        has = true;
                        break;
                    }
                if (!has) {
                  //  std::cout << "Turn B false, pos " << turn << " " << s << std::endl;
                    return false;
                }
            }
            return true;
        } else {
            if (!s.hasNextB(turn))
                return true;
            if (!m_Rest ->isInit(turn))
                m_Rest ->init(node -> getChildren(), turn);
            for (char letter : m_Rest ->elems(turn)) {
                //std::cout << letter << std::endl;
                if (!node -> hasChild(letter)) {
                    m_Rest ->remove(letter, turn);
                    continue;
                }
                for (TNode * child : node -> getChildren(letter))
                    if (!good_turn(s, child, turn + 1, alpha))
                        m_Rest ->remove(letter, turn);
            }
            if (m_Rest ->empty(turn))
                std::cout << "Turn A false, pos " << turn << " " << s << std::endl;
            return !m_Rest ->empty(turn);
        }
    }
  public:
    ~Mode2() override {}
    bool good_strategy(Strategy & s, WordTree & wt, Alphabet & alpha) override{        m_Rest = new Restricts(s);
        bool res = good_turn(s, wt.root(), 0, alpha);
        delete m_Rest;
        return res;
    }
};

#endif
