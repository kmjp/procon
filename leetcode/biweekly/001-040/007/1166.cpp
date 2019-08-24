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


class FileSystem {
public:
	map<string,int> M;
    FileSystem() {
        M.clear();
        M[""]=0;
    }
    
    bool create(string path, int value) {
		if(M.count(path)) return 0;
		string P=path;
		while(P.back()!='/') P.pop_back();
		P.pop_back();
		if(M.count(P)==0) return 0;
		M[path]=value;
		return 1;
        
    }
    
    int get(string path) {
        if(M.count(path)) return M[path];
        return -1;
    }
};