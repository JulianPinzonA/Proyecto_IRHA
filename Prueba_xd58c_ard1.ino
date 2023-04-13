int pulsePin = 0;                   // Sensor de Pulso conectado al puerto A0
// Estas variables son volatiles porque son usadas durante la rutina de interrupcion en la segunda Pestaña
volatile int BPM;                   // Pulsaciones por minuto
volatile int Signal;                // Entrada de datos del sensor de pulsos
volatile int IBI = 600;             // tiempo entre pulsaciones
volatile boolean Pulse = false;     // Verdadero cuando la onda de pulsos es alta, falso cuando es Baja
volatile boolean QS = false;        // Verdadero cuando el Arduino Busca un pulso del Corazon

void setup(){ 
 Serial.begin(9600);                // Puerto serial configurado a 9600 Baudios
 interruptSetup();                  // Configura la interrucion para leer el sensor de pulsos cada 2mS  
}

void loop(){
 int pulso = analogRead(A0);           //Lee el valor del pulsometro conectado al puerto Analogo A0
   //Serial.print("BPM = ");  Serial.println(BPM); //Habilitar estas linea para ver BPM en el monitor serial pero deshabilitar la siguiente
   Serial.println(pulso);                          // envia el valor del pulso por el puerto serie  (desabilitarla si habilita la anterior linea)
  if (QS == true){                       // Bandera del Quantified Self es verdadera cuando el Arduino busca un pulso del corazon
    QS = false;                          // Reset a la bandera del Quantified Self 
  }
}











