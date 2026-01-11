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
	int cnt(int src,int target) {
		int i,j,ret=0;
		for(i=30;i>=0;i--) if((target&(1<<i))&&(src&(1<<i))==0) {
			int dif=(1<<i)-(src&((1<<i)-1));
			src+=dif;
			ret+=dif;
		}
		return ret;
		
	}
    int maximumAND(vector<int>& nums, int k, int m) {
		int ret=0;
		int i,j;
		for(i=30;i>=0;i--) {
			int tmp=ret+(1<<i);
			vector<int> V;
			FORR(a,nums) V.push_back(cnt(a,tmp));
			sort(ALL(V));
			ll sum=0;
			FOR(j,m) sum+=V[j];
			if(sum<=k) ret=tmp;
		}
		return ret;
        
    }
};
