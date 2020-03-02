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
    string rankTeams(vector<string>& votes) {
		vector<pair<vector<int>,char>> V;
		V.resize(26);
		int i;
		FOR(i,26) {
			V[i].second='A'+i;
			V[i].first.resize(27);
		}
		FORR(s,votes) {
			FOR(i,s.size()) {
				V[s[i]-'A'].first[i]--;
				V[s[i]-'A'].first[26]++;
			}
		}
        sort(ALL(V));
        string S;
        FORR(v,V) {
			if(v.first[26]) S+=v.second;
		}
		return S;
        
    }
};
