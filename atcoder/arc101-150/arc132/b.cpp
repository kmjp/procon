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
int P[101010];
int R[101010];

int D[101010][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i];
		P[i]--;
		R[P[i]]=i;
	}
	
	if(N==2) {
		cout<<P[0]<<endl;
		return;
	}
	
	FOR(i,N) D[i][0]=D[i][1]=1<<20;
	D[R[0]][0]=0;
	queue<int> Q;
	Q.push(R[0]);
	while(Q.size()) {
		int cur=Q.front()%N;
		int id=Q.front()/N;
		Q.pop();
		
		int ncur=(cur+N-1)%N;
		if(D[ncur][id]==1<<20) {
			D[ncur][id]=D[cur][id]+1;
			Q.push(ncur+N*id);
		}
		ncur=N-1-cur;
		int nid=id^1;
		if(D[ncur][nid]==1<<20) {
			D[ncur][nid]=D[cur][id]+1;
			Q.push(ncur+N*nid);
		}
	}
	
	if((R[0]+1)%N==R[1]%N) {
		cout<<D[0][0]<<endl;
	}
	else {
		cout<<D[0][1]<<endl;
	}
	
	
	
	
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
