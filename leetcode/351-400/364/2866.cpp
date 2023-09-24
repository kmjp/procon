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

ll L[101010],R[101010];

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int N=maxHeights.size();
        vector<pair<ll,ll>> V;
        ll sum=0;
        int i,j;
        FOR(i,N) {
			L[i]=sum;
			int x=maxHeights[i];
			int num=1;
			while(V.size()&&V.back().first>=x) {
				num+=V.back().second;
				sum-=V.back().first*V.back().second;
				V.pop_back();
			}
			sum+=1LL*x*num;
			V.push_back({x,num});
		}
		sum=0;
		V.clear();
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			R[i]=sum;
			int x=maxHeights[i];
			int num=1;
			while(V.size()&&V.back().first>=x) {
				num+=V.back().second;
				sum-=V.back().first*V.back().second;
				V.pop_back();
			}
			sum+=1LL*x*num;
			V.push_back({x,num});
			ll a=sum;
			if(i) a+=L[i];
			ret=max(ret,a);
		}
		return ret;
    }
};
