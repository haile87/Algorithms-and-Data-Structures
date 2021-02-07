#include <iostream>

using namespace std;

class Complex {
	private:
		double real, imag;
	public:
		Complex(double real, double imag) {
			this->real = real;
			this->imag = imag;
		}
		bool operator==(const Complex& o){
            if(this->real == o.real && this->imag == o.imag){
                return true;
                }else
                    return false;
		}
		bool operator!=(const Complex& o){
            if(this->real != o.real || this->imag != o.imag){
                return true;
            }else
                return false;
		}
};


template <class T>
int array_search(T arr[], int arrsize, T searchfor){
    int j;
    for(j=0;j<arrsize;j++){
        if(arr[j] == searchfor){
            break;
        }else if(j==(arrsize-1) && arr[j]!=searchfor){
            return -1;
        }
    }
    return j;
}

int main(){
    int intarr[] = {1,2,3,4,5};
    double darr[] = {1.3, 3.5, 5.2, 7.9,8.6};
    char charr[] = {'c', 'f', 'i', 'h'};
    Complex carr[] = {Complex(2,4), Complex(3,5), Complex(6,7), Complex(8,12)};
    cout << array_search(intarr, 5, 3) << endl;
    cout << array_search(darr, 5, 8.6) << endl;
    cout << array_search(charr, 4, 'h') << endl;
    cout << array_search(carr, 4, Complex(8,12)) << endl;
    cout << array_search(intarr, 5, 8) << endl;
    return 0;
}
