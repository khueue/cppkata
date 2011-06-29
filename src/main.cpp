#include <iostream>
#include <fstream>
/* #include <gtest.h> */

#include "BloomDictionary.h"

const int NUM_BITS = 1024 * 1024;

int
main(void)
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
        std::cout << "not found!" << std::endl;
    }

    return 0;
}
