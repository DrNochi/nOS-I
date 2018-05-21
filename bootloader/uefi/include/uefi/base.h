#pragma once

#include <stdint.h> // Get fixed-width integer types

//
// UEFI versions
//
#define EFI_2_70_SYSTEM_TABLE_REVISION ((2 << 16) | (70))
#define EFI_2_60_SYSTEM_TABLE_REVISION ((2 << 16) | (60))
#define EFI_2_50_SYSTEM_TABLE_REVISION ((2 << 16) | (50))
#define EFI_2_40_SYSTEM_TABLE_REVISION ((2 << 16) | (40))
#define EFI_2_31_SYSTEM_TABLE_REVISION ((2 << 16) | (31))
#define EFI_2_30_SYSTEM_TABLE_REVISION ((2 << 16) | (30))
#define EFI_2_20_SYSTEM_TABLE_REVISION ((2 << 16) | (20))
#define EFI_2_10_SYSTEM_TABLE_REVISION ((2 << 16) | (10))
#define EFI_2_00_SYSTEM_TABLE_REVISION ((2 << 16) | (00))
#define EFI_1_10_SYSTEM_TABLE_REVISION ((1 << 16) | (10))
#define EFI_1_02_SYSTEM_TABLE_REVISION ((1 << 16) | (02))

#define EFI_SPECIFICATION_VERSION EFI_SYSTEM_TABLE_REVISION

//
// UEFI modifiers
//
#define IN
#define OUT
#define OPTIONAL
#define CONST const

//
// UEFI calling convention
//
#define EFIAPI __cdecl

//
// UEFI data types
//
typedef unsigned char BOOLEAN;
constexpr BOOLEAN FALSE = 0;
constexpr BOOLEAN TRUE = 1;

typedef intptr_t INTN;
typedef uintptr_t UINTN;

typedef int8_t INT8;
typedef uint8_t UINT8;

typedef int16_t INT16;
typedef uint16_t UINT16;

typedef int32_t INT32;
typedef uint32_t UINT32;

typedef int64_t INT64;
typedef uint64_t UINT64;

typedef int128_t INT128;
typedef uint128_t UINT128;

typedef char CHAR8;
typedef char16_t CHAR16;

typedef void VOID;

typedef UINTN EFI_STATUS;

typedef VOID *EFI_HANDLE;

// typedef UINT64 EFI_LBA;

typedef struct EFI_GUID
{
    UINT32 Data1;
    UINT16 Data2;
    UINT16 Data3;
    UINT8 Data4[8];
} EFI_GUID;
