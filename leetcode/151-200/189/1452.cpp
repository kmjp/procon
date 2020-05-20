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


ll mul0,mul1;
vector<ll> pmo[2];
ll mo0=1000000021,mo1=1000000009;
ll add0=1000010007, add1=1003333331;

struct RollingHash {
	string s; int l; vector<ll> hash_[2];
	void init(string s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0)>>5)%259,mul1=10007+(((ll)&mul1)>>5)%257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	pair<ll,ll> hash(int l,int r) { // s[l..r]
		if(l>r) return make_pair(0,0);
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0,
			             (hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	pair<ll,ll> hash(string s) { init(s); return hash(0,s.size()-1); }
	static pair<ll,ll> concat(pair<ll,ll> L,pair<ll,ll> R,int RL) { // hash(L+R) RL=len-of-R
		while(pmo[0].size()<RL+2) pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return make_pair((R.first + L.first*pmo[0][RL])%mo0,(R.second + L.second*pmo[1][RL])%mo1);
	}
};

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& C) {
		set<pair<ll,ll>> S[101];
		RollingHash rh;
		int i;
		FOR(i,C.size()) {
			FORR(v,C[i]) {
				pair<ll,ll> a=rh.hash(v);
				//S[i].insert((a.first<<32)||a.second);
				S[i].insert(rh.hash(v));
			}
		}
		vector<int> R;
		FOR(i,C.size()) {
			int inc=0;
			int j;
			FOR(j,C.size()) if(C[j].size()>C[i].size()) {
				if(inc) break;
				int ok=1;
				FORR(v,S[i]) if(S[j].count(v)==0) {
					ok=0;
					break;
				}
				if(ok) inc=1;
			}
			if(inc==0) R.push_back(i);
		}
        return R;
    }
};

