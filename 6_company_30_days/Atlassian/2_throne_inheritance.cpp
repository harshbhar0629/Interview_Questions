#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/throne-inheritance/submissions/1159274082/

class ThroneInheritance
{

    unordered_set<string> deathName;
    unordered_map<string, vector<string>> mp;
    string king;

public:
    ThroneInheritance(string kingName)
    {
        this->king = kingName;
    }

    void birth(string parentName, string childName)
    {
        mp[parentName].push_back(childName);
    }

    void death(string name)
    {
        deathName.insert(name);
    }

    void helper(vector<string> &ans, string &par)
    {
        if (deathName.count(par) == 0)
        {
            ans.push_back(par);
        }
        for (auto it : mp[par])
        {
            helper(ans, it);
        }
    }

    vector<string> getInheritanceOrder()
    {
        vector<string> ans;
        helper(ans, king);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(){
    

    return 0;
}