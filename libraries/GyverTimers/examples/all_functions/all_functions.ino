// Демонстрация всех функций библиотеки

#include <GyverTimers.h>

void setup() {
  // Перенастроить таймер и задать ему период или частоту
  // Все функции возвращают реальный период / частоту, которые могут отличаться от введенных
  Timer2.setPeriod(1000);           // Задать конкретный период 1000 мкс (~ 1000 гц), вернет реальный период в мкс
  Timer0.setFrequency(250);         // Задать частоту прерываний таймера в Гц, вернет реальную частоту в герцах
  Timer1.setFrequencyFloat(50.20);  // Задать частоту более точно, в дробных числах, актуально для низких частот и таймера 1
  // С этого момента таймер уже перенастроен и гоняет с выьранной частотой / периодом

  // Подключить прерывание таймера, с этого момента прерывания начнут вызываться
  Timer0.enableISR();               // Подключить стандартное прерывание, канал А, без сдига фаз
  Timer2.enableISR(CHANNEL_B); // Подключить прерывание таймера 2, канал B
  Timer1.enableISR(CHANNEL_A);  // Подключить прерывание канала А
  Timer1.enableISR(CHANNEL_B); // Подключить второе прерывание таймера 1
  // Прерывание уже начнет вызываться

  // Если вдруг прерывание нужно отключить, не останавливая таймер
  Timer1.disableISR(CHANNEL_B);
  // С этого момента прерывание B больше не будет вызываться

  // Если нужно приостановить таймер ПОЛНОСТЬЮ, аппаратно
  Timer2.pause();
  // С этого момента таймер стоит на месте, содержимое счетчика остается нетронутым

  // Теперь таймер можно вернуть в строй
  Timer2.resume();
  // Таймер продолжил считать с того же места

  // Если нужно полностью остановить таймер и сбросить содержимое счетчика
  Timer1.stop();
  // Таймер стоит, счетчик сброшен

  // Возвращаем таймер в строй
  Timer1.restart();
  // Таймер перезапущен, начал считать с начала

  // Если нужно вернуть стандартные Arduino - настройки таймера
  Timer0.setDefault();
  // Теперь таймер работает в станлартном режиме
}

// векторы прерываний
ISR(TIMER1_A) {

}

ISR(TIMER1_B) {

}

ISR(TIMER2_B) {

}

ISR(TIMER0_A) {

}

void loop() {

}
