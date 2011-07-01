#include <gtest.h>

#include "BitVector.h"

class BitVectorTest : public ::testing::Test
{
protected:
    BitVector *bits;

    BitVectorTest()
    {
        bits = new BitVector(10);
    }

    virtual
    ~BitVectorTest()
    {
        delete bits;
    }

    virtual void
    SetUp()
    {
        bits->set(1);
        bits->set(2);
        bits->set(3);
        bits->set(9);
    }

    virtual void
    TearDown()
    {
    }
};

TEST_F(BitVectorTest, CorrectBitsSet)
{
    EXPECT_EQ(false, bits->is_set(0));
    EXPECT_EQ(true, bits->is_set(1));
    EXPECT_EQ(true, bits->is_set(2));
    EXPECT_EQ(true, bits->is_set(3));
    EXPECT_EQ(false, bits->is_set(4));
    EXPECT_EQ(false, bits->is_set(5));
    EXPECT_EQ(false, bits->is_set(6));
    EXPECT_EQ(false, bits->is_set(7));
    EXPECT_EQ(false, bits->is_set(8));
    EXPECT_EQ(true, bits->is_set(9));
}

TEST_F(BitVectorTest, WrapAround)
{
    EXPECT_EQ(false, bits->is_set(10)); // Wraps to 0.
    EXPECT_EQ(true, bits->is_set(11)); // Wraps to 1.
}
