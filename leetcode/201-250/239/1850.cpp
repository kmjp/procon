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
    int getMinSwaps(string num, int k) {
		string S=num,T=num;
        while(k--) next_permutation(ALL(T));
        int did[1010]={};
		int ret=0;
		int i,j;
		FOR(i,S.size()) {
			FOR(j,S.size()) if(did[j]==0) {
				if(S[i]==T[j]) {
					did[j]=1;
					break;
				}
				else {
					ret++;
				}
			}
		}
		
		return ret;
        
    }
};
