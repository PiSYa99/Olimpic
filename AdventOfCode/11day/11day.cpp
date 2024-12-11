#include <bits/stdc++.h>

using namespace std;

ifstream fin("in.txt");

#define isz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define leni(a) (int)to_string(a).size()

void print(unordered_map <uint64_t,uint64_t> &m){
    for (auto a : m) {
        for (int i = 0; i < a.second; i++) cout << a.first << ' ';
    }
    cout << endl;
}

void part1(){
    unordered_map<uint64_t, uint64_t> m, t;
    uint64_t ts, pow10, n, n1 , ans = 0, ti = 0;
    for (int te; fin >> te;)m[te]++;

    t = m;
    for (int i = 0; i < 25; i++){
        for (pair<uint64_t,uint64_t> p : m){
            if(p.first == 0){
                t[1] += p.second;
                t[0] -= p.second;
            }
            else if(leni(p.first) % 2 == 0){
                pow10 = pow(10, leni(p.first)/2);
                n = p.first%pow10; 
                n1 = p.first / pow10; 
                t[n] += p.second;
                t[n1] += p.second;
                t[p.first] -= p.second;
            } else {
                t[p.first*2024] += p.second;
                t[p.first] -= p.second;
            }
        }
        m = t;
    }
    for (auto a : m) {
        ans += a.second;
    }
    cout << ans << endl;

}

void part2(){                       
    unordered_map<uint64_t, uint64_t> m, t;
    uint64_t ts, pow10, n, n1 , ans = 0;
    for (int te; fin >> te;)m[te]++;
    t = m;
    for (int i = 0; i < 75; i++){
        for (pair<uint64_t,uint64_t> p : m){
            if(p.first == 0){
                t[1] += p.second;
                t[0] -= p.second;
            }
            else if(leni(p.first) % 2 == 0){
                pow10 = pow(10, leni(p.first)/2);
                n = p.first%pow10; 
                n1 = p.first / pow10; 
                t[n] += p.second;
                t[n1] += p.second;
                t[p.first] -= p.second;
            } else {
                t[p.first*2024] += p.second;
                t[p.first] -= p.second;
            }
        }
        m = t;
    }
    for (auto a : m) {
        ans += a.second;
    }
    cout << ans << endl;
}

int main(){
    part2();        //iT waS Fun,, I wAs SlepPy 
}