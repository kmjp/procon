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
int C[2][2];
const ll mo=1000000007;

int ok(int v,int N) {
	if(N==2) return 1;
	for(int i=1;i<=N-2;i++) {
		int x=(v>>(i+1))&1;
		int y=(v>>(i-1))&1;
		int r=(v>>i)&1;
		
		if(C[x][y]==r) {
			int n=(v&((1<<i)-1)) | ((v>>(i+1))<<i);
			if(ok(n,N-1)) return 1;
		}
	}
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,2) FOR(x,2) {
		cin>>s;
		C[y][x]=s[0]-'A';
	}
	if(N<=3) return _P("1\n");
	
	
	int mask;
	int num=0;
	FOR(mask,1<<(7)) {
		int v=(mask<<1)|1;
		if(ok(v,9)) {
			num++;
		}
	}
	
	if(num==1) {
		cout<<1<<endl;
	}
	else if(num==21) {
		ll F[1010]={};
		F[1]=F[2]=1;
		for(i=3;i<=1005;i++) F[i]=(F[i-1]+F[i-2])%mo;
		cout<<F[N-1]<<endl;
	}
	else if(num==64) {
		ll ret=1;
		FOR(i,N-3) ret=ret*2%mo;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
