



void FDCAN1_SI(void){
	MX_FDCAN1_Init();
	FDCAN1_Filter_Config();

	//if (HAL_FDCAN_Start(&hfdcan1) != HAL_OK){ Error_Handler(); }
    //if (HAL_FDCAN_Stop(&hfdcan1) != HAL_OK){ Error_Handler(); }
}

void FDCAN3_SI(void){
	MX_FDCAN3_Init();
	FDCAN3_Filter_Config();

	//if (HAL_FDCAN_Start(&hfdcan3) != HAL_OK){ Error_Handler(); }
    //if (HAL_FDCAN_Stop(&hfdcan3) != HAL_OK){ Error_Handler(); }
}

static void FDCAN1_TX_Function(void)
{   uint8_t TxData1[8];
    TxHeader1.Identifier = 0x124;
    TxHeader1.IdType = FDCAN_STANDARD_ID;
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader1.MessageMarker = 0;

    for (uint8_t i = 0; i < 8; i++){
        TxData1[i] = rand() % 256;
    }

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, TxData1) != HAL_OK){
        Error_Handler();
    }
}

static void FDCAN3_TX_Function(void)
{	uint8_t TxData3[8];
    TxHeader3.Identifier = 0x123;
    TxHeader3.IdType = FDCAN_STANDARD_ID;
    TxHeader3.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader3.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader3.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader3.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader3.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader3.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader3.MessageMarker = 0;

    for (uint8_t i = 0; i < 8; i++){
        TxData3[i] = rand() % 256;
    }

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader3, TxData3) != HAL_OK){
        Error_Handler();
    }
}

static void FDCAN1_RX_Function(void)
{
	uint8_t RxData1[8];
    if (HAL_FDCAN_GetRxFifoFillLevel(&hfdcan1, FDCAN_RX_FIFO0) > 0) {
        if (HAL_FDCAN_GetRxMessage(&hfdcan1, FDCAN_RX_FIFO0, &RxHeader1, RxData1) == HAL_OK) {
            printf("FDCAN1\r\n");
            printf("ID: 0x%03lX \r\n", (unsigned long)RxHeader1.Identifier);
            printf("DLC: 0x%03lX \r\n", RxHeader1.DataLength);
            printf("Data: ");

            for (uint8_t i = 0; i < 8; i++){
                printf(" %02X", RxData1[i]);
            }
            printf("\r\n\n");
        }
    }
}


static void FDCAN3_RX_Function(void)
{
	uint8_t RxData3[8];
    if (HAL_FDCAN_GetRxFifoFillLevel(&hfdcan3, FDCAN_RX_FIFO1) > 0) {
        if (HAL_FDCAN_GetRxMessage(&hfdcan3, FDCAN_RX_FIFO1, &RxHeader3, RxData3) == HAL_OK)  {
        	printf("FDCAN3\r\n");
            printf("ID: 0x%03lX \r\n", (unsigned long)RxHeader3.Identifier);
            printf("DLC: 0x%03lX \r\n", RxHeader3.DataLength);
            printf("Data: ");

            for (uint8_t i = 0; i < 8; i++){
                printf(" %02X", RxData3[i]);
            }
            printf("\r\n\n");
        }
    }
}

static void FDCAN1_Filter_Config(void){
    FDCAN_FilterTypeDef filter = {0};
    filter.IdType = FDCAN_STANDARD_ID;
    filter.FilterIndex = 0;
    filter.FilterType = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
    filter.FilterID1 = 0x000;
    filter.FilterID2 = 0x000;

    if (HAL_FDCAN_ConfigFilter(&hfdcan1, &filter) != HAL_OK){
        Error_Handler();
    }

    if (HAL_FDCAN_ConfigGlobalFilter( &hfdcan1, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE) != HAL_OK){
        Error_Handler();
    }
}


static void FDCAN3_Filter_Config(void){
    FDCAN_FilterTypeDef filter = {0};

    filter.IdType = FDCAN_STANDARD_ID;
    filter.FilterIndex = 0;
    filter.FilterType = FDCAN_FILTER_MASK;
    filter.FilterConfig = FDCAN_FILTER_TO_RXFIFO1;
    filter.FilterID1 = 0x000;
    filter.FilterID2 = 0x000;

    if (HAL_FDCAN_ConfigFilter(&hfdcan3, &filter) != HAL_OK){
        Error_Handler();
    }

    if (HAL_FDCAN_ConfigGlobalFilter( &hfdcan3, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_ACCEPT_IN_RX_FIFO0, FDCAN_REJECT_REMOTE, FDCAN_REJECT_REMOTE) != HAL_OK){
        Error_Handler();
    }
}
