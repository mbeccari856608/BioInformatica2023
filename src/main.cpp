#include <stdio.h>
#include <stdint.h>
#include <nthash/nthash.hpp>
#include "seeds.h"
#include <algorithm>
#include <vector>
#include "HashInfo.h"

int main(int argc, char **argv)
{
  std::string mainSequence = "AAAAAGGGG";
  std::string otherSequence = "AACGG";

  // Calcolo i possibili spaced-seeds per la sequenza r
  std::vector<std::string> seeds = Seeds::GetSeeds(otherSequence.length());

  std::vector<uint64_t> otherSequenceHashesList;
  nthash::SeedNtHash otherSequenceHashesGenerator(otherSequence, seeds, 1, otherSequence.length());

  while (otherSequenceHashesGenerator.roll())
  {
    for (size_t i = 0; i < seeds.size(); i++)
    {
      uint64_t hash = otherSequenceHashesGenerator.hashes()[i];
      otherSequenceHashesList.push_back(hash);
    }
  }

  std::cout << "Generati " << otherSequenceHashesList.size() << " hash"
            << "\n";

  nthash::SeedNtHash mainSequenceHashesGenerator(mainSequence, seeds, 1, otherSequence.length());

  while (mainSequenceHashesGenerator.roll())
  {

    for (size_t i = 0; i < seeds.size(); i++)
    {
      uint64_t hash = mainSequenceHashesGenerator.hashes()[i];
      auto iterator = std::find(
          otherSequenceHashesList.begin(),
          otherSequenceHashesList.end(),
          hash);

      if (iterator != otherSequenceHashesList.end())
      {
        std::cout << "Trovato match in posizione " << mainSequenceHashesGenerator.get_pos() << "\n";
      }
      else
      {
        std::cout << "Match non trovato in posizione " << mainSequenceHashesGenerator.get_pos() << "\n";
      }
    }
  }

  return 0;
}
