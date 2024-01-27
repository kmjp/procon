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

int N,V,B,P,M;
map<int,int> G;
map<int,int> D,E;
ll ret;

int seg;
vector<ll> As[55],Ss[55];
vector<ll> Ms,M2;

void hoge() {
	E=D;
	M2=Ms;
	ll sum=1,tsum=1;
	int L=B;
	

	FORR(m,M2) {
		sum*=m;
		if(E[m]) {
			tsum*=m;
			E[m]--;
			m=1;
			L-=M;
		}
	}
	if(L<0) return;
	
	int i,j;
	ll tot=sum;
	M2.push_back(tsum);
	for(i=M2.size()-2;i>=0;i--) M2[i]*=M2[i+1];
	ll b=0;
	L=min(V,L/P);
	
	for(i=60;i>=0;i--) {
		int num=0;
		ll tmp=b+(1LL<<i);
		FOR(j,33) if(M2[j]<sum) {
			num+=As[j].end()-lower_bound(ALL(As[j]),(tmp+(sum-M2[j])-1)/(sum-M2[j]));
			if(num>=L) break;
		}
		if(num>=L) b+=1LL<<i;
	}
	tot+=L*b;
	FOR(j,33) {
		tot+=Ss[j].back()*M2[j];
		if(M2[j]<sum) {
			int x=lower_bound(ALL(As[j]),(b+(sum-M2[j])-1)/(sum-M2[j]))-As[j].begin();
			tot+=(Ss[j].back()-Ss[j][x])*(sum-M2[j])-1LL*b*(As[j].size()-x);
		}
	}
	ret=max(ret,tot);
}

void dfs(int cur) {
	auto it=G.lower_bound(cur);
	if(it==G.end()) {
		hoge();
		return;
	}
	int i;
	FOR(i,it->second+1) {
		D[it->first]=i;
		dfs(it->first+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string c;
	
	cin>>N>>B>>P>>M;
	FOR(i,33) As[i].reserve(1<<15);
	FOR(i,N) {
		cin>>c>>x;
		
		if(c[0]=='*'&&x==1) {
			i--,N--;
			continue;
		}
		if(c[0]=='*') {
			G[x]++;
			Ms.push_back(x);
		}
		else {
			V++;
			As[Ms.size()].push_back(x);
		}
	}
	
	FOR(i,33) {
		sort(ALL(As[i]));
		Ss[i]={0};
		FORR(a,As[i]) Ss[i].push_back(Ss[i].back()+a);
	}
	dfs(0);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
