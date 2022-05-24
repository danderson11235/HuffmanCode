#include "HuffmanCode.hpp"
#include <stdio.h>

HuffmanCode::HuffmanCode(std::string fileName)
{
    root = nullptr;
    // charList = getCharList(fileName);
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
    
    std::map<char, int>::iterator map_it;
    for (map_it = freqMap.begin(); map_it != freqMap.end(); map_it++) {
        nodeList.push_back(new Node(map_it->first, map_it->second));
    }
    std::vector<Node*>::iterator vec_it;
    std::vector<Node*>::iterator vec_save;
    while (!nodeList.empty())
    {
        if (nodeList.size() == 1) {
            root = nodeList[0];
            nodeList.pop_back();
            break;
        }
        Node* temp = nodeList[0];
        int min = temp->count;
        for (vec_it = nodeList.begin(); vec_it != nodeList.end(); vec_it++) {
            if ((*vec_it)->count < min) {
                temp = *vec_it;
                min = temp->count;
                vec_save = vec_it;
            }
        }
        nodeList.erase(vec_save);
        // Do it again
        Node* temp2 = nodeList[0];
        min = temp2->count;
        for (vec_it = nodeList.begin(); vec_it != nodeList.end(); vec_it++) {
            if ((*vec_it)->count < min) {
                temp = *vec_it;
                min = temp->count;
                vec_save = vec_it;
            }
        }
        nodeList.erase(vec_save);

        Node* comb;
        if (temp->count > temp2->count) comb = new Node(0, temp->count + temp2->count, temp2, temp);
        else comb = new Node(0, temp->count + temp2->count, temp, temp2);
        
        nodeList.push_back(comb);
    }
    

}

std::vector<char> HuffmanCode::getCharList(std::string fileName) {
    FILE* fi = fopen(fileName.c_str(), "r+");
    char c;
    std::map<char, int> freqMap;
    while ((c = getc(fi)) != EOF) {
        freqMap[c]++;
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
