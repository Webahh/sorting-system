# Pinbelegung

## Out
- Pin 0 = Motor drehen Uhrzeigersinn
- Pin 1 = Motor drehen gegen Uhrzeigersinn
- Pin 4 & 5 = Kompressor (check wenn bei an)
- Pin 6 & 7 = Saugknopf
- Pin 8 & 9 = Absenken des Krans

## In
- ADC Channel 2   | PA2 = Luftdruck (leer > 12500, Druck < 3500)
- ADC Channel 3   | PC2 = Positionserkennung (Digital)
- ADC Channel 6   | PA3 = Farbsensor (Rot: ~34000-35000, Blau: ~36800, Weiß: ~32500)
- ADC Channel 7   | PA7 = Ausgangspositionssensor (Digital) (True: < 100, False: > 30000)[Analog]
- ADC Channel 13  | PC3 = Lichtschranke (Digital) (leer < 250, Stein vorhanden > 3500)[Analog]

