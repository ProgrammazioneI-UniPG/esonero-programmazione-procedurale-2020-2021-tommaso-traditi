#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main() {
  char plaintext[128]; //dichiaro la variabile plaintext

  printf("\nInserire il testo da cifrare di massimo 128 caratteri: ");
  fgets (plaintext, 128, stdin); // il programma legge il testo inserito e lo memorizza
  int optionNumber; //dichiaro la variabile optionNumber che servirà poi per far scegliere a l'utente come procedere per cifrare il messaggio
  printf("\nCome si vuole cifrare il messaggio: \n"
  "- Digita 1 per inserire una chiave di lunghezza uguale o superiore al testo inserito;\n"
  "- Digita 2 per generare una chiave casuale;\n"
  "- Digita 0 per uscire dal programma; \n"
   "\n");
  do{   //inizio do while
  scanf("%d", &optionNumber); //il programma acquisisce la scelta fatta dall'utente
   switch (optionNumber){
     case 0: { //in questo caso il programma si chiude
       break;
     }
     case 1: { //in questo caso il programma chiede all'utente di inserire la chiave per cifrare poi il messaggio
       char chiave [128];
       char testocifrato [128];  //dichiaro le tre variabile per cifrare in XOR il messaggio
       char parola[128];

       do{ //apro un altro do while
       printf("\nInserire la chiave di cifratura: ");
       scanf("%s", chiave); //il programma acquisisce la chiave inserita


       if(strlen(plaintext) > strlen(chiave)) { //inserisco un if per far si che il programma esamini la chiave e verifichi che non sia più corta del testo da cifrare
           printf ("\nLa chiave è più corta del testo\n");
        fgets(chiave, 128, stdin); //il programmalegge la chiave inserita

          }

       if(strlen(plaintext) <= strlen(chiave)){ //il programma verifica che la chiave è lunga almeno quanto il testo inserito
           fgets(chiave, 128, stdin); //il programma legge la chiave inserita e la memorizza
           for(int i=0; i<128; i++){ //inizio del ciclo con contatore
              testocifrato[i] = plaintext[i] ^ chiave[i];
              }

          printf("\nTesto cifrato: %s\n", testocifrato);

          for(int i=0; i<128; i++){ //inizio ciclio con contatore
            parola[i] = testocifrato[i] ^ chiave[i];
                 }
          printf("Il testo originale è: %s", parola);
          return 0;

           }

       } while (strlen(chiave) < strlen(plaintext));
       break;
     }
     case 2: { //in questo caso il programma genera una chiave casuale e cifra il testo

       srand(time(0)); // generatore random della chiave
    char lettere[128];
    char testocifrato[128]; //dichiaro le tre variabili per cifrare il messaggio
    char parola[128];

    for(int i=0;i<=strlen(plaintext);i++) // inizio ciclio con contatore per generare la chiave
    {
        lettere[i]=(97+rand()%26);
    }
    printf("\nLa chiave generata è: %s\n", lettere);

    fgets(lettere, 128, stdin);

    for(int i=0; i<128; i++){ //inizio ciclo con contatore per cifrare il testo
       testocifrato[i] = plaintext[i] ^ lettere[i];
       }

   printf("Testo cifrato: %s\n", testocifrato);

   for(int i=0; i<128; i++){ //inizio ciclo con contatore per tornare alla parola originale
     parola[i] = testocifrato[i] ^ lettere[i];
          }
   printf("Il testo originale è: %s", parola);
   return 0;

       break;
     }
     default: {
       printf("\nIl numero che hai inserito è sbagliato\n"
       "...\n"
       "Come si vuole cifrare il messaggio: \n"
       "- Digita 1 per inserire una chiave di lunghezza uguale o superiore al testo inserito;\n"
       "- Digita 2 per generare una chiave casuale;\n"
       "- Digita 0 per uscire dal programma; \n"
        "\n");
       break;
     }
   }
 } while (optionNumber != &optionNumber<0
    & optionNumber>2);

  return 0;
}
