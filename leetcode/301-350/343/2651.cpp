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
    int isWinner(vector<int>& player1, vector<int>& player2) {
		int A=0;
		int i;
		FOR(i,player1.size()) {
			int x=1;
			if(i&&player1[i-1]==10) x=2;
			if(i>=2&&player1[i-2]==10) x=2;
			A+=x*player1[i];
		}
		FOR(i,player2.size()) {
			int x=1;
			if(i&&player2[i-1]==10) x=2;
			if(i>=2&&player2[i-2]==10) x=2;
			A-=x*player2[i];
		}
		if(A>0) return 1;
		if(A<0) return 2;
		return 0;
        
    }
};
