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


int D[1010];
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
		int i;
		FOR(i,1001) D[i]=1<<30;
		queue<int> Q;
		D[start]=0;
		Q.push(start);
		while(Q.size()) {
			int x=Q.front();
			Q.pop();
			if(x==goal) return D[goal];
			FORR(a,nums) {
				if(x+a==goal) return D[x]+1;
				if(x-a==goal) return D[x]+1;
				if((x^a)==goal) return D[x]+1;
				if(x+a<=1000&&x+a>=0&&D[a+x]>D[x]+1) {
					D[a+x]=D[x]+1;
					Q.push(a+x);
				}
				if(x-a>=0&&x-a<=1000&&D[x-a]>D[x]+1) {
					D[x-a]=D[x]+1;
					Q.push(x-a);
				}
				if((x^a)<=1000&&(x^a)>=0&&D[x^a]>D[x]+1) {
					D[x^a]=D[x]+1;
					Q.push(x^a);
				}
			}
		}
		
		return -1;
        
    }
};
