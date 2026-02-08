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

ll from[105][105];
ll to[105][105];

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
		int N=nums1.size();
		int M=nums2.size();
		
		int x,y;
		FOR(x,N+1) FOR(y,M+1) from[x][y]=-1LL<<60;
		from[0][0]=0;
		while(k--) {
			FOR(x,N+1) FOR(y,M+1) {
				from[x+1][y]=max(from[x+1][y],from[x][y]);
				from[x][y+1]=max(from[x][y+1],from[x][y]);
			}
			FOR(x,N+1) FOR(y,M+1) {
				to[x][y]=-1LL<<60;
				if(x&&y) to[x][y]=from[x-1][y-1]+1LL*nums1[x-1]*nums2[y-1];
			}
			swap(from,to);
		}
		
		ll ret=-1LL<<60;
		FOR(x,N+1) FOR(y,M+1) ret=max(ret,from[x][y]);
		return ret;
		
		
        
    }
};
