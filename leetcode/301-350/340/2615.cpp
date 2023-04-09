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
    vector<long long> distance(vector<int>& nums) {
        map<ll,ll> A,S,numA,numS;
        int i,N=nums.size();
        FOR(i,N) {
			A[nums[i]]+=i;
			numA[nums[i]]++;
		}
		vector<ll> V;
		FOR(i,N) {
			int x=nums[i];
			V.push_back(A[x]-numA[x]*i+numS[x]*i-S[x]);
			A[x]-=i;
			S[x]+=i;
			numA[x]--;
			numS[x]++;
		}
		return V;
    }
};
