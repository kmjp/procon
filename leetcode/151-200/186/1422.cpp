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
    int maxScore(string s) {
		int i,j;
		int ma=0;
		for(i=1;i<=s.size()-1;i++) {
			int cur=0;
			FOR(j,i) cur+=s[j]=='0';
			for(j=i;j<s.size();j++) cur+=s[j]=='1';
			ma=max(ma,cur);
		}
        return ma;
    }
};

