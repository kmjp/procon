#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
int C[3*3*3*3*3*3][3*3*3*3*3*3];
int p3[10];

void hoge(int x1,int y1,int d) {
	if(d==1) {
		C[x1][y1]=1;
	}
	else {
		d/=3;
		hoge(x1+0*d,y1+0*d,d);
		hoge(x1+0*d,y1+1*d,d);
		hoge(x1+0*d,y1+2*d,d);
		hoge(x1+1*d,y1+0*d,d);
		hoge(x1+1*d,y1+2*d,d);
		hoge(x1+2*d,y1+0*d,d);
		hoge(x1+2*d,y1+1*d,d);
		hoge(x1+2*d,y1+2*d,d);
		
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	p3[0]=1;
	FOR(i,7) p3[i+1]=p3[i]*3;
	
	cin>>N;
	hoge(0,0,p3[N]);
	FOR(y,p3[N]) {
		FOR(x,p3[N]) cout<<((C[y][x])?'#':'.');
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
