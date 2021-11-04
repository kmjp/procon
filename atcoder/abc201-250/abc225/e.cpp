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
ll X[402020],Y[402020];
int P[404040];
set<int> vis;

int comp(int a,int b) {
	if(X[a]*Y[b]==X[b]*Y[a]) {
		return a<=b;
	}
	return X[a]*Y[b]>X[b]*Y[a];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		X[i+N]=x;
		Y[i+N]=y-1;
		X[i]=x-1;
		Y[i]=y;
		P[i]=i;
		P[i+N]=i+N;
	}
	sort(P,P+2*N,comp);
	int ret=0;
	FOR(i,2*N) {
		x=P[i];
		if(x<N) {
			if(vis.count(x)) {
				ret+=vis.count(x);
				vis.clear();
			}
		}
		else {
			vis.insert(x-N);
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
