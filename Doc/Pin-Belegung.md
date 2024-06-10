# Pinbelegung

## Out
- Pin 0 = Motor drehen Uhrzeigersinn
- Pin 1 = Motor drehen gegen Uhrzeigersinn
- Pin 4 & 5 = Kompressor (check wenn bei an)
- Pin 6 & 7 = Saugknopf
- Pin 8 & 9 = Absenken des Krans

## In
- ADC Port 2 = Luftdruck (leer > 12500, Druck < 3500)
- ADC Port 3 = Positionserkennung (Digital)
- ADC Port 6 = Farbsensor (Rot: ~34000-35000, Blau: ~36800, Weiß: ~32500)
- ADC Port 7 = Ausgangspositionssensor (Digital) (True: < 100, False: > 30000)[Analog]
- ADC Port 12 = N/A
- ADC Port 13 = Lichtschranke (Digital) (leer < 250, Stein vorhanden > 3500)[Analog]
- ADC Port 14 = N/A
- ADC Port 15 = N/A