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


class MovieRentingSystem {
public:
	map<int,set<pair<int,int>>> M;
	set<vector<int>> R;
	map<pair<int,int>,int> S;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        M.clear();
        S.clear();
        R.clear();
        FORR(v,entries) {
			M[v[1]].insert({v[2],v[0]});
			S[{v[0],v[1]}]=v[2];
		}
    }
    
    vector<int> search(int movie) {
        vector<int> ret;
        FORR(r,M[movie]) {
			ret.push_back(r.second);
			if(ret.size()==5) break;
		}
		return ret;
    }
    
    void rent(int shop, int movie) {
        int a=S[{shop,movie}];
        M[movie].erase({a,shop});
        R.insert({a,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int a=S[{shop,movie}];
        M[movie].insert({a,shop});
        R.erase({a,shop,movie});
        
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ret;
        FORR(r,R) {
			ret.push_back({r[1],r[2]});
			if(ret.size()==5) break;
		}
		return ret;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
 