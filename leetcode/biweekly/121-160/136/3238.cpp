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
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int,int> M[11];
        FORR(v,pick) {
			M[v[0]][v[1]]++;
		}
		int ret=0;
		int i;
		FOR(i,n) {
			FORR(a,M[i]) {
				if(a.second>i) {
					ret++;
					break;
				}
			}
			
		}
		return ret;
    }
};
