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
    int maxIncreasingGroups(vector<int>& usageLimits) {
		sort(ALL(usageLimits));
		reverse(ALL(usageLimits));
		int N=usageLimits.size();
		int L=1,R=N,i;
		while(L<R) {
			int M=(L+R+1)/2;
			ll c=0;
			FOR(i,N) {
				c+=max(0,M-i);
				c-=min(c,(ll)usageLimits[i]);
			}
			if(c==0) L=M;
			else R=M-1;
		}
		return L;
    }
};
