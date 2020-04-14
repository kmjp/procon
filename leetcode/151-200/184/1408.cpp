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
    vector<string> stringMatching(vector<string>& words) {
		vector<string> V;
		FORR(u,words) {
			int ok=0;
			FORR(v,words) if(v.size()>u.size()) {
				for(int i=0;i+u.size()<=v.size();i++) if(v.substr(i,u.size())==u) ok=1;
			}
			if(ok) V.push_back(u);
		}
		return V;
        
    }
};
