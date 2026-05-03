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

ll S[202020];
ll V[202020];

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
		int i,N=nums.size();
		vector<int> C(N);
		FOR(i,N) {
			if(i==0) {
				C[i]=1;
			}
			else if(i==N-1) {
				C[i]=i-1;
			}
			else {
				if(abs(nums[i]-nums[i-1])<=abs(nums[i]-nums[i+1])) C[i]=i-1;
				else C[i]=i+1;
			}
		}
		FOR(i,N-1) {
			S[i+1]=S[i];
			if(C[i]==i+1) {
				S[i+1]++;
			}
			else {
				S[i+1]+=nums[i+1]-nums[i];
			}
		}
		V[N-1]=0;
		for(i=N-2;i>=0;i--) {
			V[i]=V[i+1];
			if(C[i+1]==i) {
				V[i]++;
			}
			else {
				V[i]+=nums[i+1]-nums[i];
			}
		}
		vector<int> R;
		FORR(q,queries) {
			if(q[0]<q[1]) R.push_back(S[q[1]]-S[q[0]]);
			else R.push_back(V[q[1]]-V[q[0]]);
		}
        return R;
    }
};
