//#include <stdio.h>
 
void _start()
{   
    int tmp;
    int c=0;
    //int arr[5];
    int* arr = (int*) 0x15000;
    arr[0] = 3;
    arr[1] = 5;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 4;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4 - i; j++){
            if(arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    volatile  int* tx = (volatile int*) 0x40002000;
   
    while (c < 5) {
        *tx = *arr;
        arr++;
        c++;
    }

}
