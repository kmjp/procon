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


int Q;
const int DI=600;
const int BL=300000/DI+2;
int T[DI*BL+2],V[DI*BL+2];
pair<int,int> P[DI*BL+2];
int R[DI*BL+2];

int NA[BL],NB[BL];
int avail[DI*BL+2];
ll sum[BL][DI*2+1];

void update(int v) {
	avail[v]=1;
	v=v/DI;
	int i;
	NA[v]=NB[v]=0;
	ZERO(sum[v]);
	
	int cur=DI;
	for(i=DI-1;i>=0;i--) if(avail[v*DI+i]) {
		int n=P[v*DI+i].second;
		if(T[n]==0) {
			NA[v]++;
			sum[v][cur+1]+=V[n];
			cur++;
		}
		else {
			NB[v]++;
			sum[v][0]+=V[n];
			sum[v][cur]-=V[n];
			cur--;
		}
	}
	FOR(i,DI*2) sum[v][i+1]+=sum[v][i];
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,BL*DI) {
		if(i<Q) {
			cin>>T[i]>>V[i];
			T[i]--;
		}
		P[i]={V[i],i};
	}
	sort(P,P+BL*DI);
	FOR(i,DI*BL) R[P[i].second]=i;
	
	ll suma=0;
	FOR(i,Q) {
		update(R[i]);
		if(T[i]==0) suma+=V[i];
		ll ret=suma;
		int dif=0;
		for(j=BL-1;j>=0;j--) {
			ret+=sum[j][-min(max(dif,-DI),DI)+DI];
			dif+=NA[j]-NB[j];
		}
		cout<<ret<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
