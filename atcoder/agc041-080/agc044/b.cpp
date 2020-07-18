#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
int P[505*505];

int D[505][505];
int did[505][505];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N*N) {
		cin>>P[i];
		P[i]--;
	}
	FOR(y,N) FOR(x,N) {
		did[y][x]=1;
		D[y][x]=min({x+1,y+1,N-y,N-x});
	}
	
	int ret=0;
	FOR(i,N*N) {
		y=P[i]/N;
		x=P[i]%N;
		D[y][x]=101000;
		if(y) D[y][x]=min(D[y][x],D[y-1][x]);
		if(x) D[y][x]=min(D[y][x],D[y][x-1]);
		if(y+1<N) D[y][x]=min(D[y][x],D[y+1][x]);
		if(x+1<N) D[y][x]=min(D[y][x],D[y][x+1]);
		if(x==0 || y==0 || x+1==N || y+1==N) D[y][x]=0;
		ret+=D[y][x];
		did[y][x]=0;
		queue<int> Q;
		if(y) Q.push((y-1)*500+x);
		if(x) Q.push((y-0)*500+x-1);
		if(y+1<N) Q.push((y+1)*500+x);
		if(x+1<N) Q.push((y-0)*500+x+1);
		while(Q.size()) {
			y=Q.front()/500;
			x=Q.front()%500;
			Q.pop();
			
			int mi=1010;
			if(y) mi=min(mi,D[y-1][x]);
			if(x) mi=min(mi,D[y][x-1]);
			if(y+1<N) mi=min(mi,D[y+1][x]);
			if(x+1<N) mi=min(mi,D[y][x+1]);
			if(mi+did[y][x]<D[y][x]) {
				D[y][x]=mi+did[y][x];
				if(y) Q.push((y-1)*500+x);
				if(x) Q.push((y-0)*500+x-1);
				if(y+1<N) Q.push((y+1)*500+x);
				if(x+1<N) Q.push((y-0)*500+x+1);
			}
			
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
