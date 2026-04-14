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
		int C[2]={};
		FORR(c,s) C[c-'0']++;
		int ret=0;
		if(C[0]==C[1]) ret=s.size();
		map<int,int> P;
		map<int,int> P2;
		P[0]=0;
		int i;
		int cur=0;
		FOR(i,s.size()) {
			if(s[i]=='0') cur--;
			else cur++;
			
			if(P.count(cur)) {
				ret=max(ret,i+1-P[cur]);
				if(P2.count(cur)==0) P2[cur]=i+1;
			}
			else {
				P[cur]=i+1;
			}
			if(P.count(cur-2)&&(i+1-P[cur-2])<=min(C[0],C[1])*2) ret=max(ret,(i+1-P[cur-2]));
			if(P2.count(cur-2)&&(i+1-P2[cur-2])<=min(C[0],C[1])*2) ret=max(ret,(i+1-P2[cur-2]));
			if(P.count(cur+2)&&(i+1-P[cur+2])<=min(C[0],C[1])*2) ret=max(ret,(i+1-P[cur+2]));
			if(P2.count(cur+2)&&(i+1-P2[cur+2])<=min(C[0],C[1])*2) ret=max(ret,(i+1-P2[cur+2]));
		}
        return ret;
    }
};
