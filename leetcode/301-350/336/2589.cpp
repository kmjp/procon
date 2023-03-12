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
    int findMinimumTime(vector<vector<int>>& tasks) {
		int need=0;
		int N=tasks.size();
		FORR(a,tasks) a[1]++;
		int i,j;
		FOR(i,2010) {
			int n=0;
			FORR(e,tasks) if(e[2]>0) {
				if(e[1]-i==e[2]) n=1;
			}
			if(n) {
				need++;
				FORR(e,tasks) if(e[0]<=i&&i<e[1]) e[2]--;
			}
			
		}
        return need;
    }
};
