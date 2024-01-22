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

int N[3];
int A[3][6060];
int num[3][6060];
ll S[3][6060];

template<typename V> struct ConvexHull {
	vector<pair<V,V>> Q;
	V calc(pair<V,V> p, V x) {
		return p.first*x+p.second;
	}
	int dodo(pair<V,V> A,pair<V,V> B, pair<V,V> C) {
		return ((B.second-C.second)*(B.first-A.first)<=(A.second-B.second)*(C.first-B.first));
	}
	void add(V a, V b) { // add ax+b
		if(Q.size() && Q.back().first==a) {
			//aÇ™ìØÇ∂èÍçá
			//if(b>=Q.back().second) return; //minÇÃèÍçá
			if(b<=Q.back().second) return; //maxÇÃèÍçá
			Q.pop_back();
		}
		Q.push_back({a,b});
		int v;
		while((v=Q.size())>=3 && dodo(Q[v-3],Q[v-2],Q[v-1]))
			Q[v-2]=Q[v-1], Q.pop_back();
	}
	void add(vector<pair<V,V>> v) {
		sort(v.begin(),v.end());
		for(auto r=v.begin();r!=v.end();r++) add(r->first,r->second);
	}
	
	
	V query(V x) {
		int L=-1,R=Q.size()-1;
		while(R-L>1) {
			int M=(L+R)/2;
			(0^((calc(Q[M],x)<=calc(Q[M+1],x)))?L:R)=M;
		}
		return calc(Q[R],x);
	}
};

vector<pair<ll,ll>> X;
ConvexHull<ll> ch;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>N[i];
	FOR(i,3) {
		FOR(j,N[i]) {
			cin>>x;
			A[i][3000-x]++;
		}
		FOR(j,6001) {
			num[i][j+1]=num[i][j]+A[i][j];
			S[i][j+1]=S[i][j]+A[i][j]*(3000-j);
		}
	}
	ll ma=0;
	FOR(i,6002) {
		X.clear();
		ch.Q.clear();
		if(S[0][i]>0) {
			for(j=3000;j<=6001;j++) {
				X.push_back({S[1][j],num[1][j]*S[0][i]});
			}
		}
		else {
			FOR(j,6002) {
				X.push_back({S[1][j],num[1][j]*S[0][i]});
			}
		}
		ch.add(X);
		x=0;
		FOR(j,6002) {
			while(x+1<ch.Q.size()&&ch.calc(ch.Q[x],num[2][j])<=ch.calc(ch.Q[x+1],num[2][j])) x++;
			ma=max(ma,ch.calc(ch.Q[x],num[2][j])+num[0][i]*S[2][j]);
		}
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}