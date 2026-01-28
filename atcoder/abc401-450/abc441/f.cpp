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

int N,M;
int P[1010],V[1010];

ll pre[1010][50505];
ll suf[1010][50505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>P[i]>>V[i];
		for(j=M;j>=0;j--) {
			pre[i+1][j]=max(pre[i+1][j],pre[i][j]);
			if(j+P[i]<=M) pre[i+1][j+P[i]]=max(pre[i+1][j+P[i]],pre[i][j]+V[i]);
		}
	}
	for(i=N-1;i>=0;i--) {
		for(j=M;j>=0;j--) {
			suf[i+1][j]=max(suf[i+1][j],suf[i+2][j]);
			if(j+P[i]<=M) suf[i+1][j+P[i]]=max(suf[i+1][j+P[i]],suf[i+2][j]+V[i]);
		}
	}
	ll ma=0;
	FOR(j,M+1) ma=max(ma,pre[N][j]);
	
	FOR(i,N) {
		//選ばず最大にできるか？
		ll ma1=0;
		FOR(j,M+1) ma1=max(ma1,pre[i][j]+suf[i+2][M-j]);
		//選んで最大にできるか？
		ll ma2=V[i];
		FOR(j,M-P[i]+1) ma2=max(ma2,pre[i][j]+suf[i+2][M-P[i]-j]+V[i]);
		if(ma==ma1&&ma==ma2) {
			cout<<"B";
		}
		else if(ma!=ma1) {
			cout<<"A";
		}
		else {
			cout<<"C";
		}
		
	}
	cout<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
