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
int ask(int t,vector<int> V) {
	cout<<"? "<<t+1<<" ";
	int i;
	FOR(i,N) cout<<count(ALL(V),i);
	cout<<endl;
	cin>>t;
	return t;
}
void ans(vector<int> V) {
	cout<<"! ";
	FORR(v,V) cout<<v;
	cout<<endl;
	exit(0);
}

vector<int> vis;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vis.resize(N);
	vector<int> C;
	C={0};
	for(i=1;i<N;i++) {
		k=ask(i,C);
		C.insert(C.begin()+((int)C.size()-k),i);
	}
	vis[C[0]]=1;
	for(i=1;i<N;i++) {
		vector<int> cand;
		FOR(x,i) if(vis[C[x]]) cand.push_back(C[x]);
		k=ask(C[i],cand);
		if(k) {
			FOR(x,i+1) vis[C[x]]=1;
		}
	}
	ans(vis);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
