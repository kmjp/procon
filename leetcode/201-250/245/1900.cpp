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

int X,Y;
map<vector<int>,vector<int>> M;
class Solution {
public:
	vector<int> hoge(vector<int> V) {
		if(M.count(V)) return M[V];
		int i=0,a=-1,b=-1;
		FOR(i,V.size()) {
			if(V[i]==1) a=i;
			if(V[i]==3) b=i;
		}
		
		if(a==-1||b==-1) return M[V]={100,-1};
		if(a+b==V.size()-1) return M[V]={1,1};
		
		int need=0;
		int add=0;
		need |= 1<<min(a,(int)V.size()-1-a);
		need |= 1<<min(b,(int)V.size()-1-b);
		
		if(a*2<V.size()) add^=1<<a;
		if(b*2<V.size()) add^=1<<b;

		
		a=100,b=0;
		int N=(V.size()+1)/2;
		int mask;
		int sm=((1<<N)-1)-need;
		vector<int> A,B;
		for(mask=sm;mask>=0;mask--) {
			mask=mask&sm;
			int tm=mask^add;
			A.clear();
			B.clear();
			FOR(i,N) {
				if(tm&(1<<i)) A.push_back(V[i]);
				else B.push_back(V[V.size()-1-i]);
			}
			reverse(ALL(B));
			FORR(b,B) A.push_back(b);
			auto r=hoge(A);
			a=min(a,r[0]);
			b=max(b,r[1]);
		}
		M[V].push_back(a+1);
		M[V].push_back(b+1);
		return M[V];
		
	}
	
	
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
		int i;
		M.clear();
		vector<int> V;
		X=firstPlayer-1;
		Y=secondPlayer-1;
		if(X>Y) swap(X,Y);
		FOR(i,n) {
			if(i<X) V.push_back(0);
			if(i==X) V.push_back(1);
			if(i>X&&i<Y) V.push_back(2);
			if(i==Y) V.push_back(3);
			if(i>Y) V.push_back(4);
		}
		return hoge(V);
        
    }
};
