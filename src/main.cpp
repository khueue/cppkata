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

    const int NUM_BITS = 1024 * 1024;
    BloomDictionary dict(NUM_BITS);
    dict.print_stats();

    return 0;
}
