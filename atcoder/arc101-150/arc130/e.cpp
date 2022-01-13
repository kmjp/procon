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

int N,K;
int I[303030];
int las[303030];
int C[303030];
int num[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int uni=0;
	int pre=0;
	ok[0]=1;
	for(i=1;i<=K;i++) {
		cin>>I[i];
		x=--I[i];
		if(las[x]==0) uni++;
		pre=max(pre,las[x]);
		las[x]=i;
		if(i-pre==uni) num[i]=num[pre]+1;
		else num[i]=1<<30;
	}
	
	int minnum=1<<20;
	int tar=-1;
	for(i=pre;i<=K;i++) if(num[i]<=minnum) minnum=num[i], tar=i;
	
	if(tar==-1) {
		cout<<-1<<endl;
	}
	else {
		int mi=0;
		for(i=1;i<=tar;i++) {
			C[I[i]]--;
			mi=min(mi,C[I[i]]);
		}
		FOR(i,N) cout<<(C[i]-(mi-1))<<" ";
		cout<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
