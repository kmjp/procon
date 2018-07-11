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
int A[202020];
ll S[202020];
int L[202020],R[202020];

ll hoge(int a,int b,int c,int d) {
	if(b<=a || c<=b || d<=c) return 1LL<<60;
	vector<ll> V={S[a],S[b]-S[a],S[c]-S[b],S[d]-S[c]};
	sort(ALL(V));
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<"   "<<V[0]<<" "<<V[1]<<" "<<V[2]<<" "<<V[3]<<endl;
	return V[3]-V[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], S[i+1]=S[i]+A[i];
	
	L[2]=1;
	for(i=3;i<=N;i++) {
		L[i]=L[i-1];
		while(L[i]+1<i && S[L[i]+1]<=S[i]-S[L[i]+1]) L[i]++;
	}
	
	R[N-2]=N-1;
	for(i=N-3;i>=1;i--) {
		R[i]=R[i+1];
		while(R[i]-1>i && S[R[i]-1]-S[i]>=S[N]-S[R[i]-1]) R[i]--;
	}
	
	ll ret=1LL<<60;
	for(i=2;i<=N-2;i++) {
		ret=min(ret,hoge(L[i],i,R[i],N));
		ret=min(ret,hoge(L[i]+1,i,R[i],N));
		ret=min(ret,hoge(L[i],i,R[i]-1,N));
		ret=min(ret,hoge(L[i]+1,i,R[i]-1,N));
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
