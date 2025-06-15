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
    string generateTag(string S) {
        int i;
        FORR(c,S) {
			if(c>='A'&&c<='Z') c-='A'-'a';
		}
		FOR(i,S.size()) if(i&&S[i-1]==' '&&S[i]>='a'&&S[i]<='z') S[i]+='A'-'a';
		S="#"+S;
		string V;
		FORR(c,S) if(c!=' ') V+=c;
		if(V[1]>='A'&&V[1]<='Z') V[1]-='A'-'a';
		if(V.size()>100) V=V.substr(0,100);
		return V;
    }
};

