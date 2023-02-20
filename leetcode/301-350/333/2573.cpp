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
    string findTheString(vector<vector<int>>& lcp) {
        int N=lcp.size();
        int x,y,i;
        FOR(i,N) if(lcp[i][i]!=N-i) return "";
        FOR(x,N) FOR(y,N) if(lcp[x][y]!=lcp[y][x]) return "";
        string S;
        S.resize(N);
        char nex='a';
        FOR(x,N) if(S[x]==0) {
			if(nex>'z') return "";
			S[x]=nex;
			for(y=x+1;y<N;y++) if(S[y]==0&&lcp[x][y]) S[y]=nex;
			nex++;
		}
		FOR(x,N) FOR(y,N) {
			if(lcp[x][y]==0) {
				if(S[x]==S[y]) return "";
			}
			else {
				if(max(x,y)+lcp[x][y]>N) return "";
				if(S[x]!=S[y]) return "";
				if(x+1<N&&y+1<N&&lcp[x+1][y+1]+1!=lcp[x][y]) return "";
			}
		}
		return S;
    }
};
