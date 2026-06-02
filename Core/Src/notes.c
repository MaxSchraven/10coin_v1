 printf("Enter duty cycle (percent 0-100)");
  scanf("%ld\n", &userinput);
  TIM3->CCR1 = (int)((PWM_Period*userinput)/100);
  
  printf("Enter PWM freq (Hz)");
  scanf("%ld\n", &userinput);
  htim3.Init.Period = (int) clkspeed/userinput - 1;

//  this gets stuck at UART_WaitOnFlagUntilTimeout and also does not store the variable in the given adress (i think but i kind gave up)
//  the prototype is left in but commented out
#ifdef __GNUC__
#define GETCHAR_PROTOTYPE int __io_getchar(void)
#else
#define GETCHAR_PROTOTYPE int fgetc(FILE *f)
#endif

GETCHAR_PROTOTYPE
{
  uint8_t ch = 0;

  /* Clear the Overrun flag just before receiving the first character */
  __HAL_UART_CLEAR_OREFLAG(&huart2);

  /* Wait for reception of a character on the USART RX line and echo this
   * character on console */
  HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

//  float from the workshop but float printing takes up way too much flash
PWM_DutyC = ((((float)ADC_Buff[0])/4095.0f)*3.3f)*111.11f;