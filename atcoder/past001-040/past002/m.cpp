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

int D,L,N;
vector<int> DS[101010];
vector<ll> num[101010][31];
int K;
ll F,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>L>>N;
	FOR(i,D) {
		cin>>x;
		DS[x].push_back(i);
		DS[x].push_back(i+D);
	}
	FOR(i,101000) if(DS[i].size()) {
		sort(ALL(DS[i]));
		num[i][0].resize(DS[i].size()/2);
		FOR(j,DS[i].size()/2) {
			x=DS[i][j+1]-DS[i][j];
			num[i][0][j]=(x+(L-1))/L;
		}
		FOR(x,30) {
			num[i][x+1].resize(num[i][x].size());
			FOR(j,num[i][x].size()) {
				num[i][x+1][j]=min(1LL<<60,num[i][x][j]+num[i][x][(j+(1<<x))%num[i][0].size()]);
			}
		}
	}
	
		
	FOR(i,N) {
		cin>>K>>F>>T;
		if(DS[K].size()==0) {
			cout<<0<<endl;
			continue;
		}
		F--;
		x=lower_bound(ALL(DS[K]),F)-DS[K].begin();
		ll F2=DS[K][x];
		if(F2!=F) {
			T-=1+(F2-F+L-1)/L;
			if(T<0) {
				cout<<0<<endl;
				continue;
			}
		}
		else {
			T--;
		}
		x%=(DS[K].size()/2);
		ll ret=1;
		for(j=29;j>=0;j--) if(T>=num[K][j][x]) {
			T-=num[K][j][x];
			ret+=1<<j;
			x=(x+(1<<j))%(DS[K].size()/2);
		}
		cout<<ret<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
