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


int D[505][505];
vector<int> E[555];
int ID[505];
int ng;
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
		int x,y,z;
		FOR(x,n) FOR(y,n) D[x][y]=-1;
		FOR(x,n) E[x].clear();
		FORR(e,edges) {
			E[e[0]-1].push_back(e[1]-1);
			E[e[1]-1].push_back(e[0]-1);
		}
		ng=0;
		
		FOR(x,n) {
			queue<int> Q;
			Q.push(x);
			D[x][x]=0;
			ID[x]=x;
			while(Q.size()) {
				int cur=Q.front();
				Q.pop();
				FORR(e,E[cur]) {
					ID[e]=x;
					if(D[x][e]==-1) {
						D[x][e]=D[x][cur]+1;
						Q.push(e);
					}
					else if(D[x][e]%2==D[x][cur]%2) {
						return -1;
					}
				}
			}
		}
		
		if(ng) return -1;
        int vis[501]={};
        int ret=0;
        FOR(z,n) {
			int ma1=0,ma2=0,mav=-1;
			FOR(x,n) {
				if(vis[ID[x]]==0) {
					FOR(y,x) if(ID[x]==ID[y]&&D[x][y]>mav) {
						mav=D[x][y];
						ma1=x;
						ma2=y;
					}
					if(mav==-1) {
						mav=0;
						ma1=x;
					}
				}
			}
			if(mav==-1) break;
			cout<<mav<<" "<<ma1<<endl;
			ret+=mav+1;
			vis[ID[ma1]]=1;
		}
        return ret;
        
    }
};
