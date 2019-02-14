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
    int brokenCalc(int x, int y) {
		int num=0;
		ll X=x,Y=y;
		
		if(X>=Y) return X-Y;
		while(X<<num < Y) num++;
		
		int ret=num+(X-(Y>>num));
		int i;
		int pre=0;
		FOR(i,num) {
			if(pre && (Y&(1<<i))==0) {
				ret++;
			}
			else if(pre==0 && (Y&(1<<i))) {
				pre=1;
			}
			cout<<pre<<" "<<ret<<endl;
		}
		return ret;
    }
};
