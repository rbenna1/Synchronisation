#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// Question 1 
/* On a creé ici 10 thread a l'aide d'une boucle for , en utilisant l'appelle systeme pthread create 
 il a comme argument un pointeur vers la fonction qui sera executé par les nouveau thread 
 dans ce cas la c'est notre fonction qui affiche Bonjour a chaque creation d'un thread */


void *print () {
printf("Bonjour\n"); 
return NULL ; 

}


int main(void){

pthread_t tab[10] ;
for (int i = 0 ; i< 10 ; i++) {pthread_create(&tab[i] , NULL , print , NULL); 
pthread_join (tab[i] , NULL ) ; 
} 
return EXIT_SUCCESS ; 



}



// Question 2 
/* meme chose que la question 1 , on rajoute juste dans notre fonction l'argument dans ce cas la 
un tableau de taille 10 et contient les indices de 0 a 9 */
// Les indices ne sont pas ordonnés dans les programmes multithread en raison de l'exécution concurrente des threads, ce qui entraîne un ordre non déterministe.
/*
void* fonction (void* p ) {
   printf("Bonjour %d \n" , *((int*)p)) ; 
   return NULL ; 
}


int main (void) {
    pthread_t tab[10]; 
    int indice[10] ; 
    for (int i = 0 ; i<10 ; i++) indice[i] = i ; 
    for (int i = 0 ; i<10 ; i++)  pthread_create (&tab[i] , NULL , fonction , &indice[i]) ; 
    for (int i = 0 ; i<10 ; i++) pthread_join (tab[i] , NULL) ; 
 
        return EXIT_SUCCESS ; 
    }
*/