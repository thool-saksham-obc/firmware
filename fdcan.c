#include "stdlib.h"

FDCAN_HandleTypeDef hfdcan1;
FDCAN_HandleTypeDef hfdcan3;

static void MX_FDCAN1_Init(void);
static void MX_FDCAN3_Init(void);

static void FDCAN1_Filter_Config(void);
static void FDCAN3_Filter_Config(void);

static void FDCAN1_TXF(void);
static void FDCAN1_RXF(void);

static void FDCAN3_TXF(void);
static void FDCAN3_RXF(void);

static void FDCAN1_SI(void);
static void FDCAN3_SI(void);

FDCAN_TxHeaderTypeDef TxHeader1;
FDCAN_TxHeaderTypeDef TxHeader3;

FDCAN_RxHeaderTypeDef RxHeader1;
FDCAN_RxHeaderTypeDef RxHeader3;

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

static void FDCAN1_TXF(uint8_t TxData1[8]){   
    
    TxHeader1.Identifier = 0x124;
    TxHeader1.IdType = FDCAN_STANDARD_ID;
    TxHeader1.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader1.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader1.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader1.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader1.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader1.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader1.MessageMarker = 0;

    // for (uint8_t i = 0; i < 8; i++){
    //     TxData1[i] = rand() % 256;
    // }

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader1, TxData1) != HAL_OK){
        Error_Handler();
    }
}

static void FDCAN3_TXF(uint8_t TxData3[8]){	

    TxHeader3.Identifier = 0x123;
    TxHeader3.IdType = FDCAN_STANDARD_ID;
    TxHeader3.TxFrameType = FDCAN_DATA_FRAME;
    TxHeader3.DataLength = FDCAN_DLC_BYTES_8;
    TxHeader3.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
    TxHeader3.BitRateSwitch = FDCAN_BRS_OFF;
    TxHeader3.FDFormat = FDCAN_CLASSIC_CAN;
    TxHeader3.TxEventFifoControl = FDCAN_NO_TX_EVENTS;
    TxHeader3.MessageMarker = 0;

    // for (uint8_t i = 0; i < 8; i++){
    //     TxData3[i] = rand() % 256;
    // }

    if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan3, &TxHeader3, TxData3) != HAL_OK){
        Error_Handler();
    }
}

static void FDCAN1_RXF(void){

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

static void FDCAN3_RXF(void)
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

static void MX_FDCAN1_Init(void){
    hfdcan1.Instance = FDCAN1;
    hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;     //FDCAN_MODE_NORMAL; FDCAN_MODE_INTERNAL_LOOPBACK ;
    hfdcan1.Init.AutoRetransmission = ENABLE;
    hfdcan1.Init.TransmitPause = DISABLE;
    hfdcan1.Init.ProtocolException = DISABLE;

    hfdcan1.Init.NominalPrescaler = 10;
    hfdcan1.Init.NominalSyncJumpWidth = 1;
    hfdcan1.Init.NominalTimeSeg1 = 15;
    hfdcan1.Init.NominalTimeSeg2 = 4;

    hfdcan1.Init.DataPrescaler = 1;
    hfdcan1.Init.DataSyncJumpWidth = 1;
    hfdcan1.Init.DataTimeSeg1 = 1;
    hfdcan1.Init.DataTimeSeg2 = 1;

    hfdcan1.Init.MessageRAMOffset = 0;
    hfdcan1.Init.StdFiltersNbr = 1;
    hfdcan1.Init.ExtFiltersNbr = 0;

    hfdcan1.Init.RxFifo0ElmtsNbr = 64;
    hfdcan1.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.RxFifo1ElmtsNbr = 0;
    hfdcan1.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;

    hfdcan1.Init.RxBuffersNbr = 0;
    hfdcan1.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan1.Init.TxEventsNbr = 0;
    hfdcan1.Init.TxBuffersNbr = 0;
    hfdcan1.Init.TxFifoQueueElmtsNbr = 4;
    hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan1.Init.TxElmtSize = FDCAN_DATA_BYTES_8;

    if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK){
        Error_Handler();
    }
}


static void MX_FDCAN3_Init(void){
    hfdcan3.Instance = FDCAN3;

    hfdcan3.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
    hfdcan3.Init.Mode = FDCAN_MODE_NORMAL;					//FDCAN_MODE_NORMAL; FDCAN_MODE_INTERNAL_LOOPBACK ;
    hfdcan3.Init.AutoRetransmission = ENABLE;
    hfdcan3.Init.TransmitPause = DISABLE;
    hfdcan3.Init.ProtocolException = DISABLE;

    hfdcan3.Init.NominalPrescaler = 10;
    hfdcan3.Init.NominalSyncJumpWidth = 1;
    hfdcan3.Init.NominalTimeSeg1 = 15;
    hfdcan3.Init.NominalTimeSeg2 = 4;

    hfdcan3.Init.DataPrescaler = 1;
    hfdcan3.Init.DataSyncJumpWidth = 1;
    hfdcan3.Init.DataTimeSeg1 = 1;
    hfdcan3.Init.DataTimeSeg2 = 1;

    hfdcan3.Init.MessageRAMOffset = 65;
    hfdcan3.Init.StdFiltersNbr = 1;
    hfdcan3.Init.ExtFiltersNbr = 0;

    hfdcan3.Init.RxFifo0ElmtsNbr = 0;
    hfdcan3.Init.RxFifo0ElmtSize = FDCAN_DATA_BYTES_8;
    hfdcan3.Init.RxFifo1ElmtsNbr = 64;
    hfdcan3.Init.RxFifo1ElmtSize = FDCAN_DATA_BYTES_8;

    hfdcan3.Init.RxBuffersNbr = 0;
    hfdcan3.Init.RxBufferSize = FDCAN_DATA_BYTES_8;
    hfdcan3.Init.TxEventsNbr = 0;
    hfdcan3.Init.TxBuffersNbr = 0;
    hfdcan3.Init.TxFifoQueueElmtsNbr = 4;
    hfdcan3.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
    hfdcan3.Init.TxElmtSize = FDCAN_DATA_BYTES_8;

    if (HAL_FDCAN_Init(&hfdcan3) != HAL_OK){
        Error_Handler();
    }
}

