#include "RandomWordIterator.h"

void RandomWordIterator::initRandom()
{
    if (lastSize != dict.Size()) // size changed
    {
        dist = std::unique_ptr<std::uniform_int_distribution<size_t> >(new std::uniform_int_distribution<size_t>(0, dict.Size() - 1));
        lastSize = dict.Size();
    }
}

std::string RandomWordIterator::Next()
{
    bool found = false;
    
    for (size_t i = 0; i < dict.Size(); ++i)
    {
        if (pred(dict[i]))
        {
            found = true;
            break;
        }
    }
    
    if (!found)
    {
        return "";
    }
    
    initRandom();
    std::string word;
    do
    {
        word = dict[(*dist)(dev)];
    }
    while (!pred(word));
    
    return word;
}