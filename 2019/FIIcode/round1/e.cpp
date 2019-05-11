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

int N,M;
ll X[303],Y[303];
vector<vector<ll>> P;
int under[303][303];
int num[303][303][303];

int right(int i,int j,int k) { // k is right i->j
	return (X[k]-X[i])*(Y[j]-Y[i])-(Y[k]-Y[i])*(X[j]-X[i])>0;
}

ll area(int i,int j,int k) {
	return abs((X[k]-X[i])*(Y[j]-Y[i])-(Y[k]-Y[i])*(X[j]-X[i]));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P.push_back({X[i],Y[i],i});
	}
	sort(ALL(P));
	FOR(i,N) X[i]=P[i][0], Y[i]=P[i][1];
	
	FOR(j,N) FOR(i,j) for(k=i+1;k<j;k++) under[i][j]+=right(i,j,k);
	FOR(i,N) for(j=i+1;j<N;j++) for(k=j+1;k<N;k++) {
		if(right(i,k,j)) num[i][j][k]=under[i][k]-under[i][j]-under[j][k]-1;
		else num[i][j][k]=under[i][j]+under[j][k]-under[i][k];
		
		num[i][k][j]=num[j][i][k]=num[j][k][i]=num[k][i][j]=num[k][j][i]=num[i][j][k];
	}
	
	ll S=1LL<<60;
	FOR(i,N) for(j=i+1;j<N;j++) {
		ll lef[404];
		FOR(k,N+1) lef[k]=1LL<<60;
		FOR(k,N) if(k!=i&&j!=k&&right(i,j,k)==0) lef[num[i][j][k]]=min(lef[num[i][j][k]],area(i,j,k));
		FOR(k,N) if(k!=i&&j!=k&&right(i,j,k)==1&&num[i][j][k]<=M) S=min(S,area(i,j,k)+lef[M-num[i][j][k]]);
	}
	
	if(S%2==0) {
		cout<<S/2<<".0"<<endl;
	}
	else {
		cout<<S/2<<".5"<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
