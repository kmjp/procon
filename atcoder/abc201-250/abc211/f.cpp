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
int M;
vector<pair<int,int>> V;
vector<pair<int,int>> ev[201010];
int Q;
int X[202020],Y[202020],ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) {
		cin>>M;
		V.resize(M);
		
		int tar=0;
		FOR(j,M) {
			cin>>V[j].first>>V[j].second;
			V[j].first*=2;
			V[j].second*=2;
			if(V[j].first<V[tar].first) tar=j;
			else if(V[j].first==V[tar].first&&V[j].second>V[tar].second) tar=j;
		}
		
		rotate(V.begin(),V.begin()+tar,V.end());
		if(V[0].first==V[1].first) reverse(V.begin()+1,V.end());
		for(i=0;i+1<V.size();i+=2) {
			ev[V[i].first].push_back({V[i].second,-1});
			ev[V[i+1].first].push_back({V[i+1].second,1});
		}
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>X[i]>>Y[i];
		X[i]=X[i]*2+1;
		Y[i]=Y[i]*2+1;
		ev[X[i]].push_back({i,Y[i]});
	}
	
	FOR(i,201010) {
		if(i%2==0) {
			FORR2(y,v,ev[i]) bt.add(y,v);
		}
		else {
			FORR2(i,y,ev[i]) ret[i]=bt(y);
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
