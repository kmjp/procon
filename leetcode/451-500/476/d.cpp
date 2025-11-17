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


int R[202020];
int L[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;


class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
		int N=nums.size();
		R[N]=0;
		int i;
		FOR(i,N) bt.add(i,-bt(i));
		for(i=N-1;i>=0;i--) {
			R[i]=1;
			if(i!=N-1&&nums[i]<=nums[i+1]) R[i]+=R[i+1];
			bt.add(i,R[i]);
		}
		L[0]=1;
		for(i=1;i<N;i++) {
			L[i]=1;
			if(nums[i-1]<=nums[i]) L[i]+=L[i-1];
		}
		vector<ll> ret;
		FORR(a,queries) {
			ll x=a[0],y=a[1];
			ll sum=0;
			if(y-(L[y]-1)<=x) {
				sum+=(y-x+1)*(y-x+2)/2;
			}
			else {
				sum+=1LL*L[y]*(L[y]+1)/2;
				sum+=bt(y-L[y])-bt(x-1);
			}
			ret.push_back(sum);
		}
		return ret;
        
    }
};


