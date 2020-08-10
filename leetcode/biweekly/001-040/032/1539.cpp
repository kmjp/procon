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
    int findKthPositive(vector<int>& arr, int k) {
		set<int> S;
		FORR(a,arr) S.insert(a);
		int cur=1;
		while(1) {
			if(S.count(cur)) {
				cur++;
				continue;
			}
			
			if(k==1) return cur;
			k--;
			cur++;
			
		}
		
        
    }
};


