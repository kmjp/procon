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
    long long maxAlternatingSum(vector<int>& nums) {
		vector<ll> V;
		FORR(a,nums) V.push_back(1LL*a*a);
		sort(ALL(V));
		reverse(ALL(V));
		ll ret=0;
		int N=V.size(),i;
		FOR(i,N) {
			if(i<=(N-1)/2) ret+=V[i];
			else ret-=V[i];
		}
		return ret;
    }
};

