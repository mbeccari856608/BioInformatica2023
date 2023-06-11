#include <HashInfo.h>



HashInfo::HashInfo(uint64_t startPos, uint64_t hash){
    this->hash = hash;
    this->startPos = startPos;
}


const uint64_t& HashInfo::GetPos() const {
    return this->startPos;
}

const uint64_t& HashInfo::GetHash() const {
    return this->hash;
}
