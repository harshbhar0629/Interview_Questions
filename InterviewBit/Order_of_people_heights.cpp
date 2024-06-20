#include <bits/stdc++.h>
using namespace std;

vector<int>seg;
int n;

void update(int l, int r, int idx, int pos, int val){
	if(l==r){
		seg[idx] = val;
		return;
	}
	int m = (l+r)/2;
	if(pos <= m){
		update(l, m, idx*2, pos, val);
	}
	else{
		update(m+1, r, idx*2+1, pos, val);
	}
	seg[idx] = seg[idx*2+1] + seg[idx*2];
}

int getIdx(int l, int r, int idx, int k){
	if(l==r){
		return l;
	}
	int m = (l+r)/2;
	if(seg[idx*2] >= k){
		return getIdx(l, m, idx*2, k);
	}
	else{
		return getIdx(m+1, r, idx*2+1, k-seg[idx*2]);
	}
}


void update(int pos, int val){
	update(0, n-1, 1, pos, val);
}

int getIdx(int k){
	int idx = getIdx(0, n-1, 1, k+1);
	update(idx, 0);
	return idx;
}

vector<int> findOrder(vector<int> & height, vector<int> & infront) {
	vector<pair<int,int>>arr;
	n = height.size();
	for(int i=0; i<n; i++){
		arr.push_back({height[i], infront[i]});
	}

	sort(arr.begin(), arr.end());
	seg.resize(n*4,0);
	for(int i=0; i<n; i++)  
		update(i, 1);

	vector<int>order(n, 0);

	for(int i=0; i<n; i++){
		int h = arr[i].first;
		int k = arr[i].second;
		int idx = getIdx(k);
		order[idx] = h;
	}

	return order;
}

int main(){
    

    return 0;
}