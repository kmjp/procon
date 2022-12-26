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


int N,K;
int A[1010][1010];

int FA[1010],FB[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	
	
	if(K<=N*(N-1)/2) {
		for(y=N-1;y>0;y--) {
			x=min(K,y);
			K-=x;
			FA[N-1-x]=y;
		}
		for(y=N-1;y>=0;y--) {
			A[y][N-1-FA[y]]=1;
			FOR(x,N) A[y][x]+=y*N;
		}
	}
	else if(K<=N*(N-1)) {
		K-=N*(N-1);
		FOR(i,N-1) A[i][i]=1;
		for(x=N-2;x>=0;x--) {
			for(y=x-1;y>=0;y--) {
				if(K<0) A[y][x]=1,K++;
				if(K<0) A[x][y]=1,K++;
			}
		}
		
		
	}
	else {
		cout<<"No"<<endl;
		return;
	}
	
	
	cout<<"Yes"<<endl;
	FOR(y,N) {
		//cout<<FA[y]<<"  ";
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
