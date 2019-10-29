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
ll X;
ll B[101010],L[101010],R[101010];
pair<ll,int> P[101010];

int ok(ll v) {
	if(v<0) return 0;
	ll A=0,C=0;
	ll num=v/X;
	ll lef=v%X;
	int i,j;
	FOR(i,N) {
		j=P[i].second;
		if(i<num) {
			A+=X*R[j];
			C+=B[j]*R[j];
		}
		else {
			C+=B[j]*L[j];
		}
	}
	if(lef==0) return A>=C;
	if(A>=C) return 1;
	
	FOR(i,N) {
		if(i<num) {
			int x=P[i].second;
			int y=P[num].second;
			ll A2=A-X*R[x]+X*R[y];
			ll C2=C+B[y]*(R[y]-L[y])-B[x]*(R[x]-L[x]);
			if(B[x]<=lef) {
				if(A2+lef*R[x]>=C2+B[x]*(R[x]-L[x])) return 1;
			}
			else {
				if(A2+lef*L[x]>=C2) return 1;
			}
		}
		else {
			j=P[i].second;
			if(B[j]<=lef) {
				if(A+lef*R[j]>=C+B[j]*(R[j]-L[j])) return 1;
			}
			else {
				if(A+lef*L[j]>=C) return 1;
			}
		}
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>B[i]>>L[i]>>R[i];
		P[i]={-((X-B[i])*R[i]+B[i]*L[i]),i};
	}
	sort(P,P+N);
	
	ll ret=X*N;;
	for(i=40;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
