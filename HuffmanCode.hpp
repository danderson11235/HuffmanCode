#pragma once
#include <string>

class HuffmanCode
{
private:
    struct Node
    {
        char item;
        Node* zero;
        Node* one;
        Node(char _item, Node* _zero, Node* _one) : 
            item(_item), zero(_zero), one(_one) {}
    };
    
public:
    HuffmanCode(std::string fileName);
    ~HuffmanCode();
    bool encode();
    bool decode();
};