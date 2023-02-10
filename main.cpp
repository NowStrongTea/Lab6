#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    system("chcp 1251");
    int amount;
    cout << "enter the number of criteria: ";  // entering the number of criteria
    cin >> amount;
    vector <string> names(amount);
    for (int i = 0; i < amount; i++) {
        cout << "enter a name " << i + 1 << "-th criteria: ";
        cin >> names[i];
    }
    double** nums = new double* [amount];
    for (int i = 0; i < amount; i++) {	//
        nums[i] = new double[amount];
    }
    for (int i = 0; i < amount; i++) {	// filling in the matrix
        for (int j = 0; j < amount; j++) {
            if (i == j) {
                nums[i][j] = 1;
            }
            else if (i < j) {
                while (true) {
                    cout << "enter the comparison coefficient(1-9) " << names[i]<< " s " << names[j] << ": ";	// here are the comparison coefficients
                    cin >> nums[i][j];
                    if ((nums[i][j] > 9) or (nums[i][j] <= 0)) {
                        cout << "enter a number from 1 to 9" << endl;	// error handling
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < amount; i++) {	// counting the inverse values
        for (int j = 0; j < amount; j++) {
            if (i > j) {
                nums[i][j] = 1 / nums[j][i];
            }
        }
    }
    vector<double> vec;
    double sum = 0;
    cout << "the final matrix: " << endl;	// output of the final matrix
    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            cout << setprecision(2) << nums[i][j] << "	";
            sum += nums[i][j];
        }
        vec.push_back(sum); // sum of lines
        sum = 0;
        cout << endl;
    }
    for (int i = 0; i < amount; i++) {	// sum of all matrix values
        sum += vec[i];
    }
    cout << "weight coefficients: ";	//output of weight coefficients
    for (int i = 0; i < amount; i++) {
        cout << i + 1 << " - " << vec[i] / sum << ", ";
    }
}
