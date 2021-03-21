typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,16> bt;


class Solution {
public:
	int hoge(int v,int b) {
		int ret=0;
		int i;
		int mask=0;
		for(i=15;i>=0;i--) {
			if(b&(1<<i)) {
				if(v&(1<<i)) {
					ret+=bt(mask+(2<<i)-1)-bt(mask+(1<<i)-1);
				}
				else {
					ret+=bt(mask+(1<<i)-1)-bt(mask-1);
				}
			}
			mask|=(b^v)&(1<<i);
		}
		return ret;
	}
    int countPairs(vector<int>& nums, int low, int high) {
		ZERO(bt.bit);
		ll ret=0;
		FORR(n,nums) {
			ret+=hoge(n,high+1);
			ret-=hoge(n,low);
			bt.add(n,1);
		}
		return ret;
    }
};


