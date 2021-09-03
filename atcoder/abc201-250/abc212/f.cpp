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
int A[101010],B[101010],S[101010],T[101010];
int nex[101010][22];


vector<pair<int,int>> E[101010];
vector<pair<int,int>> ev;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>S[i]>>T[i];
		A[i]--;
		B[i]--;
		S[i]=S[i]*2+1;
		T[i]=T[i]*2+1;
		E[A[i]].push_back({S[i],i});
		ev.push_back({-S[i],i});
	}
	FOR(i,N) sort(ALL(E[i]));
	sort(ALL(ev));
	
	FORR2(e,cur,ev) {
		int from=A[cur];
		int tar=B[cur];
		
		x=lower_bound(ALL(E[tar]),make_pair(T[cur],0))-E[tar].begin();
		if(x==E[tar].size()) {
			nex[cur][0]=M;
		}
		else {
			nex[cur][0]=E[tar][x].second;
		}
	}

	nex[M][0]=M;
	FOR(i,19) FOR(j,M+1) nex[j][i+1]=nex[nex[j][i]][i];
	while(Q--) {
		int X,Y,Z;
		cin>>X>>Y>>Z;
		X*=2;
		Z*=2;
		Y--;
		x=lower_bound(ALL(E[Y]),make_pair(X,0))-E[Y].begin();
		if(x==E[Y].size()||Z<=S[E[Y][x].second]) {
			cout<<(Y+1)<<endl;
		}
		else {
			int cur=E[Y][x].second;
			for(i=19;i>=0;i--) {
				if(nex[cur][i]==M) continue;
				if(S[nex[cur][i]]<=Z) cur=nex[cur][i];
			}
			if(Z<T[cur]) {
				cout<<(A[cur]+1)<<" "<<(B[cur]+1)<<endl;
			}
			else {
				cout<<(B[cur]+1)<<endl;
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
