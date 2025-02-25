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

int nex[303030];

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<ll> cand;
        FORR(e,points) {
			if(e[1]==0) cand.push_back(e[0]);
			else if(e[0]==side) cand.push_back(side+e[1]);
			else if(e[1]==side) cand.push_back(2LL*side+side-e[0]);
			else cand.push_back(4LL*side-e[1]);
			cand.push_back(4LL*side+cand.back());
		}
		sort(ALL(cand));
		ll ret=0;
		int i,j;
		int N=cand.size();
		for(i=30;i>=0;i--) {
			ll tmp=ret+(1<<i);
			if(tmp*k>4LL*side) continue;
			int x,y;
			for(x=y=0;x<N;x++) {
				while(y<N&&cand[y]-cand[x]<tmp) y++;
				nex[x]=y;
			}
			FOR(x,N/2) {
				int cur=x;
				FOR(j,k) {
					cur=nex[cur];
					if(cur==N) break;
				}
				if(cur<=x+N/2) break;
			}
			if(x<N/2) ret=tmp;
			
		}
		return ret;
    }
};


