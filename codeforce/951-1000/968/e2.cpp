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

int T,N,M;
pair<int,int> P[5050];
int L[5050],R[5050];
int B[5050],C[5050];
ll F[5050][5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ll ret=-1;
		cin>>N>>M;
		FOR(i,N) {
			B[i]=C[i]=-1;
		}
		FOR(i,M) {
			cin>>L[i]>>R[i];
			P[i]={L[i]-1,R[i]-1};
		}
		sort(P,P+M);
		FOR(i,M) L[i]=P[i].first,R[i]=P[i].second;
		int minL=L[0],maxL=L[0],minR=R[0],maxR=R[0];
		L[M]=5050;
		for(i=1;i<=M;i++) {
			if(L[i]>maxR) {
				if(maxL>=minR) 	goto out;
				for(j=minL;j<maxL;j++) C[j]=0;
				for(j=minR+1;j<=maxR;j++) C[j]=1;
				B[maxL]=minR;
				minL=maxL=L[i];
				minR=maxR=R[i];
			}
			else {
				minL=min(minL,L[i]);
				maxL=max(maxL,L[i]);
				minR=min(minR,R[i]);
				maxR=max(maxR,R[i]);
			}
		}
		
		FOR(x,N+1) FOR(y,N+1) F[x][y]=-1LL<<60;
		F[0][0]=0;
		FOR(i,N) {
			if(B[i]>=0) {
				int R=B[i];
				FOR(j,i+1) for(k=1;k<=R-i;k++) F[R+1][j+k]=max(F[R+1][j+k],F[i][j]+(R-i+1-k)*j);
				i=R;
			}
			else if(C[i]==1) {
				FOR(j,i+1) F[i+1][j+1]=F[i][j];
			}
			else if(C[i]==0) {
				FOR(j,i+1) F[i+1][j]=F[i][j]+j;
			}
			else {
				FOR(j,i+2) F[i+1][j]=max(F[i][j]+j,j?F[i][j-1]:-1LL<<60);
			}
		}
		FOR(i,N+1) {
			ret=max(ret,F[N][i]+i*(i-1)/2+(N-i)*(N-i-1)/2);
		}
		out:
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
