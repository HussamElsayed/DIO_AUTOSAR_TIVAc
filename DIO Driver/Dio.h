#include "Std_Types.h"
#include "Dio_Cfg.h"


/*
 * Dio.h
 *
 *  Created on: Oct 15, 2023
 *      Author: Hussam Elsayed
 */

#ifndef DIO_H_
#define DIO_H_
typedef struct {
                 uint8 mask;
                 uint8 offset;
                 Dio_PortType port;
} structure ;
typedef struct  {
    EcucBooleanParamDef DioDevErrorDetect;
    EcucBooleanParamDef DioFlipChannelApi;
    EcucBooleanParamDef DioVersionInfoApi;
}DioGeneral;
typedef struct  {
    EcucIntegerParamDef DioPortId;
}DioPort;
typedef struct  {
    EcucIntegerParamDef DioChannelId;
}DioChannel;
typedef struct  {
    EcucStringParamDef DioChannelGroupIdentification;
    EcucIntegerParamDef DioPortMask;
    EcucIntegerParamDef DioPortOffset;
}DioChannelGroup;
typedef struct  {
     DioPort;
}DioConfig;

typedef struct
{
  uint8 mask;
  uint8 offset;
  Dio_PortType port;
} Dio_ChannelGroupType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel (Dio_ChannelType ChannelId , Dio_LevelType Level);
unsigned char Dio_ReadPort(unsigned char PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);












#endif /* DIO_H_ */
