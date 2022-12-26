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
int C[202];
int D[202];
int A[202];
string S="";
int numask;

int ask(vector<int> V) {
	numask++;
	string S;
	assert(V.size()==N);
	cout<<"?";
	FORR(c,V) cout<<" "<<(c+1);
	cout<<endl;
	
	
	if(A[0]>=0) {
		int num=0;
		FORR(c,V) num+=A[c];
		//cout<<num<<endl;
		return num>N/2;
	}
	
	cin>>S;
	return S=="Red";
}


void ans() {
	
	cout<<"! ";
	int i;
	FOR(i,2*N) {
		if(C[i]) cout<<"R";
		else cout<<"B";
	}
	cout<<endl;
	
	if(A[0]>=0) {
		int ok=0;
		FOR(i,2*N) ok+=A[i]==C[i];
		cout<<ok<<endl;
	}
	exit(0);
	return;
}




void solve() {
	int i,j,k,l,r,x,y; string s;
	
	if(S.size()) {
		N=S.size()/2;
	}
	else {
		cin>>N;
	}
	
	vector<int> V;
	MINUS(A);
	FOR(i,S.size()) A[i]=S[i]=='R';
	
	FOR(i,2*N) C[i]=2;
	/*
	FOR(i,2*N) V.push_back(i);
	random_shuffle(ALL(V));
	ZERO(A);
	FOR(i,N) A[V[i]]=1;
	FOR(i,2*N) cout<<A[i];
	cout<<endl;
	*/
	
	vector<int> B;
	FOR(i,N) B.push_back(i);
	int L=0;
	int R=N;
	int RS=ask(B);
	int LS=RS^1;
	while(L+1<R) {
		int M=(L+R)/2;
		B.clear();
		FOR(x,M) B.push_back(x);
		FOR(x,N-M) B.push_back(2*N-1-x);
		sort(ALL(B));
		y=ask(B);
		if(y==RS) R=M;
		else L=M;
	}
	
	
	int pov=L,a,b;
	C[pov]=RS;
	C[N+pov]=RS^1;
	
	if(A[0]>=0) {
		cout<<L<<" "<<R<<endl;
		FOR(i,2*N) cout<<A[i];
		cout<<endl;
		FOR(i,2*N) cout<<C[i];
		cout<<endl;
	}
	
	for(i=pov+1;i<N+pov;i++) {
		B.clear();
		for(x=0;x<pov;x++) B.push_back(x);
		for(x=N+pov+1;x<2*N;x++) B.push_back(x);
		B.push_back(i);
		sort(ALL(B));
		y=ask(B);
		if(y==RS) C[i]=C[pov];
		else C[i]=C[N+pov];
		
		
	}
	if(A[0]>=0) {
		FOR(i,2*N) cout<<A[i];
		cout<<endl;
		FOR(i,2*N) cout<<C[i];
		cout<<endl;
	}
	vector<int> NC;
	a=0,b=0;
	for(i=pov;i<=N+pov;i++) {
		if(C[i]==1) {
			if(a<N/2) {
				a++;
				NC.push_back(i);
			}
		}
		else {
			if(b<N/2) {
				b++;
				NC.push_back(i);
			}
		}
	}
	assert(NC.size()==N-1);
	FOR(i,2*N) {
		if(i>=pov && i<=N+pov) continue;
		B=NC;
		B.push_back(i);
		sort(ALL(B));
		C[i]=ask(B);
	}
	
	if(A[0]>=0) {
		FOR(i,2*N) cout<<A[i];
		cout<<endl;
		FOR(i,2*N) cout<<C[i];
		cout<<endl;
	}
	ans();
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
