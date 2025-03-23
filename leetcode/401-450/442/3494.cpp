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

ll from[5050];
ll to[5050];

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int N=skill.size(),M=mana.size();
        int y,x;
        ZERO(from);
        FOR(y,M) {
			ll cand=0;
			ll sum=0;
			FOR(x,N) {
				cand=max(cand,from[x+1]-sum*mana[y]);
				sum+=skill[x];
			}
			from[0]=cand;
			FOR(x,N) from[x+1]=from[x]+skill[x]*mana[y];
		}
		return from[N];;
			
    }
};


