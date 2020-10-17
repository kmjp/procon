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
    double trimMean(vector<int>& arr) {
		sort(ALL(arr));
		ll sum=0;
		int i;
		int N=arr.size()/20;
		FOR(i,arr.size()) {
			if(i<N) continue;
			if(i+N>=arr.size()) continue;
			sum+=arr[i];
		}
        return sum/(arr.size()*0.9);
    }
};

 */