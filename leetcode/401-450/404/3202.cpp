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
    int maximumLength(vector<int>& nums, int k) {
		vector<int> V[1010];
		
		int ma=0;
		int i;
		FOR(i,nums.size()) V[nums[i]%k].push_back(i);
		int x,y;
		FOR(x,k) FOR(y,k) {
			int cur=0;
			int step=0;
			while(1) {
				int v;
				if(step%2==0) {
					v=lower_bound(ALL(V[x]),cur)-V[x].begin();
					if(v==V[x].size()) break;
					cur=V[x][v]+1;
				}
				else {
					v=lower_bound(ALL(V[y]),cur)-V[y].begin();
					if(v==V[y].size()) break;
					cur=V[y][v]+1;
				}
				step++;
			}
			ma=max(ma,step);
		}
		return ma;
        
    }
};
