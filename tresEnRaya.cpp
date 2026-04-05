#include <iostream>


using namespace std;
int main(){
const int jugador1 = 1;
const int jugador2 = 2;
int turno  = jugador1;
int fila , columna;
bool juegoTerminado = false;
int tablero [3][3] = {
    {0,0,0},
    {0,0,0},
    {0,0,0}
};
   //muestra el tablero
while (juegoTerminado == false) {                                        
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        cout << tablero[i][j] << " ";
    }
    cout << endl;
}
  //Pide la jugada al usuario
cout << "Turno del jugador " << turno << endl;
cout << "Ingrese fila: " << endl;
cin >> fila;
cout << "Ingrese columna: " << endl;
cin >> columna;

  //Valida la jugada ingresada
 if (fila < 0 || fila > 2 || columna < 0 || columna > 2 ){
            cout << "Movimiento invalido, intente de nuevo\n";
            continue;
}
if (tablero[fila][columna] != 0) {
    cout << "Casilla ocupada, intente de nuevo\n";
    continue;
}

  //Guarda la jugada del usuario 
tablero[fila][columna] = turno;
    
//Detecta al ganador del juego
for (int i = 0; i < 3; i++) {
        
    if (tablero[i][0] == turno && tablero[i][1] == turno && tablero[i][2] == turno) {
        cout << "Gana el jugador " << turno << "!\n";
        juegoTerminado = true;
            }
          
    if (tablero[0][i] == turno && tablero[1][i] == turno && tablero[2][i] == turno) {
         cout << "Gana el jugador " << turno << "!\n";
        juegoTerminado = true;
            }
        }

       
    if ((tablero[0][0] == turno && tablero[1][1] == turno && tablero[2][2] == turno) || (tablero[0][2] == turno && tablero[1][1] == turno && tablero[2][0] == turno)) {
        cout << "Gana el jugador " << turno << "!\n";
        juegoTerminado = true;
        }

        //Detecta si hay empate//
    bool vacios = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tablero[i][j] == 0) {
                vacios = true;
                }
            }
        }

        if (vacios == false && juegoTerminado == false) {
            cout << "Empate!\n";
            juegoTerminado = true;
        }

//Cambio de turno entre los jugadores//
        if (juegoTerminado == false) {
            if (turno == jugador1)
                turno = jugador2;
            else
                turno = jugador1;
        }
    }

    return 0;
}
