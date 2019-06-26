# solo-pong-arduino

Link para o vídeo apresentando o projeto: https://youtu.be/0katOLOThkA

Componentes: Arduino UNO, potenciômetro de 10K, matriz de LED 8x8 e jumpers.

  O projeto foi inspirado no jogo Pong, sendo uma versão simplificada para um jogador, onde a bola "rebate na parede" e volta para o jogador, que não deve deixá-la passar. A raquete é controlada pelos valores fornecidos pelo potenciômetro. A cada momento a velocidade do jogo vai aumentando, aumentando, assim, a velocidade rapidadmente. Quando o jogador perde o jogo, uma mensagem é exibida e, em seguida, a bola ressurge em uma posição aleatória para que o jogo seja recomeçado.
  O código consiste em uma matriz 8x8, que recebe somente valores binários, de modo que as posições da bola e da raquete são armazenadas nesta matriz, e a cada loop do arduino, a posição da bola é atualizada.
