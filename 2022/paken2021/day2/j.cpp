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


int N,M;
int T[202020],A[202020];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>A[i];
	vector<vector<int>> V;
	if(T[0]==0) V.push_back({A[0],M,1});
	else V.push_back({1,A[0],1});
	
	FOR(i,N-1) {
		ll sum=0,ok=0;
		FORR(a,V) {
			(sum+=1LL*(a[1]-a[0]+1)*a[2])%=mo;
			if(a[0]<=A[i]&&A[i]<=a[1]) ok=a[2];
		}
		vector<vector<int>> W;
		if(T[i]==0) {
			W.push_back({A[i],A[i],(int)sum});
			W.push_back({A[i]+1,M,(int)ok});
		}
		else {
			W.push_back({1,A[i]-1,(int)ok});
			W.push_back({A[i],A[i],(int)sum});
		}
		V.clear();
		FORR(a,W) {
			if(T[i+1]==0) {
				a[0]=max(a[0],A[i+1]);
			}
			else {
				a[1]=min(a[1],A[i+1]);
			}
			if(a[0]<=a[1]) V.push_back(a);
		}
		
	}
	ll sum=0,ok=0;
	FORR(a,V) {
		(sum+=1LL*(a[1]-a[0]+1)*a[2])%=mo;
		if(a[0]<=A[N-1]&&A[N-1]<=a[1]) ok=a[2];
	}
	ll ret=0;
	if(T[N-1]==0) {
		ret+=sum+ok*(M-A[N-1]+1-1);
	}
	else {
		ret+=sum+ok*(A[N-1]-1);
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
