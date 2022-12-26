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
int X[202020],Y[202020];

int F[202020];
int R[202020];
int rev[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(rev);
	cin>>N;
	int M=0;
	FOR(i,N) cin>>X[i];
	FOR(i,N) {
		cin>>Y[i];
		
		if(rev[Y[i]]!=-1) {
			cout<<-1<<endl;
			return;
		}
		rev[Y[i]]=i;
		
		M=max({M,X[i],Y[i]});
		
		
		
	}
	queue<int> Q;
	MINUS(R);
	FOR(i,N) Q.push(i);
	for(i=M;i>=0;i--) {
		if(Q.empty()) {
			cout<<-1<<endl;
			return;
		}
			
		x=Q.front();
		Q.pop();
		if(rev[i]>=0) {
			if(R[x]!=-1) {
				cout<<-1<<endl;
				return;
			}
			R[x]=rev[i];
			if(X[R[x]]>0) {
				Q.push(x);
			}
			F[R[x]]=i;
			X[R[x]]--;
		}
		else {
			if(R[x]!=-1) {
				if(X[R[x]]>0) {
					Q.push(x);
				}
				F[R[x]]=i;
				X[R[x]]--;
			}
			else {
				Q.push(x);
			}
		}
	}
	if(Q.size()) {
		cout<<-1<<endl;
		return;
	}
	FOR(i,N) cout<<F[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
