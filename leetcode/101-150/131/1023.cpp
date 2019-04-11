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
	bool match(string A,string B) {
		int cur=0;
		FORR(a,A) {
			if(a>='A' && a<='Z') {
				if(cur==B.size() || B[cur]!=a) return false;
				cur++;
			}
			else {
				if(cur<B.size() && B[cur]==a) cur++;
			}
		}
		return cur==B.size();
	}
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> b;
        FORR(q,queries) b.push_back(match(q,pattern));
        return b;
    }
};

