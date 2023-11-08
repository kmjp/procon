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

int T,N;
string S;
int P[402020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> num,sum;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		FOR(i,N+3) {
			num.add(i,-num(i));
			sum.add(i,-sum(i));
		}
		
		ll ret=0;
		vector<pair<ll,ll>> V;
		ll cur=201010;
		V.push_back({cur,0});
		FOR(i,N) {
			if(S[i]=='(') cur++;
			else cur--;
			V.push_back({cur,i+1});
		}
		sort(ALL(V));
		reverse(ALL(V));
		FORR2(v,i,V) {
			ret+=(sum(N+1)-sum(i))-v*(num(N+1)-num(i));
			sum.add(i,v);
			num.add(i,1);
		}
		V.clear();
		cur=P[N];
		ll sum=cur;
		V.push_back({cur,N});
		for(i=N-1;i>=0;i--) {
			if(S[i]==')') {
				cur--;
			}
			else {
				cur++;
				x=(int)V.size()-1;
				while(x>=0&&V[x].first<=cur) x--;
				if(x==-1) {
					V.clear();
					sum=1LL*cur*(N-i);
				}
				else {
					for(j=x+1;j<V.size();j++) {
						sum+=1LL*(V[j-1].second-V[j].second)*(cur-V[j].first);
					}
					V.resize(x+1);
					
				}
				
			}
			V.push_back({cur,i});
			/*
			cout<<i<<" "<<S[i]<<" "<<cur<<" "<<sum<<" "<<(sum-(N-i)*cur)<<"  :: ";
			FORR2(a,b,V) cout<<a<<":"<<b<<" ";
			cout<<endl;
			*/
			ret+=sum-1LL*(N-i)*cur;
			sum+=cur;
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
