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

int P[2020][2020];

class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		int a,b,i;
		vector<int> A=nums;
		FOR(i,N) {
			FOR(a,A.size()) {
				P[a][a+i]=A[a];
			}
			FOR(a,A.size()-1) A[a]^=A[a+1];
			A.pop_back();
		}
		int len;
		for(int len=1;len<=N;len++) {
			for(a=0;a+len<=N;a++) {
				P[a][a+len]=max(P[a][a+len],P[a][a+len-1]);
				P[a][a+len]=max(P[a][a+len],P[a+1][a+len]);
			}
		}
        vector<int> ret;
        FORR(q,queries) ret.push_back(P[q[0]][q[1]]);
        return ret;
    }
};

