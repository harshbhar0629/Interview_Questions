#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/lru-cache/

class LRUCache
{
    unordered_map<int, int> mp;
    unordered_map<int, list<int>::iterator> address;
    list<int> dll;
    int size;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        // first find its iterator
        list<int>::iterator it = address[key];
        // erase its address and also erase from dll
        address.erase(key);
        dll.erase(it);

        // updation in front from dll and also store new address
        dll.push_front(key);
        address[key] = dll.begin();

        return mp[key];
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            dll.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            size--;
        }
        if (size == capacity)
        {
            int last = dll.back();
            address.erase(last);
            dll.pop_back();
            mp.erase(last);
            size--;
        }
        size++;
        mp[key] = value;
        dll.push_front(key);
        address[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache
{
    // unordered_map<int, int> mp;
    unordered_map<int, list<pair<int, int>>::iterator> address;
    list<pair<int, int>> dll;
    int size;
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (address.find(key) == address.end())
        {
            return -1;
        }
        // first find its iterator
        list<pair<int, int>>::iterator it = address[key];
        int value = it->second;
        // erase its address and also erase from dll
        address.erase(key);
        dll.erase(it);

        // updation in front from dll and also store new address
        dll.push_front({key, value});
        address[key] = dll.begin();

        return value;
    }

    void put(int key, int value)
    {
        if (address.find(key) != address.end())
        {
            dll.erase(address[key]);
            address.erase(key);
            size--;
        }
        if (size == capacity)
        {
            auto last = dll.back();
            address.erase(last.first);
            dll.pop_back();
            size--;
        }
        size++;
        dll.push_front({key, value});
        address[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    

    return 0;
}