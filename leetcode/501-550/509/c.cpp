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


class Solution {
public:
    int divisibleGame(vector<int>& nums) {
        vector<int> C={2};
        FORR(a,nums) {
			int x=a;
			for(int i=2;i*i<=x;i++) if(x%i==0) {
				C.push_back(i);
				while(x%i==0) x/=i;
			}
			if(x>1) C.push_back(x);
		}
		sort(ALL(C));
		C.erase(unique(ALL(C)),C.end());
		ll ret=-1LL<<60;
		int k=-1;
		FORR(c,C) {
			ll mi=0;
			ll cur=0;
			FORR(a,nums) {
				if(a%c==0) cur+=a;
				else cur-=a;
				if(cur-mi>ret) {
					ret=cur-mi;
					k=c;
				}
				mi=min(mi,cur);
			}
		}
		return (ret%mo*k%mo+mo)%mo;
    }
};
