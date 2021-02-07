#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// function that finds the minimum time
int VertexWithMinimumTime(int *tarr, bool vertex[], int numofcities){
    // Initialize min value as infinity
    int minimum = INT_MAX;
    int indexformin = 0;
    for(int i = 0;i<numofcities;i++){
        if((vertex[i] == false) && (tarr[i] <= minimum)){
            minimum = tarr[i];
            indexformin = i;
        }
    }
    return indexformin;
}

// Function that finds the shortest time needed to travel between two cities
int findMinimumTime(int **adj_matrix, int your_city, int friend_city, int numofcities){
    // array holding shortest times to all cities
    int tarr[numofcities];
    // array showing if a vertex is or not included in the path
    bool vertex[numofcities];
    for(int i = 0;i<numofcities;i++)
        tarr[i] = INT_MAX, vertex[i] = false;
    tarr[your_city] = 0;
    for(int z = 0;z<(numofcities-1);z++){
        int a = VertexWithMinimumTime(tarr, vertex, numofcities);
        vertex[a] = true;
        // break if shortest path to friend_city has been found already
        if(a==friend_city)
            break;
        for(int k=0;k<numofcities;k++){
            if(!vertex[k] && adj_matrix[a][k] && (tarr[a]!=INT_MAX) &&
               ((tarr[a]+adj_matrix[a][k]) <= tarr[k])){
                tarr[k] = tarr[a] + adj_matrix[a][k];
            }
        }
    }
    return tarr[friend_city];
}

// finds which city to meet in
int find_meetup_city(int **adj_matrix, int your_city, int friend_city, int numofcities){
    int arr[numofcities];
    // find and minimize max(x,y) where x and y
    // are the times you and your friend traveled as you
    // will both be traveling simultaneously
    for(int i=0;i<numofcities;i++){
        int person1time = findMinimumTime(adj_matrix, i, your_city, numofcities);
        int person2time = findMinimumTime(adj_matrix, i, friend_city, numofcities);
        arr[i] = max(person1time, person2time);
    }
    // minimizing max(x,y)
    int minimum = arr[0];
    int indx = 0;
    for(int i=1;i<numofcities;i++){
        if(minimum > arr[i]){
            minimum = arr[i];
            indx = i;
        }
    }
    return indx;
}

int main(){
    int **adj_matrix;
    int numofcities;
    cout << "Please enter the total number of cities" << endl;
    cin >> numofcities;
    adj_matrix = new int *[numofcities];
    for(int i=0;i<numofcities;i++)
        adj_matrix[i] = new int[numofcities];
    cout << "Please enter the Adjacency Matrix" << endl;
    // You need to enter (numofcities!/r!*(numofcities - r)!) values to get all the combinations
    // of the times needed to travel between any two cities where r is the number
    // of cities compared at any given time which is two and numofcities is the total
    // number of cities. This will give the adjacency matrix by using the factorial
    // to get all possible combinations
    for(int i=0;i<numofcities;i++){
        for(int j=0;j<i;j++){
            cin >> adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
        adj_matrix[i][i] = 0;
    }
    // above is generated a symmetric matrix with zeros on the diagonal
    int your_city, friend_city;
    cout << "Please enter the cities where you and your friend live in:" << endl;
    cin >> your_city;
    cin >> friend_city;
    int meetupcity = find_meetup_city(adj_matrix, your_city, friend_city, numofcities);
    cout << "Optimal meeting point is Node " << meetupcity << endl;
    cout << "Note that the Node numbers are indices of an array so the actual city";
    cout << " to meet in would be City " << meetupcity + 1 << " (one plus the index)" << endl;
    return 0;
}
