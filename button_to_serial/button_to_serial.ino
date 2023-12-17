#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int backLight = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
// Limites para detecção das teclas, em ordem crescente
struct {
  int limite;
  char *nome;
  char *shortcut;
} teclas[] = {
  {   50, "Proxima", "audio_next\n" }, //RIGHT
  {  150, "Aumentando volume", "volume_up\n"}, // UP
  {  300, "Abaixando volume", "volume_down\n"}, // DOWN
  {  500, "MUTE", "mute\n"}, // LEFT
  {  750, "Gravar 20min", "record\n"},//SELECT
  { 1024, "                                                ", "" }  // nenhuma tecla apertada
};

// Iniciação
void setup() {
  Serial.begin(9600);
  pinMode(backLight, OUTPUT);
  lcd.begin(16, 2);
  digitalWrite(backLight, HIGH);
}
 
// Laço principal
void loop() {
  static int teclaAnt = -1;   // última tecla detectada
  // Lê a tensão no pino A0
  int leitura = analogRead(A0);
 
  // Identifica a tecla apertada pela tensão lida
  int teclaNova;
  for (teclaNova = 0; ; teclaNova++) {
    if (leitura < teclas[teclaNova].limite) {
      break;
    }
  }

  if (teclaNova != teclaAnt) {
    lcd.setCursor(0,1);
    lcd.print(teclas[teclaNova].nome);
    Serial.write(teclas[teclaNova].shortcut);
    teclaAnt = teclaNova;
  }

}
