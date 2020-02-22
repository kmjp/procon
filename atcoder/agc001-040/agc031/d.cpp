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

int N,K;
vector<int> P,Q,PR,QR;

vector<int> rev(vector<int> A) {
	vector<int> R(N);
	int i;
	FOR(i,N) R[A[i]]=i;
	return R;
}
vector<int> conv(vector<int> A,vector<int> B) { 
	vector<int> R(N);
	int i;
	FOR(i,N) R[i]=A[B[i]];
	return R;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	P.resize(N);
	Q.resize(N);
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i];
	FOR(i,N) P[i]--,Q[i]--;
	
	PR=rev(P);
	QR=rev(Q);
	K--;
	auto A=conv(conv(conv(Q,PR),QR),P);
	vector<int> E,B;
	FOR(i,N) E.push_back(i);
	B=E;
	FOR(i,30) {
		if((K/6)&(1<<i)) E=conv(E,A);
		A=conv(A,A);
	}
	
	K%=6;
	A=E;
	if(K>=3) {
		A=conv(A,Q);
		if(K>=4) A=conv(A,PR);
	}
	
	auto AR=rev(A);
	
	if(K==0) B=P;
	if(K==1) B=Q;
	if(K==2) B=conv(Q,PR);
	if(K==3) B=PR;
	if(K==4) B=QR;
	if(K==5) B=conv(QR,P);
	
	auto C=conv(conv(A,B),AR);
	FORR(c,C) cout<<c+1<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
