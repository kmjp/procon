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
string S[1010];
vector<int> E[1010];
int in[1010];

int P[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>S[y];
		FOR(x,y) {
			if(S[y][x]=='o') {
				E[y].push_back(x);
				in[x]++;
			}
			if(S[y][x]=='x') {
				E[x].push_back(y);
				in[y]++;
			}
		}
	}
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	MINUS(P);
	FOR(i,N) {
		if(Q.empty()) {
			cout<<"No"<<endl;
			return;
		}
		x=Q.front();
		Q.pop();
		P[x]=i;
		FOR(y,N) if(y!=x) {
			if(P[y]==-1) {
				S[y][x]='x';
				S[x][y]='o';
			}
			else {
				S[y][x]='o';
				S[x][y]='x';
			}
		}
		FORR(e,E[x]) {
			if(--in[e]==0) Q.push(e);
		}
	}
	
	cout<<"Yes"<<endl;
	FOR(y,N) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
