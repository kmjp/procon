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
    long long gcdSum(vector<int>& nums) {
        vector<int> V;
        int m=0;
        int g=0;
        FORR(a,nums) {
			m=max(m,a);
			g=__gcd(m,a);
			V.push_back(g);
		}
		sort(ALL(V));
		ll ret=0;
		int i;
		FOR(i,V.size()/2) ret+=__gcd(V[i],V[V.size()-1-i]);
		return ret;
    }
};


