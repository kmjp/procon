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

ll pat[1<<12][12];
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        set<ll> ok;
        int i;
        FOR(i,100000) ok.insert(1LL*i*i);
        int N=A.size();
        map<int,int> num;
        ZERO(pat);
        
        FOR(i,N) pat[1<<i][i]=1;
        ll fact=1;
        FOR(i,N) {
			num[A[i]]++;
			fact*=num[A[i]];
		}
        int mask,x,y;
        FOR(mask,1<<N) {
			FOR(x,N) if(mask&(1<<x)) {
				FOR(y,N) if((mask&(1<<y))==0 && ok.count(A[x]+A[y])) pat[mask | (1<<y)][y] += pat[mask][x];
			}
		}
        
        ll ret=0;
        FOR(i,N) ret+=pat[(1<<N)-1][i];
        return ret/fact;
    }
};
