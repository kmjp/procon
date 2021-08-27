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
vector<int> E[52*52*52],RE[52*52*52];
int F[202020],T[202020];
int in[52*52*52];
int win[52*52*52];

int id(string S) {
	int a=S[0];
	int b=S[1];
	int c=S[2];
	if(a>='a'&&a<='z') a-='a';
	else a=a-'A'+26;
	
	if(b>='a'&&b<='z') b-='a';
	else b=b-'A'+26;
	
	if(c>='a'&&c<='z') c-='a';
	else c=c-'A'+26;
	
	return a*52*52+b*52+c;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		string S;
		cin>>S;
		F[i]=id(S.substr(0,3));
		T[i]=id(S.substr(S.size()-3,3));
		E[F[i]].push_back(T[i]);
		RE[T[i]].push_back(F[i]);
		in[F[i]]++;
	}
	
	MINUS(win);
	queue<int> Q;
	FOR(i,52*52*52) if(E[i].empty()) Q.push(i);
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		win[cur]=0;
		FORR(e,E[cur]) if(win[e]==0) win[cur]=1;
		FORR(e,RE[cur]) {
			in[e]--;
			if(win[cur]==0) {
				if(win[e]==-1) {
					win[e]=1;
					Q.push(e);
				}
			}
			else {
				if(in[e]==0&&win[e]==-1) Q.push(e);
			}
		}
	}
	FOR(i,N) {
		if(win[T[i]]==1) cout<<"Aoki"<<endl;
		if(win[T[i]]==0) cout<<"Takahashi"<<endl;
		if(win[T[i]]==-1) cout<<"Draw"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
