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
    int longestBalanced(string s) {
		int ret=0;
		int a,b,c;
		int N=s.size();
		FOR(a,N) {
			int C[26]={};
			for(b=a;b<N;b++) {
				C[s[b]-'a']++;
				int co=0;
				FOR(c,26) if(C[c]) {
					if(co==0) co=C[c];
					if(co!=C[c]) break;
				}
				if(c==26) ret=max(ret,b-a+1);
			}
		}
        return ret;
    }
};

