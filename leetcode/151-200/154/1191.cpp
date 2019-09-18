
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

ll mo=1000000007;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
		ll ma=0;
		ll mi=0;
		ll cur=0;
		ll pre=0;
		FORR(v,arr) {
			cur+=v;
			ma=max(ma,cur-mi);
			pre=max(pre,cur);
			mi=min(mi,cur);
		}
		ll sum=cur;
		cur=0;
		ll suf=0;
		reverse(ALL(arr));
		FORR(v,arr) {
			cur+=v;
			suf=max(suf,cur);
		}
		if(k>=2) ma=max(ma,pre+suf+max(0LL,(k-2)*sum));
		return ma%mo;
    }
};
