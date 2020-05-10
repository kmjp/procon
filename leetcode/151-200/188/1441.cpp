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
    vector<string> buildArray(vector<int>& target, int n) {
		int is[101]={};
		FORR(t,target) is[t]=1;
		vector<string> T;
		for(int i=1;i<=n;i++) {
			T.push_back("Push");
			if(is[i]==0) T.push_back("Pop");
			if(target.back()==i) break;
		}
		return T;
        
    }
};


