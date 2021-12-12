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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

const int NUMC=26;
class Trie {
public:
	vector<vector<int> > V;
	vector<int> C;
	vector<int> C2;
	string ask(int p) {
		int cur=0;
		string R="";
		while(p) {
			if(C2[cur]) p--;
			if(p==0) break;
			int i;
			for(i=1;i<=26;i++) if(V[cur][i]) {
				if(C[V[cur][i]]<p) {
					p-=C[V[cur][i]];
				}
				else {
					R+='a'+(i-1);
					cur=V[cur][i];
					break;
				}
			}
		}
		return R;
	}
	void create(string S) { // 0 is for backtrack
		int cur=0;
		if(V.empty()) {
			V.push_back(vector<int>(NUMC+1));
			C.push_back(0);
			C2.push_back(0);
		}
		FORR(c,S) {
			C[cur]++;
			if(V[cur][c+1]==0) {
				V.push_back(vector<int>(NUMC+1)),V[cur][c+1]=V.size()-1;
				C.push_back(0);
				C2.push_back(0);
			}
			cur=V[cur][c+1];
		}
		C[cur]++;
		C2[cur]++;
	}
};
Trie T[101010];

class SORTracker {
public:
	int pos;
	BIT<int,18> bt;
    SORTracker() {
        pos=0;
        ZERO(bt.bit);
        ZERO(bt.val);
        int i;
        FOR(i,101000) T[i].V.clear();
        FOR(i,101000) T[i].C.clear();
        FOR(i,101000) T[i].C2.clear();
    }
    
    void add(string name, int score) {
		score=100001-score;
        bt.add(score,1);
        FORR(c,name) c-='a';
        T[score].create(name);
    }
    
    string get() {
        pos++;
        int x=bt.lower_bound(pos);
        int cur=pos-bt(x-1);
        
        return T[x].ask(cur);
        
        
        
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
 