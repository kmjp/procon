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
ll L;
ll A[101010],B[101010];

ll maA,miB;
ll num[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	maA=0;
	miB=1<<30;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>A[i]>>B[i];
	}
	sort(A,A+N);
	sort(B,B+N);
	
	vector<ll> V;
	ll ret=0;
	if(A[N-1]>=B[0]) {
		ll C=0,D=0;
		FOR(i,N) {
			C+=max(B[0],A[i]);
			D+=min(A[N-1],B[i]);
		}
		
		if(C<=L && L<=D) {
			cout<<A[N-1]-B[0]<<endl;
			return;
		}
		else if(L<C) {
			L=C-L;
			FOR(i,N) V.push_back(max(0LL,B[0]-A[i]));
		}
		else {
			L=L-D;
			FOR(i,N) V.push_back(max(0LL,B[i]-A[N-1]));
		}
		ret += A[N-1]-B[0];
	}
	else {
		ll C=0,D=0;
		FOR(i,N) {
			C+=max(B[0],A[i]);
			D+=min(A[N-1],B[i]);
		}
		
		if(D<=L && L<=C) {
			cout<<(L%N>0)<<endl;
			return;
		}
		else if(L>C) {
			L=L-C;
			FOR(i,N) V.push_back(B[i]-B[0]);
		}
		else {
			L=D-L;
			FOR(i,N) V.push_back(max(0LL,A[N-1]-A[i]));
		}
	}
	
	sort(ALL(V));
	x=0;
	FOR(i,V.size()) num[V.size()-i]+=V[i]-x, x=V[i];
	for(i=N;i>=1;i--) {
		if(i*num[i]>=L) {
			ret += (L+(i-1))/i;
			break;
		}
		else {
			L-=i*num[i];
			ret+=num[i];
		}
	}
	
	
	cout<<ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
