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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
		int C[26];
		int i;
		FOR(i,26) C[i]=i+1;
		FOR(i,chars.size()) C[chars[i]-'a']=vals[i];
		ll ret=0;
		ll mi=0;
		ll cur=0;
		FORR(c,s) {
			cur+=C[c-'a'];
			ret=max(ret,cur-mi);
			mi=min(mi,cur);
		}
		return ret;
        
    }
};
