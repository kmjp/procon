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



int nex[17171][26];
int N;
class Solution {
public:

	int ok(string& a,string& b,int k) {
		int cur=0;
		int i;
		FOR(i,k) {
			FORR(c,a) {
				if(nex[cur][c-'a']==N) return 0;
				cur=nex[cur][c-'a']+1;
			}
		}
		return 1;
	}
    string longestSubsequenceRepeatedK(string s, int k) {
        string R;
        int i,j;
        N=s.size();
        int C[256]={};
        FORR(c,s) C[c]++;
        FOR(j,26) nex[N][j]=N;
        for(i=N-1;i>=0;i--) {
			FOR(j,26) nex[i][j]=nex[i+1][j];
			nex[i][s[i]-'a']=i;
		}
        
        FOR(i,256) R+=string(C[i]/k,i);
        string ret;
        set<string> did;
        do {
			int i;
			FOR(i,R.size()) {
				auto V=R.substr(i);
				if(did.count(V)) continue;
				did.insert(V);
				if(V.size()>ret.size()||(V.size()==ret.size()&&V>ret)) {
					if(ok(V,s,k)) ret=V;
				}
			}
		} while(next_permutation(ALL(R)));
        
		return ret;
    }
};

