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
const ll mo=998244353;
int S[802020],T[802020];
int num[802020];
ll TD[802020];
ll RD[802020];

ll p2[802020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<ll,ll>> V,VR;
	
	p2[0]=1;
	FOR(i,801010) p2[i+1]=p2[i]*2%mo;
	
	scanf("%d",&N);
	ll CD=0;
	int TF=N+1;
	FOR(i,N) {
		scanf("%d",&S[i]);
		if(S[i]!=3) scanf("%d",&T[i]);
		if(i) TD[i]=TD[i-1];
		if(S[i]==2) {
			TD[i]+=T[i];
			CD+=T[i];
		}
		if(S[i]==3) {
			RD[i]=CD;
			if(CD<1LL<<31) {
				if(CD) TF=min(TF,(int)V.size());
				V.push_back({CD,i});
				VR.push_back({i,CD});
				CD=min(CD*2,1LL<<31);
			}
		}
		
		num[i+1]=num[i]+(S[i]==3);
	}
	if(TF==N+1) TF=V.size();
	ll ret=0;
	int ps=0;
	FOR(i,N) if(S[i]==1) {
		ll cur=T[i];
		cur-=TD[N-1]-TD[i];
		if(cur<=0) continue;
		while(ps<VR.size()&&VR[ps].first<i) ps++;
		x=ps;
		ll pat=1;
		if(TF>x) {
			pat=p2[TF-x];
			x=TF;
		}
		ll num=1;
		for(j=V.size()-1;j>=x;j--) {
			if(cur>V[j].first) {
				num+=p2[j-x];
				cur-=V[j].first;
			}
		}
		(ret+=pat*(num%mo))%=mo;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
