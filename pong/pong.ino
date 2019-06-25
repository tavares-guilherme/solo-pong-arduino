#include <LedControl.h>

const int DIN = 12;
const int CS = 11;
const int CLK = 10;
int value = 0;
int position[6] = {0,0,0,0,0,0};
//0 - 7; 1 - 14; 2 - 28; 3 - 56; 4 - 112  ; 5 - 224; 
int imagem[8][8];
char horizontal = 'd';
char vertical = 'c';
char verif = 'f';
int position_y = random(1, 7);
int position_x = random(1, 7);
int cont = 200;
LedControl lc = LedControl(DIN, CLK, CS, 0);

const byte U[] = {
  B00000000,
  B00000000,
  B01111110,
  B01000000,
  B01000000,
  B01111110,
  B00000000,
  B00000000
};

const byte L[] = {
  B00000000,
  B00000000,
  B00000000,
  B01111110,
  B01000000,
  B01000000,
  B00000000,
  B00000000
};

const byte O[] = {
  B00000000,
  B00000000,
  B01111110,
  B01000010,
  B01000010,
  B01111110,
  B00000000,
  B00000000
};

const byte S[] = {
  B00000000,
  B00000000,
  B01000110,
  B01001001,
  B01001001,
  B00110001,
  B00000000,
  B00000000
};

const byte E[] = {
  B00000000,
  B00000000,
  B01111110,
  B01001010,
  B01001010,
  B01000010,
  B00000000,
  B00000000
};

const byte clean[] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

const byte sadface[] = {
  B00000000,
  B01000000,
  B00100100,
  B00100000,
  B00100000,
  B00100100,
  B01000000,
  B00000000
};

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void lose_message(){
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, U[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, L[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, O[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, S[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, E[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, sadface[i]);
  }
  delay(1000);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, sadface[i]);
  }
  delay(1000);
  verif = 'f';
  position_y = random(1, 7);
  position_x = random(1, 7);
  for(int i = 0; i < 8; i++){
    lc.setRow(0, i, clean[i]);
  }
  horizontal = 'd';
  cont = 200;
}

void position_jogador(){
  for(int i = 0; i < 6; i++){
    if(position[i] == 1){
      if(int(7*pow(2, i)) % 2 != 0 && int(7*pow(2, i) > 7)){
        lc.setRow(0, 0, int(7*pow(2,i))+1);
      }else{
        lc.setRow(0, 0, int(7*pow(2, i)));
      }
    }
  }
}

void movimento_bola(){
  imagem[position_y][position_x] = 0;

  if(verif == 'f'){
    if(position_x == 7 || position_x == 1 || position_y == 0 || position_y == 7) verif = 't';
  }else{
    verif = 'f';
  }
  
  switch(horizontal){
    case ('d'):
      if(position_x == 7){
        horizontal = 'e';
      }else{
        if(verif == 'f') position_x++;
      }
      break;
    case ('e'):
        if(position_x == 1){
          if(vertical == 'c'){
            if(position_y == 7){
              if(imagem[position_y - 1][0] == 1) horizontal = 'd';
              else verif = 'P';              
            }else{
              if(imagem[position_y + 1][0] == 1) horizontal = 'd';
              else verif = 'P';
            }
          }else{//vertical = 'b';
            if(position_y == 0){
              if(imagem[position_y + 1][0] == 1) horizontal = 'd';
              else verif = 'P';
            }else{
              if(imagem[position_y - 1][0] == 1) horizontal = 'd';
              else verif = 'P';
            }
          }
        }else{
          if(verif == 'f') position_x--;
        }
      break;
  }

  switch(vertical){
    case ('c'):
      if(position_y == 7){
        vertical = 'b';
      }else{
        if(verif == 'f') position_y++;
      }
      break;
    case ('b'):
      if(position_y == 0){
        vertical = 'c';
      }else{
        if(verif == 'f') position_y--;
      }
      break;
  }
  imagem[position_y][position_x] = 1;
}
void define_posicao(){
  if(value < 170.5){
    for(int i = 0; i < 6; i++){
      position[i] = 0;
      imagem[i][0] = 0;
    }
    position[0] = 1;
    imagem[7][0] = 1;
    imagem[6][0] = 1;
    imagem[5][0] = 1; 
  }else{
    if(value < 341){
      for(int i = 0; i < 6; i++){
        position[i] = 0;
        imagem[i][0] = 0;
      }
      position[1] = 1;
      imagem[6][0] = 1;
      imagem[5][0] = 1;
      imagem[4][0] = 1;
    }else{
      if(value < 511.5){
        for(int i = 0; i < 6; i++) {
          position[i] = 0;
          imagem[i][0] = 0;
        }
        position[2] = 1;
        imagem[5][0] = 1;
        imagem[4][0] = 1;
        imagem[3][0] = 1;
      }else{
        if(value < 682){
          for(int i = 0; i < 6; i++){
            position[i] = 0;
            imagem[i][0] = 0;
          }
          position[3] = 1;
          imagem[4][0] = 1;
          imagem[3][0] = 1;
          imagem[2][0] = 1;
        }else{
          if(value < 852.5){
            for(int i = 0; i < 6; i++){
              position[i] = 0;
              imagem[i][0] = 0;
            }
            position[4] = 1;
            imagem[3][0] = 1;
            imagem[2][0] = 1;
            imagem[1][0] = 1;
          }else{
            for(int i = 0; i < 6; i++){
              position[i] = 0;
              imagem[i][0] = 0;            
            }
            position[5] = 1;
            imagem[2][0] = 1;
            imagem[1][0] = 1;
            imagem[0][0] = 1;
          }
        }
      }
    }
  }
}

void loop() {

  value = analogRead(A0);
  lc.setLed(0, position_x, position_y, false);
  Serial.println(position_x);
  Serial.println(position_y);
  
  define_posicao();
  position_jogador();
  movimento_bola();
  lc.setLed(0, position_x, position_y, true);

  if(verif == 'P') lose_message();
  
  delay(cont);
  if(cont >= 70) cont -= 0.15;
}
