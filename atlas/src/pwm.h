#include <Arduino.h>
#include "defines.h"

#ifndef PWM_H
#define PWM_H
float time;
time =200.0;

float corrd = 1.0;
float corre = 1.0;

void mover_motor(char lado, char direcao, float velocidade)
{
  if (lado == 'd')
  {
    if (direcao == 'f')
    { // ir para frente
      digitalWrite(PWMA, HIGH);
      digitalWrite(PWMB, LOW);
      delay(time*velocidade*corre);
      digitalWrite(PWMA, LOW);
      digitalWrite(PWMB, LOW);
      delay(time*(1-(velocidade*corre)));
    }

    if (direcao == 't')
    { // ir para trás
      digitalWrite(PWMA, LOW);
      digitalWrite(PWMB, HIGH);
      delay(time*velocidade*corre);
      digitalWrite(PWMA, LOW);
      digitalWrite(PWMB, LOW);
      delay(time*(1-(velocidade*corre)));
    }
  }

  if (lado == 'e')
  {
    if (direcao == 'f')
    { // ir para frente
      digitalWrite(PWMC, HIGH);
      digitalWrite(PWMD, LOW);
      delay(time*velocidade*corrd);
      digitalWrite(PWMC, LOW);
      digitalWrite(PWMD, LOW);
      delay(time*(1-(velocidade*corrd)));
    }

    if (direcao == 't')
    { // ir para trás
      digitalWrite(PWMC, LOW);
      digitalWrite(PWMD, HIGH);
      delay(time*velocidade*corrd);
      digitalWrite(PWMC, LOW);
      digitalWrite(PWMD, LOW);
      delay(time*(1-(velocidade*corrd)));
    }
  }
}

void controlar_motores(float velocidade, char sentido)
{
  mover_motor('e', sentido, 0.5);
  mover_motor('d', sentido, 0.5);
}

void testar_PWM()
{
  int cicloDeTrabalho = 400;

  ledcWrite(0, cicloDeTrabalho);
  ledcWrite(1, cicloDeTrabalho);
}

void frente()
{
  mover_motor('e', 'f', 0.5);
  mover_motor('d', 'f', 0.5);
}
void tras()
{
  mover_motor('e', 't', 0.5);
  mover_motor('d', 't', 0.5);
}

void direita()
{
  mover_motor('e', 'f', 0.25);
  mover_motor('d', 'f', 0.50);
}

void esquerda()
{
  mover_motor('e', 'f', 0.50);
  mover_motor('d', 'f', 0.25);
}

void parar()
{
  digitalWrite(PWMA, HIGH);
  digitalWrite(PWMB, HIGH);
  digitalWrite(PWMC, HIGH);
  digitalWrite(PWMD, HIGH);
  delay(50);
  digitalWrite(PWMA, 0);
  digitalWrite(PWMB, 0);
  digitalWrite(PWMC, 0);
  digitalWrite(PWMD, 0);
}

void girar_eixo()
{
  mover_motor('e', 'f', 0.25);
  mover_motor('d', 't', 0.25);
}

void girar_circulo()
{
  mover_motor('e', 'f', 1);
  mover_motor('d', 'f', 0.5);
}

void girar_180()
{
  mover_motor('e', 'f', 0.5);
  mover_motor('d', 't', 0.5);
  delay(200);
  parar();
}

#endif
