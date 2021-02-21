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
    string longestNiceSubstring(string s) {
		int i,j;
		string R;
		FOR(i,s.size()) {
			int A=0,B=0;
			string T;
			for(j=i;j<s.size();j++) {
				T+=s[j];
				if(s[j]>='a'&&s[j]<='z') A|=1<<(s[j]-'a');
				if(s[j]>='A'&&s[j]<='Z') B|=1<<(s[j]-'A');
				
				if(A==B&&T.size()>R.size()) R=T;
			}
		}
        return R;
    }
};
