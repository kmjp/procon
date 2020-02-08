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

int D[50505];

class Solution {
public:
    int minJumps(vector<int>& arr) {
		map<int,vector<int>> C;
		int i;
		int N=arr.size();
		FOR(i,N) {
			C[arr[i]].push_back(i);
			D[i]=1010101;
		}
		D[0]=0;
		queue<int> Q;
		Q.push(0);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			C[arr[cur]].push_back(cur-1);
			C[arr[cur]].push_back(cur+1);
			FORR(v,C[arr[cur]]) {
				if(v<0 || v>=N) continue;
				if(D[v]>D[cur]+1) {
					D[v]=D[cur]+1;
					Q.push(v);
				}
			}
			C.erase(arr[cur]);
		}
		return D[N-1];
        
    }
};

