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
    int minSwaps(string s) {
		int C[2]={};
		FORR(c,s) C[c-'0']++;
		int i,j;
		if(C[0]==C[1]) {
			int i;
			int mi=101010;
			FOR(i,2) {
				int sum=0;
				FOR(j,s.size()) {
					if(s[j]=='1'&&(j%2==i)) sum++;
				}
				mi=min(mi,sum);
			}
			return mi;
			
		}
		else if(abs(C[0]-C[1])==1) {
			int i;
			int sum=0;
			if(C[0]>C[1]) {
				FOR(j,s.size()) {
					if(s[j]=='1'&&(j%2==0)) sum++;
				}
			}
			else {
				FOR(j,s.size()) {
					if(s[j]=='1'&&(j%2==1)) sum++;
				}
			}
			return sum;
		}
		else {
			return -1;
		}
		
        
    }
};
