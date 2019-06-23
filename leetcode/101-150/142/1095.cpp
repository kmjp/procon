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

int A[101010];


class Solution {
public:
	int get(int v,MountainArray &M) {
		if(A[v]==-1) A[v]=M.get(v);
		return A[v];
	}
    int findInMountainArray(int target, MountainArray &M) {
        MINUS(A);
        int N=M.length();
        int L=0,R=N-1;
        while(R-L>=6) {
			int m1=(2*L+R)/3;
			int m2=(L+2*R)/3;
			int V[4]={
				get(L,M),
				get(m1,M),
				get(m2,M),
				get(R,M),
			};
			
			if(V[0]==V[1]) R=m1;
			else if(V[0]==V[2]) R=m2;
			else if(V[1]==V[2]) L=m1,R=m2;
			else if(V[1]==V[3]) L=m1;
			else if(V[2]==V[3]) L=m2;
			else {
				int x=max_element(V,V+4)-V;
				if(x==0) R=m1;
				if(x==1) R=m2;
				if(x==2) L=m1;
				if(x==3) L=m2;
			}
		}
		int i;
		int id=L;
		for(i=L;i<=R;i++) {
			get(i,M);
			if(A[i]>A[id]) id=i;
		}
		
		if(A[0]<=target&&target<=A[id]) {
			int i;
			int cur=-1;
			for(i=20;i>=0;i--) if(cur+(1<<i)<=id && get(cur+(1<<i),M)<=target) cur+=1<<i;
			
			if(cur>=0 && get(cur,M)==target) return cur;
		}
		
		if(target<=A[id]&&target>=get(N-1,M)) {
			int i;
			int cur=id;
			for(i=20;i>=0;i--) if(cur+(1<<i)<N && get(cur+(1<<i),M)>=target) cur+=1<<i;
			
			if(get(cur,M)==target) return cur;
		}
		return -1;
        
    }
};

