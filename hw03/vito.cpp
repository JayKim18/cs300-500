#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int minimal_distance(vector<int>& street_numbers) {
    sort(street_numbers.begin(), street_numbers.end());
    int median = street_numbers[street_numbers.size() / 2];
    int total_distance = 0;
    
    for (int s : street_numbers) {
        total_distance += abs(median - s);
    }
    
    return total_distance;
}

int main() {
    int num_cases;
    cin >> num_cases;

    while (num_cases--) {
        int r;
        cin >> r;
        vector<int> street_numbers(r);
        
        for (int i = 0; i < r; ++i) {
            cin >> street_numbers[i];
        }

        cout << minimal_distance(street_numbers) << endl;
    }

    return 0;
}
