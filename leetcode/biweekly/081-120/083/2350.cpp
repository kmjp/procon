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

vector<int> cand[101010];
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int i;
        FOR(i,k) cand[i].clear();
        int N=rolls.size();
        FOR(i,N) cand[rolls[i]-1].push_back(i);
        
        int cur=-1;
        int x,y;
        for(i=1;i<=200000;i++) {
			int nex=-1;
			FOR(x,k) {
				int a=lower_bound(ALL(cand[x]),cur+1)-cand[x].begin();
				if(a==cand[x].size()) return i;
				nex=max(nex,cand[x][a]);
			}
			cur=nex;
		}
		return i;
    }
};
