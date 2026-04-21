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

string X,Y;
int Q;
ll S[101];
ll C1[26][101010];
ll C2[26][101010];
ll NV[26][101];

ll dfs(int cur,ll A,int c) {
	if(A<=0) return 0;
	if(cur==1) return C1[c][A];
	if(cur==2) return C2[c][A];
	
	if(A<=S[cur-1]) return dfs(cur-1,A,c);
	return NV[c][cur-1]+dfs(cur-2,A-S[cur-1],c);
	
	
}

ll hoge(ll A,int c) {
	for(int i=3;i<=100;i++) if(A<=S[i]) {
		return dfs(i,A,c);
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y;
	S[1]=X.size();
	S[2]=Y.size();
	FOR(i,X.size()) {
		FOR(j,26) C1[j][i+1]=C1[j][i];
		C1[X[i]-'a'][i+1]++;
		NV[X[i]-'a'][1]++;
	}
	FOR(i,Y.size()) {
		FOR(j,26) C2[j][i+1]=C2[j][i];
		C2[Y[i]-'a'][i+1]++;
		NV[Y[i]-'a'][2]++;
	}
	for(i=3;i<=100;i++) {
		S[i]=S[i-1]+S[i-2];
		FOR(j,26) {
			NV[j][i]=NV[j][i-1]+NV[j][i-2];
		}
	}
	
	cin>>Q;
	while(Q--) {
		ll L,R;
		string s;
		cin>>L>>R>>s;
		cout<<hoge(R,s[0]-'a')-hoge(L-1,s[0]-'a')<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
