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
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<int> A(n);
        vector<vector<int>> B;
        int x,y;
        FOR(y,n) B.push_back(A);
        FORR(q,queries) {
			B[q[0]][q[1]]++;
			if(q[2]+1<n) B[q[2]+1][q[1]]--;
			if(q[3]+1<n) B[q[0]][q[3]+1]--;
			if(q[2]+1<n&&q[3]+1<n) B[q[2]+1][q[3]+1]++;
		}
		FOR(y,n) FOR(x,n) {
			if(y) B[y][x]+=B[y-1][x];
			if(x) B[y][x]+=B[y][x-1];
			if(y&&x) B[y][x]-=B[y-1][x-1];
		}
		return B;
		
		
    }
};