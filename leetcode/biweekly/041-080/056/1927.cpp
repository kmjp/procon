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
    bool sumGame(string num) {
		int A[2]={};
		int B=0;
		int N=num.size();
		int i;
		FOR(i,N) {
			if(i<N/2) {
				if(num[i]=='?') A[0]++;
				else B+=num[i]-'0';
			}
			else {
				if(num[i]=='?') A[1]++;
				else B-=num[i]-'0';
			}
		}
		
		if((A[0]+A[1])%2) {
			return 1;
		}
		
		int x=min(A[0],A[1]);
		A[0]-=x;
		A[1]-=x;
		cout<<A[0]<<" "<<A[1]<<" "<<B<<endl;
		if(A[0]) {
			return -B!=A[0]/2*9;
		}
		else if(A[1]) {
			return B!=A[1]/2*9;
		}
		else {
			return B!=0;
		}
    }
};
