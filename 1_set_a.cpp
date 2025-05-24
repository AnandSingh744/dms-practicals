// ismember: check whether an element belongs to the set or not and return value as true or false
 
#include<iostream>
using namespace std;

int is_member(int arr[],int size,int elem){
    for (int i=0;i<size;i++) {
        if (arr[i]==elem){
            return 1;
        }
    }
    return 0; 
}

int main(){
    int size;
    cout<<"Total elements to put in sets : "<<endl;
    cin>>size;

    int element[size];
    cout<<"enter the elements in set:  "<<endl;
    for(int i=0; i<size;i++){
    cin>>element[i];
    }

    int elem;
    cout<<"enter the element you want to check: "<<endl;
    cin>>elem;
    if (is_member(element,size,elem)){
        cout<<" True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}
        
