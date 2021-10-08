#!/usr/bin/python3

import sys

class Node:
    def __init__(self, data, l, r) :
        self.left = l
        self.right = r
        self.data = data
    def setR(self, node) :
        self.right = node
    def setL(self, node) :
        self.left = node
    def getData(self) :
        return self.data
    def getR(self) :
        return self.right
    def getL(self) :
        return self.left

def encode(fileName):
    f = open(fileName)
    charLibs = {'\n':0}
    for line in f:
        for c in line:
            if c in charLibs:
                charLibs[c] += 1
            else:
                charLibs[c] = 1
        charLibs['\n'] += 1
    charList = []
    #print(charLibs)
    #max = 0
    keys = list(charLibs.keys())
    while keys:
        max = 0
        maxKey = ''
        for k in keys:
            if charLibs[k] > max:
                max = charLibs[k]
                maxKey = k
        keys.remove(maxKey)
        charList.append(maxKey)
    #print(keys) # at this point I have the keys
    if not charList: return False
    of = open(fileName + ".dave", 'wb')
    for c in charList: of.write(bytes(c, 'ascii'))
    of.write(bytes('\n', 'ascii'))
    for c in charList:
        of.write(bytes(charLibs[c] + ' ', 'ascii'))
    root = Node(charList.pop(), None, None)
    # while charList:


encode("p.txt")