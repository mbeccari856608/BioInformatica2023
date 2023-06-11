#include <stdio.h>
#include <stdint.h>
#include <nthash/nthash.hpp>
#include "seeds.h"
#include <algorithm>
#include <vector>
#include "HashInfo.h"

int main(int argc, char **argv)
{
  std::string mainSequence = std::string("AAAAAGGGG");
  std::string otherSequence = std::string("AACGG");


  // Calcolo i possibili spaced-seeds per la sequenza r
  std::vector<std::string> seeds = Seeds::GetSeeds(otherSequence.length());
  std::vector<uint64_t> otherSequenceHashesList;
  nthash::SeedNtHash otherSequenceHashesGenerator(otherSequence, seeds, 1, otherSequence.length());
  
  while (otherSequenceHashesGenerator.roll())
  {
    uint64_t hash = otherSequenceHashesGenerator.hashes()[0];
    std::cout << hash << "\n";
    otherSequenceHashesList.push_back(hash);
  }

    // for (uint64_t element : otherSequenceHashesList) {
    //     std::cout << element << "\n";
    // }


  nthash::SeedNtHash mainSequenceHashesGenerator(mainSequence, seeds, 1, otherSequence.length());
  


  while (mainSequenceHashesGenerator.roll())
  {
    uint64_t hash = mainSequenceHashesGenerator.hashes()[0];
    auto iterator= std::find(
    otherSequenceHashesList.begin(),
    otherSequenceHashesList.end(),
    hash);

    ptrdiff_t index = std::distance(otherSequenceHashesList.begin(), iterator);

    if (iterator != otherSequenceHashesList.end()){
        std::cout << "Trovato match in posizione " << index << "\n";
    } else{
      std::cout << "Match non trovato in posizione " << index << "\n";
    }
  }

  return 0;
}
