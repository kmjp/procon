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



class CustomStack {
public:
	vector<int> V;
	int S=0;
    CustomStack(int maxSize) {
        S=maxSize;
        V.clear();
    }
    
    void push(int x) {
        if(V.size()<S) V.push_back(x);
    }
    
    int pop() {
        if(V.empty()) return -1;
        int r=V.back();
        V.pop_back();
        return r;
    }
    
    void increment(int k, int val) {
        int i;
        FOR(i,min(k,(int)V.size())) V[i]+=val;
    }
};

