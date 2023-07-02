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
    long long continuousSubarrays(vector<int>& nums) {
        ll ret=0;
        map<pair<int,int>,ll> M;
        FORR(n,nums) {
			map<pair<int,int>,ll> M2;
			M2[{n,n}]=1;
			ret++;
			FORR(a,M) {
				int L=min(a.first.first,n);
				int R=max(a.first.second,n);
				ll b=a.second;
				if(R-L<=2) {
					ret+=b;
					M2[{L,R}]+=b;
				}
			}
			swap(M,M2);
		}
		return ret;
    }
};
