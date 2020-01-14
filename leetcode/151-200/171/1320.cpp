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

int X[26],Y[26];
int D[27][27];
int dist[301][27][27];

class Solution {
public:
    int minimumDistance(string word) {
        int i,x,y;
        FOR(i,26) {
			X[i]=i%6;
			Y[i]=i/6;
		}
		FOR(x,26) FOR(y,26) D[x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
		FOR(i,301) FOR(x,27) FOR(y,27) dist[i][x][y]=101010;
		dist[0][26][26]=0;
		FOR(i,word.size()) {
			int t=word[i]-'A';
			FOR(x,27) FOR(y,27) {
				dist[i+1][t][y]=min(dist[i+1][t][y],dist[i][x][y]+D[x][t]);
				dist[i+1][x][t]=min(dist[i+1][x][t],dist[i][x][y]+D[y][t]);
			}
		}
		int mi=101010;
		FOR(x,27) FOR(y,27) mi=min(mi,dist[word.size()][x][y]);
		return mi;
		
        
        
    }
};
