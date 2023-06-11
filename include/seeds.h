#include <vector>
#include <string>

#ifndef SEEDS_H
#define SEEDS_H
namespace Seeds {
/**
 * @brief
 * Recupera tutti i seeds di lunghezza \p n da utilizzare
 * nell'hashing delle stringhe.
 * 
 * @example se \p n = 3 si otterrà un vettore con quattro stringhe:
 * 
 * "000", "001" "010", "100"
 * 
 * 
 */
std::vector<std::string> GetSeeds(int n);

}
#endif