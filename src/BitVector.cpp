#include <iostream>
#include <cstring>

#include "BitVector.h"

BitVector::BitVector(unsigned int num_bits)
{
    unsigned int num_bytes = (num_bits < 8) ? 1 : num_bits/8;
    bytes = new unsigned char[num_bytes];
    memset(bytes, 0, num_bytes); // Is there a better way in C++?
    this->num_bits = num_bits;
}

BitVector::~BitVector()
{
    delete[] bytes;
}

bool
BitVector::is_set(unsigned int bit)
{
    bit %= num_bits;
    int byte   = bit / 8;
    int offset = bit % 8;
    return (bytes[byte] >> offset) & 1;
}

void
BitVector::set(unsigned int bit)
{
    bit %= num_bits;
    int byte   = bit / 8;
    int offset = bit % 8;
    bytes[byte] |= 1 << offset;
}

void
BitVector::print_stats()
{
    unsigned int ones = 0;
    unsigned int zeros = 0;
    for (unsigned int i = 0; i < num_bits; ++i)
    {
        if (is_set(i))
        {
            ++ones;
        }
        else
        {
            ++zeros;
        }
    }
    std::cout << "Ones:  " << ones << std::endl;
    std::cout << "Zeros: " << zeros << std::endl;
    std::cout << "Ratio: " << (double)ones/num_bits << std::endl;
}
