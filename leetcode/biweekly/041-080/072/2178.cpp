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
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2) return {};
        vector<ll> A;
        for(int x=2;finalSum;x+=2) {
			A.push_back(min((ll)x,finalSum));
			finalSum-=min((ll)x,finalSum);
		}
		if(A.size()>=2&&A.back()<=A[A.size()-2]) {
			A[A.size()-2]+=A.back();
			A.pop_back();
		}
		return A;
    }
};
