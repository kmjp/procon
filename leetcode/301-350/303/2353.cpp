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



class FoodRatings {
public:
	map<string,string> M;
	map<string,int> C;
	map<string,set<pair<int,string>>> S;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int i;
        M.clear();
        S.clear();
        C.clear();
        FOR(i,foods.size()) {
			M[foods[i]]=cuisines[i];
			C[foods[i]]=ratings[i];
			S[cuisines[i]].insert({-ratings[i],foods[i]});
		}
    }
    
    void changeRating(string food, int newRating) {
		if(M.count(food)==0) return;
		string s=M[food];
		S[s].erase({-C[food],food});
		C[food]=newRating;
		S[s].insert({-C[food],food});
        
    }
    
    string highestRated(string cuisine) {
        return S[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 