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


int N,S,T;
ll X[101010],Y[101010];
ll C[101010];
ll D[101010];

map<ll,ll> M;

void add(ll y,ll d) {
	auto it=M.lower_bound(y+1);
	it--;
	if(it->second<=d) return;
	M[y]=d;
	while(1) {
		auto it=M.lower_bound(y+1);
		if(it==M.end()) break;
		if(it->second<d) break;
		M.erase(it);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	S--,T--;
	vector<vector<ll>> Xs;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
		Y[i]=(Y[i]*2000000000)+X[i];
		Xs.push_back({X[i],Y[i],i});
		D[i]=1LL<<60;
	}
	if(X[S]>X[T] || (X[S]==X[T] && Y[S]>Y[T])) swap(S,T);
	
	if(X[S]<=X[T] && Y[S]<=Y[T]) {
		ll ret=C[T];
		FOR(i,N) if(X[T]<=X[i] && Y[T]<=Y[i]) ret=min(ret,C[i]*2);
		cout<<ret<<endl;
		return;
	}
	
	sort(ALL(Xs));
	
	M[-1]=1LL<<61;
	ll my=1LL<<60;
	int step=0;
	
	FORR(e,Xs) {
		int cur=e[2];
		//cout<<"!"<<cur<<" "<<X[cur]<<" "<<Y[cur]<<endl;
		if(step==0) {
			if(cur==S) {
				if(my<Y[S]) M[my]=C[cur];
				M[Y[S]]=0;
				step=1;
			}
			else {
				my=min(my,Y[cur]);
			}
		}
		else {
			//FORR(m,M) cout<<m.first<<":"<<m.second<<"  ";
			//cout<<endl;
			auto it=M.lower_bound(Y[cur]);
			it--;
			D[cur]=min(1LL<<60,it->second+C[cur]);
			
			//cout<<cur<<" "<<X[cur]<<" "<<Y[cur]<<"   "<<D[cur]<<endl;
			
			
			add(Y[cur],D[cur]);
			
			it=M.begin();
			it++;
			add(it->first, D[cur]+C[cur]);
			
			if(X[cur]>=X[T] && Y[cur]>=Y[T]) D[T]=min(D[T],D[cur]+C[cur]);
			
		}
	}
	
	cout<<D[T]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
