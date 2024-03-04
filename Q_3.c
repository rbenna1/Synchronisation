#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#define N 1000 
int *tab ; 

/*


void fonction(void) {
    for (int i=0 ; i<N ; i++ ) {
        usleep(10000) ; 
        if (tab[i] == 0) printf("0 trouvé à l'index %d\n", i);
    }
}


int main(void){
    tab = (int *)malloc (sizeof(int) * N ) ; 
    for (int i = 0 ; i<N ; i++) tab[i] = rand()%100 ; 
    fonction() ; 
    return EXIT_SUCCESS; 
}
*/
// Question 2 

/* 
l'excution de la duexieme version est deux fois plus rapide , ca s'explique par le faite 
qu'on a diviser notre tableau en 2 moitiees comme avec les processus (td2) , on 2 thread qui 
s'occupent d'une moitié chacun , cela explique la difference dans les temps 
d'execution et dans l'ordre des indices affichés 






*/

void* fonction(void *p ) {
    int d , f ; 
    if (*(int *)p  == 0) {
        d = 0 ; 
        f= N/2 ; 
    }
    else {
        d = N/2 ;
        f= N ; 
    }
    for (int i = d ; i<f ; i++) {
        usleep (10000) ; 
        if (tab[i] == 0 ) printf("0 trouvé a l'index %d \n " , i ) ; 
    }
    return NULL ; 
    }

int main(void ) {
    tab = (int *) malloc (sizeof(int)*N) ;
    for (int i = 0 ; i<N ; i++) tab[i] = rand()%100 ; 
    pthread_t t1 , t2 ; 
    int a = 0 , b = 1 ; 
    pthread_create (&t1 , NULL , fonction , &a) ; 
    pthread_create (&t2 , NULL , fonction , &b) ; 
    pthread_join(t1, NULL) ; 
    pthread_join(t2 , NULL) ; 
    return EXIT_SUCCESS ; 
    
}