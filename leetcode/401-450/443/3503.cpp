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
		if(!mul0) mul0=10009,mul1=10007;
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
	static ll concat(ll L ,ll R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		ll La=L>>32,Lb=(L<<32)>>32,Ra=R>>32,Rb=(R<<32)>>32;
		return (((Ra + La*pmo[0][RL])%mo0)<<32)|((Rb + Lb*pmo[1][RL])%mo1);
	}
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;



class Solution {
public:
    int longestPalindrome(string s, string t) {
		int ret=1;
		
		
		int lp;
		FOR(lp,2) {
			unordered_set<ll> S[1010];
			int ma[1010]={};
			
			string vs=s,vt=t;
			reverse(ALL(vs));
			reverse(ALL(vt));
			
			RollingHash rhs,rht,rhvs,rhvt;
			rhs.init(s);
			rhvs.init(vs);
			rhvt.init(vt);
			S[0].insert(0);
			for(int len=1;len<=t.size();len++) {
				for(int x=0;x+len<=t.size();x++) S[len].insert(rhvt.hash(x,x+len-1));
			}
			int x;
			int N=s.size();
			FOR(x,N) {
				ma[x]=1;
				for(int len=2;x+len<=N;len++) {
					if(rhs.hash(x,x+len-1)==rhvs.hash(N-1-(x+len-1),N-1-x)) ma[x]=len;
				}
			}
			
			FOR(x,N) {
				ret=max(ret,ma[x]);
				for(int len=0;x+len<=s.size();len++) {
					if(S[len].count(rhs.hash(x,x+len-1))) ret=max(ret,len*2+ma[x+len]);
				}
			}
			
			
			swap(s,t);
			reverse(ALL(s));
			reverse(ALL(t));
		}
		return ret;
		
        
    }
};


