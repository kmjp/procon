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


vector<int> P[101010];

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
		int i;
		int N=nums.size();
		FOR(i,N) {
			int x=nums[i];
			P[i].clear();
			for(int j=2;j*j<=x;j++) if(x%j==0) {
				while(x%j==0) x/=j;
				P[i].push_back(j);
			}
			if(x>1) P[i].push_back(x);
		}
		
		int ret=0;
		map<int,int> M;
		for(int L=0,R=0;L<N;L++) {
			if(R<L) R=L;
			while(M.size()<=k&&R<N) {
				FORR(a,P[R]) M[a]++;
				if(M.size()>k) {
					FORR(a,P[R]) {
						M[a]--;
						if(M[a]==0) M.erase(a);
					}
					break;
				}
				R++;
			}
			ret=max(ret,R-L);
			if(L<R) {
				FORR(a,P[L]) {
					if(--M[a]==0) M.erase(a);
				}
			}
		
		}
        return ret;
    }
};
