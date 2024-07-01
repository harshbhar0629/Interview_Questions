#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> boxes(n), units(n);
    for (int i = 0; i < n; i++){
        cin >> boxes[i];
    }
    for (int i = 0; i < n; i++){
        cin >> units[i];
    }
    int k;
    cin >> k;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++){
        v.emplace_back(units[i], boxes[i]);
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());
    int ans = 0;
    for (int i = 0; i < n; i++){
        // cout << k << " ";
        if(k>=v[i].second){
            ans += (v[i].first * v[i].second);
            k -= v[i].second;
        }
        else{
            ans += (k * v[i].first);
            k = 0;
        }
        if(k<=0){
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}