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
    int maxStudents(vector<vector<char>>& seats) {
		int H=seats.size();
		int W=seats[0].size();
		int from[1<<8]={};
		int to[1<<8]={};
		int ma=0;
		FORR(s,seats) {
			int m=0;
			int x,y;
			FOR(x,W) if(s[x]=='.') m|=1<<x;
			FOR(x,1<<W) to[x]=-(1<<30);
			FOR(x,1<<W) {
				if((x&m)!=x) continue;
				if((x<<1)&x) continue;
				FOR(y,1<<W) {
					if((x<<1)&y) continue;
					if((y<<1)&x) continue;
					to[x]=max(to[x],from[y]+__builtin_popcount(x));
					ma=max(ma,to[x]);
				}
			}
			swap(from,to);
		}
		return ma;
		
		
        
    }
};
