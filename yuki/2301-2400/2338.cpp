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
int P[202020],S[202020];
int L[202020],R[202020],ac[202020],wa[202020];
int PL[202020],PR[202020];
int num[202020];
int start[202020];
int AC[808080];

vector<pair<int,int>> ev[202020];
const int DI=800;
int nac=0,nwa=0;

void add1(int pos) {
	int p=P[pos];
	if(S[pos]==0) {
		AC[PR[p]]++;
	}
	else {
		if(PL[p]==PR[p]) {
			nac++;
			nwa+=AC[PL[p]];
		}
		PR[p]++;
	}
}
void add2(int pos) {
	int p=P[pos];
	if(S[pos]==0) {
		AC[PL[p]]++;
		if(PL[p]<PR[p]) nwa++;
	}
	else {
		if(PL[p]==PR[p]) {
			nac++;
		}
		else {
			nwa-=AC[PL[p]];
		}
		PL[p]--;
	}
}

void del(int pos) {
	int p=P[pos];
	if(S[pos]==0) {
		AC[PL[p]]--;
		if(PL[p]<PR[p]) nwa--;
	}
	else {
		PL[p]++;
		if(PL[p]==PR[p]) {
			nac--;
		}
		else {
			nwa+=AC[PL[p]];
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,N) {
		cin>>P[i]>>s;
		S[i]=s=="AC";
		num[P[i]]++;
	}
	
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		ev[L[i]/DI].push_back({R[i],i});
	}
	int sum=0;
	FOR(i,M+1) {
		PL[i]=PR[i]=start[i]=sum+num[i];
		sum+=num[i]*2;
		
	}
	
	FOR(i,201000) if(ev[i].size()) {
		sort(ALL(ev[i]));
		int CL=i*DI,CR=i*DI;
		FORR2(r,cur,ev[i]) {
			int TL=L[cur],TR=r;
			while(CR<TR) add1(CR++);
			while(TL<CL) add2(--CL);
			while(CL<TL) del(CL++);
			ac[cur]=nac;
			wa[cur]=nwa;
		}
		while(CL<CR) del(CL++);
		FOR(j,M+1) PL[j]=PR[j]=start[j];

	}
	FOR(i,Q) {
		cout<<ac[i]<<" "<<wa[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}