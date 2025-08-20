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
vector<int> E[101010];
int U[101010],V[101010];
int D[101010];

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
	}
	dfs(1,1,0);
	
	cout<<"?";
	FOR(i,N-1) {
		if(D[U[i]]) cout<<" "<<V[i];
		else cout<<" "<<U[i];
	}
	cout<<endl;
	
	cin>>s;
	vector<int> cand;
	if(s=="Yes") {
		FOR(i,N-1) {
			if(D[U[i]]==0) cand.push_back(U[i]);
			else cand.push_back(V[i]);
		}
	}
	else {
		FOR(i,N-1) {
			if(D[V[i]]==0) cand.push_back(U[i]);
			else cand.push_back(V[i]);
		}
	}
	FOR(i,14) {
		set<int> X[2];
		FOR(j,cand.size()) X[j%2].insert(cand[j]);
		cout<<"?";
		FOR(j,N-1) {
			if(X[0].count(U[j])) {
				cout<<" "<<U[j];
			}
			else if(X[0].count(V[j])) {
				cout<<" "<<V[j];
			}
			else if(X[1].count(U[j])) {
				cout<<" "<<V[j];
			}
			else if(X[1].count(V[j])) {
				cout<<" "<<U[j];
			}
			else {
				cout<<" "<<U[j];
			}
		}
		cout<<endl;
		cin>>s;
		cand.clear();
		FORR(x,X[s=="No"]) cand.push_back(x);
	}
	cout<<"! "<<cand[0]<<endl;
	
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
