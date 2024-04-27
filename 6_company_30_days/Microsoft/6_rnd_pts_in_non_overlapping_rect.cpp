#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/description/


#define ll long long int
class Solution
{
    vector<int> pts_cum_cnt;
    int num_pts;
    vector<vector<int>> rects;

public:
    Solution(vector<vector<int>> &rects)
    {
        num_pts = 0;
        // pts_cum_cnt = {};
        this->rects = rects;

        for (auto &rect : rects)
        {
            num_pts += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            pts_cum_cnt.push_back(num_pts);
        }
    }

    vector<int> pick()
    {
        int n = pts_cum_cnt.size();
        int pts_idx = rand() % num_pts;
        int idx = upper_bound(pts_cum_cnt.begin(), pts_cum_cnt.end(), pts_idx) - pts_cum_cnt.begin();

        vector<int> &rect = rects[idx];
        int x = rect[2] - rect[0] + 1;
        int y = rect[3] - rect[1] + 1;
        int curr_pts = x * y;
        int start_pts = pts_cum_cnt[idx] - curr_pts;
        int offset = pts_idx - start_pts;
        return {rect[0] + offset % x, rect[1] + offset / x};

        // int l = 0, r = n-1;

        // while(l<r){
        //     int mid = l + (r-l)/2;
        //     if(pts_cum_cnt[mid] <= pts_idx){
        //         l = mid+1;
        //     }
        //     else{
        //         r = mid;
        //     }
        // }

        // vector<int>& rect = rects[l];
        // int x_pts = (rect[2] - rect[0]) + 1;
        // int y_pts = (rect[3] - rect[1]) + 1;
        // int total_pts_rect = x_pts*y_pts;
        // int start_pts = pts_cum_cnt[l] - total_pts_rect;
        // int offset = pts_idx - start_pts;

        // return {rect[0] + offset % x_pts, rect[1] + offset / x_pts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(){
    

    return 0;
}