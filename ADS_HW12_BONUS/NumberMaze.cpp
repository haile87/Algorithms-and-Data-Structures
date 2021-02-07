#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minimumTime(int path[], bool vertex[], int sizeofboard){
    int minimum = INT_MAX;
    int minimumindex = 0;
    for(int i=0;i<sizeofboard;i++){
        if((vertex[i] == false) && (path[i] <= minimum)){
            minimum = path[i];
            minimumindex = i;
        }
    }
    return minimumindex;
}
struct pos{
    int x;
    int y;
};

class PuzzleBoard{
    private:
        int **graphmatrix;
        int **puzzle;
        int sizeofboard;
        int squares;
        pos currentpos;
    public:
        // Subpoint B
        PuzzleBoard(int boardSize, int** fields = NULL){
            sizeofboard = boardSize;
            puzzle = new int*[sizeofboard];
            for(int i=0;i<sizeofboard;i++)
                puzzle[i] = new int[sizeofboard];
            // Create the puzzle board
            for(int i=0;i<sizeofboard;i++){
                for(int j=0;j<sizeofboard;j++)
                    puzzle[i][j] = fields[i][j];
            }
            squares = sizeofboard*sizeofboard;
            graphmatrix = new int*[squares];
            for(int i=0;i<squares;i++)
                graphmatrix[i] = new int[squares];
            // initialize graphmatrix as zero
            for(int i=0;i<squares;i++){
                for(int j=0;j<squares;j++)
                    graphmatrix[i][j] = 0;
            }
            // if a path is present from one cell to another,
            // make graphmatrix 1 there
            for(int i=0;i<sizeofboard;i++){
                for(int j=0;j<sizeofboard;j++){
                    if(i-puzzle[i][j] >= 0)
                        graphmatrix[sizeofboard*i+j][sizeofboard*(i-puzzle[i][j])+j] = 1;
                    if(j+puzzle[i][j] < sizeofboard)
                        graphmatrix[sizeofboard*i+j][sizeofboard*i+(j+puzzle[i][j])] = 1;
                    if(i+puzzle[i][j] < sizeofboard)
                        graphmatrix[sizeofboard*i+j][sizeofboard*(i+puzzle[i][j])+j] = 1;
                    if(j-puzzle[i][j] >= 0)
                        graphmatrix[sizeofboard*i+j][sizeofboard*i+(j-puzzle[i][j])] = 1;
                }
            }
            // initialize current position at point (0,0)
            currentpos.x = 0;
            currentpos.y = 0;
        }

        bool makeMove(int direction){
            int i=currentpos.x;
            int j=currentpos.y;
            if(direction==0){
                if(i-puzzle[i][j] >= 0){
                    currentpos.x -=puzzle[i][j];
                    return true;
                }
            }
            if(direction==1){
                if(j+puzzle[i][j] < sizeofboard){
                    currentpos.y += puzzle[i][j];
                    return true;
                }
            }
            if(direction==2){
                if(i+puzzle[i][j] < sizeofboard){
                    currentpos.x += puzzle[i][j];
                    return true;
                }
            }
            if(direction==3){
                if(j-puzzle[i][j] >= 0){
                    currentpos.y -= puzzle[i][j];
                    return true;
                }
            }
            return false;
        }

        bool getResult(){
            if((currentpos.x==sizeofboard-1) && (currentpos.y==sizeofboard-1))
                return true;
            return false;
        }

        friend ostream &operator<<(ostream &os, PuzzleBoard const &m){
            // display the puzzle and graph on the screen
            for(int i=0;i<m.sizeofboard;i++) {
                for(int j=0;j<m.sizeofboard;j++){
                    os << m.puzzle[i][j] << " ";
                }
                os << endl;
            }
            os << endl;
            for(int i=0; i<m.squares; i++) {
                for(int j=0;j<m.squares;j++){
                    os << m.graphmatrix[i][j] << " ";
                }
                os << endl;
            }
            return os;
        }

        // Subpoint C
        // find minimum moves needed to solve the puzzle by finding
        // the shortest path to the solution
        int solve(){
            int path[squares];
            bool vertex[squares];
            for(int i = 0;i<squares;i++){
                path[i] = INT_MAX;
                vertex[i] = false;
            }
            path[0] = 0;
            for(int i=0;i<squares;i++) {
                int j = minimumTime(path, vertex, squares);
                vertex[j] = true;
                for(int k=0;k<squares;k++){
                    if(!vertex[k] && graphmatrix[j][k] && (path[j] != INT_MAX)
                            && (path[j]+graphmatrix[j][k] < path[k])){
                        path[k] = path[j] + graphmatrix[j][k];
                    }
                }
            }
            if(path[squares-1]==INT_MAX)
                return -1;
            return path[squares-1];
        }
};

int main(){
    int **adj_matrix;
    int sizeofboard;
    cout << "Please enter the size of the puzzle board" << endl;
    cin >> sizeofboard;
    adj_matrix = new int *[sizeofboard];
    for(int i=0;i<sizeofboard;i++)
        adj_matrix[i] = new int[sizeofboard];
    cout << "Please enter the Puzzle" << endl;
    for(int i=0;i<sizeofboard;i++) {
        for(int j=0;j<sizeofboard;j++){
            cin >> adj_matrix[i][j];
        }
    }
    cout << endl;
    PuzzleBoard puzzle(sizeofboard, adj_matrix);
    cout << puzzle;
    cout << endl;
    if(puzzle.solve() == -1)
        cout << "There is no solution available!" << endl;
    else
        cout << "The minimum number of moves needed to solve the puzzle is " << puzzle.solve() << endl;
    return 0;
}
