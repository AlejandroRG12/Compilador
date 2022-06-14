int printf(char *fmt, ...);

int main(){
    int i;
    float suma = 0;
    for(i=0; i<20; i++){
        suma+=i;
    }
    printf("Suma = %g\n", suma);
    return 0;
}
