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
    int score(vector<string>& cards, char x) {
		int C[11][11]={};
		FORR(c,cards) {
			C[c[0]-'a'][c[1]-'a']++;
		}
		int ret=0;
		x-='a';
		int i,a,b;
		FOR(i,C[x][x]+1) {
			vector<int> A,B;
			A.push_back(i);
			B.push_back(C[x][x]-i);
			FOR(a,10) if(a!=x) {
				A.push_back(C[a][x]);
				B.push_back(C[x][a]);
			}
			sort(ALL(A));
			sort(ALL(B));
			int SA=0,SB=0;
			FORR(a,A) SA+=a;
			FORR(a,B) SB+=a;
			int cand=min(SA/2,SA-(int)A.back())+min(SB/2,SB-(int)B.back());
			ret=max(cand,ret);
		}
		return ret;
        
    }
};
