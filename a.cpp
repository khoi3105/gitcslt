#include <fstream>
#include <iostream>
using namespace std;

double getMedian(int* array, int num) {
	if (num % 2 != 0) {
		return *(array + (num / 2));
	}
	else {
		return ((double)(*(array + num/2) + *(array + num/2 - 1)) / 2.0);
	}
}

int main() {
    // // write file
    // ofstream out;
    // out.open("input.bin",ios::binary);
    // // input from keyboard
    // cout << "input n:";
    // int n;
    // cin >> n;
    // out.write(reinterpret_cast<char*>(&n), sizeof(int));
    // int* array = new int [n];
    // for (int i = 0; i < n; i++) {
    //     cout << "input a" << i;
    //     cin >> array[i];
    // }
    // out.write(reinterpret_cast<char*>(array), n * sizeof(int));
    // out.close();
    // delete[] array;
    // cout << "done";

    // read file
    ifstream inFile("input.bin",ios::binary);
    int n;
    inFile.read(reinterpret_cast<char*>(&n), sizeof(int));
    int* arr = new int[n];

    inFile.read(reinterpret_cast<char*>(arr), n * sizeof(int));
    inFile.close();
    for (int i =0 ; i < n ; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}