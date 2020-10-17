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
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		pair<int,int> P;
		int V=-1;
		int N=towers.size();
		int i,j;
		FOR(i,N) {
			int sum=0;
			FOR(j,N) {
				double d=hypot(towers[i][0]-towers[j][0],towers[i][1]-towers[j][1]);
				if(d<=radius) sum+=floor(towers[j][2]/(1+d));
			}
			cout<<i<<" "<<sum<<endl;
			if(V<sum) {
				V=sum;
				P={towers[i][0],towers[i][1]};
			}
			else if(V==sum) {
				P=min(P,{towers[i][0],towers[i][1]});
			}
		}
		return {P.first,P.second};
		
        
    }
};

 */