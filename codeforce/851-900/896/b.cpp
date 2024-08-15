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

int T,N,A[202020];

int num[33][33];
vector<int> E[33];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll sum=0;
		FOR(i,N) {
			cin>>A[i];
			sum+=A[i];
		}
		if(sum%N) {
			cout<<"No"<<endl;
			continue;
		}
		sum/=N;
		FOR(i,33) E[i].clear();
		ZERO(num);
		FOR(i,N) {
			if(A[i]==sum) continue;
			int ok=0;
			FOR(x,30) FOR(y,30) if(x!=y) {
				ll a=A[i]+(1LL<<x)-(1LL<<y);
				if(a==sum) {
					ok=1;
					num[x][y]++;
				}
			}
			if(ok!=1) break;
		}
		if(i!=N) {
			cout<<"No"<<endl;
			continue;
		}
		
		int ok=1;
		FOR(i,30) {
			int dif=0;
			FOR(x,30) dif+=num[x][i];
			FOR(x,30) dif-=num[i][x];
			dif/=2;
			if(dif>0) {
				x=min(dif,num[i+1][i]);
				num[i+1][i]-=x;
				num[i][32]+=x;
			}
			if(dif<0) {
				x=min(-dif,num[i][i+1]);
				num[i][i+1]-=x;
				num[31][i]+=x;
			}
		}
		
		FOR(x,33) FOR(y,33) FOR(k,num[x][y]) E[x].push_back(y);
		
		
		for(i=31;i>=0;i--) if(ok) {
			while(E[i].size()) {
				x=E[i].back();
				E[i].pop_back();
				while(x!=i) {
					if(x==32) break;
					if(E[x].empty()) {
						ok=0;
						break;
					}
					y=E[x].back();
					E[x].pop_back();
					x=y;
				}
			}
		}
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
			
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
