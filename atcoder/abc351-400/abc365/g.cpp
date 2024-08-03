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

int N,M,Q;
vector<int> Vs[202020];
int T[202020],P[202020];
int id[202020];
bitset<202020> BS[101];
int Bsum[101][202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>T[i]>>P[i];
		P[i]--;
		Vs[P[i]].push_back(i);
	}
	
	x=0;
	FOR(i,N) {
		
		if(Vs[i].size()>=2000) {
			id[i]=x;
			int cur=0;
			FOR(j,M-1) {
				if(P[j]==i) cur^=1;
				Bsum[x][j+1]=Bsum[x][j];
				if(cur) {
					BS[x][j]=1;
					Bsum[x][j+1]+=T[j+1]-T[j];
				}
			}
			x++;
		}
		else {
			id[i]=-1;
		}
	}
	cin>>Q;
	map<pair<int,int>,int> R;
	FOR(i,Q) {
		cin>>x>>y;
		x--,y--;
		if(id[x]>=0) swap(x,y);
		
		if(R.count({x,y})) {
			cout<<R[{x,y}]<<endl;
			continue;
		}
		int ret=0;
		if(id[x]>=0) {
			auto B=BS[id[x]]&BS[id[y]];
			FOR(j,M-1) if(B[j]) ret+=T[j+1]-T[j];
		}
		else if(id[y]>=0) {
			FOR(j,Vs[x].size()/2) {
				ret+=Bsum[id[y]][Vs[x][j*2+1]]-Bsum[id[y]][Vs[x][j*2]];
			}
		}
		else {
			int xp=0,yp=0,pre=0;
			int xc=0,yc=0;
			while(xc<Vs[x].size()&&yc<Vs[y].size()) {
				if(xc==Vs[x].size()) {
					h1:
					if(xp&&yp) ret+=T[Vs[y][yc]]-pre;
					yp^=1;
					pre=T[Vs[y][yc]];
					
					yc++;
				}
				else if(yc==Vs[y].size()) {
					h2:
					if(xp&&yp) ret+=T[Vs[x][xc]]-pre;
					xp^=1;
					pre=T[Vs[x][xc]];
					xc++;
				}
				else if(Vs[x][xc]<Vs[y][yc]) {
					goto h2;
				}
				else {
					goto h1;
				}
			}
		}
		cout<<ret<<endl;
		R[{x,y}]=ret;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
