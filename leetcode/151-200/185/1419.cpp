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
    int minNumberOfFrogs(string croakOfFrogs) {
		int C[5]={};
		int ma=0;
		FORR(c,croakOfFrogs) {
			if(c=='c') C[0]++;
			if(c=='r') C[0]--, C[1]++;
			if(c=='o') C[1]--, C[2]++;
			if(c=='a') C[2]--, C[3]++;
			if(c=='k') C[3]--;
			if(C[0]<0) return -1;
			if(C[1]<0) return -1;
			if(C[2]<0) return -1;
			if(C[3]<0) return -1;
			ma=max(ma,C[0]+C[1]+C[2]+C[3]);
		}
        if(C[0]+C[1]+C[2]+C[3]) return -1;
        return ma;
    }
};


