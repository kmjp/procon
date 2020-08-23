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
    vector<int> mostVisited(int n, vector<int>& rounds) {
		int i;
		vector<int> V;
		if(rounds[0]<=rounds.back()) {
			for(i=rounds[0];i<=rounds.back();i++) V.push_back(i);
		}
		else {
			for(i=1;i<=rounds.back();i++) V.push_back(i);
			for(i=rounds[0];i<=n;i++) V.push_back(i);
		}
        return V;
    }
};

