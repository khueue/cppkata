#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

/**
 * Array of bits, used to set and check them individually.
 */
class BitVector
{
private:
    unsigned char *bytes;
    unsigned int num_bits;

public:
    BitVector(unsigned int num_bits);
    ~BitVector();
    bool is_set(unsigned int bit);
    void set(unsigned int bit);
    void print_stats();
};

#endif
