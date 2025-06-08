

#include <iostream>
#include <vector>
using namespace std;

void Floyd_Warshall(int degree) {
    std::vector<std::vector<int>> arr(degree, std::vector<int>(degree));
    for (int i = 0;i < degree; i++) {
        for (int i2 = 0;i2 < degree;i2++) {
            cin >> arr[i][i2];
        }
    }
    for (int i = 0;i < degree;i++) {
        for (int x = 0;x < degree;x++) {
            for (int y = 0;y < degree;y++) {
                if (x != i && y != i) {
                    if (arr[x][i]!=-1 && arr[i][y]!=-1){
                        cout << "1st if";
                        cout << "1st element " << arr[x][i] << endl;
                        cout << "2nd element " << arr[i][y] << endl;
                        cout << "compared to " << arr[x][y] << endl;
                        if (arr[x][i] + arr[i][y] < arr[x][y]) {
                            cout << "2nd if";
                            arr[x][y] = arr[x][i] + arr[i][y];
                        }
                        else if (arr[x][y] == -1) {
                            arr[x][y] = arr[x][i] + arr[i][y];
                        }
                    }
                }
            }
        }
    }
    for (int x = 0;x < degree;x++) {
        cout << endl;
        for (int y = 0;y < degree;y++) {
            cout << arr[x][y] << " ";
        }
    }
}
int main()
{
    cout << "Enter matrix degree" << endl;
    int degree;
    cin >> degree;
    Floyd_Warshall(degree);
}

