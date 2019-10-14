#include <bits/stdc++.h>
using namespace std;
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

int N;
ll A[202020];
ll ret;

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	void clear(int entry) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]=bit[1][entry-1]=0, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};
BIT_r<ll,19> btx,bty;

void dfs(int L,int R) {
	if(L==R) {
		return;
	}
	else if(L+1==R) {
		ret+=A[L]*A[L];
		return;
	}
	else if(L+2==R) {
		ret+=A[L]*A[L];
		ret+=A[L+1]*A[L+1];
		ret+=A[L]*A[L+1];
		return;
	}
	
	int M=(L+R)/2;
	dfs(L,M);
	dfs(M+1,R);
	
	deque<pair<int,int>> X,Y;
	int a=A[M],b=A[M],i;
	ll sum=0;
	X.push_back({A[M],M});
	Y.push_back({A[M],M});
	for(i=M;i<R;i++) {
		if(A[i]>X.back().first) X.push_back({A[i],i});
		if(A[i]<Y.back().first) Y.push_back({A[i],i});
		btx.add(i,i,X.back().first);
		bty.add(i,i,Y.back().first);
		sum+=X.back().first*Y.back().first;
	}
	X.push_back({10101,R});
	Y.push_back({0,R});
	for(i=M;i>=L;i--) {
		while(A[i]>X.front().first) {
			int cur=X.front().first;
			X.pop_front();
			int nex=X.front().first;
			if(A[i]>=nex) {
				btx.add(M,X.front().second-1,nex-cur);
				sum+=(nex-cur)*bty.total(X.front().second-1);
			}
			else {
				btx.add(M,X.front().second-1,A[i]-cur);
				sum+=(A[i]-cur)*bty.total(X.front().second-1);
				X.push_front({A[i],M});
				break;
			}
		}
		while(A[i]<Y.front().first) {
			int cur=Y.front().first;
			Y.pop_front();
			int nex=Y.front().first;
			if(A[i]<=nex) {
				bty.add(M,Y.front().second-1,nex-cur);
				sum+=(nex-cur)*btx.total(Y.front().second-1);
			}
			else {
				bty.add(M,Y.front().second-1,A[i]-cur);
				sum+=(A[i]-cur)*btx.total(Y.front().second-1);
				Y.push_front({A[i],M});
				break;
			}
		}
		ret+=sum;
	}
	
	for(i=M;i<=R;i++) btx.clear(i), bty.clear(i);
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	dfs(0,N);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
