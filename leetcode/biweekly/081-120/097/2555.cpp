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

int ma[202020];

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
		
		int n=prizePositions.size();
		int i;
		FOR(i,n+1) ma[i]=0;
		int ret=0;
		for(int L=n-1,R=n-1;L>=0;L--) {
			while(prizePositions[L]+k<prizePositions[R]) R--;
			ma[L]=max(R+1-L,ma[L+1]);
			ret=max(ret,R+1-L+ma[R+1]);
		}
        return ret;
    }
};
