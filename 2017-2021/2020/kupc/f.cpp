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


int H,W;
int A[101010],B[101010],C[101010],D[101010];
ll SA[101010],SC[101010];
pair<int,int> AC[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	ll S=0;
	FOR(i,H-1) {
		cin>>A[i];
		S+=A[i];
	}
	cin>>x;
	S+=1LL*x*(H-1);
	FOR(i,W-1) cin>>B[i];
	cin>>x;
	S+=1LL*x*(W-1);
	FOR(i,H-1) cin>>C[i];
	FOR(i,W-1) {
		cin>>D[i];
		S+=D[i];
	}
	
	
	FOR(i,H-1) {
		AC[i]={A[i]-C[i],i};
	}
	sort(AC,AC+H-1);
	FOR(i,H-1) {
		SA[i+1]=SA[i]+A[AC[i].second];
		SC[i+1]=SC[i]+C[AC[i].second];
	}
	FOR(j,W-1) {
		int BD=D[j]-B[j];
		x=lower_bound(AC,AC+H-1,make_pair(BD,0))-AC;
		S+=SA[x]+1LL*x*B[j]+(SC[H-1]-SC[x])+1LL*(H-1-x)*D[j];
	}
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
