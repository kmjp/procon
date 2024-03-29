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
ll M,A[202020];
ll num[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(i,N+2) num[i]=0;
		vector<pair<int,int>> V;
		V.push_back({0,0});
		FOR(i,N) {
			cin>>x;
			x=N-x;
			while(V.back().first>x) {
				y=max(x,V[V.size()-2].first);
				num[i-V.back().second]+=V.back().first-y;
				
				if(x>V[V.size()-2].first) {
					V.back().first=x;
					break;
				}
				
				V.pop_back();
			}
			if(x>V.back().first) V.push_back({x,i});
		}
		while(V.size()>1) {
			num[N-V.back().second]+=V.back().first-V[V.size()-2].first;
			V.pop_back();
		}
		
		cin>>M;
		ll sum=0;
		for(i=N;i>=1;i--) {
			ll s=num[i]*i;
			if(M>=s) {
				sum+=(i-1)*num[i];
				M-=s;
			}
			else {
				sum+=M-(M+(i-1))/i;
				M=0;
			}
		}
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
