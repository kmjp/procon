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
int T[202020],X[202020];
int C[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>T[i]>>X[i];
	}
	vector<int> V;
	for(i=N-1;i>=0;i--) {
		if(T[i]==1) {
			if(C[X[i]]) {
				C[X[i]]--;
				V.push_back(1);
			}
			else {
				T[i]=0;
				V.push_back(0);
			}
		}
		else {
			C[X[i]]++;
		}
	}
	FOR(i,N+1) if(C[i]) {
		cout<<-1<<endl;
		return;
	}
	
	int K=0,cur=0;
	FOR(i,N) {
		if(T[i]==1) {
			cur++;
		}
		else if(T[i]==2) {
			cur--;
		}
		K=max(cur,K);
	}
	cout<<K<<endl;
	reverse(ALL(V));
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
