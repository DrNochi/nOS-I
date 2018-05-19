#pragma once

#include <uefi/table.h>
#include <uefi/memory.h>

#define EFI_RUNTIME_SERVICES_SIGNATURE 0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION EFI_SPECIFICATION_VERSION

//
// UEFI variable attributes
//
#define EFI_VARIABLE_NON_VOLATILE 0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS 0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS 0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD 0x00000008
// This attribute is identified by the mnemonic 'HR' elsewhere
// in this specification.
#define EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS 0x00000010
// NOTE: EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS is deprecated
// and should be considered reserved.
#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS 0x00000020
#define EFI_VARIABLE_APPEND_WRITE 0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS 0x00000080
// This attribute indicates that the variable payload begins
// with an EFI_VARIABLE_AUTHENTICATION_3 structure, and
// potentially more structures as indicated by fields of this
// structure. See definition below and in SetVariable().

//
// UEFI daylight saving time specifiers
//
#define EFI_TIME_ADJUST_DAYLIGHT 0x01
#define EFI_TIME_IN_DAYLIGHT 0x02

//
// UEFI timezone specifiers
//
#define EFI_UNSPECIFIED_TIMEZONE 0x07FF

//
// UEFI pointer converision flags
//
#define EFI_OPTIONAL_PTR 0x00000001

//
// UEFI capsule flags
//
#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

//
// Variable services
//
typedef EFI_STATUS(EFIAPI *EFI_GET_VARIABLE)(
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    OUT UINT32 *Attributes OPTIONAL,
    IN OUT UINTN *DataSize,
    OUT VOID *Data OPTIONAL);

typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_VARIABLE_NAME)(
    IN OUT UINTN *VariableNameSize,
    IN OUT CHAR16 *VariableName,
    IN OUT EFI_GUID *VendorGuid);

typedef EFI_STATUS(EFIAPI *EFI_SET_VARIABLE)(
    IN CHAR16 *VariableName,
    IN EFI_GUID *VendorGuid,
    IN UINT32 Attributes,
    IN UINTN DataSize,
    IN VOID *Data);

typedef EFI_STATUS(EFIAPI *EFI_QUERY_VARIABLE_INFO)(
    IN UINT32 Attributes,
    OUT UINT64 *MaximumVariableStorageSize,
    OUT UINT64 *RemainingVariableStorageSize,
    OUT UINT64 *MaximumVariableSize);

//
// Time services
//
typedef struct EFI_TIME
{
    UINT16 Year;  // 1900 – 9999
    UINT8 Month;  // 1 – 12
    UINT8 Day;    // 1 – 31
    UINT8 Hour;   // 0 – 23
    UINT8 Minute; // 0 – 59
    UINT8 Second; // 0 – 59
    UINT8 Pad1;
    UINT32 Nanosecond; // 0 – 999,999,999
    INT16 TimeZone;    // -1440 to 1440 or 2047
    UINT8 Daylight;
    UINT8 Pad2;
} EFI_TIME;

typedef struct EFI_TIME_CAPABILITIES
{
    UINT32 Resolution;
    UINT32 Accuracy;
    BOOLEAN SetsToZero;
} EFI_TIME_CAPABILITIES;

typedef EFI_STATUS(EFIAPI *EFI_GET_TIME)(
    OUT EFI_TIME *Time,
    OUT EFI_TIME_CAPABILITIES *Capabilities OPTIONAL);

typedef EFI_STATUS(EFIAPI *EFI_SET_TIME)(
    IN EFI_TIME *Time);

typedef EFI_STATUS(EFIAPI *EFI_GET_WAKEUP_TIME)(
    OUT BOOLEAN *Enabled,
    OUT BOOLEAN *Pending,
    OUT EFI_TIME *Time);

typedef EFI_STATUS(EFIAPI *EFI_SET_WAKEUP_TIME)(
    IN BOOLEAN Enable,
    IN EFI_TIME *Time OPTIONAL);

//
// Virtual memory services
//
typedef EFI_STATUS(EFIAPI *EFI_SET_VIRTUAL_ADDRESS_MAP)(
    IN UINTN MemoryMapSize,
    IN UINTN DescriptorSize,
    IN UINT32 DescriptorVersion,
    IN EFI_MEMORY_DESCRIPTOR *VirtualMap);

typedef EFI_STATUS(EFIAPI *EFI_CONVERT_POINTER)(
    IN UINTN DebugDisposition,
    IN VOID **Address);

//
// Miscellaneous runtime services
//
typedef enum EFI_RESET_TYPE
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
} EFI_RESET_TYPE;

typedef struct EFI_CAPSULE_HEADER
{
    EFI_GUID CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
} EFI_CAPSULE_HEADER;

typedef VOID(EFIAPI *EFI_RESET_SYSTEM)(
    IN EFI_RESET_TYPE ResetType,
    IN EFI_STATUS ResetStatus,
    IN UINTN DataSize,
    IN VOID *ResetData OPTIONAL);

typedef EFI_STATUS(EFIAPI *EFI_GET_NEXT_HIGH_MONO_COUNT)(
    OUT UINT32 *HighCount);

typedef EFI_STATUS(EFIAPI *EFI_UPDATE_CAPSULE)(
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    IN EFI_PHYSICAL_ADDRESS ScatterGatherList OPTIONAL);

typedef EFI_STATUS(EFIAPI *EFI_QUERY_CAPSULE_CAPABILITIES)(
    IN EFI_CAPSULE_HEADER **CapsuleHeaderArray,
    IN UINTN CapsuleCount,
    OUT UINT64 *MaximumCapsuleSize,
    OUT EFI_RESET_TYPE *ResetType);

// 
// UEFI runtime services table
// 
typedef struct EFI_RUNTIME_SERVICES
{
    EFI_TABLE_HEADER Hdr;

    //
    // Time Services
    //
    EFI_GET_TIME GetTime;
    EFI_SET_TIME SetTime;
    EFI_GET_WAKEUP_TIME GetWakeupTime;
    EFI_SET_WAKEUP_TIME SetWakeupTime;

    //
    // Virtual Memory Services
    //
    EFI_SET_VIRTUAL_ADDRESS_MAP SetVirtualAddressMap;
    EFI_CONVERT_POINTER ConvertPointer;

    //
    // Variable Services
    //
    EFI_GET_VARIABLE GetVariable;
    EFI_GET_NEXT_VARIABLE_NAME GetNextVariableName;
    EFI_SET_VARIABLE SetVariable;

    //
    // Miscellaneous Services
    //
    EFI_GET_NEXT_HIGH_MONO_COUNT GetNextHighMonotonicCount;
    EFI_RESET_SYSTEM ResetSystem;

    //
    // UEFI 2.0 Capsule Services
    //
    EFI_UPDATE_CAPSULE UpdateCapsule;
    EFI_QUERY_CAPSULE_CAPABILITIES QueryCapsuleCapabilities;

    //
    // Miscellaneous UEFI 2.0 Service
    //
    EFI_QUERY_VARIABLE_INFO QueryVariableInfo;
} EFI_RUNTIME_SERVICES;
