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
    string maximumBinaryString(string S) {
		int c=-1,i;
		FOR(i,S.size()-1) {
			if(S[i]=='0'&&S[i+1]=='0') S[i]='1';
			else if(S[i]=='0'&&S[i+1]=='1') {
				c=i;
			}
			else if(S[i]=='1'&&S[i+1]=='0' && c>=0) {
				S[c]='1';
				S[c+1]='0';
				c++;
				S[i+1]='1';
			}
			
		}
        return S;
    }
};
