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

int N;
int A[202020],B[202020];
int nex[202020];
int inorder[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int preB=-1;
	int pre=-1;
	MINUS(nex);
	
	FOR(i,N) {
		cin>>x>>y;
		if(x==1) {
			nex[i+1]=i;
		}
		else if(y==2) {
			preB=i;
		}
		else {
			inorder[i]=1;
		}
		if(y==1) {
			nex[i]=preB;
		}
	}
	FOR(i,N) if(inorder[i]==1) {
		x=i;
		while(x!=-1) {
			cout<<x+1<<endl;
			x=nex[x];
		}
	}
		
			
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
