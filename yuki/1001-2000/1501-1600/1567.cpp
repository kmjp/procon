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

int T;

int C[402020];
int S[402020];
vector<int> V[402020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=2;i<=400000;i++) C[i]=i;
	for(i=2;i<=400000;i++) {
		if(C[i]==i) {
			for(j=i;j<=400000;j+=i) {
				while(C[j]%i==0) {
					V[j].push_back(i);
					C[j]/=i;
				}
			}
		}
		x=0;
		if(V[i].size()>3||(V[i].size()==3&&V[i][0]!=V[i][2])) x=1;
		S[i]=S[i-1]+x;
	}
	
	
	
	cin>>T;
	while(T--) {
		int P,L,R;
		cin>>P>>L>>R;
		L-=P;
		R-=P;
		int ret=0;
		if(L>0) ret+=S[R]-S[L-1];
		else if(L==0) ret+=S[R]+1;
		else if(R>=0) ret+=S[R]+1+S[-L];
		else ret=S[-L]-S[-R-1];
		cout<<ret<<endl;
	}
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
