#pragma once
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <utility>
using std::pair;
using std::initializer_list;
#include <ostream>
using std::ostream;

class BiMap {

private:
    // holds the pairs ordered by keys.  All keys must be unique
    vector< pair<string, string> > ordered_by_keys_;

    // holds the pairs ordered by values.  All values must be unique
    vector< pair<string, string> > ordered_by_vals_;

    // Uses lower_bound, returns an iterator to a pair<string, string> that is either the first pair in the vector that is equal to (by key) or greater than the key, or ordered_by_keys_.end() (the last two meaning that the key isn't in ordered_by_keys_)
    // Must be private because ordered_by_keys_ is private and we cannot return an iterator to a private data structure.
    vector< pair <string, string> >::iterator find_key(string key);

    // Uses lower_bound, returns an iterator to a pair<string, string> that is either the first pair in the vector that is equal to (by value) or greater than the value, or ordered_by_vals_.end() (the last two meaning that the value isn't in ordered_by_vals_)
    // Must be private because ordered_by_vals_ is private and we cannot return an iterator to a private data structure.
    vector< pair <string, string> >::iterator find_value(string value);


public:
    // default constructor
    BiMap() = default;

    // Take each pair and place in the vectors. The initializer_list does not have to be in sorted order but the vectors should be after you add all the elements.
    BiMap(initializer_list< pair<string, string> >);

    // Returns the size of the BiMap (number of pairs) as an unsigned int
    size_t size();

    // Return the value associated with the key. If the key does not exist, then return the empty string.
    string value_from_key(string);

    // Return the key associated with the value. If the value does not exist, then return the empty string.
    string key_from_value(string);

    // if the first string as a key is in the BiMap, update the key - value pair to the value of the second parameter. Return true.
    // If the key is not in BiMap, do nothing and return false.
    bool update(string, string);

    // Look for element, as either a key or a value. If found, remove both the key and value from the BiMap and return that pair<key, value>(that order).
    // if the element does not exist as either a key or a value, return a pair of empty strings.
    // if element exists as both a key and a value, remove both pairs, and return a pair with the key that was associated with element, and the value that was associated with element.
    pair<string, string> remove(string);

    // if the string as a key is in the BiMap, do nothing and return false. Otherwise create a pair with the argument values and insert the new pair into the vectors, in sorted order, and return true.
    bool add(string, string);

    // compare the two BiMaps lexicographically, that is element by element using the string - key of the pairs as comparison values.
    // If you compare two pairs, then the comparison is based on the .first of each pair(that is, the string - key of each pair).
    // The first difference that occurs determines the compare result. If the calling BiMap is greater, return 1. If the argument BiMap is greater, return -1.
    // If all of the comparable pairs are equal but one BiMap is bigger(has more pairs), then the longer determines the return value(1 if the first is longer, -1 if the second).
    int compare(BiMap &);

    // Returns the ostream after writing the BiMap to the ostream.
    // The formatting should have each pair colon( : ) separated, and each pair comma + space separated(, ), with no trailing comma.
    // e.g., Ann : ABCD, Bob : EFGH, Charlie : IJKL
    friend ostream& operator<<(ostream&, BiMap&);
};