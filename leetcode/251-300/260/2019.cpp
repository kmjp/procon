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

int sc[1010];
set<int> S[17][17];

class Solution {
public:
	int correct(string s) {
		ll ret=0;
		ll mul=0;
		int i;
		mul=s[0]-'0';
		for(i=2;i<s.size();i+=2) {
			if(s[i-1]=='*') {
				mul*=s[i]-'0';
			}
			else {
				ret+=mul;
				mul=s[i]-'0';
			}
		}
		ret+=mul;
		return ret;
	}
    int scoreOfStudents(string s, vector<int>& answers) {
		ZERO(sc);
		int N=s.size();
		int x,y;
		string op;
		FOR(x,N/2+2) FOR(y,N/2+2) S[x][y].clear();
		FOR(x,N/2) op+=s[x*2+1];
		FOR(x,N/2+1) S[x][x+1].insert(s[x*2]-'0');
		for(int len=2;len<=N/2+1;len++) {
			for(int l=0;l+len<=N/2+1;l++) {
				for(int r=l+1;r<l+len;r++) {
					if(op[r-1]=='+') {
						FORR(a,S[l][r]) FORR(b,S[r][l+len]) if(a+b<=1000) S[l][l+len].insert(a+b);
					}
					if(op[r-1]=='*') {
						FORR(a,S[l][r]) FORR(b,S[r][l+len]) if(a*b<=1000) S[l][l+len].insert(a*b);
					}
					
				}
			}
		}
		
		FORR(s,S[0][N/2+1]) sc[s]=2;
		
        
        int ret=0;
        sc[correct(s)]+=3;
        FORR(a,answers) {
			ret+=sc[a];
		}
        return ret;
        
    }
};
