#include <bits/stdc++.h>
using namespace std;

bool check_sol(uint64_t mid, uint64_t cars[], int n, int m) {
    //folosit pentru a verifica daca se pot incadra masinile alese pe numarul de feriboturi dat
    int count = 0; 
    //pentru a calcula suma masinilor puse pe un feribot
    uint64_t sum = 0; 
    for (int i = 0; i < n; i++) {
        if (cars[i] > mid) {
            //daca o singura masina este mai grea decat posibila solutie inseamna ca solutia nu este buna
            return false; 
        }
        //altfel adaugam masina la suma 
        sum += cars[i];

        if (sum > mid) {
            //un feribot a fost umplut
            count++;
            //se reseteaza suma cu greutatea masinii curente astfel incat sa nu intre pe falses
            sum = cars[i];
        }
    }
    //avem un singur feribot cu toate masinile
    count++;
    //daca nr de feriboturi folosite pt acesta solutie e mai mic sau egal decat cel cerut inseamna ca solutia e buna
    return count <= m; 
}

uint64_t bs(uint64_t cars[], int n, int m) {
    //valoarea minima a solutiei(greutatea celei mai grele masini)
    uint64_t max_weight = *max_element(cars, cars + n);
    //valoarea maxima a solutiei(greutatea tuturor masinilor)
    uint64_t total_weight = 0;
    for (int i = 0; i < n; i++) {
        total_weight += cars[i];
    }

    uint64_t left = max_weight;
    uint64_t right = total_weight;
    uint64_t res = 0;
    //binary search
    while (left <= right) {
        uint64_t mid = left + (right - left) / 2;

        if (check_sol(mid, cars, n, m)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
}

int main() {
    ifstream fin("feribot.in");
    ofstream fout("feribot.out");
    
    //am citit nr de masini si de feriboturi din fisier
    int nr_car, nr_feribot;
    fin >> nr_car >> nr_feribot;
    //am citit greutatile masinilor intr-un vector
    uint64_t cars[nr_car];
    for(int i = 0; i < nr_car; i++){
        fin >> cars[i];
    }

    fout << bs(cars, nr_car, nr_feribot);

    return 0;
}
