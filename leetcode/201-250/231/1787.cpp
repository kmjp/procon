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

int num[2020];
map<int,int> cost[2020];
int from[1024];
int to[1024];
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
		int n=nums.size();
		int i,j;
		ZERO(num);
		ZERO(cost);
		FOR(i,k) cost[i].clear();
		FOR(i,n) {
			num[i%k]++;
			cost[i%k][nums[i]]++;
		}
		FOR(i,1024) from[i]=10000;
		from[0]=0;
		FOR(i,k) {
			int mi=10000;
			
			FOR(j,1024) mi=min(mi,from[j]);
			FOR(j,1024) to[j]=mi+num[i];
			FOR(j,1024) {
				FORR(m,cost[i]) {
					to[j^m.first]=min(to[j^m.first],from[j]+num[i]-m.second);
				}
			}
			swap(from,to);
		}
		return from[0];
		
        
    }
};
