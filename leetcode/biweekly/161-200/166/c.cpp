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

int X[202020];
int Y[202020];


class Solution {
public:
    int distinctPoints(string s, int k) {
		int i;
		FOR(i,s.size()) {
			X[i+1]=X[i];
			Y[i+1]=Y[i];
			if(s[i]=='L') X[i+1]--;
			if(s[i]=='R') X[i+1]++;
			if(s[i]=='U') Y[i+1]--;
			if(s[i]=='D') Y[i+1]++;
		}
		set<pair<int,int>> S;
		for(i=0;i+k<=s.size();i++) {
			S.insert({X[i+k]-X[i],Y[i+k]-Y[i]});
		}
		return S.size();
		
        
    }
};


