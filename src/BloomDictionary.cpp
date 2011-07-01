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

/*
 * Algorithm from "The Practice of Programming".
 */
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
    if (!str.empty())
    {
        size_t first = 0;
        return str[first];
    }
    return 0;
}

unsigned int
BloomDictionary::hash3(const std::string& str)
{
    if (!str.empty())
    {
        size_t last = str.length() - 1;
        return str[last];
    }
    return 0;
}

unsigned int
BloomDictionary::hash4(const std::string& str)
{
    if (!str.empty())
    {
        size_t middle = (str.length() - 1) / 2;
        return str[middle];
    }
    return 0;
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

void
BloomDictionary::print_stats()
{
    bits->print_stats();
}
