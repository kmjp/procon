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

int L[202020],R[202020];

class Solution {
public:
    int maximumGap(string skill, string station) {
		int x,y;
		x=0;
		int i;
		FOR(y,station.size()) if(x<skill.size()) {
			if(skill[x]==station[y]) {
				L[x]=y;
				x++;
			}
		}
		x=skill.size()-1;
		
		for(y=station.size()-1;y>=0;y--) if(x>=0) {
			if(skill[x]==station[y]) {
				R[x]=y;
				x--;
			}
		}
		int ma=0;
		FOR(i,skill.size()-1) ma=max(ma,R[i+1]-L[i]);
		return ma;
        
    }
};


