#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
		set<int> S;
		vector<pair<int,int>> V;
		int i;
		int N=nums.size();
		vector<int> R(N);
		FOR(i,nums.size()) V.push_back({-nums[i],i});
		sort(ALL(V));
		FORR(a,V) {
			int i=a.second;
			auto it=S.lower_bound(i);
			if(it!=S.end()) it++;
			if(it!=S.end()) {
				R[i]=nums[*it];
			}
			else {
				R[i]=-1;
			}
			S.insert(i);
		}
        return R;
    }
};


