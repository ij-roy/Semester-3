//heap
#include <stdio.h>
#include <stdlib.h>

heap_insert(int dpq[],int k,int addval){
    int i,father;
    i = k;
    father = (i-1)/2;
    while (i>0 && dpq[father] < addval){
        dpq[i] = dpq[father];
        i = father;
        father = (i-1)/2;
    }
    dpq[i] = addval;
}
 