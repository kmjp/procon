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
    bool sumOfNumberAndReverse(int num) {
		int i;
		for(i=0;i<=num;i++) {
			int a=i,b=0;
			while(a) b=b*10+a%10,a/=10;
			if(i+b==num) {
				cout<<i<<" "<<b<<endl;
				return 1;
			}
		}
        return 0;
    }
};
