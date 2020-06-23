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
    vector<string> getFolderNames(vector<string>& names) {
		vector<string> V;
		set<string> S;
		map<string,int> M;
		FORR(n,names) {
			while(1) {
				int x=M[n];
				string T=n;
				if(x>0) T+="("+to_string(x)+")";
				M[n]++;
				if(S.count(T)==0) {
					S.insert(T);
					V.push_back(T);
					break;
				}
			}
		}
		return V;
        
    }
};
