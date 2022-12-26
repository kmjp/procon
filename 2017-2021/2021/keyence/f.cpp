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

ll N;
string S,T;
int L;
const ll mo=998244353;
int mp[256];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class T> vector<T> fft(vector<T> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		T wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			T w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				T t1=v[j1],t2=(ll)w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=(ll)w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=(ll)v[i]*rv%mo;
	}
	return v;
}

template<class T> vector<T> MultPoly(vector<T> P,vector<T> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=(ll)P[i]*Q[i]%mo;
	return fft(P,true);
}
vector<vector<ll>> hoge(vector<vector<ll>> A,vector<vector<ll>> B) {
	int x,y,z,i;
	vector<vector<ll>> R(9);
	int pi=0,qi=0;
	FOR(x,9) {
		FOR(i,A[x].size()) if(A[x][i]) pi=max(pi,i);
		FOR(i,B[x].size()) if(B[x][i]) qi=max(qi,i);
	}
	pi=pi+qi+1;
	qi=1;
	while(qi<pi) qi*=2;
	FOR(x,9) {
		A[x].resize(qi);
		A[x]=fft(A[x]);
		B[x].resize(qi);
		B[x]=fft(B[x]);
	}
	
	
	FOR(x,3) FOR(y,3) {
		R[x*3+y].resize(qi);
		FOR(i,qi) {
			R[x*3+y][i]+=A[x*3+0][i]*B[0*3+y][i];
			R[x*3+y][i]+=A[x*3+1][i]*B[1*3+y][i];
			R[x*3+y][i]+=A[x*3+2][i]*B[2*3+y][i];
			R[x*3+y][i]%=mo;
		}
		R[x*3+y][i]%=mo;
		R[x*3+y]=fft(R[x*3+y],1);
	}
	return R;
	
}

vector<vector<ll>> get_e(int len) {
	static vector<vector<ll>> R[20];
	int i;
	
	if(R[0].empty()) {
		int x,y;
		vector<vector<ll>> C;
		FOR(x,3) FOR(y,3) {
			vector<ll> A;
			A.push_back(y>x);
			A.push_back(x>=y);
			C.push_back(A);
		}
		R[0]=C;
		FOR(i,17) R[i+1]=hoge(R[i],R[i]);
	}
	vector<vector<ll>> ret;
	FOR(i,18) if(len&(1<<i)) {
		if(ret.empty()) {
			ret=R[i];
		}
		else {
			ret=hoge(ret,R[i]);
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>T;
	S="keyence";
	mp['k']=0;
	mp['y']=2;
	mp['n']=4;
	mp['c']=5;
	
	L=T.size();
	vector<pair<char,int>> V;
	
	int add=0;
	FORR(c,T) {
		if(V.size()&&(V.back().first==c)) {
			if(c=='e') V.back().second++;
			else add++;
		}
		else {
			V.push_back({c,1});
		}
	}

	queue<vector<ll>> R2;
	for(i=0;i<V.size();i++) {
		if(V[i].first=='e') {
			int pre=(i==0)?0:mp[V[i-1].first];
			int nex=(i==V.size()-1)?7:mp[V[i+1].first];
			auto A=get_e(V[i].second);
			vector<ll> B(A[0].size()+3);
			int X[3]={1,3,6};
			int L[8]={0,-1,1,-1,2,2,-1,0};
			int y=L[nex];
			FOR(x,3) {
				int s=X[x]<pre;
				FOR(j,A[x*3+y].size()) (B[j+s]+=A[x*3+y][j])%=mo;
			}
			if(nex==7) B.erase(B.begin());
			R2.push(B);
		}
		else if(i&&V[i-1].first!='e') {
			if(mp[V[i-1].first]>=mp[V[i].first]) add++;
		}
	}
	vector<ll> addv(add+1);
	addv.back()=1;
	R2.push(addv);
	
	while(R2.size()>1) {
		auto a=R2.front();
		R2.pop();
		auto b=R2.front();
		R2.pop();
		R2.push(MultPoly(a,b,1));
	}
	vector<ll> R=R2.front();
	ll ret=0;
	ll P=1,Q=1;
	int inc0=0;
	FOR(i,T.size()) {
		Q=Q*(i+1)%mo;
		if((N+T.size()-1-i)%mo==0) {
			inc0=1;
		}
		else {
			P=P*((N+T.size()-1-i)%mo)%mo;
		}
	}
	FOR(i,R.size()) {
		//cout<<i<<" "<<R[i]<<" "<<hcomb(T.size()+1,N-1-i)<<" "<<(R[i]*hcomb(N-1-i,S.size()+1)%mo)<<endl;
		//ret+=R[i]*hcomb(T.size()+1,N-1-i)%mo;
		if(inc0==0) ret+=R[i]*P%mo*modpow(Q)%mo;
		
		if((N+T.size()-1-i)%mo==0) {
			inc0=0;
		}
		else {
			P=P*modpow((N+T.size()-1-i)%mo)%mo;
		}
		if((N-1-i)%mo==0) {
			inc0=1;
		}
		else {
			P=P*((N-1-i)%mo)%mo;
		}
		
		
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
