//
//  Dictionary.cpp
//  pripravaNaTest
//
//  Created by Adam Landauf on 19.10.2026.
//
#include<fstream>
#include<iostream>
#include "Dictionary.hpp"

std::string Dictionary::getWord(int index){
    return words[index];
}

int Dictionary::getCount(){
    return words.size();
}

void Dictionary::loadFromFile(const std::string &filename){
    std::ifstream file(filename);
    if (!file.is_open()) return;
    std::string word;
    while (file >> word){
        words.push_back(word);
    }
    
        
}
