#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/image-smoother/

class Solution{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + img[i][j];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                int a = max(1, i - 1);
                int b = max(1, j - 1);
                int c = min(n, i + 1);
                int d = min(m, j + 1);
                int sum = pre[c][d] - pre[c][b - 1] - pre[a - 1][d] + pre[a - 1][b - 1];
                int total_terms = (c - a + 1) * (1 + d - b);
                img[i - 1][j - 1] = sum / total_terms;
            }
        }
        return img;
    }
};

int main(){
    

    return 0;
}