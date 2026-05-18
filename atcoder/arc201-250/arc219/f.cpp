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

int T,N;
string S[62];
ll A[33];

int dpdp[2000][62];
int X[1900],Y[1900];

vector<int> lcs(string A,string B) {
	int AL=A.size();
	int BL=B.size();
	int i;
	FOR(i,1900) A+='0';
	
	int x,y,ma=0;
	ZERO(dpdp);
	
	FOR(x,AL+1900+1) FOR(y,BL+1) {
		if(A[x]==B[y]) dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y]+1);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x][y+1]);
		dpdp[x+1][y+1]=max(dpdp[x+1][y+1],dpdp[x+1][y]);
	}
	vector<int> V;
	FOR(i,1900) V.push_back(dpdp[AL+i][BL]);
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			ll v;
			cin>>v;
			S[i]="";
			while(v) S[i]+='0'+(v%2),v/=2;
		}
		FOR(i,1900) X[i]=i+S[0].size();
		FOR(i,N-1) {
			FOR(x,1900) Y[x]=1<<30;
			vector<int> A=lcs(S[i],S[i+1]);
			vector<int> B=lcs(S[i+1],S[i]);
			
			FOR(x,1900) FOR(y,1900) {
				if(x>=y) Y[y]=min(Y[y],X[x]+y+(int)S[i+1].size()-A[x-y]-min(x,y));
				else Y[y]=min(Y[y],X[x]+y+(int)S[i+1].size()-B[y-x]-min(x,y));
			}
			
			swap(X,Y);
		}
		int mi=1<<30;
		FOR(x,1900) mi=min(mi,X[x]);
		cout<<mi<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
