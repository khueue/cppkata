#include <gtest.h>

#include "BloomDictionary.h"

int
main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::string arg1 = argv[1];
        if (arg1 == "test")
        {
            ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
    }

    const int NUM_BITS = 100;
    BloomDictionary dict(NUM_BITS);
    dict.insert("code");
    dict.insert("kata");
    dict.insert("bloom");
    dict.print_stats();

    return 0;
}
