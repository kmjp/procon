#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		vector<pair<int,char>> V,V2;
		FORR(c,name) {
			if(V.empty() || c!=V.back().second) V.push_back({0,c});
			V.back().first++;
		}
		FORR(c,typed) {
			if(V2.empty() || c!=V2.back().second) V2.push_back({0,c});
			V2.back().first++;
		}
		if(V.size()!=V2.size()) return false;
		int i;
		FOR(i,V.size()) {
			if(V[i].second!=V2[i].second) return false;
			if(V[i].first>V2[i].first) return false;
		}
		return true;
	}
};
