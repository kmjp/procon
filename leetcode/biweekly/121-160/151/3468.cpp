#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

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
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int L=bounds[0][0];
        int R=bounds[0][1];
        int i;
        for(i=1;i<original.size();i++) {
			int dif=original[i]-original[i-1];
			L+=dif;
			R+=dif;
			L=max(L,bounds[i][0]);
			R=min(R,bounds[i][1]);
			if(R<L) return 0;
		}
        return R-L+1;
    }
};

