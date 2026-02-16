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

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=29) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	ll is(ll val,int pos=29) {
		if(v==0) return 0;
		if(pos<0) return v;
		if(val&(1LL<<pos)) {
			if(nex[1]) return nex[1]->is(val,pos-1);
			return 0;
		}
		else {
			if(nex[0]) return nex[0]->is(val,pos-1);
			return 0;
		}
	}
	int pick(ll val,int pos=29) { // sum [0,s-1]
		if(pos<0) return 0;
		
		int tar=0;
		int ismax=1; //min‚¶‚á‚È‚­max
		if(((val&(1LL<<pos))>0)^ismax) {
			if(nex[1]&&nex[1]->v) tar=1;
			else tar=0;
		}
		else {
			if(nex[0]&&nex[0]->v) tar=0;
			else tar=1;
		}
		//max‚ðŽæ‚é‚È‚çtar‚ð”½“]
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
};


class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
		vector<int> S={0};
		BinarySumTrie bst;
		int ma=0;
		multiset<int> M;
		int N=nums.size();
		FORR(a,nums) S.push_back(S.back()^a);
		bst.add(0,1);
		
		for(int L=0,R=0;L<N;L++) {
			while(L==R||R<N&&nums[R]-*M.begin()<=k&&*M.rbegin()-nums[R]<=k) {
				M.insert(nums[R]);
				R++;
				bst.add(S[R],1);
			}
			int v=bst.pick(S[L]);
			ma=max(ma,S[L]^v);
			
			
			M.erase(M.find(nums[L]));
			bst.add(S[L],-1);
		}
		
        return ma;
    }
};

