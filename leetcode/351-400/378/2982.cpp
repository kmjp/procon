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

int S[26][505050];

class Solution {
public:
    int maximumLength(string s) {
        int N=s.size();
        int i,j;
        FOR(i,26) FOR(j,N+1) S[i][j]=0;
        int cur=0;
        int pre=0;
        FORR(c,s) {
			if(c!=pre) cur=0;
			pre=c;
			cur++;
			S[c-'a'][cur]++;
		}
		int ma=-1;
		FOR(i,26) {
			for(j=N-1;j>=1;j--) {
				S[i][j]+=S[i][j+1];
				if(S[i][j]>=3) ma=max(ma,j);
			}
		}
		return ma;
    }
};
