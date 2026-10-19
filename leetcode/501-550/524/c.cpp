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

vector<int> E[101010];
int C[101010];
class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int N=edges.size()+1;
        int i;
        FOR(i,N) {
			E[i].clear();
			C[i]=0;
			if(colors[i]=='B') C[i]=1;
			if(colors[i]=='W') C[i]=2;
		}
        FORR(e,edges) {
			E[e[0]].push_back(e[1]);
			E[e[1]].push_back(e[0]);
		}
		vector<int> cand;
		FOR(i,N) {
			int NC[3]={};
			FORR(e,E[i]) NC[C[e]]++;
			if(NC[(C[i]+2)%3]==0) cand.push_back(i);
		}
		if(cand.size()!=1) return -1;
		FOR(i,N) {
			if(i==cand[0]) {
				if(E[i].size()>2) return -1;
			}
			else {
				if(E[i].size()>3) return -1;
			}
		}
		return cand[0];
        
    }
};


 