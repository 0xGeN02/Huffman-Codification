#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <emscripten.h>

using namespace std;

class HuffmanTree {
    private:
        struct TreeNode {
            char val;
            int freq;
            TreeNode* left;
            TreeNode* right;

            TreeNode(char v, int f);
            TreeNode(int f);
            ~TreeNode();
        };
        TreeNode* root;

        struct TreeNodeComparator {
            bool operator()(const TreeNode* lhs, const TreeNode* rhs) const;
        };

        void traverse_tree(const TreeNode* node, string code, unordered_map<char, string>& codes) const;

        unordered_map<char, int> get_frequencies(const string& text) const;


    public:
        HuffmanTree(const string& text);
        
        ~HuffmanTree();

        unordered_map<char, string> get_codes() const;

        string encode(const string& text) const;
        
        string decode(const string& code) const;
        
        string get_tree_graphic() const;
};

#endif