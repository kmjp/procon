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

int N,C;
vector<pair<int,int>> W[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) {
		cin>>x>>y>>k;
		W[x].push_back({y,k});
	}
	FOR(i,4) {
		W[i].push_back({0,6});
		sort(ALL(W[i]));
		reverse(ALL(W[i]));
	}
	ll ret=0;
	int R[4];
	FOR(R[1],6) FOR(R[2],3) FOR(R[3],2) {
		int LC=C-R[1]-R[2]*2-R[3]*3;
		if(LC<0) continue;
		LC/=6;
		vector<pair<ll,int>> cand;
		ll tot=0;
		for(i=1;i<=3;i++) {
			int r=R[i];
			ll sum=0;
			ll num=0;
			FORR2(a,b,W[i]) {
				int v=b;
				while(r&&v) {
					tot+=a;
					r--,v--;
				}
				if(v==0) continue;
				if(num+v>=6/i) {
					v-=6/i-num;
					sum+=1LL*a*(6/i-num);
					cand.push_back({sum,1});
					num=sum=0;
				}
				else {
					sum+=1LL*a*v;
					num+=v;
					continue;
				}
				cand.push_back({1LL*a*(6/i),v/(6/i)});
				num=v%(6/i);
				sum=1LL*a*num;
			}
		}
		sort(ALL(cand));
		reverse(ALL(cand));
		FORR2(a,b,cand) {
			x=min(LC,b);
			tot+=1LL*a*x;
			LC-=x;
		}
		ret=max(ret,tot);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
