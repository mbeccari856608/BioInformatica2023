#include <stdint.h>
#ifndef HASHINFO_H
#define HASHINFO_H

/**
 * @brief Classe che rappresenta le informazioni sull'hash originato
 * da una porzione di stringa.
 * 
 */
class HashInfo
{

private:
    uint64_t startPos;
    uint64_t hash;

public:
    /**
     * @brief Crea un nuovo oggetto di tipo HashInfo
     * 
     * @param startPos La posizione di inizio della sottostringa che ha prodotto l'hash all'interno della stringa.
     * @param hash L'hash della sottostringa.
     */
     HashInfo(uint64_t startPos, uint64_t hash);
     const uint64_t& GetPos() const;
     const uint64_t& GetHash()const;
};
#endif