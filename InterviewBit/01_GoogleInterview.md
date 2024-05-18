Question: 
  1.  Design a class which insert a value with(no duplicates)
  2.  Delete a exisiting value 
  3. Support get random with equal probability
  
  Your ques: which type of value will be comming is this Integer or String or any specific value
  => you can assume as Integer

Approach-1 we can do all operation by using array
```

class Solution{
    vector<int>v;
public: 

    Solution(){
        v={};
    }

    bool insert(int val){
        if(v.find(val) != v.end()){
            // means value already exist
            return false; // we r not able to store that particular value
        }
        v.push_back(val);
        return true; // now we r actually able to insert a given value
    }

    bool delete(int val){
        if(v.find(val) != v.end()){
            v.erase(val);
            return true; // value exist we can remove that particular element
        }

        return false; // value not exist so we can't remove any thing
    }

    int getRandom(){
        if(v.size() == 0){
            return -1; // no element present in our array
        }
        int idx = random()%v.size(); // why modular bcoz we have to take index in the range of [0..v.size()-1].
        return v[idx];
    }
};

    Time complexity analysis:
        insertion => (O(N)) for checking duplicate it takes O(N)
        deletion => (O(N))  for checking element is present or not OR for erasing an element
        getRandom() => O(1)
    SC: 
        for storing an element O(N)
```


Approach-2 we can do all operation by using array and map
```
    Questions:
        1. How we can improve searching an element..?
        2. How we can delete an element in array in constant time..?

class Solution{
    vector<int>v;
    unordered_map<int,int>
public: 

    Solution(){
        v={};
    }

    bool insert(int val){
        if(mp.count(val) == 1){
            // means value already exist
            return false; // we r unable to insert this value bcoz it was already exist
        }    
        mp[val] = v.size(); // in map what we actually storing we map a value for their respective index
        v.push_back(val);
    }

    bool delete(int val){
        if(mp.count(val) == 0 || v.size() == 0){
            // means value not exist
            return false; // we r unable to delete this value bcoz it was not exist
        }

        // 1 2 3 4 5 6 7
        // del => 3
        // => idx = 2
        // => lastVal = 7
        // swap values
        // => 1 2 7 4 5 6 3
        // remove last ele => 1 2 3 4 5 6 
        // 

        // get idx for deletion
        int idx = mp[val];

        //store last val of array
        int lastVal = v.back();
        
        //put last value in place of delete index
        v[idx] = lastVal;
        
        //remove last val bcoz it is updated on index val
        v.pop_back();
        
        //also update their map
        mp[v[idx]] = idx;
        
        //erase value from map also
        mp.erase(val);
        return true;
    }

    int getRandom(){
        if(v.size() == 0){
            return -1; // no element present in our array
        }
        int idx = random()%v.size(); // why modular bcoz we have to take index in the range of [0..v.size()-1].
        return v[idx];
    }
};

    Time complexity analysis:
        insertion => (O(1)) for checking duplicate it takes O(N)
        deletion => (O(1))  for checking element is present or not OR for erasing an element
        getRandom() => O(1)
    SC: 
        for storing an element 2*O(N)
```