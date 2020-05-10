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
    int countTriplets(vector<int>& arr) {
        int ret=0;
        int x,y,z;
        int N=arr.size();
        for(x=0;x<N;x++) {
			int a=0;
			for(y=x;y<N;y++) {
				a^=arr[y];
				int b=0;
				for(z=y+1;z<N;z++) {
					b^=arr[z];
					if(a==b) ret++;
				}
			}
		}
        return ret;
    }
};


