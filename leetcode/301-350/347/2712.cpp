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
    long long minimumCost(string s) {
		vector<ll> D,E,L={0},R={0};
		int i;
		
		FOR(i,s.size()-1) if(s[i]!=s[i+1]) {
			D.push_back(i+1);
			E.push_back(s.size()-i-1);
			L.push_back(L.back()+D.back());
		}
        reverse(ALL(E));
        FORR(e,E) R.push_back(R.back()+e);
        reverse(ALL(R));
        ll mi=1LL<<60;
        FOR(i,L.size()) mi=min(mi,L[i]+R[i]);
        return mi;
    }
};

