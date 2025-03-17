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



class Spreadsheet {
public:
	map<int,int> M[26];
    Spreadsheet(int rows) {
        int i;
        FOR(i,26) M[i].clear();
    }
    
    void setCell(string cell, int value) {
        int a=cell[0]-'A';
        int b=atoi(cell.substr(1).c_str());
        M[a][b]=value;
    }
    
    void resetCell(string cell) {
        setCell(cell,0);
    }
    int getvalue(string cell) {
		if(cell[0]>='A'&&cell[0]<='Z') {
	        int a=cell[0]-'A';
	        int b=atoi(cell.substr(1).c_str());
	        return M[a][b];
		}
		return atoi(cell.c_str());
	}
    int getValue(string formula) {
        formula=formula.substr(1);
        int i;
        FOR(i,formula.size()) if(formula[i]=='+') {
			return getvalue(formula.substr(0,i))+getvalue(formula.substr(i+1));
		}
		return 0;
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
 
 
 