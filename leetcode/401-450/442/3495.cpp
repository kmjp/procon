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
    long long minOperations(vector<vector<int>>& queries) {
        ll ret=0;
        FORR(q,queries) {
			ll C[16]={};
			int i,j;
			FOR(i,15) {
				ll L=1LL<<(i*2);
				ll R=(4LL<<(i*2))-1;
				L=max(L,(ll)q[0]);
				R=min(R,(ll)q[1]);
				if(R>=L) C[i]=R-L+1;
			}
			int del=0;
			for(i=14;i>=0;i--) {
				ret+=C[i]/2;
				if(i) C[i-1]+=C[i]/2*2;
				if(C[i]%2) {
					ret++;
					for(j=i-1;j>=0;j--) if(C[j]) {
						C[j]--;
						if(j) C[j-1]++;
						break;
					}
					if(i) C[i-1]++;
				}
			}
		}
		return ret;
    }
};


