#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"


template<typename Key, typename Value>
class KeyValuePair {

public:

    const Key k;
    Value v;

    KeyValuePair(const Key& keyIn, const Value& valueIN)
        :k(keyIn), v(valueIN) {

    }

    KeyValuePair(Key keyIn)
        :k(keyIn), v() {

    }

    bool operator<(const KeyValuePair& rhs) const {
        return k < rhs.k;
    }
};



template<typename Key, typename Value>
ostream& operator<< (ostream& o, const KeyValuePair<Key, Value>& kv) {
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {

private:
    BinarySearchTree<KeyValuePair<Key, Value>> tree;

public:

    KeyValuePair<Key, Value>* insert(const Key& k, const Value& v) {
        return &(tree.insert(KeyValuePair<Key, Value>(k, v))->data);
    }

    void write(ostream& o) const {
        tree.write(o);
    }

    KeyValuePair<Key, Value>* find(const Key& key) {
        TreeNode<KeyValuePair<Key, Value>>* toReturn = tree.find(KeyValuePair<Key, Value>(key));

        if (toReturn == nullptr)
            return nullptr;

        return &(toReturn->data);
    }
};


#endif

