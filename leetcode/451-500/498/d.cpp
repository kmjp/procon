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


vector<int> O;
int check[16];
ll p[16];
ll memo[16][2][10];

class Solution {
public:
	ll hoge(ll v,int d,int le,int pre) {
		if(d==-1) return 1;
		if(memo[d][le][pre]>=0) return memo[d][le][pre];
		ll ret=0;
		
		ll c=v/p[d]%10;
		int i;
		FOR(i,10) {
			if(le==0&&i>c) continue;
			if(check[d]) {
				if(i<pre) continue;
				ret+=hoge(v,d-1,le|(i<c),i);
			}
			else {
				ret+=hoge(v,d-1,le|(i<c),pre);
			}
		}
		
		return memo[d][le][pre]=ret;
	}
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
		ZERO(check);
		check[15]=1;
		int cur=15;
		
        FORR(a,directions) {
			if(a=='D') cur-=4;
			else cur--;
			check[cur]=1;
		}
		
		int i;
		p[0]=1;
		FOR(i,15) p[i+1]=p[i]*10;
		MINUS(memo);
		ll v=hoge(r,15,0,0);
		MINUS(memo);
		v-=hoge(l-1,15,0,0);
		return v;
		
		
    }
};


