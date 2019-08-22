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

int N,A,B;

long double getrandom() {
	int a=rand()%10000;
	int b=rand()%10000;
	return (a*10000+b)/10000000000.0;
}

vector<long double> hoge(int n,int p) {
	vector<long double> T;
	T.push_back(getrandom());
	while(T.size()<n) T.push_back(T.back()+getrandom());
	if(n<2) return T;
	long double L=0,R=17.3/(n-1);
	int i,x,y;
	FOR(i,100) {
		long double M=(L+R)/2.0;
		int num=0;
		FOR(y,n) FOR(x,y) if((T[y]+y*M)-(T[x]+x*M)<=10) num++;
		if(num>=p) L=M;
		else R=M;
	}
	
	FOR(i,n) T[i]+=L*i;
	return T;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>N>>A>>B;
	int U,V;
	for(U=1;U<=N;U++) {
		V=N-U;
		if(U>=V && U*(U-1)/2+V*(V-1)/2>=A) break;
	}
	x=A*1.0*U*(U-1)/(U*(U-1)+V*(V-1))+0.5;
	y=A-x;
	B-=U*(U-1)/2+V*(V-1)/2;
	vector<long double> S=hoge(U,x);
	vector<long double> T=hoge(V,y);
	vector<pair<long double,long double>> R;
	vector<double> C;
	FORR(s,S) FORR(t,T) {
		C.push_back(sqrt((long double)400-(t-s)*(t-s))-0.000000001);
	}
	sort(ALL(C));
	reverse(ALL(C));
	FORR(s,S) R.push_back({s,C[B-1]});
	FORR(t,T) R.push_back({t,0});
	
	/*
	int num[2]={};
	FORR(x,R) FORR(y,R) if(x<y) {
		long double a=x.first-y.first;
		long double b=x.second-y.second;
		if(a*a+b*b<=100.0000000000) num[0]++;
		if(a*a+b*b<=400.0000000000) num[1]++;
	}
	_P("%d %d %d\n",N,num[0],num[1]);
	assert(num[0]==A);
	assert(num[1]==B+U*(U-1)/2+V*(V-1)/2);
	*/
	FORR(r,R) _P("%.12lf %.12lf\n",(double)r.first,(double)r.second);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
