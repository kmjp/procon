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


int nex[101010];
int num[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
		int N=nums.size();
		vector<pair<int,int>> V,ev;
		V={{-1,-1}};
		int i;
		FOR(i,N) {
			nex[i]=N;
			num[i]=0;
			while(V.back().first>nums[i]) {
				nex[V.back().second]=i;
				V.pop_back();
			}
			V.push_back({nums[i],i});
			ev.push_back({-nums[i],i});
			bt.add(i,-bt(i));
			
		}
		sort(ALL(ev));
		ll ret=0;
		FORR2(v,i,ev) {
			ret+=bt(nex[i]-1)-bt(i);
			bt.add(i,1);
		}
		return ret;
        
    }
};

