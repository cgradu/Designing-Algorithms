#include <bits/stdc++.h>

using namespace std;

int task1(int n, int m, int x, vector <int>& p, vector <vector <int> >& g) {
	//vecrtor pentru nota adusa la solutie de fiecare platou
	vector<int> max_grade(m + 1);
	int i,j;
	//am calculat nota pe care o aduce fiecare platou
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			max_grade[i] += g[j][i];
		}
	}
	int max_buget = n * x; // bugetul maxim
	int item, price;
	//vecrtorul dp de solutii
    vector<vector<int> > dp(m + 1, vector<int>(max_buget + 1, 0));
	//pentru primul platou 0 am pus toate solutiile pe 0
	for(price = 0; price <= max_buget; price++){
		dp[0][price] = 0;
	}
	//am egalat solutia curenta cu solutia precedenta si am verificat daca putem adauga platoul curent la bugetul nostru
	//daca da comparam daca solutia cu platoul luat la nota finala este mai buna decat solutia trecuta
    for (item = 1; item <= m; item++) {
        for (price = 0; price <= max_buget; price++) {
            dp[item][price] = dp[item - 1][price];

			if (price - p[item] >= 0){
                int sol_aux = dp[item - 1][price - p[item]] + max_grade[item];
				dp[item][price] = max(dp[item][price], sol_aux);
			}   
        }
    }
	//solutia finala se afla la bugetul maxim cu toate platourile luate in considerare deci dp[m][max_buget]
    return dp[m][max_buget];
}

//la fel ca la 1
int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	vector<int> max_grade(m + 1);
	int i,j;
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			max_grade[i] += g[j][i];
		}
	}
	int max_buget = n * x;
	int item, price;
    vector<vector<int> > dp(m + 1, vector<int>(max_buget + 1, 0));
	for(price = 0; price <= max_buget; price++) {
		dp[0][price] = 0;
	}
    for (item = 1; item <= m; item++) {
        for (price = 0; price <= max_buget; price++) {
            dp[item][price] = dp[item - 1][price];

			if (price - p[item] >= 0){
                int sol_aux = dp[item - 1][price - p[item]] + max_grade[item];
				dp[item][price] = max(dp[item][price], sol_aux);
			}
			//verificam daca putem sa luam si 2 platouri
			if (price - 2 * p[item] >= 0){
                int sol_aux = dp[item - 1][price - 2 * p[item]] + 2 * max_grade[item];
				dp[item][price] = max(dp[item][price], sol_aux);
			}   
        }
    }
    return dp[m][max_buget];
}

//am incercat dar nu a iesit..:)))
int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	vector<int> max_grade(m + 1);
	int i,j;
	for(i = 1; i <= m; i++){
		for(j = 1; j <= n; j++){
			max_grade[i] += g[j][i];
		}
	}
	int max_buget = n * x;
	int item, price, count = 0;
    vector< vector<int> > dp(m + 1, vector<int>(max_buget + 1, 0));
	vector<int> sol;
	for(price = 0; price <= max_buget; price++){
		dp[0][price] = 0;
	}
    for (item = 1; item <= m; item++) {
		for (price = 0; price <= max_buget; price++) {
			dp[item][price] = dp[item - 1][price];

			if (price - p[item] >= 0){
                int sol_aux = dp[item - 1][price - p[item]] + max_grade[item];
				if(sol_aux > dp[item][price] && count + 1 <= n){
				dp[item][price] = sol_aux;
				count += 1;
				if(count == n){
				sol.push_back(dp[item][price]);
				count = 0;
				}
				}
			}

			if (price - 2 * p[item] >= 0 ){
                int sol_aux = dp[item - 1][price - 2 * p[item]] + 2 * max_grade[item];
				if(sol_aux > dp[item][price] && count + 2 <= n){
				dp[item][price] = sol_aux;
				count += 2;
				if(count == n){
				sol.push_back(dp[item][price]);
				count = 0;
				}
				}
			}   
        }
    }
	sort(sol.begin(), sol.end(), greater<int>());
    return sol[0];
}

int main() {
	ifstream fin("sushi.in");
	ofstream fout("sushi.out");

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	fin >> task;
	fin >> n >> m >> x;

	prices.assign(m + 1, 0);
	grades.assign(n + 1, vector <int> (m + 1, 0));

	// price of each sushi
	for(int i = 1; i <= m; ++i) {
		fin >> prices[i];
	}

	// each friends rankings of sushi types
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			fin >> grades[i][j];
		}
	}

	int ans = -1;

	switch(task) {
		case 1:
			ans = task1(n, m, x, prices, grades);
			break;
		case 2:
			ans = task2(n, m, x, prices, grades);
			break;
		case 3:
			ans = task3(n, m, x, prices, grades);
			break;
		default:
			cout << "wrong task number" << endl;
	}

	fout << ans << endl;

	return 0;
}
