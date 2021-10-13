#include "HuffmanCode.hpp"
#include <stdio.h>
#include <vector>
#include <stack>

HuffmanCode::HuffmanCode()
{
    root = nullptr;
}

HuffmanCode::~HuffmanCode()
{
}

bool HuffmanCode::encode(std::string fileName) {
    FILE* fi = fopen(fileName.c_str(), "r+");
    char c;
    std::map<char, int> freqMap;
    while ((c = getc(fi)) != EOF)
    {
        freqMap[c]++;
    }

    return false;
}

void buildTree(std::map<char, int> freqMap) {
    std::vector<struct Node*> freqList;
    for (auto& item : freqMap) 
    {
        Node* addnode = new Node(item.first, item.second, true, nullptr, nullptr);
        freqList.push_back(addnode);
    }
    while (!freqList.empty()) {
        int max = 0;
        char maxItem;
        for (int i = 0; i < freqList.size(); i++) {
            for (int j = 1; j < freqList.size() - i; j++) {
                if (freqList[j]->val < freqList[j-1]->val) {
                    Node* temp = freqList[j];
                    freqList[j] = freqList[j-1];
                    freqList[j-1] = temp;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    std::string fileName = argv[1];
    HuffmanCode hc;
    hc.encode(fileName);
    return 0;
}
