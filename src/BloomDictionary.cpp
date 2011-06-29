#include <string>

#include "BloomDictionary.h"

BloomDictionary::BloomDictionary(unsigned int num_bits)
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
    bits->set(hash1(str));
    bits->set(hash2(str));
    bits->set(hash3(str));
    bits->set(hash4(str));
}

bool
BloomDictionary::contains(const std::string& str)
{
    return bits->is_set(hash1(str))
        && bits->is_set(hash2(str))
        && bits->is_set(hash3(str))
        && bits->is_set(hash4(str));
}
