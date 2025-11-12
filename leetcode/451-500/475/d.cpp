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

ll from[1020][3];
ll to[1020][3];


class Solution {
public:
    long long maximumScore(vector<int>& nums, int k) {
		int N=nums.size();
		ll ret=0;
		
		int i,j,x;;
		FOR(i,3) {
			FOR(j,N+1) from[j][0]=from[j][1]=from[j][2]=-1LL<<60;
			from[0][i]=0;
			FORR(a,nums) {
				//Žæ‚ç‚È‚¢
				FOR(j,N+1) FOR(x,3) to[j][x]=from[j][x];
				FOR(j,N+1) {
					//Å‘å’l
					chmax(to[j+1][0],from[j][1]+a);
					chmax(to[j+1][0],from[j][2]-a);
					chmax(to[j][1],from[j][0]-a);
					chmax(to[j][2],from[j][0]+a);
				}
				swap(from,to);
			}
			for(j=1;j<=k;j++) ret=max(ret,from[j][i]);
		}
		
		return ret;
        
    }
};


