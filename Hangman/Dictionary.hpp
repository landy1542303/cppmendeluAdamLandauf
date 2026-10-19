//
//  Dictionary.hpp
//  pripravaNaTest
//
//  Created by Adam Landauf on 19.10.2026.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include<vector>

class Dictionary{
private:
    std::vector<std::string> words;
public:
    void loadFromFile(const std::string &filename);
    int getCount();
    std::string getWord(int index);
};

#endif /* Dictionary_hpp */
