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
int id[102][102];
vector<pair<int,int>> S;
string G[101];



void grid() {
	int y,x;
	FOR(y,N) G[y].resize(N);
	int i;
	FOR(i,S.size()-1) {
		if(S[i+1].first>S[i].first) G[S[i].first-1][S[i].second-1]='v';
		if(S[i+1].first<S[i].first) G[S[i].first-1][S[i].second-1]='^';
		if(S[i+1].second<S[i].second) G[S[i].first-1][S[i].second-1]='<';
		if(S[i+1].second>S[i].second) G[S[i].first-1][S[i].second-1]='>';
	}
}



pair<pair<int,int>,char> ask(int id) {
	cout<<"? "<<S[id].first<<" "<<S[id].second<<endl;
	int y,x;
	FOR(y,N) {
		FOR(x,N) cout<<G[y][x];
		cout<<endl;
	}
	cin>>y>>x;
	if(y==-1) return {{-1,-1},'L'};
	if(y==0) return {{1,x},'^'};
	if(y==N+1) return {{N,x},'v'};
	if(x==0) return {{y,1},'<'};
	if(x==N+1) return {{y,N},'>'};
	return {{0,0},0};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	i=0;
	FOR(y,N) {
		FOR(x,N) {
			k=x;
			if(y%2) k=N-1-k;
			id[y][k]=i++;
			S.push_back({y+1,k+1});
		}
	}
	S.push_back({N+1,S.back().second});
	grid();
	auto p=ask(0);
	if(p.second!='L') {
		S.pop_back();
		reverse(ALL(S));
		S.push_back({0,S.back().second});
		grid();
		p=ask(0);
	}
	
	if(p.second=='L') {
		int L=0,R=S.size()-1;
		while(L+1<R) {
			int M=(L+R)/2;
			p=ask(M);
			if(p.second=='L') L=M;
			else R=M;
		}
		
		int ty=S[L].first-1,tx=S[L].second-1;
		FOR(y,N) FOR(x,N) {
			if(y<ty) G[y][x]='^';
			else if(y>ty) G[y][x]='v';
			else if(x<tx) G[y][x]='<';
			else if(x>tx) G[y][x]='>';
		}
		p=ask(L);
		p.first.first=ty+1;
		p.first.second=tx+1;
	}
	cout<<"! "<<p.first.first<<" "<<p.first.second<<" "<<p.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
