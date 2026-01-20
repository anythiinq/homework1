#include "newMap.h"

Map::Map() : m_size(0), m_maxSize(DEFAULT_MAX_ITEMS) {
    m_map = new Entry[DEFAULT_MAX_ITEMS];
}

Map::Map(int n) : m_size(0), m_maxSize(n) {
    m_map = new Entry[n];
}

Map::~Map() {
    delete[] m_map;
}

bool Map::empty() const {
    return m_size == 0;
}

int Map::size() const {
    return m_size;
}

// If key is not equal to any key currently in the map and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that either the key is already in the map, or the map has a fixed
// capacity and is full).
bool Map::insert(const KeyType &key, const ValueType &value) {
    if (m_size >= m_maxSize || contains(key)) {
        return false;
    }
    
    m_map[m_size].m_key = key;
    m_map[m_size].m_value = value;
    m_size++;
    return true;
}

// If key is equal to a key currently in the map, then make that key no
// longer map to the value that it currently maps to, but instead map to
// the value of the second parameter; in this case, return true.
// Otherwise, make no change to the map and return false.
bool Map::update(const KeyType& key, const ValueType& value)
{
    for (int i = 0; i < m_size; i++)
    {
        if (key == m_map[i].m_key)
        {
            m_map[i].m_value = value;
            return true;
        }
    }
    
    return false;
}

// If key is equal to a key currently in the map, then make that key no
// longer map to the value that it currently maps to, but instead map to
// the value of the second parameter; in this case, return true.
// If key is not equal to any key that is currently in the map, and if the
// key/value pair can be added to the map, then do so and return true.
// Otherwise, make no change to the map and return false (indicating
// that the key is not already in the map and the map has a fixed
// capacity and is full).
bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    if (contains(key))
    {
        update(key, value);
        return true;
    }
    
    return insert(key, value);
}

// If key is equal to a key currently in the map, remove the key/value
// pair with that key from the map and return true.  Otherwise, make
// no change to the map and return false.
bool Map::erase(const KeyType& key)
{
    if (!contains(key))
        return false;
    
    int i;
    // updates index i to location of existing key
    for (i = 0; i < m_size; i++)
    {
        if (m_map[i].m_key == key)
        {
            break;
        }
    }
    
    while (i < m_size-1)
    {
        m_map[i].m_key = m_map[i+1].m_key;
        m_map[i].m_value = m_map[i+1].m_value;
        i++;
    }
    
    m_size--;
    return true;
}



// Return true if key is equal to a key currently in the map, otherwise
// false.
bool Map::contains(const KeyType& key) const
{
    for (int i = 0; i < m_size; i++)
    {
        if (key == m_map[i].m_key)
            return true;
    }
    
    return false;
}
 
// If key is equal to a key currently in the map, set value to the
// value in the map that the key maps to, and return true.  Otherwise,
// make no change to the value parameter of this function and return
// false.
bool Map::get(const KeyType& key, ValueType& value) const
{
    for (int i = 0; i < m_size; i++)
    {
        if (key == m_map[i].m_key)
        {
            value = m_map[i].m_value;
            return true;
        }
    }
    
    return false;
}

// If 0 <= i < size(), copy into the key and value parameters the
// key and value of the key/value pair in the map whose key is strictly
// greater than exactly i keys in the map and return true.  Otherwise,
// leave the key and value parameters unchanged and return false.
bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if (i < 0 || i >= m_size)
        return false;
    
    for (int a = 0; a < m_size; a++)
    {
        int greaterThan = 0;
        for (int b = 0; b < m_size; b++)
        {
            if (a == b)
                continue;
            
            if (m_map[a].m_key > m_map[b].m_key)
            {
                greaterThan++;
            }
        }
        
        if (greaterThan == i)
        {
            key = m_map[a].m_key;
            value = m_map[a].m_value;
            break;
        }
    }
    
    return true;
}

// Exchange the contents of this map with the other one.
void Map::swap(Map& other)
{
    // swap sizes
    int tempSize = m_size;
    m_size = other.size();
    other.m_size = tempSize;
    
    // swap content
    Entry* temp = other.m_map;
    other.m_map = m_map;
    m_map = temp;
    
    // swap max size
    int tempMaxSize = other.m_maxSize;
    other.m_maxSize = m_maxSize;
    m_maxSize = tempMaxSize;
}

