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

int N;
int A[101010];
map<int,int> M;

ll hoge() {
	int pre;
	int first=1;
	ll w,left=0;
	ll ret=0;
	int i;
	FORR(m,M) {
		if(first==1) {
			w=m.second;
			first=0;
		}
		else {
			int dif=abs(pre+m.first);
			if(left>w) {
				if(left==w*2) {
					ret+=w*dif;
				}
				else {
					FOR(i,dif) {
						if(left<=w) {
							left=0;
							break;
						}
						ret+=left-w;
						left=(left-w)*2;
						if(left>w*2) return -1;
					}
				}
			}
			else {
				left=0;
			}
			left+=m.second;
		}
		pre=-m.first;
	}
	if(left>w) {
		if(left>=w*2) return -1;
		FOR(i,pre) {
			if(left<=w) {
				left=0;
				break;
			}
			ret+=left-w;
			left=(left-w)*2;
			if(left>w*2) return -1;
		}
		if(left) return -1;
	}
	
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, M[-x]++;
	
	ll ret=1LL<<60,step=0;
	while(M.size()>1) {
		if(step>ret) break;
		ll tmp=hoge();
		if(tmp>=0) {
			ret=min(ret,step+tmp);
		}
		auto it=M.begin();
		step+=it->second;
		M[it->first+1]+=it->second*2;
		M.erase(M.begin());
	}
	ret=min(ret,step);
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
