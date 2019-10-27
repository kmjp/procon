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
    int maxLength(vector<string>& arr) {
		int mask[16]={};
		int i,j;
		int n=arr.size();
		FOR(i,arr.size()) {
			int m=0;
			FORR(c,arr[i]) {
				c-='a';
				if(m&(1<<c)) {
					m=0;
					break;
				}
				m^=1<<c;
			}
			mask[i]=m;
		}
		
		int mal=0;
		FOR(i,1<<n) {
			int m=0;
			FOR(j,n) if(i&(1<<j)) {
				if(m&mask[j]) {
					m=0;
					break;
				}
				m^=mask[j];
			}
			mal=max(mal,__builtin_popcount(m));
		}
		return mal;
		
        
    }
};
