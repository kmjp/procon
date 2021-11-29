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
    int minimumBuckets(string street) {
		int num=0;
		int i;
		FOR(i,street.size()) {
			if(street[i]=='H') {
				if(i&&street[i-1]=='B') continue;
				
				if(i+1<street.size()&&street[i+1]=='.') {
					street[i+1]='B';
					num++;
					continue;
				}
				if(i&&street[i-1]=='.') {
					street[i-1]='B';
					num++;
					continue;
				}
				return -1;
			}
		}
		return num;
        
    }
};
