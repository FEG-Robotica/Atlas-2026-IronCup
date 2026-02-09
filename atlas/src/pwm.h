#include <Arduino.h>
#include "defines.h"

#ifndef PWM_H
#define PWM_H

const double corrd = 1;
const double corre = 1;

void mover_motor(char lado, char direcao, int velocidade)
{
  if (lado == 'd')
  {
    if (direcao == 'f')
    { // ir para frente
      analogWrite(PWMA, velocidade * corre);
      analogWrite(PWMB, LOW);
    }

    if (direcao == 't')
    { // ir para trás
      analogWrite(PWMA, LOW);
      analogWrite(PWMB, velocidade * corre);
    }
  }

  if (lado == 'e')
  {
    if (direcao == 'f')
    { // ir para frente
      analogWrite(PWMC, velocidade * corre);
      analogWrite(PWMD, LOW);
    }

    if (direcao == 't')
    { // ir para trás
      analogWrite(PWMC, LOW);
      analogWrite(PWMD, velocidade * corre);
    }
  }
}

void controlar_motores(int velocidade, char sentido)
{
  mover_motor('e', sentido, 400);
  mover_motor('d', sentido, 400);
}

void testar_PWM()
{
  int cicloDeTrabalho = 400;

  ledcWrite(0, cicloDeTrabalho);
  ledcWrite(1, cicloDeTrabalho);
}

void frente()
{
  mover_motor('e', 'f', 500);
  mover_motor('d', 'f', 500);
}
void tras()
{
  mover_motor('e', 't', 400);
  mover_motor('d', 't', 400);
}

void direita()
{
  mover_motor('e', 'f', 200);
  mover_motor('d', 'f', 400);
}

void esquerda()
{
  mover_motor('e', 'f', 400);
  mover_motor('d', 'f', 200);
}

void parar()
{
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(PWMC, LOW);
  digitalWrite(PWMD, LOW);
  analogWrite(PWMA, 0);
  analogWrite(PWMB, 0);
  analogWrite(PWMC, 0);
  analogWrite(PWMD, 0);
}

void girar_eixo()
{
  mover_motor('e', 'f', 300);
  mover_motor('d', 't', 300);
}

void girar_circulo()
{
  mover_motor('e', 'f', 100);
  mover_motor('d', 'f', 50);
}

void girar_180()
{
  mover_motor('e', 'f', 400);
  mover_motor('d', 't', 400);
  delay(200);
  parar();
}

#endif
