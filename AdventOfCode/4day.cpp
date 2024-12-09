#include <bits/stdc++.h>

using namespace std;

#define isize(a) (int)a.size()
#define all(a) a.begin(),a.end()

ifstream fin("in.txt");


void part1(){
    vector<string> v;

    for(string s; getline(fin,s);) v.push_back(s);
    uint64_t count = 0; 
    string s;

    for (int i = 0; i < isize(v); ++i){
        for(int j = 0; j < isize(v[0]); ++ j){
            if(j < isize(v[0])-3 && (v[i].substr(j,4) == "XMAS" || v[i].substr(j,4) == "SAMX")){
                count++;
                
            }
            if(i < isize(v)-3){
                string s({v[i][j],v[i+1][j],v[i+2][j],v[i+3][j]});
                
                if(s == "XMAS" || s == "SAMX") count++;
            }
            if(i < isize(v)-3 && j < isize(v[0])-3){
                string s({v[i][j],v[i+1][j+1],v[i+2][j+2],v[i+3][j+3]});
                
                if(s == "XMAS" || s == "SAMX") count++;
            }
            if(i < isize(v)-3 && j >= 3){
                string s({v[i][j],v[i+1][j-1],v[i+2][j-2],v[i+3][j-3]});
                
                if(s == "XMAS" || s == "SAMX") count++;
            } 

        
        }

    }
    cout << count;


}

void part2(){
    vector<string> v;

    for(string s; getline(fin,s);) v.push_back(s);
    uint64_t count = 0; 
    string s;

    for (int i = 1; i < isize(v)-1; ++i){
        for(int j = 1; j < isize(v[0])-1; ++ j){
            if(v[i][j] == 'A'){
                string slr ({v[i-1][j-1],v[i][j],v[i+1][j+1]});
                string srl ({v[i-1][j+1],v[i][j],v[i+1][j-1]});
                if((slr == "SAM" || slr == "MAS")&&(srl == "SAM" || srl == "MAS"))
                    count++;
            }
        }
    }
    cout << count;
}


int main(){
    part2();

}