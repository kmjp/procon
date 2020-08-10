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
    bool canConvertString(string s, string t, int k) {
		int C[26]={};
		int i;
		if(s.size()!=t.size()) return 0;
		FOR(i,s.size()) {
			if(s[i]<t[i]) {
				C[t[i]-s[i]]++;
			}
			if(t[i]<s[i]) {
				C[t[i]-s[i]+26]++;
			}
		}
		
        FOR(i,min(k,(int)s.size()*26+10)) {
			int num=(i+1)%26;
			if(C[num]) C[num]--;
		}
		FOR(i,26) if(C[i]) return false;
		return true;
    }
};

