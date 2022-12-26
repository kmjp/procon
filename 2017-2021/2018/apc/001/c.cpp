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
int P[101010];
int ask(int X) {
	string S;
	cout<<X<<endl;
	/*
	if(P[X]>=0) {
		if(P[X]==2) exit(0);
		return P[X];
	}
	*/
	cin>>S;
	if(S=="Vacant") exit(0);
	if(S=="Male") return P[X]=0;
	return P[X]=1;
}

void hoge(int L,int R) {
	if(L+1==R) ask(L);
	
	int M=(L+R)/2;
	ask(M);
	
	if((P[M]==P[L])==(L%2==M%2)) {
		hoge(M,R);
	}
	else {
		hoge(L,M);
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(P);
	cin>>N;
	/*
	cin>>N>>x>>y;
	P[x]=2;
	FOR(i,N-1) {
		P[(x+1+i)%N]=y;
		y^=1;
	}
	*/
	ask(0);
	hoge(0,N);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
