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
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int i;
        int N=nums.size();
        vector<ll> A={0};
        FOR(i,N) {
			if(nums[i]) A.push_back(A.back()+i);
		}
		N=A.size()-1;
		ll ret=1LL<<60;
		for(int take=max(0,k-maxChanges);take<=min({N,k,max(0,k-maxChanges)+3});take++) {
			for(i=0;i+take<=N;i++) {
				int m1=i+take/2;
				int m2=i+take-take/2;
				ll sum=(A[i+take]-A[m2])-(A[m1]-A[i]);
				ret=min(ret,sum+(k-take)*2);
			}
		}
        return ret;
        
    }
};
