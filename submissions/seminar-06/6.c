void normalize(int *a, int *b, int *c){
    if (*b < *a){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*c < *a){
        int temp = *a;
        *a = *c;
        *c = temp;
    }
    if (*c < *b){
        int temp = *b;
        *b = *c;
        *c = temp;
    }
}


