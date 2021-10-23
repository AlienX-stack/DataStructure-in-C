#include <iostream>
using namespace std;

int main() {

    cout << "Enter the size of array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the values for the array"<<endl;
    for (int i = 0; i < n; i++) 
        cin>>arr[i];

    cout<<"Array in reverse order is: "<<endl;
    for( int i = n-1 ; i >= 0; i--) {
        cout<<arr[i]<<" ";
    }

    return 0;
}


/*
#include <iostream>
using namespace std;

int main() {

    return 0;
}
*/