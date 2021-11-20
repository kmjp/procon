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

int A[3][3];

int U[3][3],D[3][3],L[3][3],R[3][3];

int pat[1<<12][4];
int did[1<<12];

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<int> E[MV];
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		assert(NV);
		int te=0,i;
		FOR(i,NV) te += E[i].size();
		dfs(0);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};


void go() {
	DirectedEulerPath<9> dep;
	dep.init(9);
	int y,x,i;
	FOR(y,3) FOR(x,3) {
		FOR(i,U[y][x]) dep.add_path(y*3+x,y*3+x-3);
		FOR(i,D[y][x]) dep.add_path(y*3+x,y*3+x+3);
		FOR(i,L[y][x]) dep.add_path(y*3+x,y*3+x-1);
		FOR(i,R[y][x]) dep.add_path(y*3+x,y*3+x+1);
	}
	if(dep.GetPath()) {
		string S;
		int i;
		FOR(i,dep.path.size()-1) {
			int d=dep.path[i+1]-dep.path[i];
			if(d==1) S+="R";
			if(d==3) S+="D";
			if(d==-1) S+="L";
			if(d==-3) S+="U";
		}
		cout<<S<<endl;
		exit(0);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	MINUS(pat);
	
	ll S=0;
	FOR(y,3) FOR(x,3) {
		cin>>A[y][x];
		if((y+x)%2) S+=A[y][x];
		else S-=A[y][x];
	}
	if(S) {
		cout<<"NO"<<endl;
		return;
	}
	
	for(U[1][1]=0;U[1][1]<=A[1][1];U[1][1]++) {
		for(D[1][1]=0;U[1][1]+D[1][1]<=A[1][1];D[1][1]++) {
			for(L[1][1]=0;U[1][1]+D[1][1]+L[1][1]<=A[1][1];L[1][1]++) {
				R[1][1]=A[1][1]-U[1][1]-D[1][1]-L[1][1];
				for(R[0][0]=0;R[0][0]<=A[0][0];R[0][0]++) {
					int ok=1;
					L[0][2]=A[0][1]-R[0][0]-U[1][1];
					D[0][2]=A[0][2]-L[0][2];
					if(L[0][2]<0||D[0][2]<0) ok=0;
					U[2][2]=A[1][2]-D[0][2]-R[1][1];
					L[2][2]=A[2][2]-U[2][2];
					if(U[2][2]<0||U[2][2]<0) ok=0;
					R[2][0]=A[2][1]-L[2][2]-D[1][1];
					U[2][0]=A[2][0]-R[2][0];
					if(U[2][0]<0||R[2][0]<0) ok=0;
					D[0][0]=A[1][0]-U[2][0]-L[1][1];
					if(R[0][0]+D[0][0]!=A[0][0]) ok=0;
					if(ok) {
						int mask=0;
						if(R[0][0]) mask|=1<<0;
						if(D[0][0]) mask|=1<<1;
						if(L[0][2]) mask|=1<<2;
						if(D[0][2]) mask|=1<<3;
						if(U[2][2]) mask|=1<<4;
						if(L[2][2]) mask|=1<<5;
						if(U[2][0]) mask|=1<<6;
						if(R[2][0]) mask|=1<<7;
						if(U[2][2]) mask|=1<<8;
						if(D[2][2]) mask|=1<<9;
						if(L[2][2]) mask|=1<<10;
						if(R[2][2]) mask|=1<<11;
						pat[mask][0]=U[1][1];
						pat[mask][1]=D[1][1];
						pat[mask][2]=L[1][1];
						pat[mask][3]=R[0][0];
					}
				}
			}
		}
	}
	int m1,m2;
	FOR(m1,1<<12) if(pat[m1][0]>=0) {
		FOR(m2,1<<12) if(pat[m2][0]>=0) {
			int t=m1|m2;
			if(did[t]) continue;
			did[t]=1;

			U[1][1]=pat[m1][0];
			D[1][1]=pat[m1][1];
			L[1][1]=pat[m1][2];
			R[0][0]=pat[m1][3];
			R[1][1]=A[1][1]-U[1][1]-D[1][1]-L[1][1];
			L[0][2]=A[0][1]-R[0][0]-U[1][1];
			D[0][2]=A[0][2]-L[0][2];
			U[2][2]=A[1][2]-D[0][2]-R[1][1];
			L[2][2]=A[2][2]-U[2][2];
			R[2][0]=A[2][1]-L[2][2]-D[1][1];
			U[2][0]=A[2][0]-R[2][0];
			D[0][0]=A[1][0]-U[2][0]-L[1][1];
			
			D[0][1]=pat[m2][0];
			U[2][1]=pat[m2][1];
			R[1][0]=pat[m2][2];
			L[0][1]=pat[m2][3];
			L[1][2]=A[1][1]-D[0][1]-U[2][1]-R[1][0];
			R[0][1]=A[0][1]-L[0][1]-D[0][1];
			U[1][2]=A[0][2]-R[0][1];
			D[1][2]=A[1][2]-U[1][2]-L[1][2];
			R[2][1]=A[2][2]-D[1][2];
			L[2][1]=A[2][1]-R[2][1]-U[2][1];
			D[1][0]=A[2][0]-L[2][1];
			U[1][0]=A[1][0]-D[1][0]-R[1][0];
			go();
		}
	}
	
	
	cout<<"NO"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
