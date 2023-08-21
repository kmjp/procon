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

vector<int> V[101010];
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int i;
        FOR(i,n+2) V[i].clear();
        FOR(i,n) V[nums[i]-1].push_back(i);
        int ret=0;
        FOR(i,n) if(V[i].size()) {
			for(int L=0,R=0;L<V[i].size();L++) {
				if(R<L) R=L;
				while(R+1<V[i].size()&&(V[i][R+1]-V[i][L])-(R+1-L)<=k) R++;
				ret=max(ret,R+1-L);
			}
		}
		return min(ret,n);
    }
};
