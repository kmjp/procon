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
    int countLargestGroup(int n) {
		map<int,int> M;
		int i;
		for(i=1;i<=n;i++) {
			int x=0,r=i;
			while(r) {
				x+=r%10;
				r/=10;
			}
			M[x]++;
		}
		
		int ma=0,num=0;
		FORR(m,M) {
			if(m.second>ma) ma=m.second,num=0;
			if(m.second==ma) num++;
		};
		return num;
        
    }
};

