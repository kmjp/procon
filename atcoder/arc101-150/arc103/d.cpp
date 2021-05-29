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
ll X[1001],Y[1001],P[1001];
ll M;
ll V[40];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P[i]=(abs(X[i])+abs(Y[i]))%2;
		if(P[i]!=P[0]) return _P("-1\n");
	}
	
	M=32;
	FOR(i,32) {
		V[i]=1LL<<(31-i);
	}
	if(P[0]==0) V[M++]=1;
	
	cout<<M<<endl;
	FOR(i,M) {
		cout<<V[i]<<" ";
	}
	cout<<endl;
	
	FOR(i,N) {
		string S;
		FOR(j,M) {
			if(abs(X[i])>=abs(Y[i])) {
				if(X[i]>=0) {
					S+='R';
					X[i]-=V[j];
				}
				else {
					S+='L';
					X[i]+=V[j];
				}
			}
			else {
				if(Y[i]>=0) {
					S+='U';
					Y[i]-=V[j];
				}
				else {
					S+='D';
					Y[i]+=V[j];
				}
			}
		}
		cout<<S<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
