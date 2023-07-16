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

  size_t otherSequenceLength = otherSequence.length();

  // Calcolo i possibili spaced-seeds per la sequenza r
  std::vector<std::string> seeds = Seeds::GetSeeds(otherSequenceLength);

  std::vector<uint64_t> otherSequenceHashesList;
  nthash::SeedNtHash otherSequenceHashesGenerator(otherSequence, seeds, 1, otherSequenceLength);

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
        size_t matchPos = mainSequenceHashesGenerator.get_pos();
        std::cout << "Trovato match in posizione " << matchPos << "\n";

        std::string original = mainSequence.substr(matchPos, otherSequenceLength);
        std::cout << "Sottostringa originale: " << original << "\n";

        std::cout << "Sottostringa alternativa " << otherSequence << "\n";

        std::string snipPos = otherSequence.substr(i, 1);

        std::cout << "La sottostringa alternativa differisce in posizione " << i << " per il carattere " << snipPos << "\n";

      }
    }
  }

  return 0;
}
