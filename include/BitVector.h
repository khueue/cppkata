#ifndef _BIT_VECTOR_H_
#define _BIT_VECTOR_H_

class BitVector
{
private:
    unsigned char *bytes;

public:
    BitVector(int num_bits);
    ~BitVector();
    bool is_set(int bit);
    void set(int bit);
};

#endif
