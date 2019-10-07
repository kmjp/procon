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

ll from[5];
ll to[5];
ll mo=1000000007;

class Solution {
public:
    int countVowelPermutation(int n) {
        int i,j;
        FOR(i,5) from[i]=1;
        
        FOR(i,n-1) {
			ZERO(to);
			to[0]=from[1];
			to[1]=from[0]+from[2];
			to[2]=from[0]+from[1]+from[3]+from[4];
			to[3]=from[2]+from[4];
			to[4]=from[0];
			
			FOR(j,5) to[j]%=mo;
			swap(from,to);
		}
        ll ret=0;
        FOR(i,5) ret+=from[i];
        return ret%mo;
        
    }
};
