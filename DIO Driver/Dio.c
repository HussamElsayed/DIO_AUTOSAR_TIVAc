#include "Det.h"
#include "SchM_Dio.h"
#include "Dio.h"
#include "Dio_MemMap.h"
#include "tm4c123gh6pm.h"

/*
 * Dio.c
 *
 *  Created on: Oct 16, 2023
 *      Author: Hussam Elsayed
 */


//--------------------------------------------------------------------------
// write channel
void Dio_WriteChannel (Dio_ChannelType ChannelId , Dio_LevelType Level){


    switch (ChannelId/8)
    {  case 0 :
        ChannelId = ChannelId - 0 * 8 ;
        GPIO_PORTA_DATA_R |= Level<<ChannelId;
        break;
    case 1 :
        ChannelId = ChannelId - 1 * 8 ;
        GPIO_PORTB_DATA_R |= Level<<ChannelId;
        break;
    case 2 :
        ChannelId = ChannelId - 2 * 8 ;
        GPIO_PORTC_DATA_R |= Level<<ChannelId;
        break;
    case 3 :
        ChannelId = ChannelId - 3 * 8 ;
        GPIO_PORTD_DATA_R |= Level<<ChannelId;
        break;
    case 4 :
        ChannelId = ChannelId - 4 * 8 ;
        GPIO_PORTE_DATA_R |= Level<<ChannelId;
        break;
    case 5 :
        ChannelId = ChannelId - 5 * 8 ;
        GPIO_PORTF_DATA_R |= Level<<ChannelId;
        break;
    default :
        break ;
    }
}

//--------------------------------------------------------------------------
// Read channel;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_PortLevelType channel;

    switch (ChannelId/8)
    {  case 0 :
        ChannelId = ChannelId - 0 * 8 ;
        channel = (GPIO_PORTA_DATA_R)&(1<<ChannelId) ;
        break;
    case 1 :
        ChannelId = ChannelId - 1 * 8 ;
        channel = (GPIO_PORTB_DATA_R)&(1<<ChannelId) ;
        break;
    case 2 :
        ChannelId = ChannelId - 2 * 8 ;
        channel = (GPIO_PORTC_DATA_R)&(1<<ChannelId) ;
        break;
    case 3 :
        ChannelId = ChannelId - 3 * 8 ;
        channel = (GPIO_PORTD_DATA_R)&(1<<ChannelId) ;
        break;
    case 4 :
        ChannelId = ChannelId - 4 * 8 ;
        channel = (GPIO_PORTE_DATA_R)&(1<<ChannelId) ;
        break;
    case 5 :
        ChannelId = ChannelId - 5 * 8 ;
        channel = (GPIO_PORTF_DATA_R)&(1<<ChannelId) ;
        break;
    default :
        break ;
    }
    return channel ;
}

//--------------------------------------------------------------------------
// write port


void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level)
{
	 switch (PortId)
     {  case 0 :
	        GPIO_PORTA_DATA_R |= Level;
	        break;
	    case 1 :
	        GPIO_PORTB_DATA_R |= Level;
	        break;
	    case 2 :
	        GPIO_PORTC_DATA_R |= Level;
	        break;
	    case 3 :
	        GPIO_PORTD_DATA_R |= Level;
	        break;
	    case 4 :
	        GPIO_PORTE_DATA_R |= Level;
	        break;
	    case 5 :
	        GPIO_PORTF_DATA_R |= Level;
	        break;
	    default :
	        break ;
     }
}

//--------------------------------------------------------------------------
// Read Port

unsigned char Dio_ReadPort(unsigned char PortId)
{
   volatile unsigned long* port_ptr =(void *)0U;
    switch (PortId)
    {
    case 0 :
        port_ptr = &GPIO_PORTA_DATA_R ;
        break;
    case 1 :
        port_ptr = &GPIO_PORTB_DATA_R ;
        break;
    case 2 :
        port_ptr = &GPIO_PORTC_DATA_R ;
        break;
    case 3 :
        port_ptr = &GPIO_PORTD_DATA_R ;
        break;
    case 4 :
        port_ptr = &GPIO_PORTE_DATA_R ;
        break;
    case 5 :
        port_ptr = &GPIO_PORTF_DATA_R ;
        break;
    default :
        break;
    }

    return *port_ptr;


}




//--------------------------------------------------------------------------
// Read channel Group

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
    volatile Dio_PortLevelType * port_ptr = (void *)0;
    Dio_PortLevelType group ;

    switch (ChannelGroupIdPtr->port)
    {
    case 0 :
        port_ptr = &GPIO_PORTA_DATA_R ;
        break;
    case 1 :
        port_ptr = &GPIO_PORTB_DATA_R ;
        break;
    case 2 :
        port_ptr = &GPIO_PORTC_DATA_R ;
        break;
    case 3 :
        port_ptr = &GPIO_PORTD_DATA_R ;
        break;
    case 4 :
        port_ptr = &GPIO_PORTE_DATA_R ;
        break;
    case 5 :
        port_ptr = &GPIO_PORTF_DATA_R ;
        break;
    default :
        break;
    }

    group = ((*port_ptr)&(ChannelGroupIdPtr->mask))>> ChannelGroupIdPtr->offset;
    return group;
}


//--------------------------------------------------------------------------
// write channel group

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
    volatile Dio_PortLevelType * port_ptr = (void *)0;
    switch (ChannelGroupIdPtr->port)
    {
    case 0 :
        port_ptr = &GPIO_PORTA_DATA_R ;
        break;
    case 1 :
        port_ptr = &GPIO_PORTB_DATA_R ;
        break;
    case 2 :
        port_ptr = &GPIO_PORTC_DATA_R ;
        break;
    case 3 :
        port_ptr = &GPIO_PORTD_DATA_R ;
        break;
    case 4 :
        port_ptr = &GPIO_PORTE_DATA_R ;
        break;
    case 5 :
        port_ptr = &GPIO_PORTF_DATA_R ;
        break;
    default :
        break;
    }

    *port_ptr = ((*port_ptr)&(~(ChannelGroupIdPtr->mask))) | (Level<<ChannelGroupIdPtr->offset);

}





