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
    bool checkZeroOnes(string s) {
		int ma[2]={};
		int i,j;
		FOR(i,s.size()) {
			for(j=i;j<s.size();j++) if(s[j]!=s[i]) break;
			ma[s[i]-'0']=max(ma[s[i]-'0'],j-i);
		}
		return ma[0]<ma[1];
        
    }
};
