#include "emscripten.h"
#include "emscripten/bind.h"
#include "seeds.h"
#include <nthash/nthash.hpp>
#include <sstream>


std::vector<std::string> SpacedSeeds(std::string mainSequence, std::string otherSequence)
{
  std::ostringstream stringStream;
  std::vector<std::string> result;

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

  stringStream << "Generati " << otherSequenceHashesList.size() << " hash"
            << std::endl;
  result.push_back(stringStream.str());
  stringStream.str(std::string());
  stringStream.clear();
  

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
        
        stringStream << "Trovato match in posizione " << matchPos << "\n";
        result.push_back(stringStream.str());
        stringStream.str(std::string());
        stringStream.clear();

        std::string original = mainSequence.substr(matchPos, otherSequenceLength);
        stringStream << "Sottostringa originale: " << original << "\n";
        result.push_back(stringStream.str());
        stringStream.str(std::string());
        stringStream.clear();


        stringStream << "Sottostringa alternativa: " << otherSequence << "\n";
        result.push_back(stringStream.str());
        stringStream.str(std::string());
        stringStream.clear();

        std::string snipPos = otherSequence.substr(i, 1);

        stringStream << "La sottostringa alternativa differisce in posizione " << i << " per il carattere " << snipPos << "\n";
        result.push_back(stringStream.str());
        stringStream.str(std::string());
        stringStream.clear();

      }
    }
  }

  return result;
}

EMSCRIPTEN_BINDINGS (mymodule) {
  emscripten::register_vector<std::string>("StringList");
  emscripten::function("GetSeeds", &Seeds::GetSeeds);
  emscripten::function("SpacedSeeds", &SpacedSeeds);

}