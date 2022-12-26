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

int H,W;
string C[24];

ll from[1<<24][2];
ll to[1<<24][2];
const ll mo=1000000007;

vector<int> masks;
vector<int> nmasks;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>C[y];
	/*
	FOR(i,1<<W) {
		j=i&((i<<1)|(i>>1));
		//if(i==j) masks.push_back(i);
		masks.push_back(i);
	}
	*/
	from[0][0]=1;
	masks.push_back(0);
	FOR(y,H) {
		FOR(x,W) {
			nmasks.clear();
			
			
			FORR(mask,masks) if(from[mask][0]||from[mask][1]) {
				if(C[y][x]=='.' && (mask&(1<<x))==0) {
					int nmask=mask|(1<<x);
					if(x) nmask|=1<<(x-1);
					if(x+1<W) nmask|=1<<(x+1);
					to[nmask][1] += from[mask][0];
					nmasks.push_back(nmask);
				}
				// not put
				to[mask&((1<<W)-1-(1<<x))][0] += from[mask][0];
				to[mask|(1<<x)][0] += from[mask][1];
				nmasks.push_back(mask|(1<<x));
				nmasks.push_back(mask&((1<<W)-1-(1<<x)));
			}
			sort(ALL(nmasks));
			nmasks.erase(unique(ALL(nmasks)),nmasks.end());
			
			FORR(mask,nmasks) {
				from[mask][0]=to[mask][0]%mo;
				from[mask][1]=to[mask][1]%mo;
				to[mask][0]=to[mask][1]=0;
			}
			swap(masks,nmasks);
		}
		
		FORR(mask,masks) {
			from[mask][0]+=from[mask][1];
			from[mask][1]=0;
		}
	}
	ll ret=0;
	FORR(mask,masks) {
		ret+=from[mask][0];
		//cout<<mask<<" "<<from[mask][0]<<endl;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
