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


int H,N;
int P[1<<19];
const ll mo=1000000007;
vector<pair<int,pair<ll,ll>>> V;
vector<pair<int,pair<ll,ll>>> V2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H;
	N=1<<H;
	FOR(i,N-1) {
		//x=i+1;
		cin>>x;
		P[(1<<(H-1))+i]=x+(1<<(H-1))-1;
	}
	//srand(time(NULL));
	//random_shuffle(P+(1<<(H-1)),P+(2<<(H-1)));
	//for(i=(1<<(H-1));i<1<<H;i++) cout<<i<<" "<<P[i]<<endl;
	
	
	ll ret=0;
	for(i=1;i<1<<(H-1);i++) {
		int cur=i;
		//cout<<i<<endl;
		V.clear();
		V.push_back({2*cur,{1LL*cur*(2*cur)%mo,0LL}});
		V.push_back({2*cur+1,{0LL,(2*cur+1)}});
		while(V[0].first<1<<(H-1)) {
			V2.clear();
			FORR(a,V) {
				V2.push_back({2*a.first,{a.second.first*1LL*a.first*2%mo,a.second.second*1LL*a.first*2%mo}});
				V2.push_back({2*a.first+1,{a.second.first*1LL*(a.first*2+1)%mo,a.second.second*1LL*(a.first*2+1)%mo}});
			}
			swap(V,V2);
		}
		FORR(v,V) {
			v.first=P[v.first];
			//cout<<v.first<<":"<<v.second.first<<":"<<v.second.second<<" -> ";
			v.second.first=v.second.first*v.first%mo;
			v.second.second=v.second.second*v.first%mo;
			//cout<<v.first<<":"<<v.second.first<<":"<<v.second.second<<endl;
		}
		sort(ALL(V));
		while(V.size()>1) {
			V2.clear();
			FOR(j,V.size()) {
				x=V[j].first/2;
				if(j+1<V.size() && V[j].first/2==V[j+1].first/2) {
					ret+=(V[j].second.first*V[j+1].second.second+V[j].second.second*V[j+1].second.first)%mo*x%mo;
					V2.push_back({x,{(V[j].second.first+V[j+1].second.first)*x%mo,(V[j].second.second+V[j+1].second.second)*x%mo}});
					j++;
				}
				else {
					V2.push_back({x,{V[j].second.first*x%mo,V[j].second.second*x%mo}});
				}
			}
			swap(V,V2);
			
		}
		//cout<<i<<" "<<ret<<endl;
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
