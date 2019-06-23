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
    vector<double> sampleStats(vector<int>& count) {
		vector<double> R(5,0);
        int N=256;
        int i;
        double sum=0,ns=0;
        int id=0;
        R[0]=-1;
        FOR(i,N) {
			if(count[i]) R[1]=i;
			if(count[i] && R[0]==-1) R[0]=i;
			if(count[i]>count[id]) id=i;
			sum+=1.0*i*count[i];
			ns+=count[i];
		}
		
		R[2]=sum/ns;
		R[4]=id;
		ll C1=(ns+1)/2,C2=ns/2+1;
        FOR(i,N) {
			if(C1>0&&C1<=count[i]) R[3]+=i;
			C1-=count[i];
			if(C2>0&&C2<=count[i]) R[3]+=i;
			C2-=count[i];
		}
		R[3]/=2.0;
		
        
        
        return R;
    }
};

