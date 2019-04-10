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
    string baseNeg2(int N) {
		string S;
		if(N==0) return "0";
		while(N) {
			S.push_back('0' + (abs(N)%2));
			N-=abs(N)%2;
			N/=-2;
		}
		reverse(ALL(S));
		return S;
    }
};

