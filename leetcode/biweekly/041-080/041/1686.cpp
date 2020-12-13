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
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
		int N=aliceValues.size(),i;
		vector<pair<int,int>> V;
		FOR(i,N) V.push_back({aliceValues[i]+bobValues[i],i});
		sort(ALL(V));
		reverse(ALL(V));
		ll sum=0;
		FOR(i,V.size()) {
			int j=V[i].second;
			if(i%2==0) sum+=aliceValues[j];
			else sum-=bobValues[j];
		}
		if(sum>0) sum=1;
		if(sum<0) sum=-1;
		return sum;
        
    }
};



