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

int S[30][101010];

class Solution {
public:
	ll range(int L,int R) {
		int ret=0,i;
		FOR(i,30) if(S[i][R+1]-S[i][L]==R+1-L) ret|=1<<i;
		return ret;
	}
    int minimumDifference(vector<int>& nums, int k) {
		int N=nums.size();
        int i,j;
        FOR(j,30) FOR(i,N) {
			S[j][i+1]=S[j][i];
			if(nums[i]&(1<<j)) S[j][i+1]++;
		}
		ll ma=-1LL<<40;
		for(int L=0,R=0;L<N;L++) {
			R=max(R,L);
			while(R<N&&range(L,R)>k) R++;
			if(R<N) ma=max(ma,range(L,R));
		}
		ll mi=1LL<<40;
		for(int L=0,R=0;L<N;L++) {
			R=max(R,L);
			while(R<N&&range(L,R+1)>=k) R++;
			if(range(L,R)>=k) mi=min(mi,range(L,R));
		}
		
		return min(abs(ma-k),abs(mi-k));
		
		
    }
};
