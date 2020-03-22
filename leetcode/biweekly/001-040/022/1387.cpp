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
    int getKth(int lo, int hi, int k) {
		vector<pair<int,int>> V;
		int i;
		for(i=lo;i<=hi;i++) {
			int cur=i;
			int step=0;
			while(cur>1) {
				step++;
				if(cur%2==0) cur/=2;
				else cur=cur*3+1;
			}
			V.push_back({step,i});
		}
		sort(ALL(V));
		return V[k-1].second;
    }
};

