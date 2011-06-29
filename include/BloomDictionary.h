#ifndef _BLOOM_DICTIONARY_H_
#define _BLOOM_DICTIONARY_H_

#include <string>

#include "BitVector.h"

class BloomDictionary
{
private:
    BitVector *bits;
    unsigned int hash1(const std::string& str);
    unsigned int hash2(const std::string& str);
    unsigned int hash3(const std::string& str);
    unsigned int hash4(const std::string& str);

public:
    BloomDictionary(int num_bits);
    ~BloomDictionary();
    void insert(const std::string& str);
    bool contains(const std::string& str);
};

#endif
