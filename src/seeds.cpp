#include <vector>
#include <string>
#include <bitset>
#include "seeds.h"

std::vector<std::string> Seeds::GetSeeds(size_t n)
{
    std::vector<std::string> result;

    std::string baseString(n, '1');


    for (size_t i = 0; i < n; i++)
    {
        std::string current = baseString;
        current[i] = '0';
        result.push_back(current);
    }


    return result;
}
