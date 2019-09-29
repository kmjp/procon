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
    string removeDuplicates(string s, int k) {
		vector<pair<char,int>> V;
		FORR(c,s) {
			if(V.empty() || V.back().first!=c) V.push_back({c,0});
			V.back().second++;
			while(V.size() && V.back().second>=k) {
				V.back().second-=k;
				if(V.back().second==0) V.pop_back();
				
			}
		}
		string R;
		FORR(v,V) {
			int i;
			FOR(i,v.second) R.push_back(v.first);
		}
		return R;
        
    }
};


