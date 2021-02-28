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
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
		int C[2][7]={};
		int S=0;
		FORR(s,nums1) C[0][s]++, S+=s;
		FORR(s,nums2) C[1][s]++, S-=s;
		int num=0;
		int i;
		if(S>0) {
			for(i=5;i>=1;i--) {
				while(C[0][1+i]&&S) S-=min(S,i),num++,C[0][i+1]--;
				while(C[1][6-i]&&S) S-=min(S,i),num++,C[1][6-i]--;
			}
		}
		if(S<0) {
			S=abs(S);
			for(i=5;i>=1;i--) {
				while(C[1][1+i]&&S) S-=min(S,i),num++,C[1][i+1]--;
				while(C[0][6-i]&&S) S-=min(S,i),num++,C[0][6-i]--;
			}
		}
		if(S) return -1;
		return num;
		
        
    }
};
