#ifndef ALPHABET_H
#define ALPHABET_H

//Class Alphabet where the Imput text will be encoded via assigning the bytes via position on the alphabet
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <emscripten.h>

using namespace std;

class Alphabet {
    private:
        vector<char> alphabet;

        unordered_map<char, int> char_to_binary;

        ~Alphabet();
        
    public:
        Alphabet(const string& text);

        string encode(const string& text) const;

        string decode(const string& encoded_text) const;

};

//alphabet es un vector que guarda char values del imput text
//char_to_binary es un hashmap que asocia un num binario a cada char value del imput text

#endif