#include <bits/stdc++.h>
using namespace std;
//

class Solution
{

    int maxGap(vector<int> &bars)
    {
        sort(bars.begin(), bars.end());
        int cnt = 2;
        int ans = 2;
        for (int i = 1; i < bars.size(); i++)
        {
            cnt = (bars[i - 1] + 1 == bars[i]) ? cnt + 1 : 2;
            ans = max(ans, cnt);
        }
        return ans;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        int ans = min(maxGap(hBars), maxGap(vBars));
        return ans * ans;
    }
};

int main(){
    

    return 0;
}