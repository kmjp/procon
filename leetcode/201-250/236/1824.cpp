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
    int minSideJumps(vector<int>& obstacles) {
        int from[3]={1,0,1};
        int i;
        for(i=1;i<=obstacles.size()-1;i++) {
			int to[3]={1<<20,1<<20,1<<20};
			if(obstacles[i]>0) from[obstacles[i]-1]=1<<20;
			to[0]=min({from[0]+0,from[1]+1,from[2]+1});
			to[1]=min({from[0]+1,from[1]+0,from[2]+1});
			to[2]=min({from[0]+1,from[1]+1,from[2]+0});
			if(obstacles[i]>0) to[obstacles[i]-1]=1<<20;
			swap(from,to);
		}
		return min({from[0],from[1],from[2]});
    }
};
