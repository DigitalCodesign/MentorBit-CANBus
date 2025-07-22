/*

            ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗               
            ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║               
            ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║               
            ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║               
            ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗          
            ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝          
                                                                                        
     ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
    ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
    ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
    ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
    ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
     ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝ 
        

    Autor: Digital Codesign
    Version: 1.0.0
    Fecha de creación: Enero de 2024
    Fecha de version: Enero de 2024
    Repositorio: https://github.com/DigitalCodesign/MentorBit-CANBus
    Descripcion: 
        Esta libreria esta especificamente diseñada para ser utilizada junto con 
        el modulo MentorBit CAN
    Metodos principales:
        MentorBitCANBus -> constructor de la clase
        begin -> inicializador, debe colocarse en el setup

    TODO: CONFIRM_BUFFER_BYTES
    TODO: SEND_I2C_BUFFER
    TODO: CHANGE_CAN_BITRATE
    TODO: CHANGE_I2C_ADDRESS
    TODO: SEND_BYTES_TO_CAN

*/

#ifndef MentorBitCANBus_h
#define MentorBitCANBus_h

#include <Wire.h>
#include <mcp2515.h>

class MentorBit_CANBus
{

    public:

    MentorBit_CANBus();
        void begin();
        bool configI2CAddress(uint8_t new_i2c_address);
        bool configCANBitrate(uint8_t new_can_bitrate);
        bool available();
        // Method to received a CAN frame
        // Method to send a CAN frame

    private:

        struct can_frame _can_buffer;

}

#endif
