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
pair<int,int> P[101];
int X[101],Y[101];
const ll mo=1000000007;

ll num[88][88][88];
int S[88][88][88];
int A[88][88];
ll up[80][80][2];
ll down[80][80][2];


int side(int a,int b,int c) {
	ll Xab=X[b]-X[a];
	ll Yab=Y[b]-Y[a];
	ll Xac=X[c]-X[a];
	ll Yac=Y[c]-Y[a];
	
	return Xab*Yac>Yab*Xac;
}

ll area(int a,int b) {
	ll S=X[a]*Y[b]-Y[a]*X[b];
	return abs(S)%2;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
	}
	sort(P,P+N);
	FOR(i,N) X[i]=P[i].first, Y[i]=P[i].second;
	
	FOR(i,N) FOR(j,N) A[i][j]=area(i,j);
	FOR(i,N) FOR(j,N) FOR(k,N) S[i][j][k]=side(i,j,k);
	FOR(i,N) FOR(j,N) FOR(k,N) {
		if(!S[i][j][k]) continue;
		num[i][j][k]=1;
		FOR(x,N) {
			if(S[i][j][x]==0) continue;
			if(S[j][k][x]==0) continue;
			if(S[k][i][x]==0) continue;
			(num[i][j][k]*=2)%=mo;
		}
	}
	
	ll ret=0;
	FOR(i,N) {
		ZERO(up);
		ZERO(down);
		for(x=i+1;x<N;x++) up[i][x][0]=down[i][x][0]=1;
		for(x=i;x<N;x++) {
			for(y=x+1;y<N;y++) for(k=y+1;k<N;k++) {
				ll w=num[i][y][k]+num[i][k][y];
				int a=A[i][y]^A[y][k]^A[k][i];
				if(S[x][y][k]) {
					(up[y][k][a^0]+=w*up[x][y][0])%=mo;
					(up[y][k][a^1]+=w*up[x][y][1])%=mo;
				}
				else {
					(down[y][k][a^0]+=w*down[x][y][0])%=mo;
					(down[y][k][a^1]+=w*down[x][y][1])%=mo;
				}
			}
			if(x>i) {
				ll U[2]={0,0},D[2]={0,0};
				FOR(y,N) {
					(U[0]+=up[y][x][0])%=mo;
					(U[1]+=up[y][x][1])%=mo;
					(D[0]+=down[y][x][0])%=mo;
					(D[1]+=down[y][x][1])%=mo;
				}
				
				(ret+=U[0]*D[0]+mo-1+U[1]*D[1])%=mo;
			}
		}
		
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
