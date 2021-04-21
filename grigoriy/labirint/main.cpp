#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <ctime>
#include <cmath>
#include <random>
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

void checkMatrix(int **matrix, int n, int m){
    int startRows, startColumns, countRows, countColumns;
    startColumns = -1;
    startRows = -1;
    countColumns = 0;
    countRows = 0;
    for (int i = 2; i < n - 1; ++i) {
        for (int j = 2; j < m - 1; ++j) {
            if (matrix[i][j] == -1 && matrix[i - 1][j] == -1){
                if(startColumns == -1){
                    startColumns = j;
                }
                countColumns++;
            }
            if (matrix[i][j] == -1 && matrix[i][j - 1] == -1){
                if (startRows == -1){
                    startRows = i;
                }
                countRows++;
            }
            for (int k = startColumns; k < startColumns + countColumns; ++k) {
                matrix[i][k] = 0;
            }
            for (int k = startRows; k < startRows + countRows; ++k) {
                matrix[k][j] = 0;
            }
        }
    }
    if (matrix[1][2] == -1 && matrix[2][1] == -1){
        if ((countRows + countColumns) % 2 == 0){
            matrix[1][2] = 0;
        }
        else{
            matrix[2][1] = 0;
        }
    }
}

class LAB
{
public:
    int **A;
    int N, M;
    int *px;
    int *py;
    int len;
    const int WALL = -1;
    const int SPACE = 0;
    explicit LAB(int n = 1, int m = 1);
    static int randNum(int min, int max) {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(mt);
    }
    void gran() const;
    void DIVISION(int x, int y, int width, int height, int Mwidth, int Mheight);
    ~LAB();
};

LAB::LAB(int n, int m)
{
    N = n;
    M = m;
    len = 0;
    int R = (N) * (M);
    px = new int[R];
    py = new int[R];

    A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
    for (int i = 0; i < R; i++)
    {
        px[i]=0;
        py[i] = 0;
    }
}

void LAB::gran() const
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            A[i][j] = WALL;
        }
    }

    for (int i = 1; i < N-1; i++)
    {
        for (int j = 1; j < M-1; j++)
        {
            // if ((i % 2 != 0)&&(j % 2 !=0)) A[i][j] = 0; //ñîçäà¸ò ïîëå èç êëåòîê
            A[i][j] = SPACE; //îñòàâëÿåò ïóñòîå ïîëå a*b
        }
    }
}

void LAB::DIVISION(int x, int y, int width, int height, int Mwidth, int Mheight)
{
    bool ORIENTATION = true;
    int random1 = randNum(1, 2);
    int random2 = randNum(1, 2);
    //if (width>33) random1= randNum(1, 2);
    //if (height>33) random2 = randNum(1, 2);

    if ((width <= random1) || (height <= random2))
    {
        return;
    }
    if (width > height)
    {
        ORIENTATION = false;
    }
    if (ORIENTATION)
    {
        int Startx = x;
        int Starty = y + height / 2;

        for (int i = 0; i < width; i++)
        {
            A[Startx + i][Starty] = WALL;
        }

        int HoleCount = 0;
        if (Startx - 1 > 0 && A[Startx - 1][Starty] == SPACE)
        {
            HoleCount++;
            A[Startx][Starty] = SPACE;
        }

        if (Startx - 1 > 0 && A[Startx + 1][Starty] == SPACE)
        {
            HoleCount++;
            A[Startx][Starty] = SPACE;
        }

        if (Startx - 1 > 0 && A[Startx][Starty-1] == SPACE)
        {
            HoleCount++;
            A[Startx][Starty] = SPACE;
        }
        if (Startx - 1 > 0 && A[Startx][Starty + 1] == SPACE)
        {
            HoleCount++;
            A[Startx][Starty] = SPACE;
        }
        //print();

        if (Startx + width < Mwidth && A[Startx + width][Starty] == SPACE)
        {
            HoleCount++;
            A[Startx + (width - 1)][Starty] = SPACE;
        }

        /*if (Startx + width < Mwidth && A[Startx + width][Starty+1] == SPACE)
        {
            HoleCount++;
            A[Startx + (width - 1)][Starty] = SPACE;
        }*/ //Ëèøíÿÿ äîãàäêà

        /*if (Startx + width < Mwidth && A[Startx + width][Starty - 1] == SPACE)
        {
            HoleCount++;
            A[Startx + (width - 1)][Starty] = SPACE;
        }*/ //Ëèøíÿÿ äîãàäêà

        if (HoleCount == 0)
        {
            int Holex = Startx + randNum(0, width-1); //rand() % width;
            int Holey = Starty;

            A[Holex][Holey] = SPACE;
        }

        DIVISION(x, y, width, height / 2, Mwidth, Mheight);

        if (height % 2 == 0)
        {
            DIVISION(x, Starty + 1, width, (height / 2) - 1, Mwidth, Mheight);
        }
        else
        {
            DIVISION(x, Starty + 1, width, (height / 2), Mwidth, Mheight);
        }
    }
    else
    {
        int Startx = x + width / 2;
        int Starty = y;

        for (int i = 0; i < height; i++)
        {
            A[Startx][Starty + i] = WALL;
        }

        int VHoleCount = 0;
        if (Starty - 1 > 0 && A[Startx][Starty - 1] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty] = SPACE;
        }

        if (Starty - 1 > 0 && A[Startx][Starty + 1] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty] = SPACE;
        }
        if (Starty - 1 > 0 && A[Startx-1][Starty] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty] = SPACE;
        }
        if (Starty - 1 > 0 && A[Startx+1][Starty] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty] = SPACE;
        }
        //	print();


        if (Starty + height < Mheight && A[Startx][Starty + height] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty + (height - 1)] = SPACE;
        }
        /*if (Starty + height < Mheight && A[Startx-1][Starty + height] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty + (height - 1)] = SPACE;
        }*/ //ÒÅÑÒ

        /*if (Starty + height < Mheight && A[Startx+1][Starty + height] == SPACE)
        {
            VHoleCount++;
            A[Startx][Starty + (height - 1)] = SPACE;
        }*/ //ÒÅÑÒ

        if (VHoleCount == 0)
        {
            int Holex = Startx;
            int Holey = Starty + randNum(0, height-1); //rand() % height;
            A[Holex][Holey] = SPACE;
        }

        DIVISION(x, y, width / 2, height, Mwidth, Mheight);
        if (width % 2 == 0)
        {
            DIVISION(Startx + 1, y, (width / 2) - 1, height, Mwidth, Mheight);
        }
        else
        {
            DIVISION(Startx + 1, y, (width / 2), height, Mwidth, Mheight);
        }

    }
    A[Mwidth][Mheight] = -2;
}

LAB::~LAB()
{
    for (int i = 0; i < N; i++) {
        delete[] A[i];
    }
    delete[] A;
}


int main()
{
    /*int n = 8, m = 8;
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
            else{
                matrix[i][j] = 0;
            }
        }
    }
    matrix[1][3] = -1;
    matrix[2][4] = -1;
    matrix[3][1] = -1;
    matrix[3][4] = -1;
    matrix[4][6] = -1;
    matrix[5][4] = -1;
    printMatrix(matrix,nf,mf);
    cout << endl;
    checkMatrix(matrix,nf,mf);

    matrix[1][1] = 1;
    matrix[nf - 2][mf - 2] = 0;
    printMatrix(matrix,nf,mf);
    cout << endl;
    checkMatrix(matrix,nf,mf);*/

    int n = 100, m = 101;
    int nf = n + 2, mf = m + 2;
    LAB l(nf,mf);
    l.gran();
    l.DIVISION(1,1,n,m,n,m);
    l.A[1][1] = 1;
    l.A[n][m] = 0;
    cout << endl;


    // Algorithm

    auto *pairs = new pair<int, int>[nf * mf];
    for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            pairs[i*mf + j] = make_pair(i , j);
        }
    }
    /*for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            cout << pairs[i*mf + j].first << "," << pairs[i*mf + j].second << " ";
        }
        cout << endl;
    }*/
    auto *vectors = new vector<int>[nf * mf];
    int for_vec1[2] = {0, nf - 1};
    int for_vec2[2] = {0, mf - 1};
    for (auto i : for_vec1) {
        for (int j = 0; j < mf; ++j) {
            if (i == 0){
                vectors[i*mf + j].push_back(l.A[i + 1][j]);
            }
            else{
                vectors[i*mf + j].push_back(l.A[i - 1][j]);
            }
        }
    }
    for (int i = 0; i < nf; i++) {
        for (auto j : for_vec2) {
            if (i == 0){
                vectors[i*mf + j].push_back(l.A[i][j + 1]);
            }
            else{
                vectors[i*mf + j].push_back(l.A[i][j - 1]);
            }
        }
    }
    for (int i = 1; i < nf - 1; ++i) {
        for (int j = 1; j < mf - 1; ++j) {
            vectors[i*mf + j].push_back(l.A[i - 1][j]);
            vectors[i*mf + j].push_back(l.A[i + 1][j]);
            vectors[i*mf + j].push_back(l.A[i][j - 1]);
            vectors[i*mf + j].push_back(l.A[i][j + 1]);
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
//    printMatrix(l.A,nf,mf);
    cout << endl;

    int key = 1;
    bool f = true;
    while(f){
        f = false;
        for (int i = 1; i < nf - 1; ++i) {
            for (int j = 1; j < mf - 1; ++j) {
                for (int k = 0; k < vectors[i*mf + j].size(); ++k) {
                    if (key == vectors[i*mf + j][k] && !visited[i*mf + j] && l.A[pairs[i*mf + j].first][pairs[i*mf + j].second] != -1){
                        l.A[pairs[i*mf + j].first][pairs[i*mf + j].second] = key + 1;
                        visited[i*mf + j] = true;
                        vectors[(i - 1)*mf + j][k] = key + 1;
                        vectors[(i + 1)*mf + j][k] = key + 1;
                        vectors[i*mf + j - 1][k] = key + 1;
                        vectors[i*mf + j + 1][k] = key + 1;
                        f = true;
                    }
                }
            }
        }
        key++;
        if (l.A[nf - 2][mf - 2] != 0){
            f = false;
        }
    }

    printMatrix(l.A, nf, mf);
    cout << endl;

    if (l.A[nf - 2][mf - 2] != 0){
        map <int, pair<int, int>> path;
        map <int, pair<int, int>>::iterator it;
        key = l.A[nf - 2][mf - 2];
        path[key] = pairs[(nf - 2)*mf + mf - 2];
        key = key - 1;
        for (int i = nf - 2; i > 0; --i) {
            for (int j = mf - 2; j > 0; --j) {
                if (key == l.A[i][j]){
                    if (fabs(path[key + 1].first - pairs[i*mf + j].first) < 2 && fabs(path[key + 1].second - pairs[i*mf + j].second) < 2){
                        path[key] = pairs[i*mf + j];
                        key--;
                    }
                }
            }
        }
        cout << "Path: ";
        for (it = path.begin(); it != path.end(); ++it) {
            cout << it->first << ":" << it->second.first << "," << it->second.second << " ";
        }
        cout << endl;
    }
    else{
        cout << "Path does not exist" << endl;
    }

    delete[] vectors;
    delete[] pairs;

    return 0;
}
