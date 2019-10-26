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
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(ALL(folder));
        vector<string> S;
        FORR(f,folder) {
			if(S.empty()) S.push_back(f);
			else {
				string a=S.back();
				if(f.size()>a.size()+1 && a+"/"==f.substr(0,a.size()+1)) continue;
				S.push_back(f);
				
				
			}
		}
        return S;
    }
};

