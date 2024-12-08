#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    int findMinimumTime(vector<int>& strength, int K) {
        sort(ALL(strength));
        
        int ret=1<<30;
        
        
        do {
	        int turn=0;
	        int cur=0;
	        int X=1;
	        FORR(a,strength) {
				turn+=(a+X-1)/X;
				X+=K;
			}
			ret=min(ret,turn);
		} while(next_permutation(ALL(strength)));
		return ret;
    }
};

