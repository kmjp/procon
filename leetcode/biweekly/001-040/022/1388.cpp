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

vector<int> V;
int memo[1010][1010];

class Solution {
public:
	int hoge(int L,int R) {
		if((R-L)%3) return -1;
		if(L+3==R) return V[L+1];
		if(L==R) return 0;
		if(memo[L][R]>=0) return memo[L][R];
		int ret=-1;
		int i;
		for(i=L+3;i<R;i+=3) ret=max(ret,hoge(L,i)+hoge(i,R));
		for(i=L+1;i<R;i+=3) ret=max(ret,V[i]+hoge(L+1,i)+hoge(i+1,R-1));
		return memo[L][R]=ret;
	}

    int maxSizeSlices(vector<int>& slices) {
		
		V=slices;
		int i;
		int N=V.size();
		FOR(i,N) V.push_back(V[i]);
		MINUS(memo);
		int ret=0;
		int a,b,c;
		FOR(a,N) for(b=a+1;b-a<=N;b+=3) for(c=b+1;c<N;c+=3) {
			ret=max(ret,max({V[a],V[b],V[c]})+hoge(a+1,b)+hoge(b+1,c)+hoge(c+1,a+N));
		}
		return ret;
		
        
    }
};

