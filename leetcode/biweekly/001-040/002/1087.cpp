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


vector<string> R;
vector<string> V;
string CC;

class Solution {
public:
	void dfs(int cur) {
		if(cur==V.size()) {
			R.push_back(CC);
		}
		else {
			FORR(c,V[cur]) {
				CC.push_back(c);
				dfs(cur+1);
				CC.pop_back();
			}
		}
	}
    vector<string> permute(string S) {
		
		V.clear();
		int i=0;
		while(i<S.size()) {
			string C;
			if(S[i]=='{') {
				while(S[i]!='}') {
					if(S[i]>='a' && S[i]<='z') C.push_back(S[i]);
					i++;
				}
			}
			else {
				C.push_back(S[i]);
			}
			sort(ALL(C));
			V.push_back(C);
			i++;
		}
		
		R.clear();
		dfs(0);
		
		
		return R;
        
    }
};

