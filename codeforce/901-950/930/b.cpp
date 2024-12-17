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
string S;
vector<int> L,R;
vector<ll> LS,RS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		L.clear();
		R.clear();
		LS={0LL};
		RS={0LL};
		FOR(i,N) {
			if(S[i]=='<') {
				L.push_back(i);
				LS.push_back(LS.back()+i);
			}
			else {
				R.push_back(i);
				RS.push_back(RS.back()+i);
			}
		}
		
		FOR(i,N) {
			int nr=lower_bound(ALL(R),i+1)-R.begin();
			int nl=L.end()-lower_bound(ALL(L),i);
			ll ret=-1;
			if(S[i]=='<') {
				nl=min(nl,nr+1);
				nr=min(nr,nl);
				if(nl==nr) {
					x=lower_bound(ALL(L),i)-L.begin();
					ret=N+i+2*(LS[x+nl]-LS[x+1]);
					x=lower_bound(ALL(R),i)-R.begin();
					ret-=2*(RS[x]-RS[x-nr]);
				}
				else {
					x=lower_bound(ALL(L),i)-L.begin();
					ret=i+2*(LS[x+nl]-LS[x+1])+1;
					x=lower_bound(ALL(R),i)-R.begin();
					ret-=2*(RS[x]-RS[x-nr]);
				}
				
			}
			else {
				nr=min(nr,nl+1);
				nl=min(nl,nr);
				if(nl==nr) {
					x=lower_bound(ALL(L),i)-L.begin();
					ret=2*(LS[x+nl]-LS[x]);
					x=lower_bound(ALL(R),i+1)-R.begin();
					ret-=2*(RS[x]-RS[x-nr])-R[x-1];
					ret++;
				}
				else {
					x=lower_bound(ALL(L),i)-L.begin();
					ret=N+2*(LS[x+nl]-LS[x]);
					x=lower_bound(ALL(R),i+1)-R.begin();
					ret-=2*(RS[x]-RS[x-nr])-R[x-1];
				}
			}
			cout<<ret<<" ";
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
