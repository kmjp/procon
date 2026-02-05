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

int len[3030303][10];
int from[3030303][10];
vector<pair<int,int>> cand[303030];
int to[3030303][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(x,N) FOR(y,10) len[x][y]=1<<20;
	queue<int> Q;
	for(x=1;x<=9;x++) if(len[x%N][x]==1<<20) {
		len[x%N][x]=1;
		cand[1].push_back({x%N,x});
		Q.push(x%N*10+x);
	}
	
	while(Q.size()) {
		int cur=Q.front()/10;
		int la=Q.front()%10;
		Q.pop();
		if(cur==0) break;
		for(x=la;x<=9;x++) {
			int nex=(cur*10+x)%N;
			if(len[nex][x]==1<<20) {
				len[nex][x]=len[cur][la]+1;
				from[nex][x]=cur*10+la;
				cand[len[nex][x]].push_back({nex,x});
				Q.push(nex*10+x);
			}
		}
	}
	int mi=1<<20;
	FOR(i,10) mi=min(mi,len[0][i]);
	if(mi==1<<20) {
		cout<<-1<<endl;
		return;
	}
	MINUS(to);
	FOR(i,10) if(len[0][i]==mi) to[0][i]=1;
	for(x=mi-1;x>=1;x--) FORR2(cur,la,cand[x]) {
		for(y=la;y<=9;y++) if(to[(cur*10+y)%N][y]>=0) {
			to[cur][la]=y;
			break;
		}
	}
	for(i=1;i<=9;i++) if(to[i%N][i]>=0) {
		cout<<i;
		int cur=i%N;
		x=i;
		while(cur!=0) {
			y=to[cur][x];
			cout<<y;
			cur=(cur*10+y)%N;
			x=y;
		}
		return;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
