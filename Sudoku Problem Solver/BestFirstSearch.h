#ifndef BEST_FIRST_SEARCH_H
#define BEST_FIRST_SEARCH_H

#include "Searchable.h"

#include <memory>
using std::unique_ptr;

class BestFirstSearch {

protected:

    int nodes = 0;
    
public:

    BestFirstSearch(std::unique_ptr<Searchable> && startFrom) {
        // TODO: Finish Implementing, put startFrom onto the queue
    }
    
    int getNodesExpanded() const {
        return nodes;
    }
    
    Searchable * solve() {
        // TODO: Finish Implementing search, returning a pointer to the solution (if one is found)
    
        return nullptr;
    }
};


#endif
