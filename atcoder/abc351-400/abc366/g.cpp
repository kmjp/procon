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

int N,M;
vector<int> E[60];
ll ret[66];

const int MAT=64;
bitset<64> BS[645];
int V[64],R[64];

int Gauss(int R,int C,bitset<MAT> BS[MAT],int v[MAT],int r[MAT]) {
	int i,j,k;
	int nex=0;
	FOR(i,R) {
		while(nex<C) {
			for(j=i;j<R;j++) if(BS[j][nex]) break;
			if(j!=R) break;
			nex++;
		}
		if(nex>=C) break;
		swap(BS[i],BS[j]);
		swap(v[i],v[j]);
		FOR(j,R) if(i!=j && BS[j][nex]) {
			v[j]^=v[i];
			BS[j]^=BS[i];
		}
		nex++;
	}
	FOR(i,C) r[i]=0;
	int num=0;
	FOR(i,R) {
		
		FOR(j,C) if(BS[i][j]) break;
		if(j<C) {
			r[j]=v[i];
			num++;
		}
		else if(v[i]) {
			return -1;
		}
	}
	
	return num;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	FOR(i,N) {
		ZERO(V);
		FOR(x,N) {
			BS[x].reset();
			FORR(e,E[x]) BS[x][e]=1;
		}
		BS[N].reset();
		BS[N][i]=1;
		V[N]=1;
		x=Gauss(N+1,N,BS,V,R);
		if(x==-1) {
			cout<<"No"<<endl;
			return;
		}
		FOR(x,N) {
			if(R[x]) ret[x]|=1LL<<i;
		}
	}
	
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
