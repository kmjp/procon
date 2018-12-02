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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(ALL(deck));
        reverse(ALL(deck));
        deque<int> D;
        FORR(d,deck) {
			if(D.size()) {
				int x=D.back();
				D.pop_back();
				D.push_front(x);
			}
			D.push_front(d);
		}
		vector<int> R;
		FORR(d,D) R.push_back(d);
		return R;
    }
};
