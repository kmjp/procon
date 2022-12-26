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
int A[505050];

int iskado(int cur) {
	if(cur<0||cur>=N) return 0;
	if(cur==0||cur==N-1) return 1;
	int L=cur-1;
	int R=cur+1;
	if(A[cur]==A[L]) return 0;
	if(A[cur]==A[R]) return 0;
	if(A[L]==A[R]) return 0;
	return (A[L]<A[cur])==(A[R]<A[cur]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		vector<int> cand;
		FOR(i,N) if(iskado(i)==0) cand.push_back(i);
		
		if(cand.size()>6) {
			cout<<"No"<<endl;
			continue;
		}
		int ret=0;
		FORR(x,cand) {
			for(int c=max(0,x-1);c<=min(x+1,N-1);c++) {
				FOR(i,N) if(i!=c) {
					int cur=N-cand.size();
					set<int> S;
					S.insert(i-1);
					S.insert(i);
					S.insert(i+1);
					S.insert(c-1);
					S.insert(c);
					S.insert(c+1);
					FORR(s,S) cur-=iskado(s);
					swap(A[i],A[c]);
					FORR(s,S) cur+=iskado(s);
					if(cur==N) ret=1;
					swap(A[i],A[c]);
				}
			}
		}
		if(ret) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
