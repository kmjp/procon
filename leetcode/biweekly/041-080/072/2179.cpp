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

int P[101010];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		int N=nums1.size();
		int i,j;
		FOR(i,N) {
			P[nums2[i]]=i;
		}
		ll ret=0;
		FOR(i,N) {
			j=P[nums1[i]];
			ll le=bt(j);
			ll mo=(N-1-j)-(bt(N-1)-bt(j));
			ret+=le*mo;
			bt.add(j,1);
		}
		FOR(i,N) bt.add(i,-1);
		
		return ret;
        
    }
};
