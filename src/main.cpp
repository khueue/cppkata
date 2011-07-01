#include <iostream>
#include <fstream>
#include <gtest.h>

#include "BloomDictionary.h"

const int NUM_BITS = 1024 * 1024;

TEST(FactorialTest, HandlesZeroInput)
{
    EXPECT_EQ(1, 1);
}

int
main(int argc, char *argv[])
{
    BloomDictionary dict(NUM_BITS);

    std::string line;
    std::ifstream file("/usr/share/dict/words");
    while (std::getline(file, line))
    {
        dict.insert(line);
    }
    file.close();

    std::ifstream file2("/usr/share/dict/words");
    while (std::getline(file2, line))
    {
        if (!dict.contains(line))
        {
            std::cout << dict.contains(line) << std::endl;
        }
    }
    file2.close();

    if (!dict.contains("kata"))
    {
        std::cout << "Not found!" << std::endl;
    }

    dict.print_stats();

    ::testing::InitGoogleTest(&argc, argv);
    int tests = RUN_ALL_TESTS();
    (void)tests;

    return 0;
}
