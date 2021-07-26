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
    int getLucky(string s, int k) {
		int A=0;
		FORR(c,s) {
			int b=c-'a'+1;
			while(b) {
				A+=b%10;
				b/=10;
			}
		}
		cout<<A<<endl;
		k--;
		while(k--) {
			int B=0;
			while(A) {
				B+=A%10;
				A/=10;
				;
			}
			A=B;
		}
		return A;
		
        
    }
};
