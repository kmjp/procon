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
    long long maximumTotalDamage(vector<int>& power) {
		map<int,ll> A;
		FORR(p,power) A[p]+=p;
		map<int,ll> M;
		M[1<<30]=M[(1<<30)+1]=M[(1<<30)+2]=0;
		
		ll ret=0;
		FORR(p,A) {
			ll a=p.first;
			ll b=p.second;
			ll ma=b;
			int i;
			auto it=M.begin();
			FOR(i,3) {
				if(-it->first<a-2) ma=max(ma,it->second+b);
				it++;
			}
			M[-a]=ma;
			ret=max(ret,ma);
			while(M.size()>3) {
				int a=M.rbegin()->first;
				ll b=M.rbegin()->second;
				M.erase(a);
				a=M.rbegin()->first;
				M[a]=max(M[a],b);
			}
			
		}
		return ret;
        
    }
};
