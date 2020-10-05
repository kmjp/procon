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



map<int,int> M;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(M.count(n)) return M[n];
        int ma=0;
        while(1<<(ma+1)<=n) ma++;
        int nex=-1;
        int i;
        FOR(i,ma) if(n&(1<<i)) nex=i;
        
        if(nex==-1) return M[n]=1+minimumOneBitOperations(n+1);
        
        int ret;
        int lef=n^(1<<ma)^(1<<nex);
        ret=minimumOneBitOperations(lef);
        
		ret+=1+minimumOneBitOperations((1<<ma)^(1<<nex)^(1<<(1+nex)));
        
        return M[n]=ret;
    }
};
