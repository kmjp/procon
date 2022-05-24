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

const ll mo=1000000007;

ll LS[202020];
ll L[202020];
ll RS[202020];
ll R[202020];


class Solution {
public:
    int totalStrength(vector<int>& strength) {
		int N=strength.size();
		L[0]=LS[0]=0;
		R[N+1]=RS[N+1]=0;
		int i;
		for(i=1;i<=N;i++) {
			L[i]=(L[i-1]+strength[i-1])%mo;
			(LS[i]=LS[i-1]+L[i])%=mo;
		}
		for(i=N;i>=1;i--) {
			R[i]=(R[i+1]+strength[i-1])%mo;
			(RS[i]=RS[i+1]+R[i])%=mo;
		}
		set<int> S;
		S.insert(0);
		S.insert(N+1);
		vector<pair<int,int>> cand;
		FOR(i,N) cand.push_back({strength[i],i+1});
		sort(ALL(cand));
		
		ll ret=0;
		FORR(a,cand) {
			int cur=a.second;
			S.insert(cur);
			auto it=S.find(cur);
			int pre=*prev(it);
			int nex=*next(it);
			
			ll ri=(LS[nex-1]+mo-LS[cur]-L[cur]*(nex-1-cur)%mo)%mo;
			ll le=(RS[pre+1]+mo-RS[cur]-R[cur]*(cur-(pre+1))%mo)%mo;
			ll la=cur-pre;
			ll lb=nex-cur;
			(ret+=ri*la%mo*strength[cur-1])%=mo;
			(ret+=le*lb%mo*strength[cur-1])%=mo;
			(ret+=la*lb%mo*strength[cur-1]%mo*strength[cur-1])%=mo;
			
		}
		return ret%mo;
		
		
        
    }
};
