#include "HuffmanCode.hpp"
#include <stdio.h>
#include <list>
#include <stack>
#include <iostream>


HuffmanCode::HuffmanCode(std::string fileName)
{
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
        vec_save = nodeList.begin();
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
        vec_save = nodeList.begin();
        for (vec_it = nodeList.begin(); vec_it != nodeList.end(); vec_it++) {
            if ((*vec_it)->count < min) {
                temp2 = *vec_it;
                min = temp2->count;
                vec_save = vec_it;
            }
        }
        nodeList.erase(vec_save);

        Node* comb;
        if (temp->count > temp2->count) comb = new Node(0, temp->count + temp2->count, temp2, temp);
        else comb = new Node(0, temp->count + temp2->count, temp, temp2);
        
        nodeList.push_back(comb);
    }
    
    buildRepList(root, "");
    
    fclose(fi);
}



HuffmanCode::~HuffmanCode()
{
}

void HuffmanCode::buildRepList(Node* node, std::string rep) {
    if (node == nullptr) {
        // rep.pop_back();
        return;
    }
    if (node->item != 0) {
        repList[node->item] = rep;
    }
    buildRepList(node->zero, rep + "0");
    buildRepList(node->one, rep + "1");
}

std::string HuffmanCode::encode(std::string fileName) {
    FILE* fi = fopen(fileName.c_str(), "r+");
    std::string output = "";
    char c;
    while ((c = getc(fi)) != EOF)
    {
        output += repList[c];
    }
    
    return output;
}

std::string HuffmanCode::decode(std::string fileName) {
    FILE* fi = fopen(fileName.c_str(), "r+");
    char c;
    std::string output;
    Node* temp = root;
    while ((c = getc(fi)) != EOF) {
        if (c == '0') temp = temp->zero;
        else if (c == '1') temp = temp->one;
        else return "";
        if (temp == nullptr) return "";
        if (temp->item != 0) {
            output += temp->item;
            temp = root;
        }
    }
    return output;
}

void HuffmanCode::printTree(Node* root) {
    if (root == nullptr) return;
    std::cout << "(" << root->item << ", " << root->count << ")" << std::endl;
    printTree(root->zero);
    printTree(root->one);
}

void HuffmanCode::printTree() {
    printTree(root);
}

std::vector<char> HuffmanCode::getCharList(std::string fileName) {
    FILE* fi = fopen(fileName.c_str(), "r+");
    char c;
    std::map<char, int> freqMap;
    while ((c = getc(fi)) != EOF) {
        freqMap[c]++;
    }
    return std::vector<char>();
}

int main(int argc, char const *argv[])
{
    std::string fileName = argv[1];
    HuffmanCode hc(fileName);
    hc.printTree();
    // hc.encode(fileName);
    return 0;
}
