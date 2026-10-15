static void MX_GPIO_Init(void) {
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin : I2C1*/
  GPIO_InitStruct.Pin = ;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : I2C2*/
  GPIO_InitStruct.Pin = ;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : I2C3*/
  GPIO_InitStruct.Pin = ;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART1*/
  GPIO_InitStruct.Pin = GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART2*/
  GPIO_InitStruct.Pin = GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART3*/
  GPIO_InitStruct.Pin =  GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART4*/
  GPIO_InitStruct.Pin = GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART5*/
  GPIO_InitStruct.Pin = GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*Configure GPIO pins : UART6*/
  GPIO_InitStruct.Pin = GPIO_PIN_ | GPIO_PIN_;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = ;
  HAL_GPIO_Init(GPIO, &GPIO_InitStruct);

  /*FDCAN1*/
  GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF6_FDCAN1;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*FDCAN3*/
  GPIO_InitStruct.Pin = GPIO_PIN_11 | GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF6_FDCAN3;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}