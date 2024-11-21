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

ll H,W,N,M;
ll S,C,SX,SY;
ll X[505050],Y[505050],A[505050];
const ll mo=998244353;
template<class V> V ext_gcd(V p,V q,V& x, V& y) { // get px+qy=gcd(p,q)
	if(q==0) return x=1,y=0,p;
	V g=ext_gcd(q,p%q,y,x);
	y-=p/q*x;
	return g;
}

template<class V> pair<V,V> crt(V a1,V mo1,V a2,V mo2) { // return (x,y) y=lcm(a1,a2),x%mo1=a1,x%mo2=a2
	V g,x,y,z;
	g=ext_gcd(mo1,mo2,x,y);
	a1=(a1%mo1+mo1)%mo1;a2=(a2%mo2+mo2)%mo2;
	if(a1%g != a2%g) return pair<V,V>(-1,0); // N/A
	V lcm=mo1*(mo2/g);
	if(lcm<mo1) return pair<V,V>(-2,0); // overflow
	
	V v=a1+((a2-a1)%lcm+lcm)*x%lcm*(mo1/g);
	return make_pair(((v%lcm)+lcm) % lcm,lcm);
}

vector<vector<ll>> V;
ll na=0,nb=0,cur=0,mi=0;
void out(ll add) {
	SX+=add;
	SY+=add;
	SX%=2*W;
	SY%=2*H;
	if(SX>=W) SX=2*W-SX;
	if(SY>=H) SY=2*H-SY;
	cout<<SX<<" "<<(H-SY)<<" "<<na%mo<<" "<<nb%mo<<endl;
	exit(0);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W>>H>>N>>M>>S>>C>>SX>>SY;
	SY=H-SY;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>A[i];
		Y[i]=H-Y[i];
		A[i+1*N]=A[i];
		A[i+2*N]=A[i];
		A[i+3*N]=A[i];
		X[i+1*N]=X[i];
		X[i+2*N]=2*W-X[i];
		X[i+3*N]=2*W-X[i];
		Y[i+1*N]=2*H-Y[i];
		Y[i+2*N]=2*H-Y[i];
		Y[i+3*N]=Y[i];
	}
	N*=4;
	FOR(i,M) {
		cin>>X[N+i]>>Y[N+i]>>A[N+i];
		Y[N+i]=H-Y[N+i];
		A[N+i]=-A[N+i];
		A[N+i+1*M]=A[N+i];
		A[N+i+2*M]=A[N+i];
		A[N+i+3*M]=A[N+i];
		X[N+i+1*M]=X[N+i];
		X[N+i+2*M]=2*W-X[N+i];
		X[N+i+3*M]=2*W-X[N+i];
		Y[N+i+1*M]=2*H-Y[N+i];
		Y[N+i+2*M]=2*H-Y[N+i];
		Y[N+i+3*M]=Y[N+i];
	}
	M*=4;
	ll a=2*H*W/__gcd(H,W);
	V.push_back({0,0,0});
	V.push_back({a,0,a/H+a/W});
	FOR(i,N+M) {
		if(X[i]<SX) X[i]+=2*W;
		if(Y[i]<SY) Y[i]+=2*H;
		auto p=crt<__int128>(X[i]-SX,2*W,Y[i]-SY,2*H);
		if(p.first>0) {
			V.push_back({(ll)p.first,A[i],(ll)((p.first+SX)/W+(p.first+SY)/H),i});
		}
	}
	sort(ALL(V));
	
	FOR(i,V.size()) if(i) {
		if(V[i][1]>0) na++;
		if(V[i][1]<0) nb++;
		cur-=C*(V[i][2]-V[i-1][2]);
		mi=min(mi,cur);
		cur+=V[i][1];
		mi=min(mi,cur);
	}
	if(S+mi>0&&cur>=0) {
		cout<<-1<<endl;
		return;
	}
	cur=-cur;
	ll step=(S+mi+cur-1)/cur;
	if(cur<=0) step=0;
	S-=cur*step;
	na=step%mo*na%mo;
	nb=step%mo*nb%mo;
	
	FOR(i,V.size()) if(i) {
		if(C*(V[i][2]-V[i-1][2])>=S) {
			ll step=(S+C-1)/C+V[i-1][2];
			ll add=0;
			for(j=62;j>=0;j--) {
				ll ax=SX+add+(1LL<<j);
				ll ay=SY+add+(1LL<<j);
				if(ax/W+ay/H<step) add+=(1LL<<j);
			}
			add++;
			out(add);
			
		}
		S-=C*(V[i][2]-V[i-1][2]);
		if(V[i][1]>0) na++;
		if(V[i][1]<0) nb++;
		S+=V[i][1];
		if(S<=0) {
			out(V[i][0]);
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
