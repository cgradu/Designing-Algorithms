#include <bits/stdc++.h>

using namespace std;

uint64_t SolveTask1(vector<int>& a, vector<int>& b) {
    vector<int> aux;
    //am luat un vector auxiliar si am luat toate elementele 
    for(int i = 0; i < (int)a.size(); i++){
    aux.push_back((uint64_t)a[i]);
    aux.push_back((uint64_t)b[i]);
    }
    //am sortat crescator vectorul
    sort(aux.begin(), aux.end());
    uint64_t sum = 0;
    //am luat ultima jumatate de vector deoarece ne dorim maximul dintre elementele acestor 2 vectori deci solutia se afla in ultima jumatate a vectorului creat
    for(int i = (int)aux.size() / 2; i < (int)aux.size(); i++){
        sum += aux[i];
    }
    return sum;
}

uint64_t SolveTask2(vector<int>& a, vector<int>& b, int moves) {
    vector<uint64_t> max_values, min_values;
    //am luat un vector de valori minime si maxime
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] < b[i]){
            max_values.push_back((uint64_t)b[i]);
            min_values.push_back((uint64_t)a[i]);
        }
        else{
            max_values.push_back((uint64_t)a[i]);
            min_values.push_back((uint64_t)b[i]);
        }
    }
    //am sortat crescator vectorul de valori maxime si descrescator cel de valori minime
    sort(max_values.begin(), max_values.end());
    sort(min_values.begin(), min_values.end(), greater<int>());
    uint64_t sum = 0;
    //am schimbat cele mai mici elementele din vectorul de valori maxime cu cele mai mari din vectorul de valori minime in numarul de mutari date
    for(int i = 0; i < (int)max_values.size(); i++){
        if(min_values[i] > max_values[i] && moves != 0){
            max_values[i] = min_values[i];
            moves--;
        }
        sum += max_values[i];
    }
    return sum;
}

int main() {
    ifstream fin("nostory.in");
    ofstream fout("nostory.out");
    //am citit numarul taskului
    int task;
    fin >> task;
    //am citit datele problemei
    int n, moves;
    if (task == 1) {
        fin >> n;
    } 
    else {
        fin >> n >> moves;
    }
    //am citit vectorii
    int elem;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        fin >> elem;
        a[i] = elem;
    }
    
    for(int i = 0; i < n; i++){
        fin >> elem;
        b[i] = elem;
    }
    //am folosit fucntiile create pentru a oferi rezolvarea taskului cerut
    if(task == 1){
        uint64_t res = SolveTask1(a ,b);
        fout << res << "\n";
    }
    else{
        uint64_t res = SolveTask2(a ,b, moves);
        fout << res << "\n";
    }

    return 0;
}