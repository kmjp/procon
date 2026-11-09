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
    long long countValidSubstrings(string s) {
		vector<int> ng;
		int i,N=s.size();
		FOR(i,N-2) if(s.substr(i,3)=="abc") ng.push_back(i+2);
		ng.push_back(N);
		
		ll ret=0;
		FOR(i,N) {
			auto it=lower_bound(ALL(ng),i+2);
			if(it==ng.end()) ret+=N-i;
			else ret+=*it-i;
		}
		return ret;
		
        
    }
};
