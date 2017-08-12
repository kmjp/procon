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
int A[1010];

double FF(int j) {
	double p=0,q=0;
	double a=1,b=1;
	for(int i=1;i<=j;i++) {
		a *= 0.81;
		b *= 0.9;
		p += a;
		q += b;
	}
	return sqrt(p)/q;
}

double Gr(double X) {
	double A=log(X)/log(2);
	return A*800;
}
double G(double X) {
	return pow(2,X/800.0);
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	double p=0,q=0;
	double pp=1;
	FOR(i,N) {
		cin>>A[i];
		pp *= 0.9;
		p += G(A[i])*pp;
		q += pp;
	}
	
	double F=(FF(N)-FF(100000))*1200/(FF(1)-FF(100000));
	double R=Gr(p/q)-F;
	cout<<(int)(R+0.5)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
