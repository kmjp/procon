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
    int sumFourDivisors(vector<int>& nums) {
		int ret=0;
		FORR(n,nums) {
			vector<int> V;
			int i;
			int a=0;
			for(i=2;i*i<=n;i++) while(n%i==0) {
				a++;
				V.push_back(i);
				n/=i;
			}
			if(n>1) V.push_back(n);
			sort(ALL(V));
			if(V.size()==2 && V[0]!=V[1]) ret+=(V[0]+1)*(V[1]+1);
			if(V.size()==3 && V[0]==V[2]) ret+=1+V[0]+V[0]*V[0]+V[0]*V[0]*V[0];
			
		}
		return ret;
    }
};

