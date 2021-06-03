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
    string maxValue(string n, int x) {
		int i;
		char c='0'+x;
		int N=n.size();
		if(n[0]=='-') {
			for(i=1;i<N;i++) {
				if(c<n[i]) {
					return n.substr(0,i)+c+n.substr(i);
				}
			}
			return n+c;
		}
		else {
			for(i=0;i<N;i++) {
				if(c>n[i]) {
					return n.substr(0,i)+c+n.substr(i);
				}
			}
			return n+c;
		}
        
    }
};
