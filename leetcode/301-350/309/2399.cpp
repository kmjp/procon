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
    bool checkDistances(string s, vector<int>& distance) {
		vector<int> C[26];
		int i;
		FOR(i,s.size()) C[s[i]-'a'].push_back(i);
		FOR(i,26) {
			if(C[i].empty()) continue;
			if(C[i].size()&&C[i][1]-C[i][0]!=distance[i]+1) return 0;
		}
		return 1;
        
    }
};
