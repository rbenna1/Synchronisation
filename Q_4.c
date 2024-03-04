#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>





volatile int count = 0;

//Question 1 
/*

void *fonction ( void *p) {
    for ( int i = 0 ; i <10000 ; i++) count ++ ; 
    return NULL ; 
}


int main (void) {
    pthread_t tab[10] ; 
    for (int i =0 ; i<10 ; i++) pthread_create (&tab[i] , NULL , fonction , NULL ) ; 
    for (int i = 0 ; i<10 ; i++) pthread_join(tab[i] , NULL) ; 
    printf("%d\n" , count) ; 
    return EXIT_SUCCESS ; 
}

*/



// Question 2 ; 

/*
Mutex : Intialisation d'un mutex pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ; 
pthread_mutex_lock(&m) ; si aucun thread n'a demander le lock sur le mutex on lock le mutex 
ouis on execute la suite du code 
si il est deja bloqué , on attend que le thread bloqué lbere le mutex , puis on excute la suite 
du code 
 pthread_mutex_unlock(&m) ; on libere le mutex 

*/
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER ; // variable globale ;

void *fonction (void *p ) {
 for ( int i = 0 ; i < 10000 ; i++) { 
    pthread_mutex_lock(&m) ; 
    count ++ ; 
    pthread_mutex_unlock(&m) ; 
 }
 return NULL ; 
}

int main (void) {
    pthread_t tab[10] ; 
    for (int i =0 ; i<10 ; i++) pthread_create (&tab[i] , NULL , fonction , NULL ) ; 
    for (int i = 0 ; i<10 ; i++) pthread_join(tab[i] , NULL) ; 
    printf("%d\n" , count) ; 
    return EXIT_SUCCESS ; 
}