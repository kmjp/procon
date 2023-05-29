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

int R[101010];
int C[101010];

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        int H=mat.size();
        int W=mat[0].size();
        vector<vector<int>> dp=mat; 
        map<int,vector<pair<int,int>>> M;
        int y,x;
        FOR(y,H) FOR(x,W) {
			M[mat[y][x]].push_back({y,x});
			dp[y][x]=1;
			R[y]=C[x]=0;
		}
        int ma=0;
        FORR(a,M) {
			auto b=a.second;
			FORR(c,b) {
				y=c.first;
				x=c.second;
				dp[y][x]=max(1+R[y],1+C[x]);
				ma=max(ma,dp[y][x]);
			}
			FORR(c,b) {
				y=c.first;
				x=c.second;
				R[y]=max(R[y],dp[y][x]);
				C[x]=max(C[x],dp[y][x]);
			}
		}
		return ma;
    }
};
