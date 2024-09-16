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

unordered_set<ll> S[50505];

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(time(NULL)+((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	/*ˆÈ‰ºll”Å*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	ll hash(VT s) { init(s); return hash(0,s.size()-1); }
	static ll concat(ll L ,ll R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		ll La=L>>32,Lb=(L<<32)>>32,Ra=R>>32,Rb=(R<<32)>>32;
		return (((Ra + La*pmo[0][RL])%mo0)<<32)|((Rb + Lb*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

RollingHash rh;
int dp[50505];
vector<pair<int,int>> E[50505];


class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
		int i,j,N=target.size();
		FOR(i,50501) S[i].clear(),E[i].clear(),dp[i]=1<<20;
		dp[0]=0;
		FOR(i,N) E[i+1].push_back({i,0});
		
		FORR(w,words) {
			rh.init(w);
			for(i=1;i<=w.size();i++) S[i].insert(rh.hash(0,i-1));
		}
		rh.init(target);
		FOR(i,N) {
			int len=0;
			for(j=20;j>=0;j--) if(i+len+(1<<j)<=N&&S[len+(1<<j)].count(rh.hash(i,i+len+(1<<j)-1))) len+=(1<<j);
			if(len) E[i].push_back({i+len,1});
		}
		
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		while(Q.size()) {
			int co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			FORR(e,E[cur]) if(dp[e.first]>co+e.second) {
				dp[e.first]=co+e.second;
				Q.push({-dp[e.first],e.first});
			}
			
		}
		if(dp[N]>=1<<20) return -1;
		return dp[N];
        
    }
};
