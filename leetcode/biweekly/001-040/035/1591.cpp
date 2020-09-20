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


int L[61],R[61],U[61],D[61];
int S[61];
vector<int> V[61];
class Solution {
public:
    bool isPrintable(vector<vector<int>>& G) {
		int H=G.size();
		int W=G[0].size();
		int i,y,x,j;
		for(i=1;i<=60;i++) {
			L[i]=U[i]=61;
			R[i]=D[i]=-1;
			S[i]=0;
			V[i].clear();
		}
		
		FOR(y,H) FOR(x,W) {
			S[G[y][x]]++;
			L[G[y][x]]=min(L[G[y][x]],x);
			R[G[y][x]]=max(R[G[y][x]],x);
			U[G[y][x]]=min(U[G[y][x]],y);
			D[G[y][x]]=max(D[G[y][x]],y);
			V[G[y][x]].push_back(y*100+x);
		}
		queue<int> Q;
		for(i=1;i<=60;i++) {
			if(S[i]) {
				S[i]-=(R[i]-L[i]+1)*(D[i]-U[i]+1);
				if(S[i]==0) Q.push(i);
			}
			
		}
		cout<<"go"<<endl;
		while(Q.size()) {
			i=Q.front();
			cout<<"!"<<i<<" "<<S[i]<<endl;
			Q.pop();
			FORR(d,V[i]) {
				y=d/100;
				x=d%100;
				for(j=1;j<=60;j++) {
					if(S[j]<0&&L[j]<=x&&x<=R[j]&&U[j]<=y&&y<=D[j]) {
						S[j]++;
						if(S[j]==0) Q.push(j);
					}
				}
			}
		}
		for(i=1;i<=60;i++) if(S[i]) return 0;
		return 1;
        
    }
};


