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

const int DI=320;
int N,Q;

int C[DI+8][101010];
int S[DI+8][101010];
int A[101010];
int cnt[101010];
ll dpL[DI+8][DI+8];
ll dpR[DI+8][DI+8];

void add(int pos,int v) {
	pos/=DI;
	int i;
	FOR(i,pos+1) dpL[i][pos]+=(S[pos+1][v]-S[i][v]);
	for(i=pos+1;i<DI;i++) dpR[pos][i]+=(S[i+1][v]-S[pos+1][v]);
	C[pos][v]++;
	FOR(i,DI) S[i+1][v]=S[i][v]+C[i][v];
}

void del(int pos,int v) {
	pos/=DI;
	int i;
	C[pos][v]--;
	FOR(i,DI) S[i+1][v]=S[i][v]+C[i][v];
	FOR(i,pos+1) dpL[i][pos]-=(S[pos+1][v]-S[i][v]);
	for(i=pos+1;i<DI;i++) dpR[pos][i]-=(S[i+1][v]-S[pos+1][v]);
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		add(i,A[i]);
	}
	cin>>Q;
	ll ret=0;
	while(Q--) {
		ll L,R;
		cin>>i>>L>>R;
		L=(L+ret)%N;
		R=(R+ret)%N;
		if(i==1) {
			del(L,A[L]);
			A[L]=R;
			add(L,A[L]);
		}
		else {
			if(L>R) swap(L,R);
			R++;
			ret=(R-L)*(R-L-1)/2;
			if(R-L<=1000) {
				for(i=L;i<R;i++) ret-=cnt[A[i]]++;
				for(i=L;i<R;i++) cnt[A[i]]=0;
			}
			else {
				x=(L+DI-1)/DI;
				y=R/DI;
				for(i=x;i<y;i++) ret-=dpL[x][i]+dpR[i][y-1];
				for(i=L;i<x*DI;i++) ret-=(S[y][A[i]]-S[x][A[i]])+cnt[A[i]]++;
				for(i=y*DI;i<R;i++) ret-=(S[y][A[i]]-S[x][A[i]])+cnt[A[i]]++;
				for(i=L;i<x*DI;i++) cnt[A[i]]=0;
				for(i=y*DI;i<R;i++) cnt[A[i]]=0;
				
			}
			cout<<ret<<" ";
		}
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
