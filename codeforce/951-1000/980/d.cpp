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
vector<int> W[101];

double dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>x>>y;
		W[x].push_back(y);
		S+=y;
	}
	ll sum=0;
	FORR(w,W[100]) sum+=w;
	FOR(i,101) {
	}
	
	if(sum>=250000) {
		cout<<sum<<endl;
		return;
	}
	dp[sum]=1;
	for(i=1;i<=99;i++) if(W[i].size()) {
		sort(ALL(W[i]));
		reverse(ALL(W[i]));
		
		for(x=250000;x>=0;x--) if(dp[x]) {
			int cur=x;
			double r=dp[x];
			FORR(w,W[i]) {
				// P*W < P*(p/100)*(W+w)
				if(1LL*100*cur>1LL*i*(cur+w)) break;
				cur+=w;
				r*=i/100.0;
				dp[cur]=max(dp[cur],r);
			}
		}
	}
	double ret=0;
	FOR(i,222000) ret=max(ret,i*dp[i]);
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
