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

int H,W,S;
int L[1010],R[1010],U[1010],D[1010],C[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,256) L[i]=U[i]=1010, R[i]=D[i]=-1;
	int sum=0;
	cin>>H>>W>>S;
	FOR(y,H) FOR(x,W) {
		cin>>k;
		k--;
		if(C[k]==0) sum++, C[k]=1;
		chmin(L[k],x);
		chmin(U[k],y);
		chmax(R[k],x);
		chmax(D[k],y);
	}
	
	int ret=sum;
	FOR(j,256) if(C[j]) FOR(i,j) if(C[i]) {
		int CT=min(U[i],U[j]);
		int CD=max(D[i],D[j]);
		int span=S/(CD+1-CT);
		vector<pair<int,int>> ev;
		FOR(x,256) if(C[x]&&U[x]>=CT&&D[x]<=CD&&R[x]-L[x]+1<=span) {
			ev.push_back({(R[x]+1-span)*2,1});
			ev.push_back({L[x]*2+1,-1});
		}
		sort(ALL(ev));
		int cur=0;
		FORR2(e,v,ev) {
			cur+=v;
			ret=min(ret,sum-cur);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
