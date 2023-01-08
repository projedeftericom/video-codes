// Author: projedefteri.com
// One Button Motor Control with Arduino in Proteus

// Sabit PIN Numaraları:
const int butonPin = 12;
const int motoreksiPin = 4;
const int motorartiPin = 1;

// Motorun artı ve eksi durumlarını tutan değişkenler:
int motorEksiDurum = HIGH;
int motorArtiDurum = LOW;
int butonDurum;
int sonbutonDurum = LOW;

unsigned long sonDebounceZamani = 0;
unsigned long debounceZamani = 50;

void setup() {
  pinMode(butonPin, INPUT);
  pinMode(motoreksiPin, OUTPUT);
  pinMode(motorartiPin, OUTPUT);
  // Motorların ilk durumları:
  digitalWrite(motoreksiPin, motorEksiDurum);
  digitalWrite(motorartiPin, motorArtiDurum);
}

void loop() {
  // Buton pin durmunu okuyup butonDurumuOkuma değişkenine yazdık:
  int butonDurumuOkuma = digitalRead(butonPin);

  // Butonun şu anki durumu ile önceki durumunu karşılatırıyoruz:
  if (butonDurumuOkuma != sonbutonDurum) {
      // Buton durumu değiştiyse, zamanlayıcıyı sıfırlıyoruz:
    sonDebounceZamani = millis();
  }
  // millis'den sonDebounceZamani çıkarıyoruz ve bu değeri debounceZamani zamanından büyükse:
  if ((millis() - sonDebounceZamani) > debounceZamani) {
    // Okunan buton durumu buton durumundan farklıysa:
    if (butonDurumuOkuma != butonDurum) {
      // butonDurum değişkenine butonun şu anki durumu yazıyoruz:
      butonDurum = butonDurumuOkuma;
      // Butona basıldıysa:
      if (butonDurum == HIGH) {
        // Motorun eksi ve artı kablolarını, motorun eksi ve artı durumunun tam tersini yaptık, motorEksiDurum
        // HIGH ise LOW, LOW ise HIGH yapıyoruz, aynı zamanda motorArtiDurum durum içinde aynısını yapıyoruz:
        motorEksiDurum = !motorEksiDurum;
        motorArtiDurum = !motorArtiDurum;
      }
    }
  }
  // Motorun artı ve eksi pinlerine ayarladığımız motor artı eksi durumlarını yazıyoruz:
  digitalWrite(motoreksiPin, motorEksiDurum);
  digitalWrite(motorartiPin, motorArtiDurum);
  // Son buton durum değişkenine botunun okunan durumunu yazıyoruz:
  sonbutonDurum = butonDurumuOkuma;
}
