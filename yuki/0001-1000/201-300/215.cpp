#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

inline int mulmod(int a,int b,int mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}

struct Kitamasa_fast {
	vector<int> P;
	static int ext_gcd(int p,int q,int& x, int& y) { // get px+qy=gcd(p,q)
		if(q==0) return x=1,y=0,p;
		int g=ext_gcd(q,p%q,y,x);
		y-=p/q*x;
		return g;
	}
	static int inv(int p,int q) { // return (1/p)%q ( p,q is co-prime)
		int xx,yy,g=ext_gcd(p,q,xx,yy);
		if(xx<0) xx+=q, yy-=p;
		return xx;
	}
	static inline int modpow(int a, int n, int mo) {
		int r=1;
		while(n) r=(n&1)?mulmod(r,a,mo):r,a=mulmod(a,a,mo),n>>=1;
		return r;
	}
	static vector<int> FMT(vector<int> v, int mo, bool rev=false) { // v.size()=2^k, mo = 2^22*k+1, 
		int i,j,k,n=v.size(); // n=2^k;
		int pf=modpow(3,(mo-1)/n,mo);
		int rt=modpow(3,(mo-1)/4,mo);
		if(rev) {
			pf=modpow(pf,mo-2,mo);
			rt=modpow(3,(mo-1)/4*3,mo);
		}
		
		FOR(i,n) while(v[i]>=mo) v[i]%=mo;
		
		for(i=0,j=1;j<n-1;j++) {
			for(int k=n>>1;k>(i^=k);k>>=1);
			if(i>j) swap(v[i],v[j]);
		}
		for(int j=0;j<n;j+=2) {
			if(v[j+1]==0) {
				v[j+1]=v[j];
			}
			else {
				int t1=v[j],t2=v[j+1];
				v[j]+=t2, v[j+1]=t1-t2;
				if(v[j]>=mo) v[j]-=mo;
				if(v[j+1]<0) v[j+1]+=mo;
			}
		}
		
		for(int m=4; m<=n; m*=2) {
			if(m!=n) {
				int ba=modpow(pf,n/(2*m),mo);
				int w1=1,w2=1,w3=1;
				FOR(i,m/2) {
					for(int j0=i;;j0+=2*m) {
						int j1=j0+m/2;
						int j2=j1+m/2;
						int j3=j2+m/2;
						if(j3>=n) break;
						
						int a = v[j0];
						int b = mulmod(v[j1],w2,mo);
						int c = mulmod(v[j2],w1,mo);
						int d = mulmod(v[j3],w3,mo);
						int ab1 = a+b; if(ab1>=mo) ab1-=mo;
						int ab2 = a-b; if(ab2<0)   ab2+=mo;
						int cd1 = c+d; if(cd1>=mo) cd1-=mo;
						int cd2 = c-d; if(cd2<0)   cd2+=mo;
						cd2=mulmod(rt,cd2,mo);
						
						v[j0]=ab1+cd1; if(v[j0]>=mo) v[j0]-=mo;
						v[j1]=ab2+cd2; if(v[j1]>=mo) v[j1]-=mo;
						v[j2]=ab1-cd1; if(v[j2]<0)   v[j2]+=mo;
						v[j3]=ab2-cd2; if(v[j3]<0)   v[j3]+=mo;
					}
					w1=mulmod(w1,ba,mo);
					w2=mulmod(w1,w1,mo);
					w3=mulmod(w2,w1,mo);
				}
				m*=2;
			}
			else {
				int ba=modpow(pf,n/m,mo);
				int w=1;
				FOR(i,m/2) {
					for(int j1=i,j2=i+m/2;j2<n;j1+=m,j2+=m) {
						int t1=v[j1],t2=mulmod(w,v[j2],mo);
						v[j1]+=t2, v[j2]=t1-t2;
						if(v[j1]>=mo) v[j1]-=mo;
						if(v[j2]<0) v[j2]+=mo;
					}
					w=mulmod(w,ba,mo);
				}
			}
		}
		
		if(rev) {
			int rn=modpow(n,mo-2,mo);
			FOR(i,n) v[i]=mulmod(v[i],rn,mo);
		}
		return v;
		
	}
	static inline int CRT_garner(vector<pair<int,int> > V,int mo=1000000007) {
		int x,y,N=V.size();
		static int invinv[3][3];
		if(invinv[0][1]==0) {
			FOR(y,N) FOR(x,N) invinv[x][y]=inv(V[x].first,V[y].first);
		}
		
		FOR(y,N) FOR(x,y) {
			int k=V[y].second-V[x].second;
			if(k<0) k+=V[y].first;
			V[y].second = mulmod(k,invinv[x][y],V[y].first);
		}
		int ret=mulmod(V[2].second,V[1].first,mo) + V[1].second;
		if(ret>=mo) ret -= mo;
		ret = mulmod(ret,V[0].first,mo) + V[0].second;
		if(ret>=mo) ret -= mo;
		return ret;
	}
	
	static vector<int> convol_sub(vector<int> a,vector<int> b, int mo, bool FMTb=true) { // mo = 2^k+1
		int i,n=1;
		if(FMTb) {
			while(n<a.size()+b.size()-1) n*=2;
		}
		else {
			n=b.size();
		}
		
		a.resize(n), a=FMT(a,mo);
		if(FMTb) b.resize(n), b=FMT(b,mo);
		FOR(i,b.size()) a[i]=mulmod(a[i],b[i],mo);
		return FMT(a,mo,true);
	}
	static vector<int> convol_sub(vector<int> a,int mo) { // mo = 2^k+1
		int i,n=1;
		while(n<2*a.size()-1) n*=2;
		a.resize(n), a=FMT(a,mo);
		FOR(i,a.size()) a[i]=mulmod(a[i],a[i],mo);
		return FMT(a,mo,true);
	}
	
	static vector<int> fastconvol(vector<int>& a,vector<int>& b,int mo,int t=999999) {
		int n=1,x,y,i;
		while(n<a.size()+b.size()-1) n*=2;
		vector<int> ax,bx;
		FOR(i,a.size()) if(a[i]) ax.push_back(i);
		FOR(i,b.size()) if(b[i]) bx.push_back(i);
		vector<int> ret(n,0);
		FORR(ra,ax) FORR(rb,bx) if(ra+rb<t) {
			ret[ra+rb]=mulmod(a[ra],b[rb],mo);
			if(ret[ra+rb]>=mo) ret[ra+rb]-=mo;
		}
		return ret;
	}
	
	static vector<int> convol(vector<int>& a,vector<int>& b, int mo,int t=99999999) {
		int i,ma=0,mb=0;
		FOR(i,a.size()) if(a[i]) ma++;
		FOR(i,b.size()) if(b[i]) mb++;
		if(ma*mb<500000) return fastconvol(a,b,mo,t);
		
		int mop[3]={0xA000001,0x1C000001,0x23800001};
		auto x = (&a==&b)?convol_sub(a,mop[0]):convol_sub(a,b,mop[0]);
		auto y = (&a==&b)?convol_sub(a,mop[1]):convol_sub(a,b,mop[1]);
		auto z = (&a==&b)?convol_sub(a,mop[2]):convol_sub(a,b,mop[2]);
		t=min(t,(int)x.size());
		
		vector<int> R(t);
		vector<pair<int,int> > P{{mop[0],0},{mop[1],0},{mop[2],0}};
		for(int i=0;i<t;i++) { // garner
			P[0].second = x[i];
			P[1].second = y[i];
			P[2].second = z[i];
			R[i] = CRT_garner(P,mo);
		}
		return R;
	}
	static vector<int> convolf(vector<int> a,vector<vector<int>> b, int mo,int t=99999999) {
		int mop[3]={0xA000001,0x1C000001,0x23800001};
		auto x = convol_sub(a,b[0],mop[0],false);
		auto y = convol_sub(a,b[1],mop[1],false);
		auto z = convol_sub(a,b[2],mop[2],false);
		t=min(t,(int)x.size());
		
		vector<int> R(t);
		vector<pair<int,int> > P{{mop[0],0},{mop[1],0},{mop[2],0}};
		for(int i=0;i<t;i++) { // garner
			P[0].second = x[i];
			P[1].second = y[i];
			P[2].second = z[i];
			R[i] = CRT_garner(P,mo);
		}
		return R;
	}
	
	static vector<int> mult(vector<int>& v,vector<int>& v2,vector<vector<int>>& Ds,vector<vector<int>>& IDs, int mo) {
		int k=v.size(),i;
		vector<int> res(k,0);
		vector<int> beta=convol(v,v2,mo);
		for(i=k-1;i<beta.size()&&i-(k-1)<k;i++) res[i-(k-1)]=beta[i];
		beta.resize(k-1);
		
		vector<int> q=convolf(beta,IDs,mo,k-1);
		q=convolf(q,Ds,mo);
		for(i=k-1;i<q.size()&&i-(k-1)<k;i++) if((res[i-(k-1)]+=q[i])>=mo) res[i-(k-1)]-=mo;
		return res;
	}

	vector<int> getid(vector<int> D, int mo) {
		int t=1,k=D.size();
		vector<int> id(1,1);
		while(t<=k) {
			t=min(2*t,k+1);
			vector<int> D2=D;
			D2.resize(t);
			vector<int> cur=convol(D2,id,mo,t);
			cur.resize(t);
			cur[0]+=2;
			if(cur[0]>=mo) cur[0]-=mo;
			id=convol(id,cur,mo,t);
			id.resize(t);
		}
		
		return id;
	}
	void calc(ll N, vector<int> D, int mo) {
		int n=D.size(),i;
		vector<int> p(n,0),v(n,0);
		p[0]=v[1]=1;
		reverse(ALL(D));reverse(ALL(p));reverse(ALL(v));
		D.insert(D.begin(),mo-1);
		vector<int> id=getid(D,mo);
		
		vector<vector<int> > Ds,IDs;
		int mop[3]={0xA000001,0x1C000001,0x23800001};
		while(n&(n-1)) n++;
		D.resize(n*2);id.resize(n*2);
		FOR(i,3) Ds.push_back(FMT(D,mop[i])), IDs.push_back(FMT(id,mop[i]));
		
		while(N) {
			if(N%2) p=mult(p,v,Ds,IDs,mo);
			v=mult(v,v,Ds,IDs,mo);
			//if(N%2) p=mult2(p,v,D,id,mo);
			//v=mult2(v,v,D,id,mo);
			N/=2;
		}
		reverse(ALL(p));
		P=p;
	}
	ll calc(ll N, vector<int> A, vector<int> D, int mo) {
		// A_K=A0*D0+A1*D1+A2*D2..+A_K-1*D_K-1 return A_N
		int i; ll ret=0;
		calc(N,D,mo);
		FOR(i,A.size()) ret += mulmod(A[i],P[i],mo);
		return (int)(ret%mo);
	}
};

ll N;
int P,C,M;
int A[6]={2,3,5,7,11,13};
int B[6]={4,6,8,9,10,12};

int dp[2][320][4096];
ll dp2[8000];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>C;
	dp[0][0][0]=dp[1][0][0]=1;
	
	FOR(x,6) FOR(y,P) FOR(i,y*13+1) if((dp[0][y+1][i+A[x]] += dp[0][y][i])>=mo) dp[0][y+1][i+A[x]]-=mo;
	FOR(x,6) FOR(y,C) FOR(i,y*12+1) if((dp[1][y+1][i+B[x]] += dp[1][y][i])>=mo) dp[1][y+1][i+B[x]]-=mo;
	vector<int> p,q;
	FOR(i,4096) p.push_back(dp[0][P][i]), q.push_back(dp[1][C][i]);
	p=Kitamasa_fast::convol(p,q,mo);
	M=P*13+C*12;
	
	ll tot=0;
	if(N<=2*M) {
		dp2[0]=1;
		for(i=1;i<=2*M+2;i++) {
			FOR(x,M+1) if(i>=x) dp2[i] += dp2[i-x]*p[x]%mo;
			dp2[i] %= mo;
		}
		for(ll v=max(0LL,N-M);v<N;v++) {
			for(x=1;x<=M;x++) if(v+x>=N) tot += dp2[v]*p[x]%mo;
			tot %= mo;
		}
	}
	else {
		Kitamasa_fast kf;
		vector<int> A(M,1),V(M,0);
		FOR(i,M) V[i]=p[M-i];
		tot = kf.calc(N+M-1,A,V,mo);
	}
	
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
