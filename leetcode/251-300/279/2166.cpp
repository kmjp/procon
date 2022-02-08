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




class Bitset {
public:
	int N;
	int sw;
	unordered_set<int> S;
    Bitset(int size) {
		N=size;
		S.clear();
		sw=0;
    }
    
    void fix(int idx) {
		if(sw==0) {
	        S.insert(idx);
	    }
	    else {
			S.erase(idx);
		}
    }
    
    void unfix(int idx) {
		if(sw==1) {
	        S.insert(idx);
	    }
	    else {
			S.erase(idx);
		}
    }
    
    void flip() {
        sw^=1;
    }
    
    bool all() {
		if(sw==0) {
	        return S.size()==N;
	    }
	    else {
			return S.empty();
		}
    }
    
    bool one() {
		if(sw==1) {
	        return S.size()!=N;
	    }
	    else {
			return !S.empty();
		}
    }
    
    int count() {
		if(sw==0) {
	        return S.size();
	    }
	    else {
			return N-S.size();
		}
    }
    
    string toString() {
		string R;
		int i;
		FOR(i,N) {
			if(S.count(i)) {
				if(sw==0) R+='1';
				else R+='0';
			}
			else {
				if(sw==0) R+='0';
				else R+='1';
			}
		}
		return R;
        
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
 