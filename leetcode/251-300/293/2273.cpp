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
    vector<string> removeAnagrams(vector<string>& words) {
        set<string> S;
        vector<string> R;
        FORR(s,words) {
			if(R.empty()) {
				R.push_back(s);
			}
			else {
				string a=R.back();
				string t=s;
				sort(ALL(a));
				sort(ALL(t));
				if(a!=t) R.push_back(s);
			}
		}
		return R;
    }
};
