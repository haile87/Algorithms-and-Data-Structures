#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
//the execution time is calculated in microseconds
//Used  Chrono functionality to calculate time( source is geeksforgeeks.org )

class MergeSort{
	//k number of array subsequences
    private:
        int k;

	public:
	    void setter(int x){
            k = x;
	    }
	    int getter(){
            return k;
	    }
        void mergeSort(int* arr,int startel, int endel){
            if(endel - startel >= k){
                insertionSort(arr, startel, endel);
                return;
            }
            int midel = (startel + endel)/2;
            mergeSort(arr,startel,midel);
            mergeSort(arr,midel,endel);
            merging(arr,startel,midel,endel);
        }

        void merging(int *arr, int startel, int midel, int endel){
            int i = 0;
            for(i=startel;i<midel;startel++){
                arr[i]=arr[startel];
                i++;
            }
            for(i=midel;i<=endel;midel++){
                arr[i]=arr[midel];
                i++;
            }
        }
        int* insertionSort(int* arr, int startel, int endel){
            int i = 0,j = 0,key = 0;
            for(i=startel+1;i<=endel;i++){
                key = arr[i];
                j=i-1;
                while(j>=0 && key<arr[j]){
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
            }
            return arr;
        }
};

int main(){
    int x = 0, m = 0, g = 0;
    MergeSort arrsort;
    srand(time(NULL));
    cout << "Please enter the value of k less than 50 as the smallest array is of size 50 " << endl;
    cout << endl;
    cout << "And because we can not divide an array into subgroups of k larger than its size" << endl;
    cin >> g;
    arrsort.setter(g);
		//average case, best case and worst case arrays to calculate the execution time for each case with increasing size
		int array2averagecase[50], bestcase2[50], worstcase2[50];
		int array3averagecase[100], bestcase3[100], worstcase3[100];
		int array4averagecase[500], bestcase4[500], worstcase4[500];
		int array5averagecase[10000], bestcase5[1000], worstcase5[1000];
		int array6averagecase[5000], bestcase6[5000], worstcase6[5000];
		int array7averagecase[10000], bestcase7[10000], worstcase7[10000];
		int array8averagecase[20000], bestcase8[20000], worstcase8[20000];
		int array9averagecase[50000], bestcase9[50000], worstcase9[50000];

		//first array cases
		for(x=0;x<50;x++){
			m = rand();
			array2averagecase[x]  = m;
			bestcase2[x] = x+1;
			worstcase2[x] = 50-x;
		}
		//second array cases
		for(x=0;x<100;x++){
			m = rand();
			array3averagecase[x]  = m;
			bestcase3[x] = x+1;
			worstcase3[x] = 100-x;
		}
		//third array cases
		for(x=0;x<500;x++){
			m = rand();
			array4averagecase[x]  = m;
			bestcase4[x]   = x+1;
			worstcase4[x]  = 500-x;
		}
		//fourth array cases
		for(x=0;x<1000;x++){
			m = rand();
			array5averagecase[x] = m;
			bestcase5[x] = x+1;
			worstcase5[x] = 1000-x;
		}
		//fifth array cases
		for(x = 0;x<5000;x++){
			m = rand();
			array6averagecase[x] = m;
			bestcase6[x] = x+1;
			worstcase6[x] = 5000-x;
		}
		//sixth array case
		for(x=0;x<10000;x++){
			m = rand()%20000 + 1;
			array7averagecase[x] = m;
			bestcase7[x]  = x+1;
			worstcase7[x]  = 10000-x;
		}
		//seventh array case
		for(x=0;x<20000;x++){
			m = rand();
			array8averagecase[x] = m;
			bestcase8[x] = x+1;
			worstcase8[x] = 20000-x;
		}
		//eighth array case
		for(x=0;x<50000;x++){
			m = rand();
			array9averagecase[x] = m;
			bestcase9[x] = x+1;
			worstcase9[x] = 50000-x;
		}
		/////Average cases/////

		//time to sort size 50 array
        auto starttime2 = high_resolution_clock::now();
		arrsort.mergeSort(array2averagecase, 0, 49);
		auto endtime2 = high_resolution_clock::now();
		auto time2 = duration_cast<chrono::microseconds>(endtime2 - starttime2);

		//time to sort size 100 array
		auto starttime3 = high_resolution_clock::now();
		arrsort.mergeSort(array3averagecase, 0, 99);
		auto endtime3 = high_resolution_clock::now();
		auto time3 = duration_cast<chrono::microseconds>(endtime3 - starttime3);

		//time to sort size 500 array
		auto starttime4 = high_resolution_clock::now();
		arrsort.mergeSort(array4averagecase, 0, 499);
		auto endtime4 = high_resolution_clock::now();
		auto time4 = duration_cast<chrono::microseconds>(endtime4 - starttime4);

		//time to sort size 1000 array
		auto starttime5 = high_resolution_clock::now();
		arrsort.mergeSort(array5averagecase, 0, 999);
		auto endtime5 = high_resolution_clock::now();
		auto time5 = duration_cast<chrono::microseconds>(endtime5 - starttime5);

		//time to sort size 5000 array
		auto starttime6 = high_resolution_clock::now();
		arrsort.mergeSort(array6averagecase, 0, 4999);
		auto endtime6 = high_resolution_clock::now();
		auto time6 = duration_cast<chrono::microseconds>(endtime6 - starttime6);

		//time to sort size 10000 array
		auto starttime7 = high_resolution_clock::now();
		arrsort.mergeSort(array7averagecase, 0, 9999);
		auto endtime7 = high_resolution_clock::now();
		auto time7 = duration_cast<chrono::microseconds>(endtime7 - starttime7);

		//time to sort size 20000 array
		auto starttime8 = high_resolution_clock::now();
		arrsort.mergeSort(array8averagecase, 0, 19999);
		auto endtime8 = high_resolution_clock::now();
		auto time8 = duration_cast<chrono::microseconds>(endtime8 - starttime8);
		//time to sort size 50000 array
		auto starttime9 = high_resolution_clock::now();
		arrsort.mergeSort(array9averagecase, 0, 49999);
		auto endtime9 = high_resolution_clock::now();
		auto time9 = duration_cast<chrono::microseconds>(endtime9 - starttime9);

		cout << "Average case Execution time for array of size 50 for k = " << arrsort.getter() << " : " << time2.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 100 for k = " << arrsort.getter() << " : " << time3.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 500 for k = " << arrsort.getter() << " : " << time4.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 1000 for k = " <<arrsort.getter() << " : " << time5.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 5000 for k = " << arrsort.getter() << " : " << time6.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 10000 for k = " << arrsort.getter() << " : " << time7.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 20000 for k = " << arrsort.getter() << "  : " << time8.count() << " microseconds" << endl;
		cout << "Average case Execution time for array of size 50000 for k = " << arrsort.getter() << " : " << time9.count() << " microseconds" << endl;

		/////Best cases/////

		//time to sort size 50 array
		auto starttime11 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase2, 0, 49);
		auto endtime11 = high_resolution_clock::now();
		auto time11 = duration_cast<chrono::microseconds>(endtime11 - starttime11);

		//time to sort size 100 array
		auto starttime12 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase3, 0, 99);
		auto endtime12 = high_resolution_clock::now();
		auto time12 = duration_cast<chrono::microseconds>(endtime12 - starttime12);

		//time to sort size 500 array
		auto starttime13 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase4, 0, 499);
		auto endtime13 = high_resolution_clock::now();
		auto time13 = duration_cast<chrono::microseconds>(endtime13 - starttime13);

		//time to sort size 1000 array
		auto starttime14 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase5, 0, 999);
		auto endtime14 = high_resolution_clock::now();
		auto time14 = duration_cast<chrono::microseconds>(endtime14 - starttime14);

		//time to sort size 5000 array
		auto starttime15 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase6, 0, 4999);
		auto endtime15 = high_resolution_clock::now();
		auto time15 = duration_cast<chrono::microseconds>(endtime15 - starttime15);

		//time to sort size 10000 array
		auto starttime16 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase7, 0, 9999);
		auto endtime16 = high_resolution_clock::now();
		auto time16 = duration_cast<chrono::microseconds>(endtime16 - starttime16);
		//time to sort size 20000 array
		auto starttime17 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase8, 0, 19999);
		auto endtime17 = high_resolution_clock::now();
		auto time17 = duration_cast<chrono::microseconds>(endtime17 - starttime17);

		//time to sort size 50000 array
		auto starttime18 = high_resolution_clock::now();
		arrsort.mergeSort(bestcase9, 0, 49999);
		auto endtime18 = high_resolution_clock::now();
		auto time18 = duration_cast<chrono::microseconds>(endtime18 - starttime18);

		cout << "Best case Execution time for array of size 50 for k = " << arrsort.getter() << " : " << time11.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 100 for k = " << arrsort.getter() << " : " << time12.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 500 for k = " << arrsort.getter() << " : " << time13.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 1000 for k = " <<arrsort.getter() << " : " << time14.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 5000 for k = " << arrsort.getter() << " : " << time15.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 10000 for k = " << arrsort.getter() << " : " << time16.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 20000 for k = " << arrsort.getter() << "  : " << time17.count() << " microseconds" << endl;
		cout << "Best case Execution time for array of size 50000 for k = " << arrsort.getter() << " : " << time18.count() << " microseconds" << endl;

        /////Worst cases/////

		//time to sort size 50 array
		auto starttime20 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase2, 0, 49);
		auto endtime20 = high_resolution_clock::now();
		auto time20 = duration_cast<chrono::microseconds>(endtime20 - starttime20);

		//time to sort size 100 array
		auto starttime21 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase3, 0, 99);
		auto endtime21 = high_resolution_clock::now();
		auto time21 = duration_cast<chrono::microseconds>(endtime21 - starttime21);

		//time to sort size 500 array
		auto starttime22 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase4, 0, 499);
		auto endtime22 = high_resolution_clock::now();
		auto time22 = duration_cast<chrono::microseconds>(endtime22 - starttime22);

		//time to sort size 1000 array
		auto starttime23 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase5, 0, 999);
		auto endtime23 = high_resolution_clock::now();
		auto time23 = duration_cast<chrono::microseconds>(endtime23 - starttime23);

		//time to sort size 5000 array
		auto starttime24 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase6, 0, 4999);
		auto endtime24 = high_resolution_clock::now();
		auto time24 = duration_cast<chrono::microseconds>(endtime24 - starttime24);

		//time to sort size 10000 array
		auto starttime25 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase7, 0, 9999);
		auto endtime25 = high_resolution_clock::now();
		auto time25 = duration_cast<chrono::microseconds>(endtime25 - starttime25);

		//time to sort size 20000 array
		auto starttime26 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase8, 0, 19999);
		auto endtime26 = high_resolution_clock::now();
		auto time26 = duration_cast<chrono::microseconds>(endtime26 - starttime26);

		//time to sort size 50000 array
		auto starttime27 = high_resolution_clock::now();
		arrsort.mergeSort(worstcase9, 0, 49999);
		auto endtime27 = high_resolution_clock::now();
		auto time27 = duration_cast<chrono::microseconds>(endtime27 - starttime27);

		cout << "Worst case Execution time for array of size 50 for k = " << arrsort.getter() << " : " << time20.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 100 for k = " << arrsort.getter() << " : " << time21.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 500 for k = " << arrsort.getter() << " : " << time22.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 1000 for k = " <<arrsort.getter() << " : " << time23.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 5000 for k = " << arrsort.getter() << " : " << time24.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 10000 for k = " << arrsort.getter() << " : " << time25.count() << " microseconds" << endl;
		cout << "Worst case Execution time for array of size 20000 for k = " << arrsort.getter() << "  : " << time26.count() << " microseconds" << endl;
        cout << "Worst case Execution time for array of size 50000 for k = " << arrsort.getter() << " : " << time27.count() << " microseconds" << endl;

        return 0;
}
