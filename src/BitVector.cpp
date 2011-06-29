#include <cstring>

#include "BitVector.h"

BitVector::BitVector(int num_bits)
{
    bytes = new unsigned char[num_bits/8];
    memset(bytes, 0, num_bits/8);
}

BitVector::~BitVector()
{
    delete[] bytes;
}

bool
BitVector::is_set(int bit)
{
    int byte   = bit / 8;
    int offset = bit % 8;
    return (bytes[byte] >> offset) & 1;
}

void
BitVector::set(int bit)
{
    int byte   = bit / 8;
    int offset = bit % 8;
    bytes[byte] |= 1 << offset;
}
