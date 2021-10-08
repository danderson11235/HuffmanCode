#include "HuffmanCode.hpp"
#include <map>
#include <stdio.h>

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
    

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
