#include <string>

#include "BloomDictionary.h"

BloomDictionary::BloomDictionary(int num_bits)
{
    bits = new BitVector(num_bits);
}

BloomDictionary::~BloomDictionary()
{
    delete bits;
}

unsigned int
BloomDictionary::hash1(const std::string& str)
{
    const int MULTIPLIER = 37;
    unsigned int h = 0;
    for (size_t i = 0; i < str.length(); ++i)
    {
        h = h*MULTIPLIER + str[i];
    }
    return h;
}

unsigned int
BloomDictionary::hash2(const std::string& str)
{
    return str[0];
}

unsigned int
BloomDictionary::hash3(const std::string& str)
{
    return str[str.length()-1];
}

unsigned int
BloomDictionary::hash4(const std::string& str)
{
    return str[(str.length()-1) / 2];
}

void
BloomDictionary::insert(const std::string& str)
{
    bits->set(hash1(str) % (1024*1024));
    bits->set(hash2(str) % (1024*1024));
    bits->set(hash3(str) % (1024*1024));
    bits->set(hash4(str) % (1024*1024));
}

bool
BloomDictionary::contains(const std::string& str)
{
    unsigned int h1 = hash1(str) % (1024*1024);
    unsigned int h2 = hash1(str) % (1024*1024);
    unsigned int h3 = hash1(str) % (1024*1024);
    unsigned int h4 = hash1(str) % (1024*1024);
    return bits->is_set(h1)
        && bits->is_set(h2)
        && bits->is_set(h3)
        && bits->is_set(h4);
}
