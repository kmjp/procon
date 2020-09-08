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
    string modifyString(string s) {
		int i;
		FOR(i,s.size()) if(s[i]=='?') {
			s[i]='a';
			
			if(i&&s[i-1]==s[i]) s[i]++;
			if(i+1<s.size()&&s[i+1]==s[i]) s[i]++;
			if(i&&s[i-1]==s[i]) s[i]++;
			if(i+1<s.size()&&s[i+1]==s[i]) s[i]++;
			if(i&&s[i-1]==s[i]) s[i]++;
			if(i+1<s.size()&&s[i+1]==s[i]) s[i]++;
			
		}
		return s;
        
    }
};
