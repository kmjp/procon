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
    vector<int> replaceNonCoprimes(vector<int>& nums) {
		vector<int> V;
		FORR(n,nums) {
			while(V.size()) {
				if(__gcd(n,V.back())==1) {
					break;
				}
				n*=V.back()/__gcd(n,V.back());
				V.pop_back();
			}
			V.push_back(n);
		}
		return V;
        
    }
};
