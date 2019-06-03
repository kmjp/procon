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
	int mult(string A,string B) {
		int a=A.size();
		int b=B.size();
		if(b%a) return 0;
		for(int x=0;x<b;x+=a) if(B.substr(x,a)!=A) return 0;
		return 1;
		
	}
    string gcdOfStrings(string A, string B) {
        int a=A.size();
        int b=B.size();
        for(int x=min(a,b);x>=1;x--) {
			string C=B.substr(0,x);
			if(mult(C,A) && mult(C,B)) return C;
		}
        return "";
    }
};

