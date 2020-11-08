#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S;
const ll mo=1000000007;

struct modint {
	ll v;
	modint(const ll a=0) { v=a; if(v>=mo||v<0) v=(v%mo+mo)%mo;}
	static modint pow(const modint& a,ll n=mo-2) {
		ll b=a.v,r=1;
		while(n) r=r*((n%2)?b:1)%mo,b=b*b%mo,n>>=1;
		return modint(r);
	}
	modint& operator+=(const modint& a) { v+=a.v; if(v>=mo) v-=mo; return *this;}
	modint& operator-=(const modint& a) { v+=mo-a.v; if(v>=mo) v-=mo; return *this;}
	modint& operator*=(const modint& a) { v=v*a.v%mo; return *this;}
	modint& operator/=(const modint& a) { assert(a.v!=0); *this*=pow(a); return *this;}
	modint operator+(const modint& a) const { modint res(*this); return res+=a;}
	modint operator-(const modint& a) const { modint res(*this); return res-=a;}
	modint operator*(const modint& a) const { modint res(*this); return res*=a;}
	modint operator/(const modint& a) const { modint res(*this); return res/=a;}
	friend ostream& operator<<(ostream& os, const modint& a){ os<<a.v; return os;}
};


template<int D> struct Poly {
	modint k[D];
	Poly Integrate() {
		Poly q;
		int i;
		FOR(i,D-1) q.k[i+1]=k[i]/(i+1);
		return q;
	}
	void Negate() { int i; FOR(i,D) k[i]=modint(0)-k[i];}
	void Add(Poly& p) { int i; FOR(i,D) k[i]+=p.k[i];}
	modint Sub(const modint& x) {
		modint r(1),ret(0);
		int i;
		FOR(i,D) ret+=r*k[i], r*=x;
		return ret;
	}
};

struct Val {
	Poly<1024> P,Q;
	modint R;
};

Val integrate(Val& v,bool is1x=true) {
	Val ret;
	Poly<1024> PI,QI;
	PI=v.P.Integrate();
	QI=v.Q.Integrate();
	
	if(is1x) {
		ret.P=PI;
		ret.P.Negate();
		ret.P.k[0]+=PI.Sub(1);
		ret.Q=QI;
		ret.Q.Negate();
		ret.Q.k[0]+=QI.Sub(1);
		ret.Q.k[0]-=v.R;
		ret.R=v.R;
	}
	else {
		ret.P=PI;
		ret.P.k[0]=v.R;
		ret.Q=QI;
		ret.Q.k[0]=0;
		ret.R-=v.R;
	}
	return ret;
}

void ValAdd(Val& a,Val b) {
	a.P.Add(b.P);
	a.Q.Add(b.Q);
	a.R+=b.R;
}

Val D[1010][2][2][2];

vector<modint> AddVec(vector<modint>& A,vector<modint> B) {
	A[0]+=B[0];
	A[1]+=B[1];
	A[2]+=B[2];
	return A;
}
vector<modint> SubVec(vector<modint>& A,vector<modint> B) {
	A[0]-=B[0];
	A[1]-=B[1];
	A[2]-=B[2];
	return A;
}

modint fact[1010],factrs[1010];

vector<modint> defint(Val A) {
	vector<modint> ret;
	int i;
	A.P=A.P.Integrate();
	ret.push_back(A.P.Sub(1)-A.P.Sub(0));
	A.Q=A.Q.Integrate();
	ret.push_back(A.Q.Sub(1)-A.Q.Sub(0));
	ret.push_back(0);
	ret[0]+=A.R;
	ret[1]-=A.R;
	return ret;
}
vector<modint> defint_e(Val A) {
	vector<modint> ret={0,0,0};
	
	int i;
	FOR(i,1010) {
		ret[0]+=A.P.k[i]*fact[i];
		ret[1]-=A.P.k[i]*fact[i]*factrs[i];
		ret[1]+=A.Q.k[i]*fact[i];
		ret[2]-=A.Q.k[i]*fact[i]*factrs[i];
	}
	ret[0]+=A.R/modint(2);
	ret[2]-=A.R/modint(2);
	return ret;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=factrs[0]=1;
	for(i=1;i<=1005;i++) {
		fact[i]=fact[i-1]*i;
		factrs[i]=factrs[i-1]+modint(1)/fact[i];
	}
	
	cin>>N>>S;
	if(S[0]=='X') {
		D[0][0][1][0].R=1;
	}
	else {
		D[0][0][0][1].R=1;
		D[0][1][1][1].P.k[0]=1;
		D[0][1][1][1].R=-1;
	}
	for(i=1;i<N;i++) {
		if(S[i]=='X') {
			ValAdd(D[i][0][1][0],integrate(D[i-1][1][1][0],0));
			ValAdd(D[i][0][1][0],integrate(D[i-1][1][1][1],0));
			ValAdd(D[i][0][1][0],integrate(D[i-1][0][0][1],1));
			ValAdd(D[i][0][1][0],integrate(D[i-1][0][1][1],1));
			ValAdd(D[i][0][1][0],integrate(D[i-1][1][0][1],1));
			ValAdd(D[i][0][1][0],integrate(D[i-1][1][1][1],1));
		}
		else {
			ValAdd(D[i][0][0][1],integrate(D[i-1][1][1][0],0));
			ValAdd(D[i][0][0][1],integrate(D[i-1][1][1][1],0));
			ValAdd(D[i][1][1][1],integrate(D[i-1][0][1][0],0));
			ValAdd(D[i][1][1][1],integrate(D[i-1][0][1][1],0));
			ValAdd(D[i][0][0][1],integrate(D[i-1][0][1][0],1));
			ValAdd(D[i][0][0][1],integrate(D[i-1][0][1][1],1));
			ValAdd(D[i][0][0][1],integrate(D[i-1][1][1][0],1));
			ValAdd(D[i][0][0][1],integrate(D[i-1][1][1][1],1));
		}
	}
	
	vector<modint> ret={0,0,0};
	AddVec(ret,defint(D[N-1][0][1][1]));
	AddVec(ret,defint(D[N-1][1][1][1]));
	AddVec(ret,defint_e(D[N-1][0][1][0]));
	AddVec(ret,defint_e(D[N-1][1][1][0]));
	AddVec(ret,defint(D[N-1][0][0][1]));
	AddVec(ret,defint(D[N-1][1][0][1]));
	SubVec(ret,defint_e(D[N-1][0][0][1]));
	SubVec(ret,defint_e(D[N-1][1][0][1]));
	cout<<ret[0]<<" "<<ret[1]<<" "<<ret[2]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
