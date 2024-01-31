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
    int maximumLength(vector<int>& nums) {
		map<ll,int> M;
		FORR(n,nums) M[n]++;
		
		int ma=1;
		if(M.count(1)) {
			ma=(M[1]-1)/2*2+1;
		}
			
		FORR2(a,b,M) {
			int cur=1;
			ll x=a;
			while(1) {
				if(a==1||M.count(x)==0) {
					ma=max(ma,cur*2-3);
					break;
				}
				ma=max(ma,cur*2-1);
				if(M[x]==1) {
					break;
				}
				cur++;
				x=x*x;
			}
		}
		return ma;
        
    }
};
