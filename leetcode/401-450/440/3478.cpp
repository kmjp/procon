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
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
		multiset<ll> V;
		int N=nums1.size();
		vector<ll> ret(N);
		int i;
		ll sum=0;
		FOR(i,k) V.insert(0);
		map<int,vector<int>> M;
		FOR(i,N) M[nums1[i]].push_back(i);
		FORR(a,M) {
			FORR(v,a.second) ret[v]=sum;
			FORR(v,a.second) {
				sum+=nums2[v];
				V.insert(nums2[v]);
				sum-=*V.begin();
				V.erase(V.begin());
			}
		}
		return ret;
        
    }
};


