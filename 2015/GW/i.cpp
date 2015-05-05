#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int T[501][501];
int H[501][501];
ll X,A,B,C;


int Rand() {
  return X = (A * X + B) % C;
}
void Shuffle() {
  for (int i = 0; i < N*N; ++i) {
    int ai = Rand() % N;
    int aj = Rand() % N;
    int bi = Rand() % N;
    int bj = Rand() % N;
    if (ai == bi && aj == bj) continue;
    swap(T[ai][aj], T[bi][bj]);
  }
}

ll dodo() {
	int i,j,k,l,r,x,y; string s;
	priority_queue<pair<int,int> > Q;
	FOR(y,N) FOR(x,N) {
		H[y][x]=min(H[y][x],x+1);
		H[y][x]=min(H[y][x],y+1);
		H[y][x]=min(H[y][x],N-y);
		H[y][x]=min(H[y][x],N-x);
		Q.push(make_pair(-H[y][x],y*500+x));
	}
	ll sum=0;
	while(Q.size()) {
		auto r=Q.top();
		Q.pop();
		int ch=-r.first;
		int cy=r.second/500,cx=r.second%500;
		if(H[cy][cx]!=ch) continue;
		sum+=ch;
		for(int dy=-1;dy<=1;dy++) for(int dx=-1;dx<=1;dx++) {
			int ty=cy+dy,tx=cx+dx;
			if(tx<0 || tx>=N || ty<0 || ty>=N) continue;
			if(H[ty][tx]>ch+1) {
				H[ty][tx]=ch+1;
				Q.push(make_pair(-H[ty][tx],ty*500+tx));
			}
		}
	}
	return sum;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	cin>>X>>A>>B>>C;
	FOR(y,N) FOR(x,N) cin>>T[y][x];
	while(Q--) {
		FOR(y,N) FOR(x,N) H[y][x]=T[y][x];
		cout<<dodo()<<endl;
		Shuffle();
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
