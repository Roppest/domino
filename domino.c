/*Este juego de dominó utiliza 4 jugadores que se
reparten 28 piezas, 7 para cada jugador.
Los jugadores están representados como arreglos de fichas.

Universidad Autónoma Metropolitana - Cuajimalpa

Rodrigo Vázquez Espino
Marco Antonio
Dany Galan

*/
#include <stdio.h>
#include <stdlib.h>
#include "domino.h"
#include <time.h>

#define TAM 28 //jugadores
#define MANO 7 //cada jugador tiene 7 fichas iniciales
#define JUGADORES 4 //num de jugadores

struct ficha sopa[TAM];//conjunto de fichas
struct ficha jugador1[MANO];
struct ficha jugador2[MANO];
struct ficha jugador3[MANO];
struct ficha jugador4[MANO];//Cuatro jugadores

struct jugador
{
  struct ficha mano[MANO];
};

int jugadorConMula, ganador, turno;
struct jugador jugadores[JUGADORES];//regula los turnos de los jugadores
/*turnos[0] = jugador1;
turnos[1] = jugador2;
turnos[2] = jugador3;
turnos[3] = jugador4;*/
void jugar()
{
  printf("Comienza el juego\n");
  /*struct ficha sopa[TAM];//conjunto de fichas
  struct ficha j1[MANO];
  struct ficha j2[MANO];
  struct ficha j3[MANO];
  struct ficha j4[MANO];//Cuatro jugadores*/
  //int k=0;//iterador

  iniFichas();
  //printFichas(sopa);
  //printf("\nFichas revueltas:\n");
  printf("Estado Inicial:");
  revolverFichas();
  printFichas(sopa);

  repartirFichas();

  printJugadores();

  printf("El jugador que tiene la mula es: Jugador %d\n", jugadorConMula);


}

void iniFichas()
{
  int numeros[] = {0,1,2,3,4,5,6};
  int k = 0;

  for(int i = 0; i < 7; i++)
  {
    for(int j = i; j < 7; j++)
    {
      sopa[k].num1 = numeros[i];
      sopa[k].num2 = numeros[j];
      k++;
    }
  }
}

//imprime fichas en la sopa
void printFichas(struct ficha sopa[])
{
  printf("Fichas en la sopa:\n");
  for(int i = 0; i < TAM; i++)
    printf("|%2d|%2d|\n", sopa[i].num1, sopa[i].num2);

  printf("\n");
}

//revuelve la sopa, cambia una ficha por otra en un índice random
void revolverFichas()
{
  int x;
  struct ficha aux;
  time_t t;
  srand((unsigned)time(&t));

  for(int i = 0; i < TAM; i++)
  {
    aux = sopa[i];
    x = rand() % (TAM-1);
    sopa[i] = sopa[x];
    sopa[x] = aux;
  }
}

//similar a un juego real, repate empezando por el primer jugador
//hacia los demas.
/*
void repartirFichas()
{
  int i=0,j1=0,j2=0,j3=0,j4=0;

  while(i < TAM)
  {
    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 1;

    jugador1[j1] = sopa[i];
    i++;
    j1++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 2;

    jugador2[j2] = sopa[i];
    i++;
    j2++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 3;

    jugador3[j3] = sopa[i];
    i++;
    j3++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 4;

    jugador4[j4] = sopa[i];
    i++;
    j4++;
  }
}*/

void repartirFichas()
{
  int i=0,j1=0,j2=0,j3=0,j4=0;

  while(i < TAM)
  {
    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 1;

    jugadores[0].mano[j1] = sopa[i];
    i++;
    j1++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 2;

    jugadores[1].mano[j2] = sopa[i];
    i++;
    j2++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 3;

    jugadores[2].mano[j3] = sopa[i];
    i++;
    j3++;

    if(sopa[i].num1 == 6)
      if(sopa[i].num2 == 6)
        jugadorConMula = 4;

    jugadores[3].mano[j4] = sopa[i];
    i++;
    j4++;
  }
}
/*
void printJugadores()
{
  int i;
  printf("\nJugador 1: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugador1[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugador1[i].num1, jugador1[i].num2);
      }
    }
  }
  printf("\nJugador 2: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugador2[i].num2 != -1)
      {
        printf("|%2d|%2d| ", jugador2[i].num1, jugador2[i].num2);
      }
    }
  }
  printf("\nJugador 3: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugador3[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugador3[i].num1, jugador3[i].num2);
      }
    }
  }
  printf("\nJugador 4: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugador4[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugador4[i].num1, jugador4[i].num2);
      }
    }
  }
  printf("\n");
}*/


void printJugadores()
{
  int i;
  printf("\nJugador 1: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugadores[0].mano[i].num1 != -1)//se cambia a -1 cuando ya se jugo
      {
        printf("|%2d|%2d| ", jugadores[0].mano[i].num1, jugadores[0].mano[i].num2);
      }
    }
  }
  printf("\nJugador 2: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugadores[1].mano[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugadores[1].mano[i].num1, jugadores[1].mano[i].num2);
      }
    }
  }
  printf("\nJugador 3: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugadores[2].mano[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugadores[2].mano[i].num1, jugadores[2].mano[i].num2);
      }
    }
  }
  printf("\nJugador 4: \n");
  {
    for(i=0; i < MANO;i++)
    {
      if(jugadores[3].mano[i].num1 != -1)
      {
        printf("|%2d|%2d| ", jugadores[3].mano[i].num1, jugadores[3].mano[i].num2);
      }
    }
  }
  printf("\n");
}

void pasarTurno()
{

}
