#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;

void printMatrix(int **matrix, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}

void randMatrix(int **matrix, int n, int m){
    srandom(time(nullptr));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = int(random()%2 - 1);
        }
    }
}


int main()
{
    int n = 5, m = 5; // 5,6
    int nf = n + 2, mf = m +2;
    int** matrix = new int*[nf];
    for (int i = 0; i < nf; ++i) {
        matrix[i] = new int[mf];
    }

    randMatrix(matrix, nf, mf);
    for (int i = 0; i < nf; ++i) {
        for (int j = 0; j < mf; ++j) {
            if(i == 0 || i == nf - 1 || j == 0 || j == mf - 1){
                matrix[i][j] = -1;
            }
            /*else{
                matrix[i][j] = 0;
            }*/
        }
    }
   /* matrix[1][3] = -1;
    matrix[2][4] = -1;
    matrix[3][1] = -1;
    matrix[3][4] = -1;
    matrix[4][6] = -1;
    matrix[5][4] = -1;*/

    matrix[1][1] = 1;
    matrix[nf - 2][mf - 2] = 0;


    // Algorithm

    auto *pairs = new pair<int, int>[nf * mf];
    for (int i = 1; i < nf - 1; ++i) {          // To without walls
        for (int j = 1; j < mf - 1; ++j) {
            pairs[i*mf + j] = make_pair(i , j);
        }
    }
    /*for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            cout << pairs[i*mf + j].first << "," << pairs[i*mf + j].second << " ";      // See a range
        }
        cout << endl;
    }*/
    auto *vectors = new vector<int>[nf * mf];
    int for_vec1[2] = {0, nf - 1};
    int for_vec2[2] = {0, mf - 1};
    for (auto i : for_vec1) {
        for (int j = 0; j < mf; ++j) {
            if (i == 0){
                vectors[i*mf + j].push_back(matrix[i + 1][j]);
            }
            else{
                vectors[i*mf + j].push_back(matrix[i - 1][j]);
            }
        }
    }
    for (int i = 0; i < nf; i++) {
        for (auto j : for_vec2) {
            if (i == 0){
                vectors[i*mf + j].push_back(matrix[i][j + 1]);
            }
            else{
                vectors[i*mf + j].push_back(matrix[i][j - 1]);
            }
        }
    }
    for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            vectors[i*mf + j].push_back(matrix[i - 1][j]);
            vectors[i*mf + j].push_back(matrix[i + 1][j]);
            vectors[i*mf + j].push_back(matrix[i][j - 1]);
            vectors[i*mf + j].push_back(matrix[i][j + 1]);
        }
    }
 /*   for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            cout << pairs[i*mf + j].first << "," << pairs[i*mf + j].second << ": ";
            for (int k : vectors[i*mf + j]) {
                cout << k << " ";
            }
            cout << endl;
        }
    }*/

    bool visited[nf*mf];
    for (int i = 0; i < nf*mf; ++i) {
        visited[i] = false;
    }
    visited[mf + 1] = true;
    printMatrix(matrix,nf,mf);
    cout << endl;

    map<int, pair<int, int>> path;
    path[1] = pairs[mf + 1];
    map<int, pair<int, int>>::iterator it;
    int key = 1;
    bool f = true;
    while(f){
        f = false;
        for (int i = 1; i < nf - 1; ++i) {
            for (int j = 1; j < mf - 1; ++j) {
                for (int k = 0; k < vectors[i*mf + j].size(); ++k) {
                    /*cout << "key: " << key << endl;
                    cout << "vectors[" << i*mf + j << "][" << k << "]: " << vectors[i*mf + j][k] << " " << endl;*/
                    if (key == vectors[i*mf + j][k] && !visited[i*mf + j] && matrix[pairs[i*mf + j].first][pairs[i*mf + j].second] != -1){
                        matrix[pairs[i*mf + j].first][pairs[i*mf + j].second] = key + 1;
                        visited[i*mf + j] = true;
                        vectors[(i - 1)*mf + j][k] = key + 1;
                        vectors[(i + 1)*mf + j][k] = key + 1;
                        vectors[i*mf + j - 1][k] = key + 1;
                        vectors[i*mf + j + 1][k] = key + 1;
                        f = true;
                        it = path.find(key + 1);
                        if (it == path.end()){///////////////
                            if (fabs(path[key].first - pairs[i*mf + j].first) < 2 && fabs(path[key].second - pairs[i*mf + j].second) < 2){
                                path[key + 1] = pairs[i*mf + j];
//                                cout << "key: " << key + 1 << ", " << "pair: " << pairs[i*mf + j].first << "," << pairs[i*mf + j].second << endl;
                            }
                        }
//                        cout << "pairs[" << i*mf + j << "].first: " << pairs[i*mf + j].first << " " << "pairs[" << i*mf + j << "].second: " << pairs[i*mf + j].second << endl;
                    }
                }
            }
        }
        key++;
        if (matrix[nf - 2][mf - 2] != 0){
            f = false;
        }
    }
//    if (matrix[nf - 2][mf - 2] != 0){
        map <int, pair<int, int>> path2;
        map <int, pair<int, int>>::iterator it2;
        int kk = matrix[nf - 2][mf - 2];
        path2[kk] = pairs[(nf - 2)*mf + mf - 2];
        kk = kk - 1;
//        for (int i = 1; i < nf - 1; ++i) {
//            for (int j = 1; j < mf - 1; ++j) {
        for (int i = nf - 2; i > 0; --i) {
            for (int j = mf - 2; j > 0; --j) {
                if (kk == matrix[i][j]){
//                    cout << "kk: " << kk << ",  pairs[" << (/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j) << "].first:" << pairs[(/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j)].first << ",  pairs[" << (/*nf - 1 - */i)*mf + (/*mf - 1 -*/ j) << "].second:" << pairs[(/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j)].second << endl;
//                    cout << "path2[" << kk + 1 << "].first:" << path2[kk + 1].first << ", path2[" << kk + 1 << "].second:" << path2[kk + 1].second << endl;
                    if (fabs(path2[kk + 1].first - pairs[(/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j)].first) < 2 && fabs(path2[kk + 1].second - pairs[(/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j)].second) < 2){
                        path2[kk] = pairs[(/*nf - 1 -*/ i)*mf + (/*mf - 1 -*/ j)];
                        kk--;
                    }
                }
            }
        }
//    }

    printMatrix(matrix, nf, mf);

    cout << "path:  ";
    for (it = path.begin(); it != path.end(); ++it) {
        cout << it->first << ":" << it->second.first << "," << it->second.second << " ";
    }
    cout << endl;
    cout << "path2:   ";
    for (it2 = path2.begin(); it2 != path2.end(); ++it2) {
        cout << it2->first << ":" << it2->second.first << "," << it2->second.second << " ";
    }

  /*  for (int i = 0; i < nf*mf; ++i) {
        if(i%8 == 0 && i != 0){
            cout << endl;
        }
        cout << visited[i] << " ";
    }
    cout << endl;
    for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            cout << pairs[i*mf + j].first << "," << pairs[i*mf + j].second << ": ";
            for (int k : vectors[i*mf + j]) {
                cout << k << " ";
            }
            cout << endl;
        }
    }
*/

//    for (int i = 0; i < mf; ++i) {
//        delete[] matrix[i];
//    }
    delete[] matrix;
    delete[] vectors;
    delete[] pairs;

    return 0;
}
