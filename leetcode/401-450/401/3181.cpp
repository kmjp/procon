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
    int maxTotalReward(vector<int>& rewardValues) {
		bitset<100000> vis,cur,mask;
		cur[0]=mask[0]=1;
		FORR(r,rewardValues) vis[r]=1;
		int i;
		for(i=1;i<=50000;i++) {
			if(vis[i]) cur|=(cur&mask)<<i;
			mask[i]=1;
		}
		int ma=0;
		FOR(i,100000) if(cur[i]) ma=i;
		
        return ma;
        
    }
};
