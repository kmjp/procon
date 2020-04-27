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
int S[505],T[505];
unsigned long long U[505],V[505];
unsigned long long A[505][505];
int B[505][505];
int R[505][2];
int C[505][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>U[i];
	FOR(i,N) cin>>V[i];
	
	FOR(r,64) {
		MINUS(B);
		ZERO(R);
		ZERO(C);
		FOR(i,N) {
			if(S[i]==1 && (U[i]&1)==0) {
				FOR(j,N) {
					if(B[i][j]==1)return _P("-1\n");
					B[i][j]=0;
				}
			}
			if(S[i]==0 && (U[i]&1)==1) {
				FOR(j,N) {
					if(B[i][j]==0)return _P("-1\n");
					B[i][j]=1;
				}
			}
			
			if(T[i]==1 && (V[i]&1)==0) {
				FOR(j,N) {
					if(B[j][i]==1) return _P("-1\n");
					B[j][i]=0;
				}
			}
			if(T[i]==0 && (V[i]&1)==1) {
				FOR(j,N) {
					if(B[j][i]==0) return _P("-1\n");
					B[j][i]=1;
				}
			}
		}
		
		
		FOR(y,N) FOR(x,N) {
			if((U[y]&1)==(V[x]&1)) B[y][x]=U[y]&1;
			if(B[y][x]==-1) B[y][x]=0;
			R[y][B[y][x]]++;
			C[x][B[y][x]]++;
		}
		
			
		FOR(y,N) if(S[y]==1&&(U[y]&1)==1) {
			if(R[y][1]) continue;
			FOR(x,N) if(T[x]==0&&(V[x]&1)==0&&C[x][0]>1) {
				B[y][x]=1;
				R[y][0]--;
				C[x][0]--;
				R[y][1]++;
				C[x][1]++;
				break;
			}
			if(x==N) return _P("-1\n");
		}
		FOR(x,N) if(T[x]==1&&(V[x]&1)==1) {
			if(C[x][1]) continue;
			FOR(y,N) if(S[y]==0&&(U[y]&1)==0&&R[y][0]>1) {
				B[y][x]=1;
				R[y][0]--;
				C[x][0]--;
				R[y][1]++;
				C[x][1]++;
				break;
			}
			if(y==N) return _P("-1\n");
		}
		FOR(y,N) {
			if(S[y]==0&&(U[y]&1)==1&&R[y][1]!=N) return _P("-1\n");
			if(S[y]==0&&(U[y]&1)==0&&R[y][1]==N) return _P("-1\n");
			if(S[y]==1&&(U[y]&1)==1&&R[y][1]==0) return _P("-1\n");
			if(S[y]==1&&(U[y]&1)==0&&R[y][1]!=0) return _P("-1\n");
		}
		FOR(x,N) {
			if(T[x]==0&&(V[x]&1)==1&&C[x][1]!=N) return _P("-1\n");
			if(T[x]==0&&(V[x]&1)==0&&C[x][1]==N) return _P("-1\n");
			if(T[x]==1&&(V[x]&1)==1&&C[x][1]==0) return _P("-1\n");
			if(T[x]==1&&(V[x]&1)==0&&C[x][1]!=0) return _P("-1\n");
		}
		
		FOR(y,N) FOR(x,N) if(B[y][x]) A[y][x]|=1ULL<<r;
		FOR(j,N) U[j]>>=1,V[j]>>=1;
	}
	
	
	
	FOR(y,N) {
		FOR(x,N) cout<<A[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
