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

ll H,W;
int N;
set<pair<int,int>> S;
vector<ll> Rs,Cs;
ll NR,NC;
ll weight[1010][1010];
ll ret;
ll mo=1000000007;
int D[100][100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll r2=(mo+1)/2;
	ll r3=(mo+1)/3;
	
	cin>>H>>W>>N;
	Rs.push_back(0);
	Rs.push_back(H);
	Cs.push_back(0);
	Cs.push_back(W);
	FOR(i,N) {
		cin>>y>>x;
		Rs.push_back(y);
		Rs.push_back(y+1);
		Cs.push_back(x);
		Cs.push_back(x+1);
		S.insert({y,x});
	}
	sort(ALL(Rs));
	sort(ALL(Cs));
	Rs.erase(unique(ALL(Rs)),Rs.end());
	Cs.erase(unique(ALL(Cs)),Cs.end());
	
	NR=Rs.size()-1;
	NC=Cs.size()-1;
	FOR(y,NR) FOR(x,NC) {
		weight[y][x]=(Rs[y+1]-Rs[y])*(Cs[x+1]-Cs[x])%mo;
		if(S.count({Rs[y],Cs[x]})) weight[y][x]=0;
	}
	
	FOR(y,NR) {
		ll t=Rs[y+1]-Rs[y];
		ll L=0,R=0;
		FOR(x,NC) {
			FOR(i,y) L+=weight[i][x];
			for(i=y+1;i<NR;i++) R+=weight[i][x];
		}
		(ret+=(L%mo)*(R%mo)%mo*(t-1))%=mo;
		(ret+=(W%mo)*((L+R)%mo)%mo*((t*(t-1)/2)%mo))%=mo;
		(ret+=W*W%mo*t%mo*(t+1)%mo*r2%mo*r2%mo*(((2*t+1)*r3+mo-1)%mo))%=mo;
	}
	FOR(x,NC) {
		ll t=Cs[x+1]-Cs[x];
		ll L=0,R=0;
		FOR(y,NR) {
			FOR(i,x) L+=weight[y][i];
			for(i=x+1;i<NC;i++) R+=weight[y][i];
		}
		(ret+=(L%mo)*(R%mo)%mo*(t-1))%=mo;
		(ret+=(H%mo)*((L+R)%mo)%mo*((t*(t-1)/2)%mo))%=mo;
		(ret+=H*H%mo*t%mo*(t+1)%mo*r2%mo*r2%mo*(((2*t+1)*r3+mo-1)%mo))%=mo;
	}
	
	FOR(y,NR) FOR(x,NC) if(weight[y][x]) {
		int cy,cx,ty,tx;
		FOR(ty,NR) FOR(tx,NC) D[ty][tx]=101010;
		queue<int> Q;
		D[y][x]=0;
		Q.push(y*100+x);
		while(Q.size()) {
			cy=Q.front()/100;
			cx=Q.front()%100;
			Q.pop();
			
			int d[4]={1,0,-1,0};
			FOR(i,4) {
				ty=cy+d[i];
				tx=cx+d[i^1];
				if(ty<0 || ty>=NR || tx<0 || tx>=NC) continue;
				if(weight[ty][tx]==0) continue;
				if(D[ty][tx]<=D[cy][cx]+1) continue;
				D[ty][tx]=D[cy][cx]+1;
				Q.push(ty*100+tx);
				if(y*100+x<ty*100+tx) {
					(ret+=weight[y][x]*weight[ty][tx]%mo*D[ty][tx])%=mo;
				}
			}
		}
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
