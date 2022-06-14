int printf(char *fmt, ...);

int main(){
    int i;
    int suma = 3;
    switch(suma){
        case 0:
        break;
        case 1:
        break;
        case 2:
        break;
        case 3:
        printf("Hola desde switch = 3, %g", suma);
        break;
        default:
        printf("La suma no se reconocio!!\n");
    }
        
    return 0;
}