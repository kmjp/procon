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
    int minMovesToMakePalindrome(string s) {
		int ret=0;
		while(s.size()>1) {
			int L[26]={},R[26]={};
			int i;
			FOR(i,26) {
				L[i]=s.size()+1;
				R[i]=-1;
			}
			FOR(i,s.size()) {
				L[s[i]-'a']=min(i,L[s[i]-'a']);
				R[s[i]-'a']=i;
			}
			int ma=0;
			FOR(i,26) if(L[i]!=R[i]&&R[i]>=0) {
				if(L[i]+s.size()-1-R[i]<L[ma]+s.size()-1-R[ma]) ma=i;
			}
			ret+=L[ma]+s.size()-1-R[ma];
			s=s.substr(0,L[ma])+s.substr(L[ma]+1,R[ma]-L[ma]-1)+s.substr(R[ma]+1);
		}
        return ret;
    }
};
