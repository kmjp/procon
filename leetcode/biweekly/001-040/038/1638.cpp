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
	int dif(string a,string b) {
		int i,j=0;
		FOR(i,a.size()) j+=a[i]!=b[i];
		return j==1;
	}
    int countSubstrings(string s, string t) {
        int ret=0;
        int i,j,len;
        for(len=1;len<=s.size();len++) {
			for(i=0;i+len<=s.size();i++) {
				for(j=0;j+len<=t.size();j++) {
					ret+=dif(s.substr(i,len),t.substr(j,len));
				}
			}
		}
		return ret;
    }
};

