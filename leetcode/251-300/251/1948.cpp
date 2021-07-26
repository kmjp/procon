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

struct node {
	vector<string> val;
	ll hash;
	vector<int> children;
	int del;
};
node nodes[101010];
map<vector<string>,int> mp;

using VT = string;

struct RollingHash {
	static const ll mo0=1000000021,mo1=1000000009;
	static ll mul0,mul1;
	static const ll add0=1000010007, add1=1003333331;
	static vector<ll> pmo[2];
	VT s; int l; vector<ll> hash_[2];
	void init(VT s) {
		this->s=s; l=s.size(); int i,j;
		hash_[0]=hash_[1]=vector<ll>(1,0);
		if(!mul0) mul0=10009+(((ll)&mul0+time(NULL))>>5)%1259,mul1=10007+(((ll)&mul1)>>5)%2257;
		if(pmo[0].empty()) pmo[0].push_back(1),pmo[1].push_back(1);
		FOR(i,l) hash_[0].push_back((hash_[0].back()*mul0+add0+s[i])%mo0);
		FOR(i,l) hash_[1].push_back((hash_[1].back()*mul1+add1+s[i])%mo1);
	}
	/*ˆÈ‰ºll”Å*/
	ll hash(int l,int r) { // s[l..r]
		if(l>r) return 0;
		while(pmo[0].size()<r+2)
			pmo[0].push_back(pmo[0].back()*mul0%mo0), pmo[1].push_back(pmo[1].back()*mul1%mo1);
		return (((hash_[0][r+1]+(mo0-hash_[0][l]*pmo[0][r+1-l]%mo0))%mo0)<<32) | 
			             ((hash_[1][r+1]+(mo1-hash_[1][l]*pmo[1][r+1-l]%mo1))%mo1);
	}
	ll hash(VT s) { init(s); return hash(0,s.size()-1); }
};
vector<ll> RollingHash::pmo[2]; ll RollingHash::mul0,RollingHash::mul1;

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000009};
	static vector<ll> prim = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	return (a<<32)+b;
}


RollingHash rh;
vector<vector<string>> VV;
map<ll,int> hashes;


class Solution {
public:
	void dfs(int cur) {
		vector<ll> V,V2;
		FORR(c,nodes[cur].children) {
			V.push_back(nodes[c].hash);
		}
		ll a=tree_normalize(V);
		if(V.size()&&hashes[a]>1) return;
		if(cur) VV.push_back(nodes[cur].val);
		FORR(c,nodes[cur].children) dfs(c);
		
	}
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
		int i;
		FOR(i,paths.size()+10) nodes[i].hash=0, nodes[i].children.clear(),nodes[i].del=0;
		mp.clear();
		vector<string> root={};
		mp[root]=0;
		hashes.clear();
		sort(ALL(paths));
		FORR(p,paths) {
			auto q=p;
			q.pop_back();
			int pa=mp[q];
			int add=mp.size();
			nodes[pa].children.push_back(add);
			mp[p]=add;
			nodes[add].val=p;
			nodes[add].hash=rh.hash(p.back());
		}
		
		for(i=mp.size()-1;i>=0;i--) {
			vector<ll> V,V2;
			V.push_back(nodes[i].hash);
			FORR(c,nodes[i].children) {
				V.push_back(nodes[c].hash);
				V2.push_back(nodes[c].hash);
			}
			nodes[i].hash=tree_normalize(V);
			ll a=tree_normalize(V2);
			hashes[a]++;
		}
		VV.clear();
		dfs(0);
		
		return VV;
    }
};

