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


const ll mo=1000000007;

ll num[1<<20];
ll dp[1<<20];
ll p2[1<<20];
class Solution {
public:
    int countEffective(vector<int>& nums) {
		ZERO(num);
		int tm=0;
		FORR(n,nums) {
			num[n]++;
			tm|=n;
		}
		int len=0;
		while(tm>=1<<len) len++;
		int i,mask;
		p2[0]=1;
		FOR(i,nums.size()+1) p2[i+1]=p2[i]*2%mo;
		
		FOR(i,len) FOR(mask,1<<len) if(mask&(1<<i)) num[mask]+=num[mask^(1<<i)];
		
		FOR(mask,1<<len) dp[mask]=p2[num[mask]];
		FOR(i,len) FOR(mask,1<<len) if(mask&(1<<i)) (dp[mask]-=dp[mask^(1<<i)]);
		
		return (p2[nums.size()]+mo-dp[tm]%mo)%mo;
		
		
        
    }
};
