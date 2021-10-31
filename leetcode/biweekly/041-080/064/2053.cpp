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
    string kthDistinct(vector<string>& arr, int k) {
		string R;
		set<string> S;
		map<string,int> M;
		
		FORR(a,arr) M[a]++;
		FORR(a,arr) if(M[a]==1) {
			if(S.count(a)==0) {
				S.insert(a);
				if(S.size()==k) R=a;
			}
		}
        return R;
    }
};
