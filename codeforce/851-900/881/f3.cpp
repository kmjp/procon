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

int T,N;
int X[202020];
int P[21][200005],D[200005];

typedef array<int,7> ARR;
ARR V[21][202020];
// sum, ma, mi, Lma,Lmi,Rma,Rmi

ARR merge(ARR L,ARR R) {
	ARR C;
	C[0]=L[0]+R[0];
	C[1]=max({L[1],R[1],L[5]+R[3]});
	C[2]=min({L[2],R[2],L[6]+R[4]});
	C[3]=max(L[3],L[0]+R[3]);
	C[4]=min(L[4],L[0]+R[4]);
	C[5]=max(R[5],R[0]+L[5]);
	C[6]=min(R[6],R[0]+L[6]);
	return C;
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		X[1]=1;
		V[0][0]={0,0,0,0,0,0,0};
		V[0][1]={1,1,0,1,0,1,0};
		D[1]=1;
		FOR(i,19) {
			V[i+1][1]=V[0][1];
			V[i+1][0]=V[0][0];
		}
		
		
		int nex=2;
		while(N--) {
			cin>>s;
			if(s=="+") {
				cin>>y>>x;
				P[0][nex]=y;
				D[nex]=D[y]+1;
				if(x==1) {
					V[0][nex]={1,1,0,1,0,1,0};
				}
				else {
					V[0][nex]={-1,0,-1,0,-1,0,-1};
				}
				FOR(i,19) {
					P[i+1][nex]=P[i][P[i][nex]];
					V[i+1][nex]=merge(V[i][nex],V[i][P[i][nex]]);
				}
				nex++;
				
			}
			else {
				cin>>x>>y>>k;
				
				if(x==y) {
					if(k==0||V[0][x][0]==k) {
						cout<<"Yes"<<endl;
					}
					else {
						cout<<"No"<<endl;
					}
				}
				else {
					if(D[x]>D[y]) swap(x,y);
					int lc=lca(x,y);
					ARR R={0,0,0,0,0,0,0};
					ARR R2={0,0,0,0,0,0,0};
					for(i=20;i>=0;i--) if(D[x]-(1<<i)>=D[lc]-1) {
						R=merge(R,V[i][x]);
						x=P[i][x];
					}
					for(i=20;i>=0;i--) if(D[y]-(1<<i)>=D[lc]) {
						R2=merge(R2,V[i][y]);
						y=P[i][y];
					}
					swap(R2[3],R2[5]);
					swap(R2[4],R2[6]);
					R=merge(R,R2);
					if(R[1]>=k&&k>=R[2]) {
						cout<<"Yes"<<endl;
					}
					else {
						cout<<"No"<<endl;
					}
				}
						
				
				
			}
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
