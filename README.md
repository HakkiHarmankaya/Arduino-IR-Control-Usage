# 📡 Arduino #13: IR Kumanda ile LED Kontrolü

Bu projede, bir **IR (kızılötesi) kumanda** ile **bir LED’i uzaktan kontrol etmeyi** öğreneceğiz.  
Kumandadan belirli bir tuşa basıldığında LED yanacak veya sönecek.

🔗 [Web Siteme Bakmak İçin Tıkla](https://www.hakkiharmankaya.com/)  
🔗 [Tinkercad Tasarımına Göz At](https://www.tinkercad.com/things/lkekfj7KtYH?sharecode=dVEGk9T706E89mKk_--u8w0AvcwurdptIGIIRJEO2-E)

---

## 🧰 Gerekli Malzemeler

- 1 adet **IR alıcı sensör (örneğin VS1838B)**
- 1 adet **IR kumanda**
- 1 adet **LED**
- 1 adet **220Ω direnç**
- 1 adet **Arduino**
- 1 adet **breadboard**
- **Jumper kabloları**

---

## ⚙️ Adım Adım Devre Kurulumu

### 🔹 Adım 1: Devreyi Kurun

- **IR alıcı sensör**:
  - **VCC** → **5V**
  - **GND** → **GND**
  - **OUT** → **D3**

- **LED**:
  - **Anot (uzun bacak)** → direnç → **D4**
  - **Katot (kısa bacak)** → **GND**

---

## 🔹 Adım 2: Kumanda Kodlarını Alın

1. Arduino’ya IR kütüphanesi yüklü olmalıdır:  
   📦 `IRremote` (Arduino Library Manager’dan yüklenebilir)

2. Aşağıdaki kod sayesinde, IR kumandanın hangi tuşuna bastığınızda hangi **hexadecimal (HEX)** değerin geldiğini Serial Monitor üzerinden görebilirsiniz.

---

## 🔹 Adım 3: Arduino Kodunu Yazın ve Yükleyin

```cpp
#include <Arduino.h>
#include <IRremote.hpp>

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(3);     // IR alıcı sensör D3 pinine bağlı
  pinMode(4, OUTPUT);      // LED D4 pinine bağlı
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);

    if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
      digitalWrite(4, !digitalRead(4)); // LED'i toggle et
    }

    IrReceiver.resume(); // Sonraki sinyali bekle
  }
}
