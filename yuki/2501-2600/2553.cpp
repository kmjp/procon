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

int N,M;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	vector<int> V;
	int ret=0;
	FOR(i,N) {
		if(S[i]!='-') V.push_back(i);
		if(S[i]=='o') ret++;
	}
	vector<int> C[3][2];
	FOR(i,V.size()-1) if(V[i+1]-V[i]>1) {
		C[(S[V[i]]=='o')+(S[V[i+1]]=='o')][(V[i+1]-V[i]-1)%2].push_back(V[i+1]-V[i]-1);
	}
	FOR(x,3) FOR(y,2) sort(ALL(C[x][y]));
	
	FORR(v,C[2][1]) {
		if(M>=v/2) {
			M-=v/2;
			ret+=v;
		}
		else {
			ret+=M*2;
			M=0;
		}
	}
	vector<int> CC;
	FORR(v,C[2][0]) CC.push_back(v);
	FORR(v,C[1][1]) CC.push_back(v);
	FORR(v,C[1][0]) CC.push_back(v);
	FORR(v,CC) {
		if(M>=v/2) {
			M-=v/2;
			ret+=v/2*2;
			v%=2;
		}
		else {
			ret+=M*2;
			M=0;
		}
	}
	vector<int> DD;
	FORR(v,C[0][1]) DD.push_back(v);
	FORR(v,C[0][0]) DD.push_back(v);
	sort(ALL(DD));
	reverse(ALL(DD));
	FORR(v,DD) {
		if(M>=(v+1)/2) {
			M-=(v+1)/2;
			ret+=(v+1)/2*2-1;
			v=(v+1)%2;
		}
		else if(M) {
			ret+=M*2-1;
			M=0;
		}
	}
	FORR(v,CC) if(M&&v) ret++, M--;
	FORR(v,DD) if(M&&v) ret++, M--;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
