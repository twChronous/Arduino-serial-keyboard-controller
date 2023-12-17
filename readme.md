
# Arduino serial keyboard controller

Esse projeto usa um arduino para controlar algums atalhos e teclas do teclado

## Referência

 - [Node Serialport](https://serialport.io/docs/api-serialport)
 - [Arduino](https://www.arduino.cc/reference/en/language/functions/communication/serial/)
 - [Robotjs](https://robotjs.iot)


## Rodando localmente

Clone o projeto

```bash
  git clone https://github.com/twChronous/Arduino-serial-keyboard-controller
```

Entre no diretório do projeto

```bash
  cd Arduino-serial-keyboard-controller
```

Instale as dependências

```bash
  pnpm install
```

Abra o Arduino IDE
Encontre a pasta e envie o codigo na pasta *button_to_serial* para o seu Arduino!

Inicie o listener

```bash
  node listener
```

*_caso você inicie o listener antes de enviar o codigo para o Arduino a porta serial pode ficar ocupada causando erros!_*

