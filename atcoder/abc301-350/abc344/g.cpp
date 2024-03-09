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
ll X[5050],Y[5050];
ll Xs[5050],Ys[5050];
int Q;
ll G0,Ra,Rb;
pair<ll,ll> P[10101010];
int Ps[5050],Pos[5050];

ll nex() {
	G0=48271*G0%((1LL<<31)-1);
	return G0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	pair<ll,int> V[5050];
	FOR(i,N) {
		cin>>Xs[i]>>Ys[i];
		Ys[i]=-Ys[i];
	}
	cin>>Q>>G0>>Ra>>Rb;
	FOR(i,N) {
		V[i]={-Ra*Xs[i]+Ys[i],i};
	}
	sort(V,V+N);
	FOR(i,N) {
		X[i]=Xs[V[i].second],Y[i]=Ys[V[i].second];
		Ps[i]=Pos[i]=i;
	}
	
	vector<pair<ll,pair<int,int>>> ev;
	FOR(x,N) for(y=x+1;y<N;y++) if(X[x]>X[y]) {
		ll y1=-Ra*X[x]+Y[x];
		ll y2=-Ra*X[y]+Y[y];
		ll a=(y2-y1+X[x]-X[y]-1)/(X[x]-X[y])-Ra;
		ev.push_back({a,{x,y}});
	}
	sort(ALL(ev));
	
	
	
	
	FOR(i,Q) {
		ll A=-Ra+(nex()%(2*Ra+1));
		ll B=nex()*((1LL<<31)-1);
		B+=nex();
		B=-Rb+B%(2*Rb+1);
		
		P[i]={A,B};
	}
	sort(P,P+Q);
	ll ret=0;
	int cur=0;
	FOR(i,Q) {
		if(cur<ev.size()&&P[i].first>=ev[cur].first) {
			vector<pair<int,int>> Vs;
			while(cur<ev.size()&&P[i].first>=ev[cur].first) {
				Vs.push_back({Pos[ev[cur].second.first],Pos[ev[cur].second.second]});
				cur++;
			}
			sort(ALL(Vs));
			FORR2(a,b,Vs) {
				a=Ps[a];
				b=Ps[b];
			}
			FORR2(x,y,Vs) {
				while(Pos[x]<Pos[y]) {
					k=Ps[Pos[y]-1];
					swap(Pos[k],Pos[y]);
					Ps[Pos[k]]=k;
					Ps[Pos[y]]=y;
				}
			}
		}
		ll a=P[i].first*X[Ps[0]]+P[i].second+Y[Ps[0]];
		if(a>0) continue;
		int c=0;
		for(x=13;x>=0;x--) if(c+(1<<x)<N) {
			ll a=P[i].first*X[Ps[c+(1<<x)]]+P[i].second+Y[Ps[c+(1<<x)]];
			if(a<=0) c+=1<<x;
		}
		ret+=c+1;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
