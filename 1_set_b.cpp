//powerset: list all the elements of the power set of a set .
#include <iostream>
using namespace std;

void powerSet(int set[], int size) {
    int total=1;
    for(int i=0;i<size;i++){
        total*=2;
    }

    for (int i=0;i<total;i++){
        cout<<"{";
        int num=i;

        for (int j=0;j<size;j++){
            if (num%2==1){
                cout<<set[j]<<" ";
            }
            num/=2;
        }
        cout<<"}"<<endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the set: ";
    cin >> size;

    int mySet[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> mySet[i];
    }
    
    powerSet(mySet,size);
    return 0;
}
