#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.txt");
#define all(a) a.begin(),a.end()
#define isz(a) (int)a.size()

void part1(){
    vector<string> m;
    for(string s; getline(fin,s); m.push_back(s));
    vector<string> res(isz(m),m[0]);
     
    char t, t2;
    int difi, difj;
    uint64_t ans{};
    for (int i = 0; i < isz(m); ++i){
        for(int j = 0; j < isz(m[0]); ++j){
            if(m[i][j] == '.' || m[i][j] == '#') continue;
            t = m[i][j];
            for(int k = 0; k < isz(m); ++k){
                for(int l = 0; l < isz(m[0]); ++l){
                    if(i == k && j == l) continue;
                    if(m[i][j] == '.' || m[i][j] == '#') continue;
                    t2 = m[k][l];
                    if (t2 != t) continue;
                    if(2*i - k >= 0 && 2*i - k < isz(m) &&
                        2*j - l >= 0 && 2*j - l < isz(m[0]) &&
                        res[2*i - k][2*j - l] == '.'){     
                            res[2*i - k][2*j - l] = '#';
                            ans++;
                    }
                    if(2*k - i >= 0 && 2*k - i < isz(m) &&
                        2*l - j >= 0 && 2*l - j <= isz(m[0]) &&
                        res[2*k - i][2*l - j] == '.'){ 
                            res[2*k - i][2*l - j] = '#';
                            ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

void print(vector<string> &v){
    for (auto s : v){
        cout << s << endl;
    }
}

void part2(){
    vector<string> m;
    for(string s; getline(fin,s); m.push_back(s));
    vector<string> res(isz(m),m[0]);
     
    char t, t2;
    int difi, difj;
    uint64_t ans{};
    for (int i = 0; i < isz(m); ++i){
        for(int j = 0; j < isz(m[0]); ++j){
            if(m[i][j] == '.' || m[i][j] == '#') continue;
            t = m[i][j];
            
            for(int k = 0; k < isz(m); ++k){
                for(int l = 0; l < isz(m[0]); ++l){
                    if(i == k && j == l) continue;
                    if(m[i][j] == '.' || m[i][j] == '#') continue;
                    t2 = m[k][l];
                    if (t2 != t) continue;
                    res[i][j] = '#';
                    res[k][l] = '#';
                    int dif_ik = i-k;
                    int dif_jl = j-l; 
                    for(int ir = i, jr = j;ir + dif_ik >= 0 && ir + dif_ik < isz(m) &&
                        jr + dif_jl >= 0 && jr + dif_jl < isz(m[0]);){
                        if(res[ir + dif_ik][jr + dif_jl] == '.'){     
                            res[ir + dif_ik][jr + dif_jl] = '#';
                        }
                        ir += dif_ik;
                        jr += dif_jl;       
                    }
                    for(int kr = k, lr = l;kr - dif_ik >= 0 && kr - dif_ik < isz(m) &&
                        lr - dif_jl >= 0 && lr - dif_jl <= isz(m[0]);){
                            if(res[k -  dif_ik][l - dif_jl] == '.'){ 
                                res[k -  dif_ik][l - dif_jl] = '#';
                            }
                        kr -=  dif_ik;
                        lr -= dif_jl;
                    }
                }
            }
        }
    }
    for(string s : res){
        for(char c : s){
            if (c == '#') ans++;
        }
    }
    cout << ans << endl;
    
}
int main(){
    part2();

}