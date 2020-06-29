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
    bool canArrange(vector<int>& arr, int k) {
		multiset<int> S;
		FORR(a,arr) {
			int x=(a%k+k)%k;
			int y=(k-x)%k;
			if(S.count(x)) {
				S.erase(S.find(x));
			}
			else {
				S.insert(y);
			}
		}
        return S.empty();
    }
};

