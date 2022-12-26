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

int RX=-101,RY,RZ;

// 質問クエリ
ll ask(int x, int y, int z) {
	ll d;
	
	cout << "?" << " " << x << " " << y << " " << z << endl;
	if(RX!=-101) {
		return abs(x-RX)+abs(y-RY)+abs(z-RZ);
	}
	cin >> d;
	return d;
}

// 回答クエリ
void answer(int x, int y, int z) {
	cout << "!" << " " << x << " " << y << " " << z << endl;
	exit(0);
	
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	//cin>>RX>>RY>>RZ;
	
	int X=0,Y=0,Z=0;
	int L,R;
	L=-100;
	R=100;
	ll mi;
	while(L+2<R) {
		int M1=(2*L+R)/3;
		int M2=(L+R*2)/3;
		int V1=ask(M1,Y,Z);
		int V2=ask(M2,Y,Z);
		if(V1<V2) R=M2;
		if(V1>V2) L=M1;
		if(V1==V2) L=M1,R=M2;
	}
	
	mi=ask(L,Y,Z);
	X=L;
	for(i=L+1;i<=R;i++) {
		ll r=ask(i,Y,Z);
		if(r<mi) mi=r, X=i;
	}
	
	L=-100;
	R=100;
	while(L+2<R) {
		int M1=(2*L+R)/3;
		int M2=(L+R*2)/3;
		int V1=ask(X,M1,Z);
		int V2=ask(X,M2,Z);
		if(V1<V2) R=M2;
		if(V1>V2) L=M1;
		if(V1==V2) L=M1,R=M2;
	}
	
	mi=ask(X,L,Z);
	Y=L;
	for(i=L+1;i<=R;i++) {
		ll r=ask(X,i,Z);
		if(r<mi) mi=r, Y=i;
	}
	
	L=-100;
	R=100;
	while(L+2<R) {
		int M1=(2*L+R)/3;
		int M2=(L+R*2)/3;
		int V1=ask(X,Y,M1);
		int V2=ask(X,Y,M2);
		if(V1<V2) R=M2;
		if(V1>V2) L=M1;
		if(V1==V2) L=M1,R=M2;
	}
	
	mi=ask(X,Y,L);
	Z=L;
	for(i=L+1;i<=R;i++) {
		ll r=ask(X,Y,i);
		if(r<mi) mi=r, Z=i;
	}
	answer(X,Y,Z);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
