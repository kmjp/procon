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

class CombinationIterator {
public:
	vector<string> V;
	int id=0;
    CombinationIterator(string characters, int combinationLength) {
        sort(ALL(characters));
        V.clear();
        int N=characters.size();
        int mask;
        int i;
        FOR(mask,1<<N) if(__builtin_popcount(mask)==combinationLength) {
			string T;
			FOR(i,N) if(mask&(1<<i)) T+=characters[i];
			V.push_back(T);
		}
        sort(ALL(V));
    }
    
    string next() {
        return V[id++];
    }
    
    bool hasNext() {
        return id<V.size();
    }
};

