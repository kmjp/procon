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
int ask(int a,int b) {
	cout<<1<<" "<<a+1<<" "<<b+1<<endl;
	cin>>a;
	if(a>0) a--;
	return a;
}

int nex[5050];
int P[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) nex[i]=ask(i,i);
	
	int d=-1,f=1;
	FOR(i,N) {
		int cur=i;
		int step=0;
		while(cur!=-1) {
			step++;
			cur=nex[cur];
		}
		if(step>d) {
			d=step;
			f=i;
		}
	}
	P[f]=1;
	int pre=f;
	for(i=2;i<=N;i++) {
		x=ask(f,pre);
		P[x]=i;
		pre=x;
	}
	cout<<2;
	FOR(i,N) cout<<" "<<P[i];
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
