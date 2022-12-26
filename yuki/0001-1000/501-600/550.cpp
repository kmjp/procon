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

ll A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	ll X,Y,Z;
	for(X=-1000000;X<=1000000;X++) {
		if((__int128_t)X*X*X+(__int128_t)A*X*X+(__int128_t)B*X+C==0) {
			break;
		}
	}
	if(X==0) {
		C=B;
		B=A;
	}
	else {
		B=A+X;
		C=-C/X;
	}
	
	long double D=max((long double)0.0,(long double)B*B-4*C);
	for(Y=(-B+sqrt(D))/2-2;Y<=(-B+sqrt(D))/2+2;Y++) {
		
		Z=-B-Y;
		if(abs(Y)>=1000000000) continue;
		if(abs(Z)>=1000000000) continue;
		if(Y*Z!=C) continue;
		if(Y+Z!=-B) continue;
		break;
	}
	
	
	if(X>Y) swap(X,Y);
	if(Y>Z) swap(Y,Z);
	if(X>Y) swap(X,Y);
	cout<<X<<" "<<Y<<" "<<Z<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
