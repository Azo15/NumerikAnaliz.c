# NumerikAnaliz - Kök Bulma Yöntemleri

**NumerikAnaliz**, `f(x) = 0.85x² - 2.5x - 4` fonksiyonunun kökünü bulmak için üç temel sayısal yöntemin uygulandığı bir C projesidir:

- Newton-Raphson Metodu  
- Bisection (İkiye Bölme) Metodu  
- Regula Falsi (Doğrusal İnterpolasyon) Metodu

Bu proje, sayısal analiz konularını öğrenmek isteyen öğrenciler ve geliştiriciler için bir örnek çalışma niteliğindedir.

---

## 🔧 Özellikler

- Her yöntem maksimum 15 iterasyona kadar çalışır  
- Hata sınırı (`HATA`) = `0.0004`  
- Her adımda yaklaşık kök ve hata değeri hesaplanır  
- Elde edilen sonuçlar karşılaştırmalı olarak tablo halinde sunulur  
- Belirtilen hata sınırına hangi iterasyonda ulaşıldığı gösterilir  

---
🧑‍💻 Geliştirici Bilgileri

Ad Soyad: Azo Ismail

E-posta: ismailazo260@gmail.com

GitHub: [ github.com/Azo15](https://github.com/Azo15)

İletişim için yukarıdaki bilgilerden bana ulaşabilirsiniz. yorum ve önerilrilerinizi her zaman memnuniyetle karşılarım!

---
## 🚀 Derleme ve Çalıştırma

Bu program C dilinde yazılmıştır ve GCC gibi bir derleyiciyle çalıştırılabilir:

```bash
gcc numerikanaliz.c -o numerikanaliz -lm
./numerikanaliz
NumerikAnaliz/
│
├── numerikanaliz.c         # Ana C kod dosyası
└── README.md               # Proje açıklama dosyası

