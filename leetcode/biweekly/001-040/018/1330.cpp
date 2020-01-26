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
    int maxValueAfterReverse(vector<int>& V) {
		int N=V.size();
		ll S=0;
		int i;
		FOR(i,N-1) S+=abs(V[i]-V[i+1]);
		ll add=0;
		ll hoge[4];
		FOR(i,4) hoge[i]=-(1LL<<60);
		FOR(i,N-1) {
			
			add=max(add,hoge[0]-(V[i+1]+V[i])-abs(V[i+1]-V[i]));
			add=max(add,hoge[1]-(V[i+1]-V[i])-abs(V[i+1]-V[i]));
			add=max(add,hoge[2]-(-V[i+1]+V[i])-abs(V[i+1]-V[i]));
			add=max(add,hoge[3]-(-V[i+1]-V[i])-abs(V[i+1]-V[i]));
			
			hoge[0]=max(hoge[0],V[i+1]+V[i]-1LL*abs(V[i+1]-V[i]));
			hoge[1]=max(hoge[1],V[i+1]-V[i]-1LL*abs(V[i+1]-V[i]));
			hoge[2]=max(hoge[2],-V[i+1]+V[i]-1LL*abs(V[i+1]-V[i]));
			hoge[3]=max(hoge[3],-V[i+1]-V[i]-1LL*abs(V[i+1]-V[i]));
		}
		
		// ’[
		FOR(i,N-1) add=max(add,1LL*abs(V[N-1]-V[i])-abs(V[i+1]-V[i]));
		FOR(i,N-1) add=max(add,1LL*abs(V[i+1]-V[0])-abs(V[i+1]-V[i]));
		
		cout<<S<<" "<<add<<endl;
		return S+add;
		
        
    }
};
