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

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
		multiset<int> S;
		vector<int> ev[101010];
		FORR(e,events) ev[e[0]].push_back(e[1]);
		int ret=0;
		int i;
		FOR(i,100010) {
			FORR(e,ev[i]) S.insert(e);
			if(S.size()) {
				ret++;
				S.erase(S.begin());
			}
			
			
			while(S.size()&&*S.begin()<=i) S.erase(S.begin());
		}
        return ret;
    }
};


