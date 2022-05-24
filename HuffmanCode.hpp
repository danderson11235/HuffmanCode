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
            item(_item), count(_count), zero(nullptr), one(nullptr) {}
        Node(char _item, int _count) :
            item(_item), count(_count), zero(nullptr), one(nullptr) {}
    };
    Node* root;
    std::vector<char> getCharList(std::string fileName);
    std::vector<Node*> nodeList;
public:
    HuffmanCode(std::string fileName);
    ~HuffmanCode();
    bool encode(std::string fileName);
    bool decode(std::string fileName);
};
