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
    long long maxGCDScore(vector<int>& nums, int k) {
		int N=nums.size();
		ll ma=1;
		int i,j;
		int p2[1515];
		FOR(i,N) {
			p2[i]=0;
			while(nums[i]%2==0) {
				p2[i]++;
				nums[i]/=2;
			}
		}
		
		FOR(i,N) {
			map<int,int> M;
			int g=0;
			for(j=i;j<N;j++) {
				g=__gcd(g,nums[j]);
				M[p2[j]]++;
				int len=j-i+1;
				int d=M.begin()->first;
				if(M.begin()->second<=k) d++;
				ma=max(ma,g*(1LL<<d)*len);
			}
		}
		return ma;
        
    }
};


