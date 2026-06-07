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

int num[101010];
int numC[101010];
int numD[101010];

class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
		int i,j;
		FOR(i,100010+1) num[i]=numC[i]=0;
		FORR(a,nums) numC[a]++;
		for(i=1;i<=100000;i++) {
			for(j=i;j<=100000;j+=i) num[i]+=numC[j];
		}
        int ret=0;
        if(numC[1]) ret=1;
        for(i=2;i<=100000;i++) if(i<=maxVal || numC[i]) {
			vector<int> C;
			int cur=i;
			for(j=2;j*j<=cur;j++) if(cur%j==0) {
				C.push_back(j);
				while(cur%j==0) cur/=j;
			}
			if(cur>1) C.push_back(cur);
			int mask;
			int V=C.size();
			int tot=0;
			FOR(mask,1<<V) if(mask) {
				int v=1;
				FOR(j,V) if(mask&(1<<j)) v*=C[j];
				if(__builtin_popcount(mask)%2==1) tot+=num[v];
				else tot-=num[v];
			}
			
			if(numC[i]) {
				ret=max(ret,i-(tot-1));
			}
			else ret=max(ret,i-max(1,tot));
		}
		return ret;
    }
};
