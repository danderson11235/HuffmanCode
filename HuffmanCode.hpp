#pragma once
#include <string>
#include <map>

struct Node
{
    char item;
    int val;
    bool charNode;
    Node* zero;
    Node* one;
    Node(char _item, int _val, bool _charNode, Node* _zero, Node* _one) : 
        item(_item), val(_val), charNode(_charNode), zero(_zero), one(_one) {}
};

class HuffmanCode
{
private:
    Node* root;
    void buildTree(std::map<char, int> freqMap);
public:

    HuffmanCode();
    ~HuffmanCode();
    bool encode(std::string fileName);
    bool decode(std::string fileName);
};
