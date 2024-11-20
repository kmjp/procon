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


int S[202020];
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		int i;
		FOR(i,N+1) S[i]=0;
		FORR(q,queries) {
			S[q[0]]++;
			S[q[1]+1]--;
		}
		FOR(i,N) {
			S[i+1]+=S[i];
			if(S[i]<nums[i]) return 0;
		}
		return 1;
        
    }
};
