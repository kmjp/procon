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

int C[10101][26];


class Solution {
public:
    int largestVariance(string s) {
		ZERO(C);
		int i,j,N=s.size();
		FOR(i,N) {
			s[i]-='a';
			C[i][s[i]]++;
		}
		FOR(i,26) FOR(j,N) if(j) C[j][i]+=C[j-1][i];
		int ma=0;
		int x,y;
		FOR(x,26) FOR(y,26) {
			if(x==y) continue;
			if(C[N-1][x]==0) continue;
			if(C[N-1][y]==0) continue;
			int nx=0,ny=0;
			FOR(i,N) {
				if(s[i]==x) nx++;
				if(s[i]==y) ny++;
				if(ny) ma=max(ma,nx-ny);
				if(ny>nx&&C[N-1][y]-C[i][y]) nx=ny=0;
			}
		}
		return ma;
        
    }
};