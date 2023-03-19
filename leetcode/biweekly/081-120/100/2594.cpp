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



int num[100000];
ll S[101010];
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
		int N=ranks.size();
		ll ret=1LL<<60;
		int i,j;
		for(i=59;i>=0;i--) {
			ll tmp=ret-(1LL<<i);
			ll sum=0;
			FOR(j,N) {
				ll a=tmp/ranks[j];
				sum+=sqrt(a+0.11);
				if(sum>=cars) break;
			}
			if(sum>=cars) ret=tmp;
		}
		return ret;
        
    }
};

