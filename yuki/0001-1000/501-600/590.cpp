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

int A[2][101010];
int uf[2][101010];
int id[2][101010];
int size[2][101010];
ll mo=1000000007;

map<pair<int,int>,vector<int>> M;

ll ext_gcd(ll p,ll q,ll& x, ll& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	ll g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

pair<ll,ll> crt(ll a1,ll mo1,ll a2,ll mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	ll g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<ll,ll>(-1,0); // N/A
	ll lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<ll,ll>(-2,0); // overflow
	ll v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

ll hoge(int X,int Y,vector<int> R) {
	int i;
	int g=__gcd(X,Y);
	
	map<int,vector<ll>> V;
	FORR(r,R) {
		int a=id[0][r];
		int b=id[1][r];
		int dif=(a-b+Y)%g;
		a=(a+X-dif)%X;
		pair<ll,ll> tmp=crt(a,X,b,Y);
		V[dif].push_back(tmp.first);
	}
	ll ret=0;
	FORR(r,V) {
		vector<ll> vec=r.second;
		sort(ALL(vec));
		vec.push_back(vec[0]+1LL*X*Y/g);
		FOR(i,vec.size()-1) {
			ll dif=vec[i+1]-vec[i];
			(ret+=(dif%mo)*((dif+mo-1)%mo)%mo*((mo+1)/2))%=mo;
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(j,2) {
		FOR(i,N) {
			cin>>A[j][i], A[j][i]--;
			uf[j][i]=-1;
		}
		FOR(i,N) if(uf[j][i]==-1) {
			int pre=i;
			size[j][i]=1;
			uf[j][i]=i;
			while(A[j][pre]!=i) {
				pre=A[j][pre];
				uf[j][pre]=i;
				id[j][pre]=size[j][i];
				size[j][i]++;
			}
		}
	}
	FOR(i,N) M[{uf[0][i],uf[1][i]}].push_back(i);
	ll ret=0;
	FORR(r,M) {
		(ret+=hoge(size[0][r.first.first],size[1][r.first.second],r.second))%=mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
