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


    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int N=username.size();
        int i;
        map<string,vector<pair<int,string>>> M;
        FOR(i,N) {
			M[username[i]].push_back({timestamp[i],website[i]});
		}
		
		map<vector<string>,int> C;
		
		FORR(m,M) {
			auto V=m.second;
			sort(ALL(V));
			int x,y,z;
			set<vector<string>> CC;
			FOR(z,V.size()) FOR(y,z) FOR(x,y) {
				vector<string> S={V[x].second,V[y].second,V[z].second};
				CC.insert(S);
			}
			FORR(c,CC) C[c]++;
		}
		
		int num=-1;
		vector<string> R;
		FORR(c,C) {
			if(c.second>num) {
				num=c.second;
				R=c.first;
			}
			if(c.second==num) R=min(R,c.first);
			
		}
		return R;
		
		
		
    }
};

