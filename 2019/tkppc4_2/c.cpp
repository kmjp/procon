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

int Amemo[22][22][2];
int Bmemo[22][22][2];

int Bwin(int A,int B,int cur);
int Awin(int A,int B,int cur) {
	if(A==0 && B==0) return cur;
	
	if(Amemo[A][B][cur]<0) {
		Amemo[A][B][cur]=0;
		if(A && Bwin(A-1,B,cur)==0) Amemo[A][B][cur]=1;
		if(B && Bwin(A,B-1,cur^1)==0) Amemo[A][B][cur]=1;
	}
	return Amemo[A][B][cur];
}
int Bwin(int A,int B,int cur) {
	if(A==0 && B==0) return cur==0;
	
	if(Bmemo[A][B][cur]<0) {
		Bmemo[A][B][cur]=0;
		if(A && Awin(A-1,B,cur)==0) Bmemo[A][B][cur]=1;
		if(B && Awin(A,B-1,cur)==0) Bmemo[A][B][cur]=1;
	}
	return Bmemo[A][B][cur];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	ll A,B;
	
	/*
	MINUS(Amemo);
	MINUS(Bmemo);
	FOR(x,21) {
		FOR(y,21) cout<<Awin(x,y,0);
		cout<<endl;
	}
	*/
	cin>>A>>B;
	if(B%4==0 || (B%4==3 && A%2==0)) {
		cout<<"Devil"<<endl;
	}
	else {
		cout<<"Angel"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
