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


bitset<1024> V[10];

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		int i,j;
		FOR(i,N) {
			V[i].reset();
			V[i][nums[i]]=1;
		}
		FOR(j,queries.size()) {
			{
				int ok=1;
				FOR(i,N) if(V[i][0]==0) ok=0;
				if(ok) return j;
			}
			for(i=queries[j][0];i<=queries[j][1];i++) V[i]|=V[i]>>queries[j][2];
			{
				int ok=1;
				FOR(i,N) if(V[i][0]==0) ok=0;
				if(ok) return j+1;
			}
		}
		return -1;
        
    }
};


