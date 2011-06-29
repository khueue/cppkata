#include <cstring>

#include "BitVector.h"

BitVector::BitVector(unsigned int num_bits)
{
    bytes = new unsigned char[num_bits/8];
    memset(bytes, 0, num_bits/8);
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
