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

int N,M,Q;
vector<pair<int,int>> E[202020];
int X[202020],Y[202020],Z[202020],W[202020];
int R[22][806060];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	vector<int> Vs;
	Vs.push_back(1);
	Vs.push_back(100000001);
	
	FOR(i,M) {
		cin>>x>>y>>k;
		E[x-1].push_back({y,k});
		Vs.push_back(y);
		Vs.push_back(k);
	}
	FOR(i,Q) {
		cin>>X[i]>>Y[i]>>Z[i]>>W[i];
		X[i]--;
		Z[i]--;
		if(Y[i]>W[i]) swap(Y[i],W[i]),swap(X[i],Z[i]);
		Vs.push_back(Y[i]);
		Vs.push_back(W[i]);
	}
	
	
	sort(ALL(Vs));
	Vs.erase(unique(ALL(Vs)),Vs.end());
	FOR(i,N) {
		sort(ALL(E[i]));
		vector<pair<int,int>> V;
		FORR2(a,b,E[i]) {
			a=lower_bound(ALL(Vs),a)-Vs.begin();
			b=lower_bound(ALL(Vs),b)-Vs.begin();
			R[0][a]=max(R[0][a],b);
			if(V.empty() || a>V.back().second) {
				V.push_back({a,b});
			}
			else {
				V.back().second=max(V.back().second,b);
			}
		}
		FORR2(a,b,V) R[0][a]=max(R[0][a],b);
		E[i]=V;
	}
	FOR(i,Vs.size()) if(i) R[0][i]=max({R[0][i],R[0][i-1],i});
	FOR(i,20) {
		FOR(j,Vs.size()) R[i+1][j]=R[i][R[i][j]];
	}
	
	FOR(i,Q) {
		ll sum=W[i]-Y[i];
		x=lower_bound(ALL(Vs),Y[i])-Vs.begin();
		y=lower_bound(ALL(Vs),W[i])-Vs.begin();
		j=lower_bound(ALL(E[X[i]]),make_pair(x+1,0))-E[X[i]].begin();
		if(j&&E[X[i]][j-1].first<=x) x=max(x,E[X[i]][j-1].second);
		j=lower_bound(ALL(E[Z[i]]),make_pair(y+1,0))-E[Z[i]].begin();
		if(j&&E[Z[i]][j-1].second>=y) y=min(y,E[Z[i]][j-1].first);
		
		if(x>=y) {
			cout<<sum+(X[i]!=Z[i])<<endl;
			continue;
		}
		if(R[20][x]<y) {
			cout<<-1<<endl;
			continue;
		}
		for(j=19;j>=0;j--) if(R[j][x]<y) {
			sum+=(1<<j);
			x=R[j][x];
		}
		sum+=2;
		cout<<sum<<endl;
	}
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
