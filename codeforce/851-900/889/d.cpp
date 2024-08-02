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

int ask(int u,int k,set<int> V) {
	cout<<"? "<<(u+1)<<" "<<k<<" "<<V.size();
	FORR(v,V) cout<<" "<<v+1;
	cout<<endl;
	cin>>u;
	return u;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	set<int> ok;
	cin>>N;
	FOR(i,63) {
		int L=0,R=N;
		while(L+1<R) {
			int M=(L+R)/2;
			set<int> A;
			for(j=L;j<M;j++) A.insert(j);
			if(ask(0,N+i,A)) R=M;
			else L=M;
		}
		ok.insert(L);
	}
	if(ok.size()==63) {
		for(k=63;k<=N*2;k*=2) {
			if(ok.size()<k){
				FOR(i,N) if(ok.count(i)==0) {
					if(ask(i,N,ok)) ok.insert(i);
				}
				break;
			}
			FOR(i,N) if(ok.count(i)==0) {
				if(ask(i,k,ok)) ok.insert(i);
			}
		}
	}
	else {
		FOR(i,N) if(ok.count(i)==0) {
			if(ask(i,101010,ok)) ok.insert(i);
		}
	}
	cout<<"! "<<ok.size();
	FORR(v,ok) cout<<" "<<v+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
