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

int N,V;
double X[5050],Y[5050];
ll mask[5050];
double T[5050];

pair<double,double> hoge(int a,int b,int c) {
	if(a==b || a==c) return {1e10,1e10};
	double mi=1e10;
	double L=0,R=1;
	int i;
	FOR(i,100) {
		double M1=(2*L+R)/3;
		double M2=(2*R+L)/3;
		double X1=X[b]+(X[c]-X[b])*M1;
		double Y1=Y[b]+(Y[c]-Y[b])*M1;
		double X2=X[b]+(X[c]-X[b])*M2;
		double Y2=Y[b]+(Y[c]-Y[b])*M2;
		double D1=hypot(X[a]-X1,Y[a]-Y1)+hypot(X[c]-X1,Y[c]-Y1)/V;
		double D2=hypot(X[a]-X2,Y[a]-Y2)+hypot(X[c]-X2,Y[c]-Y2)/V;
		
		if(D1<=D2) R=M2;
		if(D2<=D1) L=M1;
		mi=min({mi,D1,D2});
	}
	
	return {X[b]+(X[c]-X[b])*L,Y[b]+(Y[c]-Y[b])*L};
	
}

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>V;
	cin>>X[N]>>Y[N]>>X[N+1]>>Y[N+1];
	
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		mask[i]=1LL<<i;
		if(i) mask[i]|=1LL<<(i-1);
	}
	
	int num=N+2;
	FOR(i,N+2) FOR(j,N) {
		if(j) {
			auto a=hoge(i,j-1,j);
			if(a.first!=1e10) {
				X[num]=a.first;
				Y[num]=a.second;
				mask[num]=1LL<<(j-1);
				num++;
			}
		}
		if(j+1<N) {
			auto a=hoge(i,j+1,j);
			if(a.first!=1e10) {
				X[num]=a.first;
				Y[num]=a.second;
				mask[num]=(1LL<<j);
				num++;
			}
		}
	}
	
	FOR(x,num) T[x]=1e10;
	T[N]=0;
	priority_queue<pair<double,int>> Q;
	Q.push({0,N});
	while(Q.size()) {
		double t=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(t!=T[cur]) continue;
		FOR(i,num) {
			double d=hypot(X[i]-X[cur],Y[i]-Y[cur]);
			if(mask[i]&mask[cur]) d/=V;
			if(t+d<T[i]) {
				T[i]=t+d;
				Q.push({-T[i],i});
			}
		}
	}
	_P("%.12lf\n",T[N+1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
