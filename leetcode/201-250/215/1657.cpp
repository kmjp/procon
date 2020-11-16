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


/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
 

class Solution {
public:
    bool closeStrings(string word1, string word2) {
		map<int,int> M[2];
		vector<int> V[2];
		vector<int> W[2];
		FORR(c,word1) M[0][c]++;
		FORR(c,word2) M[1][c]++;
        FORR(m,M[0]) V[0].push_back(m.second), W[0].push_back(m.first);
        FORR(m,M[1]) V[1].push_back(m.second), W[1].push_back(m.first);
        sort(ALL(V[0]));
        sort(ALL(V[1]));
        sort(ALL(W[0]));
        sort(ALL(W[1]));
        return V[0]==V[1]&&W[0]==W[1];
    }
};

