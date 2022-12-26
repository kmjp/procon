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

int N,Q;
ll X[101010];
ll Y[101010];
string S[20202];
int I[20202],V[202020];
const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<int> cand;
	FOR(i,Q) {
		cin>>S[i]>>I[i];
		if(S[i]=="x"||S[i]=="y") cin>>V[i];
		cand.push_back(I[i]);
		cand.push_back(I[i]+1);
	}
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	FOR(i,Q) {
		if(S[i]=="x") X[I[i]]=V[i];
		if(S[i]=="y") Y[I[i]]=V[i];
		if(S[i]=="a") {
			ll A=1,B=1;
			FORR(c,cand) {
				if(c==I[i]) break;
				if(X[c]) (A += X[c]*B%mo*B)%=mo;
				if(Y[c]) B = (B*Y[c]+1)%mo;
				else B=1;
			}
			cout<<A<<endl;
		}
		
	}
		
		
	while(Q--) {
		cin>>s>>x;
		if(s=="x") cin>>X[x];
		else if(s=="y") cin>>Y[x];
		else if(s=="a") {
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
