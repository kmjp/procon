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


ll ret[50505];

class Solution {
public:
    string stoneGameIII(vector<int>& V) {
        ZERO(ret);
        int N=V.size();
        int i;
        for(i=N-1;i>=0;i--) {
			ret[i]=-(1LL<<60);
			ret[i]=max(ret[i],V[i]-ret[i+1]);
			if(i+1<N) ret[i]=max(ret[i],V[i]+V[i+1]-ret[i+2]);
			if(i+2<N) ret[i]=max(ret[i],V[i]+V[i+1]+V[i+2]-ret[i+3]);
		}
        if(ret[0]>0) return "Alice";
        if(ret[0]<0) return "Bob";
        return "Tie";
        
    }
};

