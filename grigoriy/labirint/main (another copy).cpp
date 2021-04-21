#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <ctime>
#include <cmath>
#include <locale>
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
    int *py;      // êîîðäèíàòû ÿ÷ååê, âõîäÿùèõ  ïóòü
    int len;                       // äëèíà ïóòè
    const int WALL = -1;
    const int SPACE = 0;
    LAB();
    LAB(int n = 1, int m = 1);
    void print();
    void print2();
    int randNum(int min, int max)
    {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(min, max);
        return dist(mt);
    }
    void gran();
    void DIVISION(int x, int y, int width, int height, int Mwidth, int Mheight);
    bool ALGORITHM(int ax, int ay, int bx, int by);
    ~LAB();
};
LAB::LAB()
{
    N = 5;
    M = 5;
    len = 0;
    int R = M *N;
    px = new int[R];
    py = new int[R];
    for (int i = 0; i < R; i++)
    {
        px[i] = 0;
        py[i] = 0;
    }
    A = new int* [N];
    for (int i = 0; i < N; i++)
    {
        A[i] = new int[M];
    }
}

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

void LAB::print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == WALL) cout << "#"<<" ";
            if (A[i][j] == SPACE) cout<< "  ";
        }
        cout << endl;
    }
}

void LAB::print2()
{
    for (int j = 0; j < ((N-2)*(M-2)); j++) if ((px[j] > 0) && (py[j] > 0)) cout << py[j] << "," << px[j] << endl;
    //if((px[j] > 0) && (py[j] > 0))
}

void LAB::gran()
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

bool LAB:: ALGORITHM(int ax, int ay, int bx, int by)   // ïîèñê ïóòè èç ÿ÷åéêè (ax, ay) â ÿ÷åéêó (bx, by)
{
    int dx[4] = { 1, 0, -1, 0 };   // ñìåùåíèÿ, ñîîòâåòñòâóþùèå ñîñåäÿì ÿ÷åéêè
    int dy[4] = { 0, 1, 0, -1 };   // ñïðàâà, ñíèçó, ñëåâà è ñâåðõó
    int d, x, y, k;
    bool stop;

    if (A[ay][ax] == WALL || A[by][bx] == WALL) return false;  // ÿ÷åéêà (ax, ay) èëè (bx, by) - ñòåíà

    // ðàñïðîñòðàíåíèå âîëíû
    d = 0;
    A[ay][ax] = 0;            // ñòàðòîâàÿ ÿ÷åéêà ïîìå÷åíà 0
    do {
        stop = true;               // ïðåäïîëàãàåì, ÷òî âñå ñâîáîäíûå êëåòêè óæå ïîìå÷åíû
        for (y = 0; y < N; ++y)
            for (x = 0; x < M; ++x)
                if (A[y][x] == d)                         // ÿ÷åéêà (x, y) ïîìå÷åíà ÷èñëîì d
                {
                    for (k = 0; k < 4; ++k)                    // ïðîõîäèì ïî âñåì íåïîìå÷åííûì ñîñåäÿì
                    {
                        int iy = y + dy[k], ix = x + dx[k];
                        if ((iy >= 0) && (iy <N) && (ix >= 0) && (ix < M) && (A[iy][ix] == SPACE))
                        {
                            stop = false;              // íàéäåíû íåïîìå÷åííûå êëåòêè
                            A[iy][ix] = d + 1;      // ðàñïðîñòðàíÿåì âîëíó
                        }
                    }
                }
        d++;
    } while (!stop && A[by][bx] == SPACE);

    if (A[by][bx] == SPACE) return false;  // ïóòü íå íàéäåí

    // âîññòàíîâëåíèå ïóòè
    len = A[by][bx];            // äëèíà êðàò÷àéøåãî ïóòè èç (ax, ay) â (bx, by)
    x = bx;
    y = by;
    d = len;
    while (d > 0)
    {
        px[d] = x;
        py[d] = y;                   // çàïèñûâàåì ÿ÷åéêó (x, y) â ïóòü
        d--;
        for (k = 0; k < 4; ++k)
        {
            int iy = y + dy[k], ix = x + dx[k];
            if ((iy >= 0 )&& (iy <N )&& (ix >= 0 )&& (ix < M )&& (A[iy][ix] == d))
            {
                x = x + dx[k];
                y = y + dy[k];           // ïåðåõîäèì â ÿ÷åéêó, êîòîðàÿ íà 1 áëèæå ê ñòàðòó
                break;
            }
        }
    }
    px[0] = ax;
    py[0] = ay;
    return true;
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
    int n = 8, m = 8; // 5,6
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
           /* else{
                matrix[i][j] = 0;
            }*/
        }
    }
/*    matrix[1][3] = -1;
    matrix[2][4] = -1;
    matrix[3][1] = -1;
    matrix[3][4] = -1;
    matrix[4][6] = -1;
    matrix[5][4] = -1;*/
/*    printMatrix(matrix,nf,mf);
    cout << endl;
    checkMatrix(matrix,nf,mf);*/

    matrix[1][1] = 1;
    matrix[nf - 2][mf - 2] = 0;
    printMatrix(matrix,nf,mf);
    cout << endl;
    checkMatrix(matrix,nf,mf);


    // Algorithm

    auto *pairs = new pair<int, int>[nf * mf];
    for (int i = 1; i < nf - 1; ++i) {          // To without walls
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
                    }
                }
            }
        }
        key++;
        if (matrix[nf - 2][mf - 2] != 0){
            f = false;
        }
    }

    printMatrix(matrix, nf, mf);
    cout << endl;

    if (matrix[nf - 2][mf - 2] != 0){
        map <int, pair<int, int>> path;
        map <int, pair<int, int>>::iterator it;
        key = matrix[nf - 2][mf - 2];
        path[key] = pairs[(nf - 2)*mf + mf - 2];
        key = key - 1;
        for (int i = nf - 2; i > 0; --i) {
            for (int j = mf - 2; j > 0; --j) {
                if (key == matrix[i][j]){
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

//    for (int i = 0; i < mf; ++i) {
//        delete[] matrix[i];
//    }    if(matrix[n][m] == 0){
    delete[] matrix;
    delete[] vectors;
    delete[] pairs;

    return 0;
}
