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
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		vector<int> V;
		int i=0;
		FORR(p,pushed) {
			while(V.size() && i<popped.size() && V.back()==popped[i]) {
				V.pop_back();
				i++;
			}
			V.push_back(p);
		}
		while(V.size() && i<popped.size() && V.back()==popped[i]) {
			V.pop_back();
			i++;
		}
		
		return i==popped.size();
        
    }
};
