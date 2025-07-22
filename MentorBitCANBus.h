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

struct can_frame {
    uint32_t can_id;
    uint8_t can_dlc;
    uint8_t data[8];
}

class MentorBit_CANBus
{

    public:

        MentorBit_CANBus();
        void begin(uint8_t i2c_addr = 0x05);
        bool configI2CAddress(uint8_t new_i2c_address);
        bool configCANBitrate(uint8_t new_can_bitrate);
        bool available();
        bool readMessage(struct can_frame *frame);
        bool sendMessage(struct can_frame * frame);

    private:

        uint8_t _i2c_address;

}

#endif
