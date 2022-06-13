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
    long long distinctNames(vector<string>& ideas) {
		ll C[26][26]={};
		map<string,int> S;
		FORR(s,ideas) {
			string t=s.substr(1);
			S[t]|=1<<(s[0]-'a');
		}
		int i;
		FORR(s,ideas) {
			string t=s.substr(1);
			int ma=S[t];
			FOR(i,26) {
				if((ma&(1<<i))==0) C[s[0]-'a'][i]++;
			}
		}
		
		ll ret=0;
		int x,y;
		FOR(x,26) FOR(y,26) ret+=C[x][y]*C[y][x];
		return ret;
		
        
    }
};
