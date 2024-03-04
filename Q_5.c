#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 3 // pour tester sur un nombre dif de threads 

void lire() {
    printf("Lire debut\n") ; 
    usleep(rand()%500000); 
    printf("lire fin\n");
}
void ecrire() {
    printf("ecrire debut\n") ; 
    usleep(rand()%500000);
    printf("ecrire fin\n");
}

/* Question 1  : Parmi les trois conditions (C1, C2, C3), seule la condition C1 est 
remplie. Les conditions C2 et C3 ne sont pas satisfaites. 
Il est possible qu'un thread entre dans la section "écrire" tandis qu'un autre 
thread est en train de lire ou d'écrire dans la base de données simultanément.
*/ 


// Question 2 
// c'est facile , il suffit simplement de d'exectuer lire() ou ecrire dans une section critique
// et pour cela on utilise pthread_mutex_lock(&m) m est notre mutex 
// on lis ou on ecis , puis on procede au deverouillage avec pthread_mutex_unlock(&m)
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ; 


void *fonction (void * arg) {
    while (1) {
if ((rand() % 2) == 0) {
pthread_mutex_lock(&m);
lire();
pthread_mutex_unlock(&m);
} else {
pthread_mutex_lock(&m);
ecrire();
pthread_mutex_unlock(&m);
}
}

}


int main() {
    pthread_t tab[N] ;  // exemples   
    for (int i =0 ; i<N ; i++) pthread_create(&tab[i] ,NULL , fonction , NULL) ;
    for (int i =0 ; i<N ; i++) pthread_join (tab[i],NULL); 
    return 0 ;

}


// Question 3 
/*
Pour satisfaire les conditions C1, C2 et C3, On doit utiliser un ensemble de 
verrous, comprenant un verrou pour les lectures et un verrou pour les écritures. 
Les lecteurs doivent acquérir le verrou de lecture avant de lire, tandis que les 
écrivains doivent acquérir le verrou d'écriture avant d'écrire.  On doit egalement
gérer le nombre de lecteurs actifs pour garantir que les écritures sont bloquées 
lorsque des lectures sont en cours, conformément aux conditions C2 et C3.
*/