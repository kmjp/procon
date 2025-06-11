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

const ll mo=1000000007;
template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) (bit[0][entry-1]+=val0)%=mo, (bit[1][entry-1]+=val1)%=mo, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return ((e*(v0%mo)+v1)%mo+mo)%mo;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		val%=mo;
		update(L,val,((-val*(L-1))%mo+mo)%mo);
		update(R+1,mo-val,(val*R%mo+mo)%mo);
	}
};
BIT_r<ll,20> bt;

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int N=nums.size();
        int i;
        FOR(i,N+1) bt.add(i,i,mo-bt.total(i));
        bt.add(0,0,1);
        int L,R;
        multiset<int> V;
        for(L=R=0;L<N;L++) {
			while(R<N) {
				V.insert(nums[R]);
				if(*V.rbegin()-*V.begin()>k) {
					V.erase(nums[R]);
					break;
				}
				R++;
			}
			ll a=(bt.total(L)-bt.total(L-1)+mo)%mo;
			bt.add(L+1,R,a);
			V.erase(V.find(nums[L]));
		}
		return (bt.total(N)-bt.total(N-1)+mo)%mo;
    }
};

