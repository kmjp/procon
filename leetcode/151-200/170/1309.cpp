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
    string freqAlphabets(string s) {
		string S;
		int i;
		FOR(i,s.size()) {
			if(i+2<s.size() && s[i+2]=='#') {
				S+='a'+(s[i]-'0')*10+(s[i+1]-'0')-1;
				i+=2;
			}
			else {
				S+='a'+s[i]-'1';
			}
		}
        return S;
        
    }
};
