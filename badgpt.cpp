#include <bits/stdc++.h>
using namespace std;
constexpr uint64_t MOD =  1e9 + 7;
constexpr int KMAX = 2;

//precizare: am impartit toate numerele la MOD
void multiply_matrix(uint64_t A[KMAX][KMAX], uint64_t B[KMAX][KMAX], uint64_t C[KMAX][KMAX]) {
    uint64_t tmp[KMAX][KMAX];
 
    for (int i = 0; i < KMAX; ++i) {
        for (int j = 0; j < KMAX; ++j) {
            uint64_t sum = 0; // presupun că suma încape pe 64 de biți
 
            for (int k = 0; k < KMAX; ++k) {
                sum += A[i][k] % MOD * B[k][j] % MOD;
            }
 
            tmp[i][j] = sum % MOD;
        }
    }
 
    //  C = tmp
    memcpy(C, tmp, sizeof(tmp));
}
 
// R = C^p
void power_matrix(uint64_t C[KMAX][KMAX], uint64_t p, uint64_t R[KMAX][KMAX]) {
    // tmp = I (matricea identitate)
    uint64_t tmp[KMAX][KMAX];
    for (int i = 0; i < KMAX; ++i) {
        for (int j = 0; j < KMAX; ++j) {
            tmp[i][j] = (i == j) ? 1 : 0;
        }
    }
 
    while (p != 1) {
        if  (p % 2 == 0) {
            multiply_matrix(C, C, C);     // C = C*C
            p /= 2;                       // rămâne de calculat C^(p/2)
        } else {
            // reduc la cazul anterior:
            multiply_matrix(tmp, C, tmp); // tmp = tmp*C
            --p;                          // rămâne de calculat C^(p-1)
        }
    }
 
    // avem o parte din rezultat în C și o parte în tmp
    multiply_matrix(C, tmp, R);           // rezultat = tmp * C
}
 
uint64_t fibo(uint64_t n) {
    // construiesc matricea C
    //matricea Fibonacci
    uint64_t C[KMAX][KMAX] = {{1, 1}, {1, 0}};
    //am inmultit matricea de n ori
    power_matrix(C, n, C);
 
    // am luat F(n+1) deoarece am F(0) = 0 si astfel s-a decalat cu 1 numarul n cu F-ul sau
    uint64_t sol = C[0][0];
    return sol % MOD;
}

int main(){
    ifstream fin("badgpt.in");
    ofstream fout("badgpt.out");
    //am citit stringul din fisier
    string my_string;
    getline(fin, my_string); 
    //l-am transformat in stream pentru a putea citi gruparile de litera-numar
    stringstream ss(my_string);
    char letter;
    uint64_t number;
    //res = resultat
    uint64_t res = 1;
    while(ss >> letter >> number){
        //daca litera este n sau u inmultit fibonacci de nr respectiv la rezultatul nostru
        if(letter == 'n' || letter == 'u'){
            res *= fibo(number) % MOD;
            res = res % MOD;
            cout << number << " -> fibo: " << fibo(number) << endl; 
        }
    }
    fout << res % MOD;
    return 0;
}