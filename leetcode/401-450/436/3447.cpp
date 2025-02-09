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



int memo[101010];
int cand[101010];
int did[101010];
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
		int i;
		FOR(i,101000) {
			cand[i]=1<<20;
			did[i]=0;
		}
		FOR(i,groups.size()) if(cand[groups[i]]==-1) cand[groups[i]]=i;
		vector<int> ret;
		FOR(i,elements.size()) {
			int e=elements[i];
			if(did[e]) continue;
			did[e]=1;
			for(int j=e;j<=100000;j+=e) cand[j]=min(cand[j],i);
		}
		FORR(g,groups) {
			if(cand[g]==1<<20) ret.push_back(-1);
			else ret.push_back(cand[g]);
		}
		
		return ret;
        
    }
};
