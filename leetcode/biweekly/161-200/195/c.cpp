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
		set<int> A,B,C;
		int i,N=s.size();
		FOR(i,N) {
			if(s[i]=='a') A.insert(i);
			if(s[i]=='b') B.insert(i);
			if(s[i]=='c') C.insert(i);
		}
		A.insert(N);
		B.insert(N);
		C.insert(N);
		ll ret=0;
		FOR(i,N) {
			int nex=*A.lower_bound(i);
			nex=*B.lower_bound(nex);
			nex=*C.lower_bound(nex);
			ret+=nex-i;
		}
        return ret;
    }
};
