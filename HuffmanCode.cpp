#include "HuffmanCode.hpp"
#include <map>
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
    std::vector<char> freqList;
    for (auto& item : freqMap) 
    {
        freqList.push_back(item.first);
    }
    while (!freqList.empty()) {
        int max = 0;
        char maxItem;
        for (int i = 0; i < freqList.size(); i++) {
            
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    std::string fileName = argv[1];
    HuffmanCode hc;
    hc.encode(fileName);
    return 0;
}
