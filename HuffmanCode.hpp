#pragma once
#include <string>
#include <map>
#include <vector>

class HuffmanCode
{
private:
    struct Node
    {
        char item;
        int count;
        Node* zero;
        Node* one;
        Node(char _item, int _count, Node* _zero, Node* _one) : 
            item(_item), count(_count), zero(_zero), one(_one) {}
        Node(char _item, int _count) :
            item(_item), count(_count), zero(nullptr), one(nullptr) {}
    };
    std::vector<char> getCharList(std::string fileName);
    std::vector<Node*> nodeList;
    Node* root;
    void printTree(Node* root);

public:
    HuffmanCode(std::string fileName);
    ~HuffmanCode();
    bool encode(std::string fileName);
    bool decode(std::string fileName);
    void printTree();
};
