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
ll X[55],Y[55],Z[55];
int mi;


__int128 abs2(__int128& a) {
	if(a<0) return -a;
	return a;
}

pair<__int128,__int128> normalize(pair<__int128,__int128> a) {
	__int128 b=__gcd(abs2(a.first),abs2(a.second));
	a.first/=b;
	a.second/=b;
	if(a.second<0) {
		a.first=-a.first;
		a.second=-a.second;
	}
	return a;
}

pair<__int128,__int128> hoge(pair<__int128,__int128> p1,pair<__int128,__int128> p2,pair<__int128,__int128> a) { //p1+(p2-p1)*a
	pair<__int128,__int128> p3={p2.first*p1.second-p1.first*p2.second,p1.second*p2.second};
	p3.first*=a.first;
	p3.second*=a.second;
	pair<__int128,__int128> p4={p1.first*p3.second+p3.first*p1.second,p1.second*p3.second};
	return normalize(p4);
	
}


int hoge(__int128 px,__int128 qx,__int128 py,__int128 qy,__int128 pz,__int128 qz) {
	set<pair<pair<__int128,__int128>,pair<__int128,__int128>>> S;
	if(px>=0) return N;
	int i;
	FOR(i,N) {
		pair<__int128,__int128> a={-px,qx*X[i]-px};
		pair<__int128,__int128> y=hoge({py,qy},{Y[i],1},a);
		pair<__int128,__int128> z=hoge({pz,qz},{Z[i],1},a);
		S.insert({y,z});
	}
	
	return S.size();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	mi=N;
	FOR(i,N) cin>>X[i]>>Y[i]>>Z[i];
	
	int a1,a2,b1,b2;
	FOR(a1,N) FOR(a2,N) FOR(b1,N) FOR(b2,N) if(a1<b1) {
		if(X[a1]>=X[a2]) continue;
		if(X[b1]>=X[b2]) continue;
		if(a1==b2) continue;
		if(a2==b1) continue;
		if(a2==b2) continue;
		
		pair<__int128,__int128> pa={X[a2],X[a2]-X[a1]};
		pair<__int128,__int128> pb={X[b2],X[b2]-X[b1]};
		pair<__int128,__int128> ya=hoge({Y[a2],1},{Y[a1],1},pa);
		pair<__int128,__int128> yb=hoge({Y[b2],1},{Y[b1],1},pb);
		pair<__int128,__int128> za=hoge({Z[a2],1},{Z[a1],1},pa);
		pair<__int128,__int128> zb=hoge({Z[b2],1},{Z[b1],1},pb);
		if(ya==yb&&za==zb) continue;
		pair<__int128,__int128> dya={Y[a2]-Y[a1],X[a2]-X[a1]};
		pair<__int128,__int128> dyb={Y[b2]-Y[b1],X[b2]-X[b1]};
		pair<__int128,__int128> dza={Z[a2]-Z[a1],X[a2]-X[a1]};
		pair<__int128,__int128> dzb={Z[b2]-Z[b1],X[b2]-X[b1]};
		pair<__int128,__int128> a={0,0},b={0,0};
		if(dza!=dzb) {
			pair<__int128,__int128> zdif={za.first*zb.second-zb.first*za.second,za.second*zb.second};
			pair<__int128,__int128> zdif2={dza.first*dzb.second-dzb.first*dza.second,dza.second*dzb.second};
			a={zdif.first*zdif2.second,zdif.second*zdif2.first};
		}
		if(dya!=dyb) {
			pair<__int128,__int128> ydif={ya.first*yb.second-yb.first*ya.second,ya.second*yb.second};
			pair<__int128,__int128> ydif2={dya.first*dyb.second-dyb.first*dya.second,dya.second*dyb.second};
			b={ydif.first*ydif2.second,ydif.second*ydif2.first};
		}
		if(a.first==0&&b.first==0) continue;
		if(a.first==0) a=b;
		if(b.first==0) b=a;
		if(a.second==0||b.second==0) continue;
		a=normalize(a);
		b=normalize(b);
		if(a!=b) continue;
		if(a.first>0) {
			pair<__int128,__int128> c={X[a2]*a.second+a.first,(X[a2]-X[a1])*a.second};
			pair<__int128,__int128> ty=hoge({Y[a2],1},{Y[a1],1},c);
			pair<__int128,__int128> tz=hoge({Z[a2],1},{Z[a1],1},c);
			mi=min(mi,hoge(-a.first,a.second,ty.first,ty.second,tz.first,tz.second));
		}
	}
	
	FOR(a1,N) FOR(a2,N) {
		if(X[a1]>=X[a2]) continue;
		int dx=X[a2]-X[a1];
		int dy=Y[a2]-Y[a1];
		int dz=Z[a2]-Z[a1];
		int a=2000/dx+1;
		mi=min(mi,hoge(X[a1]-dx*a,1,Y[a1]-dy*a,1,Z[a1]-dz*a,1));
	}
	
	
	cout<<mi<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
