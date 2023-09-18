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
    long long maximumSum(vector<int>& nums) {
		int N=nums.size();
		vector<int> V;
		int i;
		FOR(i,N) V.push_back(i+1);
		for(i=2;i*i<=N;i++) {
			FORR(a,V) while(a%(i*i)==0) a/=i*i;
		}
		map<int,ll> M;
		ll ma=0;
		FOR(i,N) {
			M[V[i]]+=nums[i];
			ma=max(ma,M[V[i]]);
		}
		return ma;
		
        
    }
};
