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
    string evaluate(string s, vector<vector<string>>& knowledge) {
		map<string,string> a;
		FORR(k,knowledge) a[k[0]]=k[1];
		string T,K,R;
		int ins=0;
		FORR(c,s) {
			if(c=='(') {
				ins=1;
				K="";
			}
			else if(c==')') {
				if(a.count(K)) R+=a[K];
				else R+="?";
				ins=0;
			}
			else {
				if(ins==0) R+=c;
				else K+=c;
			}
		}
		return R;
		
        
    }
};
