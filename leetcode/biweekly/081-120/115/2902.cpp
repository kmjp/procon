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

int C[20202];
ll from[20202];
ll S[20202];
ll to[20202];
const ll mo=1000000007;
class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
		FORR(n,nums) C[n]++;
		ZERO(from);
		int i,j;
		from[0]=C[0]+1;
		for(i=1;i<=20000;i++) if(C[i]) {
			for(j=0;j<=20000;j++) {
				S[j]=from[j];
				if(j>=i) (S[j]+=S[j-i])%=mo;
			}
			for(j=i;j<=20000;j++) {
				from[j]=S[j];
				if(j-(C[i]+1)*i>=0) from[j]+=mo-S[j-(C[i]+1)*i];
				from[j]%=mo;
			}
		}
		
		ll ret=0;
		for(i=l;i<=r;i++) ret+=from[i];
		
		FORR(n,nums) C[n]=0;
		return ret%mo;
        
    }
};
