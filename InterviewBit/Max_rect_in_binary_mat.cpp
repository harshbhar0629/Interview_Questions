#include <bits/stdc++.h>
using namespace std;
// https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/

int maxRectArea(const vector<int> &rect){
    int n = rect.size();
    vector<int> prev(n, -1), next(n, n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and rect[st.top()] > rect[i])
        {
            // if coming ith element is smaller then ith element is next smaller element
            next[st.top()] = i;
            st.pop();
        }
        if (!st.empty())
        {
            // if stack is not empty then prev smaller element is stack.top()
            prev[i] = st.top();
        }
        st.push(i);
    }

    int mxArea = 0;
    for (int i = 0; i < n; i++)
    {
        int len = next[i] - prev[i] - 1;
        int bre = rect[i];
        mxArea = max(mxArea, len * bre);
    }

    return mxArea;
}

int maximalRectangle(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<int> rect(m, 0);
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
            {
                rect[j] = 0;
            }
            else
            {
                rect[j] += 1;
            }
        }

        maxArea = max(maxArea, maxRectArea(rect));
    }

    return maxArea;
}

int main(){
    

    return 0;
}