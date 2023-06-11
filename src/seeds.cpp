#include <vector>
#include <string>
#include <bitset>
#include "seeds.h"

std::vector<std::string> Seeds::GetSeeds(int n)
{
    std::vector<std::string> seeds;

    int limite = 1 << n; // Calcola 2^n come shift a sinistra di n posizioni

    for (int i = 1; i < limite; i <<= 1)
    {
        seeds.push_back(std::bitset<32>(i).to_string().substr(32 - n));
    }

    return seeds;
}