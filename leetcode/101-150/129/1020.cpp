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


class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
		vector<ll> S;
		int N=A.size();
		ll sum=0;
		FORR(a,A) sum+=a;
		if(sum%3) return false;
		ll cand=sum/3;
		
		int num=0;
		ll cur=0;
		FORR(a,A) {
			cur+=a;
			if(cand==cur) cur=0,num++;
		}
		
		return num>=3;
		
        
    }
};

