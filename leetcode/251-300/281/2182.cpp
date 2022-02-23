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
    string repeatLimitedString(string s, int repeatLimit) {
		int C[26]={};
		FORR(c,s) C[c-'a']++;
		
		int pre=-1,cnt=0;
		string R;
		int i;
		FOR(i,1000000) {
			int j;
			for(j=25;j>=0;j--) if(C[j]) {
				if(pre==j&&cnt==repeatLimit) continue;
				break;
			}
			if(j<0) break;
			R+='a'+j;
			C[j]--;
			if(pre!=j) cnt=0;
			pre=j;
			cnt++;
			
		}
		return R;
        
    }
};

