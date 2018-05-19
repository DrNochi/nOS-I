#pragma once

#include <uefi/boot-services.h>
#include <uefi/runtime-services.h>
#include <uefi/configuration-table.h>
#include <uefi/protocols/simple-text-input.h>
#include <uefi/protocols/simple-text-output.h>

#define EFI_SYSTEM_TABLE_SIGNATURE 0x5453595320494249
#define EFI_SYSTEM_TABLE_REVISION EFI_2_70_SYSTEM_TABLE_REVISION

typedef struct EFI_SYSTEM_TABLE
{
    EFI_TABLE_HEADER Hdr;

    CHAR16 *FirmwareVendor;
    UINT32 FirmwareRevision;

    EFI_HANDLE ConsoleInHandle;
    EFI_SIMPLE_TEXT_INPUT_PROTOCOL *ConIn;
    EFI_HANDLE ConsoleOutHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *ConOut;
    EFI_HANDLE StandardErrorHandle;
    EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *StdErr;

    EFI_RUNTIME_SERVICES *RuntimeServices;
    EFI_BOOT_SERVICES *BootServices;

    UINTN NumberOfTableEntries;
    EFI_CONFIGURATION_TABLE *ConfigurationTable;
} EFI_SYSTEM_TABLE;
