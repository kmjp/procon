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


class BrowserHistory {
public:
	vector<string> V;
	int cur;
    BrowserHistory(string homepage) {
        V.clear();
        V.push_back(homepage);
        cur=0;
    }
    
    void visit(string url) {
		V.resize(cur+1);
		V.push_back(url);
		cur++;
        
    }
    
    string back(int steps) {
        cur=max(0,cur-steps);
        return V[cur];
    }
    
    string forward(int steps) {
        cur=min((int)V.size()-1,cur+steps);
        return V[cur];
    }
};

