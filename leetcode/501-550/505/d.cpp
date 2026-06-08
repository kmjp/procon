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

int N,L,R;
ll S[101010];

ll dp[101010],cnt[101010];



class Solution {
public:
	
	pair<ll,int> hoge(ll P) {
		//ペナルティP
		int i;
		deque<array<ll,3>> D;
		
		for(i=1;i<=N;i++) {
			dp[i]=dp[i-1];
			cnt[i]=cnt[i-1];
			
			
			//小さいもの削除
			int t=i-L;
			if(t>=0) {
				array<ll,3> p={dp[t]-S[t],cnt[t],t};
				while(D.size()&&D.back()<=p) D.pop_back();
				D.push_back(p);
			}
			while(D.size()&&D[0][2]<i-R) D.pop_front();
			
			//最大値のものに1個追加
			if(D.size()) {
				auto p=D[0];
				ll nv=S[i]+p[0]-P;
				int nc=p[1]+1;
				if(nv>dp[i]||(nv==dp[i]&&nc>cnt[i])) {
					dp[i]=nv;
					cnt[i]=nc;
				}
			}
		}
		return {dp[N],cnt[N]};
	}
	ll go(ll m) {
		ll L=-1LL<<40,R=1LL<<40,ret=-1LL<<40;
		while(R-L>1) {
			ll M=(R+L)/2;
			auto p=hoge(M);
			if(p.second>=m) {
				ret=p.first+m*M;
				L=M;
			}
			else {
				R=M;
			}
		}
		return ret;
	}
	
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
		N=nums.size();
		int i;
		FOR(i,N) S[i+1]=S[i]+nums[i];
		L=l,R=r;
		auto p=hoge(0);
		if(p.second>m) {
			//m個以上取るのが最適なら、m個とる
			return go(m);
		}
		else if(p.second>=1) {
			//1個以上m個以下が最適なら、今の解を変える
			return p.first;
		}
		else {
			//１個も取らないのが最適なら、１個だけ取る
			return go(1);
		}
		
        
    }
};

