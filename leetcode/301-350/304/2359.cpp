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

int D[101010][2];
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int i;
        int N=edges.size();
        FOR(i,N) D[i][0]=D[i][1]=101010;
        FOR(i,2) {
			int cur=(i==0)?node1:node2;
			D[cur][i]=0;
			int d=0;
			while(edges[cur]!=-1) {
				cur=edges[cur];
				if(D[cur][i]!=101010) break;
				D[cur][i]=++d;
			}
		}
		
		int mi=-1;
		FOR(i,N) {
			if(D[i][0]<101010&&D[i][1]<101010) {
				if(mi==-1||max(D[mi][0],D[mi][1])>max(D[i][0],D[i][1])) mi=i;
			}
		}
		return mi;
    }
};

