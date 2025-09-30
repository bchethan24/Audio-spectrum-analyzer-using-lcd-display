#include <LiquidCrystal.h>
#include <arduinoFFT.h>
#define MIC_PIN A0
#define SAMPLES 64
#define SAMPLING_FREQUENCY 5000

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

double vReal[SAMPLES];
double vImag[SAMPLES];
ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, SAMPLES, SAMPLING_FREQUENCY);

unsigned int sampling_period_us;
unsigned long microseconds;
byte bars[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 31},
  {0, 0, 0, 0, 0, 0, 31, 31},
  {0, 0, 0, 0, 0, 31, 31, 31},
  {0, 0, 0, 0, 31, 31, 31, 31},
  {0, 0, 0, 31, 31, 31, 31, 31},
  {0, 0, 31, 31, 31, 31, 31, 31},
  {0, 31, 31, 31, 31, 31, 31, 31}
};

int contrastPin = 6;
double previousPeak = 0;
unsigned long lastActionTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(contrastPin, OUTPUT);
  analogWrite(contrastPin, 45);

  lcd.begin(16, 2);
  lcd.clear();
  for (int i = 0; i < 8; i++) {
    lcd.createChar(i, bars[i]);
  }
  sampling_period_us = round(1000000.0 / SAMPLING_FREQUENCY);
}

void loop() {
  // Read analog values
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();
    vReal[i] = analogRead(MIC_PIN);
    vImag[i] = 0;
    while (micros() - microseconds < sampling_period_us);
  }
  FFT.windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.compute(FFT_FORWARD);
  FFT.complexToMagnitude();
  lcd.clear();
  double barValues[8];
  for (int i = 0; i < 8; i++) {
    int startBin = i * 2;   // 0-1, 2-3, ..., 14-15
    int endBin = startBin + 2;
    double sum = 0;
    for (int j = startBin; j < endBin; j++) {
      sum += vReal[j];
    }
    double avg = sum / 2.0;
    barValues[i] = avg;
    int barHeight = constrain(map((int)avg, 0, 100, 0, 8), 0, 7);
    lcd.setCursor(i, 0); lcd.write(byte(barHeight));
    lcd.setCursor(i, 1); lcd.write(byte(barHeight));
  }
  for (int i = 0; i < 8; i++) {// // Serial Plotter Output 
  
    Serial.print(barValues[i]);
    if (i < 7) Serial.print("\t");
  }
  Serial.println();
  delay(50);
}
