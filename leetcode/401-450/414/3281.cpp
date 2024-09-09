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
    int maxPossibleScore(vector<int>& start, int d) {
		sort(ALL(start));
		ll ret=0;
		int i,j;
		for(i=30;i>=0;i--) {
			ll s=start[0];
			int ok=1;
			for(j=1;j<start.size();j++) {
				if(start[j]+d<s+(ret+(1LL<<i))) {
					ok=0;
					break;
				}
				s=max(s+(ret+(1LL<<i)),(ll)start[j]);
			}
			if(ok) ret+=1LL<<i;
		}
		return ret;
        
    }
};
