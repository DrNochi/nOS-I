#pragma once

#include <uefi/base.h>

//
// UEFI event types
//
// These types can be “ORed” together as needed – for example,
// EVT_TIMER might be “Ored” with EVT_NOTIFY_WAIT or
// EVT_NOTIFY_SIGNAL.
#define EVT_TIMER 0x80000000
#define EVT_RUNTIME 0x40000000
#define EVT_NOTIFY_WAIT 0x00000100
#define EVT_NOTIFY_SIGNAL 0x00000200
#define EVT_SIGNAL_EXIT_BOOT_SERVICES 0x00000201
#define EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE 0x60000202

//
// UEFI event groups
//
#define EFI_EVENT_GROUP_EXIT_BOOT_SERVICES                                             \
    {                                                                                  \
        0x27abf055, 0xb1b8, 0x4c26, { 0x80, 0x48, 0x74, 0x8f, 0x37, 0xba, 0xa2, 0xdf } \
    }
#define EFI_EVENT_GROUP_VIRTUAL_ADDRESS_CHANGE                                         \
    {                                                                                  \
        0x13fa7698, 0xc831, 0x49c7, { 0x87, 0xea, 0x8f, 0x43, 0xfc, 0xc2, 0x51, 0x96 } \
    }
#define EFI_EVENT_GROUP_MEMORY_MAP_CHANGE                                             \
    {                                                                                 \
        0x78bee926, 0x692f, 0x48fd, { 0x9e, 0xdb, 0x1, 0x42, 0x2e, 0xf0, 0xd7, 0xab } \
    }
#define EFI_EVENT_GROUP_READY_TO_BOOT                                                 \
    {                                                                                 \
        0x7ce88fb3, 0x4bd7, 0x4679, { 0x87, 0xa8, 0xa8, 0xd8, 0xde, 0xe5, 0xd, 0x2b } \
    }
#define EFI_EVENT_GROUP_RESET_SYSTEM                                                   \
    {                                                                                  \
        0x62da6a56, 0x13fb, 0x485a, { 0xa8, 0xda, 0xa3, 0xdd, 0x79, 0x12, 0xcb, 0x6b } \
    }

// 
// UEFI data types
// 
typedef VOID *EFI_EVENT;

typedef enum EFI_TIMER_DELAY
{
    TimerCancel,
    TimerPeriodic,
    TimerRelative
} EFI_TIMER_DELAY;
