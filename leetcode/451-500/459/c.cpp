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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt[6];

class Solution {
public:
	int hoge(ll a) {
		int ret=0;
		while(a>1) {
			ret++;
			a=__builtin_popcountll(a);
		}
		return ret;
	}
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
		int i;
		FOR(i,6) ZERO(bt[i].bit);
		FOR(i,nums.size()) {
			int x=hoge(nums[i]);
			bt[x].add(i+1,1);
		}
		vector<int> ret;
		FORR(q,queries) {
			if(q[0]==1) {
				ret.push_back(bt[q[3]](q[2]+1)-bt[q[3]](q[1]));
			}
			else {
				i=q[1];
				int x=hoge(nums[i]);
				bt[x].add(i+1,-1);
				nums[i]=q[2];
				x=hoge(nums[i]);
				bt[x].add(i+1,1);
			}
		}
        return ret;
    }
};


