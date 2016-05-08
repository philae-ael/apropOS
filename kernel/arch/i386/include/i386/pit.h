#ifndef PIT_H
#define PIT_F

#define PIT_DATA_CHAN0 0x40 // Chanel 0 data RW
#define PIT_DATA_CHAN1 0x41 // Chanel 1 data RW
#define PIT_DATA_CHAN2 0x42 // Chanel 2 data RW
#define PIT_COMMAND    0x43 // Mode/Command register RO


#define PIT_COMMAND_CHAN(x) ((x) << 6)
#define PIT_COMMAND_ACCESS_MODE(x) ((x) << 4)
#define PIT_COMMAND_OP_MODE(x) ((x) << 4)


#define PIT_COMMAND_MODE0 0 //0 0 0 = Mode 0 (interrupt on terminal count)
#define PIT_COMMAND_MODE1 1 // 0 0 1 = Mode 1 (hardware re-triggerable one-shot)
#define PIT_COMMAND_MODE2 2 // 0 1 0 = Mode 2 (rate generator)
#define PIT_COMMAND_MODE3 3 // 0 1 1 = Mode 3 (square wave generator)
#define PIT_COMMAND_MODE4 4 // 1 0 0 = Mode 4 (software triggered strobe)
#define PIT_COMMAND_MODE5 5 // 1 0 1 = Mode 5 (hardware triggered strobe)
#define PIT_COMMAND_MODE6 6 // 1 1 0 = Mode 2 (rate generator, same as 010b)
#define PIT_COMMAND_MODE6 7 // 1 1 1 = Mode 3 (square wave generator, same as 011b)







#endif
