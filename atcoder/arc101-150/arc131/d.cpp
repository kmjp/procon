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
int M;
ll D;
ll R[101010];
ll S[101010];
ll dif[2020202];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>D;
	FOR(i,M+1) {
		cin>>R[i];
	}
	FOR(i,M) cin>>S[i];
	
	vector<pair<ll,ll>> add,sum;
	add.push_back({-1LL<<60,0});
	sum=add;
	FOR(i,M) {
		add.push_back({R[i+1]+1,S[i+1]-S[i]});
		add.push_back({-R[i+1],S[i]-S[i+1]});
	}
	sort(ALL(add));
	for(i=1;i<add.size();i++) {
		sum.push_back(add[i]);
		sum.back().second=sum[sum.size()-2].second+add[i].second;
	}
	
	map<ll,ll> dif;
	ll cur=0;
	ll ret=0;
	FOR(i,N) {
		ll p=0;
		if(i>=1) {
			if(i%2==1) {
				p=-(i+1)/2*D;
			}
			else {
				p=i/2*D;
			}
		}
		x=lower_bound(ALL(sum),make_pair(p+1,-1LL<<60))-sum.begin()-1;
		cur+=sum[x].second;
		while(x+1<sum.size()&&add[x+1].first<=p+D) {
			x++;
			dif[add[x].first-p]+=add[x].second;
		}
	}
	ret=cur;
	FOR(i,D) {
		cur+=dif[i];
		ret=max(ret,cur);
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
