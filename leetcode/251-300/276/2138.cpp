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
    vector<string> divideString(string s, int k, char fill) {
		while(s.size()%k) s+=fill;
		vector<string> V;
		int i;
		for(i=0;i<s.size();i+=k) {
			V.push_back(s.substr(i,k));
		}
        return V;
    }
};
