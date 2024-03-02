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

ll V[4];

int X[3],Y[3],Z[3];

int ok() {
	ll A[4]={};
	
	A[3]+=max(0,min({X[0],X[1],X[2]})+7-max({X[0],X[1],X[2]}))*max(0,min({Y[0],Y[1],Y[2]})+7-max({Y[0],Y[1],Y[2]}))*max(0,min({Z[0],Z[1],Z[2]})+7-max({Z[0],Z[1],Z[2]}));
	A[2]+=max(0,min(X[0],X[1])+7-max(X[0],X[1]))*max(0,min(Y[0],Y[1])+7-max(Y[0],Y[1]))*max(0,min(Z[0],Z[1])+7-max(Z[0],Z[1]));
	A[2]+=max(0,min(X[2],X[1])+7-max(X[2],X[1]))*max(0,min(Y[2],Y[1])+7-max(Y[2],Y[1]))*max(0,min(Z[2],Z[1])+7-max(Z[2],Z[1]));
	A[2]+=max(0,min(X[0],X[2])+7-max(X[0],X[2]))*max(0,min(Y[0],Y[2])+7-max(Y[0],Y[2]))*max(0,min(Z[0],Z[2])+7-max(Z[0],Z[2]));
	A[2]-=A[3]*3;
	A[1]=(3*7*7*7)-A[2]*2-A[3]*3;
	
	return A[1]==V[1]&&A[2]==V[2]&&A[3]==V[3];
	
	
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>V[i+1];
	
	for(X[1]=-7;X[1]<=7;X[1]++) for(X[2]=min(X[0],X[1])-7;X[2]<=max(X[0],X[1])+7;X[2]++)
	for(Y[1]=-7;Y[1]<=7;Y[1]++) for(Y[2]=min(Y[0],Y[1])-7;Y[2]<=max(Y[0],Y[1])+7;Y[2]++)
	for(Z[1]=-7;Z[1]<=7;Z[1]++) for(Z[2]=min(Z[0],Z[1])-7;Z[2]<=max(Z[0],Z[1])+7;Z[2]++) {
		if(ok()) {
			cout<<"Yes"<<endl;
			FOR(i,3) cout<<X[i]<<" "<<Y[i]<<" "<<Z[i]<<" ";
			cout<<endl;
			return;
		}
		
	}
	cout<<"No"<<endl;

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
