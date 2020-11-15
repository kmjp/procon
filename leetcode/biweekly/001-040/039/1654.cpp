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

int ng[4040];
int D[4040][2];

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        ZERO(ng);
        int i;
        FOR(i,4010) D[i][0]=D[i][1]=1<<30;
        FORR(v,forbidden) ng[v]=1;
        D[0][0]=0;
        queue<int> Q;
        Q.push(0);
        while(Q.size()) {
			int cur=Q.front()%5000000;
			int id=Q.front()/5000000;
			Q.pop();
			if(cur==x) return D[cur][id];
			
			if(cur+a<=4010&&ng[cur+a]==0&&D[cur+a][0]>D[cur][id]+1) {
				D[cur+a][0]=D[cur][id]+1;
				Q.push(cur+a);
			}
			if(id==0&&cur-b>=0&&ng[cur-b]==0&&D[cur-b][1]>D[cur][id]+1) {
				D[cur-b][1]=D[cur][id]+1;
				Q.push(cur-b+5000000);
			}
		}
		return -1;
    }
};
