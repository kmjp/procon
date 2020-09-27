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



map<string,vector<string>> M;
set<string> D;
string K;

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        M.clear();
        D.clear();
        K=kingName;
    }
    
    void birth(string parentName, string childName) {
        M[parentName].push_back(childName);
    }
    
    void death(string name) {
        D.insert(name);
    }
    
    void dfs(string K,vector<string>& R) {
		if(D.count(K)==0) R.push_back(K);
		FORR(k,M[K]) dfs(k,R);
	}
    vector<string> getInheritanceOrder() {
        vector<string> R;
        dfs(K,R);
        return R;
    }
};

