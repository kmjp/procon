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

BIT_r<ll,23> bt;


class Solution {
public:
    int sumCounts(vector<int>& nums) {
		int N=nums.size();
		int i;
		FOR(i,N+1) bt.add(i,i+1,mo-bt.total(i));
		
		map<int,int> M;
		ll sum=0;
		ll ret=0;
		for(i=N-1;i>=0;i--) {
			if(M.count(nums[i])) {
				int x=M[nums[i]];
				int b=N-x;
				ll sb=bt.total(N-1)-bt.total(x-1);
				(sum-=2*sb-b)%=mo;
				sum=(sum%mo+mo)%mo;
				bt.add(x,N-1,mo-1);
			}
			ll v=bt.total(N-1);
			int n=N-i;
			(sum+=2*v%mo+n)%=mo;
			bt.add(i,N-1,1);
			M[nums[i]]=i;
			(ret+=sum)%=mo;
		}
		return ret;
		
        
    }
};
