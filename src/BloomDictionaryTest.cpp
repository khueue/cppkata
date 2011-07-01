#include <fstream>
#include <gtest.h>

#include "BloomDictionary.h"

/* Currently unused.
class BloomDictionaryTest : public ::testing::Test
{
protected:
    BloomDictionaryTest()
    {
    }

    virtual
    ~BloomDictionaryTest()
    {
    }

    virtual void
    SetUp()
    {
    }

    virtual void
    TearDown()
    {
    }
};
*/

TEST(BloomDictionaryTest, NoFalsePositives)
{
    BloomDictionary dict(10);

    dict.insert("code");
    EXPECT_EQ(true, dict.contains("code"));

    dict.insert("kata");
    EXPECT_EQ(true, dict.contains("kata"));

    EXPECT_EQ(false, dict.contains("bloom"));
}

TEST(BloomDictionaryTest, FalsePositives)
{
    BloomDictionary dict(1); // Guarantees collisions.

    dict.insert("code");
    EXPECT_EQ(true, dict.contains("code"));

    dict.insert("kata");
    EXPECT_EQ(true, dict.contains("kata"));

    EXPECT_EQ(true, dict.contains("bloom")); // Never inserted!
}

TEST(BloomDictionaryTest, WholeDictionaryProperlyInserted)
{
    BloomDictionary dict(10*1024*1024);
    std::string line;
    std::ifstream file("/usr/share/dict/words");
    while (std::getline(file, line))
    {
        dict.insert(line);
        EXPECT_EQ(true, dict.contains(line));
    }
    file.close();
}
